/*! *****************************************************************************
 * @file    blinky_example.c
 * @brief   Example showing how to use the GPIO driver to blink LEDs as outputs.
 -----------------------------------------------------------------------------
Copyright (c) 2017 Analog Devices, Inc.

All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:
  - Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.
  - Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.
  - Modified versions of the software must be conspicuously marked as such.
  - This software is licensed solely and exclusively for use with processors
    manufactured by or for Analog Devices, Inc.
  - This software may not be combined or merged with other code in any manner
    that would cause the software to become subject to terms and conditions
    which differ from those listed here.
  - Neither the name of Analog Devices, Inc. nor the names of its
    contributors may be used to endorse or promote products derived
    from this software without specific prior written permission.
  - The use of this software may or may not infringe the patent rights of one
    or more patent holders.  This license does not release you from the
    requirement that you obtain separate licenses from these patent holders
    to use this software.

THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES, INC. AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-
INFRINGEMENT, TITLE, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL ANALOG DEVICES, INC. OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, PUNITIVE OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, DAMAGES ARISING OUT OF
CLAIMS OF INTELLECTUAL PROPERTY RIGHTS INFRINGEMENT; PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

*****************************************************************************/


#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "py/compile.h"
#include "py/runtime.h"
#include "py/repl.h"
#include "py/gc.h"
#include "py/mperrno.h"
#include "lib/utils/pyexec.h"


#include "port.h"



// typedef struct {
//     ADI_GPIO_PORT Port;
//     ADI_GPIO_DATA Pins;
// } PinMap;


// /* LED GPIO assignments */

// #ifdef __EVCOG__
// PinMap MSB = {ADI_GPIO_PORT2, ADI_GPIO_PIN_10};  /*   Red LED on GPIO42 (DS4) */
// PinMap LSB = {ADI_GPIO_PORT2, ADI_GPIO_PIN_2};   /* Green LED on GPIO34 (DS3) */
// #else
// PinMap MSB = {ADI_GPIO_PORT1, ADI_GPIO_PIN_15};  /*   Red LED on GPIO31 (DS4) */
// PinMap LSB = {ADI_GPIO_PORT2, ADI_GPIO_PIN_0};   /* Green LED on GPIO32 (DS3) */
// #endif

// Helper function to init the AD4050
static void init_ad4050();
static void sendTestString();

// Static variables
static char *stack_top;
// Uart
static ADI_UART_CONST_HANDLE hDevOutput = NULL;
uint32_t pUartHwError = NULL;
// Uart Buffer
static uint8_t OutDeviceMem[ADI_UART_BIDIR_MEMORY_SIZE] ADI_ALIGNED_ATTRIBUTE(4);
static char sendMe[] = "Hello, world!\n\r";

// LED GPIOs
static uint8_t gpioMemory[ADI_GPIO_MEMORY_SIZE] = {0};
static ADI_GPIO_RESULT eGpioResult = 0;
typedef struct {
    ADI_GPIO_PORT Port;
    ADI_GPIO_DATA Pins;
} PinMap;
static PinMap MSB = {ADI_GPIO_PORT2, ADI_GPIO_PIN_10};  /*   Red LED on GPIO42 (DS4) */
static PinMap LSB = {ADI_GPIO_PORT2, ADI_GPIO_PIN_2};   /* Green LED on GPIO34 (DS3) */




int main(void)
{

    // Init Code
    init_ad4050();

    // Print for Debug
    sendTestString();

    // Run Micropython
    int stack_dummy;
    stack_top = (char*)&stack_dummy;

    // #if MICROPY_ENABLE_GC
    // gc_init(heap, heap + sizeof(heap));
    // #endif

     eGpioResult = adi_gpio_SetHigh (MSB.Port, MSB.Pins);
    DEBUG_RESULT("adi_gpio_SetHigh (MSB).", eGpioResult, ADI_GPIO_SUCCESS);

    eGpioResult = adi_gpio_SetHigh(LSB.Port,  LSB.Pins);
    DEBUG_RESULT("adi_gpio_SetHigh (LSB).", eGpioResult, ADI_GPIO_SUCCESS);

    // eGpioResult = adi_gpio_SetLow (MSB.Port, MSB.Pins);
    // DEBUG_RESULT("adi_gpio_SetLow (MSB).", eGpioResult, ADI_GPIO_SUCCESS);

    // eGpioResult = adi_gpio_SetLow(LSB.Port,  LSB.Pins);
    // DEBUG_RESULT("adi_gpio_SetLow (LSB).", eGpioResult, ADI_GPIO_SUCCESS);

    mp_init();

    #if MICROPY_ENABLE_COMPILER
    #if MICROPY_REPL_EVENT_DRIVEN
    pyexec_event_repl_init();
    for (;;) {
        int c = mp_hal_stdin_rx_chr();
        if (pyexec_event_repl_process_char(c)) {
            break;
        }
    }
    #else
    pyexec_friendly_repl();
    #endif
    //do_str("print('hello world!', list(x+1 for x in range(10)), end='eol\\n')", MP_PARSE_SINGLE_INPUT);
    //do_str("for i in range(10):\r\n  print(i)", MP_PARSE_FILE_INPUT);
    #else
    pyexec_frozen_module("frozentest.py");
    #endif
    
    mp_deinit();

    
    return 0;
}

void init_ad4050(){



    /* Initialize the power service */
    if (ADI_PWR_SUCCESS != adi_pwr_Init())
    {
        return 1;
    }
    if (ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_HCLK,1))
    {
        return 1;
    }
    if (ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_PCLK,1))
    {
        return 1;
    }




    /* Initialize GPIO driver */
    eGpioResult= adi_gpio_Init(gpioMemory, ADI_GPIO_MEMORY_SIZE);
    DEBUG_RESULT("adi_GPIO_Init failed.", eGpioResult, ADI_GPIO_SUCCESS);

    /* Enable MSB output */
    eGpioResult = adi_gpio_OutputEnable(MSB.Port, MSB.Pins, true);
    DEBUG_RESULT("adi_GPIO_SetOutputEnable failed on MSB.", eGpioResult, ADI_GPIO_SUCCESS);

    /* Enable LSB output */
    eGpioResult = adi_gpio_OutputEnable(LSB.Port, LSB.Pins, true);
    DEBUG_RESULT("adi_GPIO_SetOutputEnable failed on LSB.", eGpioResult, ADI_GPIO_SUCCESS);



    char aDebugString[150u];
    hDevOutput = NULL;
    ADI_ALIGNED_PRAGMA(4)
    #define UART0_TX_PORTP0_MUX (1u<<20)
    #define UART0_RX_PORTP0_MUX (1u<<22)

    /* Set the pinmux for the UART */
    *pREG_GPIO0_CFG |= UART0_TX_PORTP0_MUX | UART0_RX_PORTP0_MUX;

    /* Open the UART device, data transfer is bidirectional with NORMAL mode by default */
    adi_uart_Open(0u, ADI_UART_DIR_BIDIRECTION, OutDeviceMem, sizeof OutDeviceMem, &hDevOutput);

    // Need to configure clock after Uart has been opened
    adi_uart_ConfigBaudRate(hDevOutput, 3, 2, 719, 3);// Corresponds to 115200, taken from Table 17-2, pg. 17-4 in Ref Manual
    // adi_uart_EnableAutobaud(hDevOutput, false, ADI_UART_AUTOBAUD_NO_ERROR);

    // Printout for Debug
    // char welcomeMsg[] = "\n\r\n\r\n\r*******************\n\r***** STARTUP *****\n\r*******************\n\rUart Enabled...\n\r";
    // adi_uart_Write(hDevOutput, welcomeMsg, strlen(welcomeMsg), false, &pUartHwError);

    

}

void sendTestString(){
    // char welcomeMsg[] = "Uart Testing...\n\r";
    // while(true){
    //     for (volatile uint32_t i = 0; i < 1000000; i++){};
    //     adi_uart_Write(hDevOutput, welcomeMsg, strlen(welcomeMsg), false, &pUartHwError);
    // }
}

mp_lexer_t *mp_lexer_new_from_file(const char *filename) {
    mp_raise_OSError(MP_ENOENT);
}

mp_import_stat_t mp_import_stat(const char *path) {
    return MP_IMPORT_STAT_NO_EXIST;
}

mp_obj_t mp_builtin_open(size_t n_args, const mp_obj_t *args, mp_map_t *kwargs) {
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_KW(mp_builtin_open_obj, 1, mp_builtin_open);

// This must be implemented by a port.  It's called by nlr_jump
// if no nlr buf has been pushed.  It must not return, but rather
// should bail out with a fatal error.
NORETURN void nlr_jump_fail(void *val){
    while (1);
}

void NORETURN __fatal_error(const char *msg) {
    while (1);
}

#ifndef NDEBUG
void MP_WEAK __assert_func(const char *file, int line, const char *func, const char *expr) {
    printf("Assertion '%s' failed, at file %s:%d\n", expr, file, line);
    __fatal_error("Assertion failed");
}
#endif







// HAL Functions, overwrite these
#ifndef mp_hal_stdin_rx_chr
int mp_hal_stdin_rx_chr(void){

    /* Ignore return codes since there's nothing we can do if it fails */
    int recv_char = 0;
    adi_uart_Read(hDevOutput, &recv_char, 1, 0, &pUartHwError);
    return recv_char;

}
#endif

#ifndef mp_hal_stdout_tx_strn
void mp_hal_stdout_tx_strn(const char *str, size_t len){

    // Are we receiving a special character?
    char firstChar = *str;
    if( firstChar=='\b' ){

        // Micropythonn is sending us spacing characters so print them
        // adi_uart_Write(hDevOutput, str, 1, false, &pUartHwError);
        char tx_me = 0x20;
        adi_uart_Write(hDevOutput, tx_me, 1, false, &pUartHwError);

    }else{

        // Not receiving a special character, print out what we received
        adi_uart_Write(hDevOutput, str, len, false, &pUartHwError);

    }

}
#endif

#ifndef mp_hal_delay_ms
void mp_hal_delay_ms(mp_uint_t ms);
#endif

#ifndef mp_hal_delay_us
void mp_hal_delay_us(mp_uint_t us);
#endif

#ifndef mp_hal_ticks_ms
mp_uint_t mp_hal_ticks_ms(void);
#endif

#ifndef mp_hal_ticks_us
mp_uint_t mp_hal_ticks_us(void);
#endif

#ifndef mp_hal_ticks_cpu
mp_uint_t mp_hal_ticks_cpu(void);
#endif

// If port HAL didn't define its own pin API, use generic
// "virtual pin" API from the core.
#ifndef mp_hal_pin_obj_t
#define mp_hal_pin_obj_t mp_obj_t
#define mp_hal_get_pin_obj(pin) (pin)
#define mp_hal_pin_read(pin) mp_virtual_pin_read(pin)
#define mp_hal_pin_write(pin, v) mp_virtual_pin_write(pin, v)
#include "extmod/virtpin.h"
#endif