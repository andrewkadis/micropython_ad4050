/*********************************************************************************
   @file:   xint_example_cog.c
   @brief:  Example demonstrating how to use the XINT driver on the EV-COG 
            board. 
 -------------------------------------------------------------------------------

Copyright(c) 2017 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/


#include "xint_example_cog.h"

#include <common.h>
#include <drivers/pwr/adi_pwr.h>
#include <drivers/gpio/adi_gpio.h>
#include <drivers/xint/adi_xint.h>


#define SYSTEM_CORE_CLOCK  (26000000u)
#define SYSTICK_MS_DIVIDER (1000u)


static uint8_t gpioMemory[ADI_GPIO_MEMORY_SIZE];
static uint8_t xintMemory[ADI_XINT_MEMORY_SIZE];
static volatile uint32_t nMilliseconds;
static volatile uint32_t nInterrupts;


void SysTick_Handler(void)
{
    nMilliseconds++;
}



static void xintCallback(void* pCBParam, uint32_t nEvent,  void* pEventData)
{
    if ((ADI_XINT_EVENT) nEvent == ADI_XINT_EVENT_INT1)
    {
        nInterrupts++;
    }
}


int main(void)
{
    ADI_GPIO_RESULT gpioResult;
    ADI_XINT_RESULT xintResult;
    ADI_PWR_RESULT  pwrResult;

    pwrResult = adi_pwr_Init();
    DEBUG_RESULT("adi_pwr_Init failed.", pwrResult, ADI_PWR_SUCCESS);

    pwrResult = adi_pwr_SetClockDivider(ADI_CLOCK_HCLK, 1u);
    DEBUG_RESULT("adi_pwr_SetClockDivider (HCLK) failed.", pwrResult, ADI_PWR_SUCCESS);

    pwrResult = adi_pwr_SetClockDivider(ADI_CLOCK_PCLK, 1u);
    DEBUG_RESULT("adi_pwr_SetClockDivider (PCLK) failed.", pwrResult, ADI_PWR_SUCCESS);

    common_Init();

    /* SysTick used to give upper limit on example run-time */
	SysTick_Config(SYSTEM_CORE_CLOCK  / SYSTICK_MS_DIVIDER);

	/* Configure hardware */
    do
    {
        /* Init the GPIO service */
        if(ADI_GPIO_SUCCESS != (gpioResult = adi_gpio_Init(gpioMemory, ADI_GPIO_MEMORY_SIZE)))
        {
            DEBUG_MESSAGE("adi_gpio_Init failed\n");
            break;
        }

        /* Configure the pin for the push button to act as an input */
        if(ADI_GPIO_SUCCESS != (gpioResult = adi_gpio_InputEnable(ADI_GPIO_PORT1, ADI_GPIO_PIN_0, true)))
        {
            DEBUG_MESSAGE("adi_gpio_InputEnable failed\n");
            break;
        }

        /* Initialize the XINT driver */
        if(ADI_XINT_SUCCESS != (xintResult = adi_xint_Init(xintMemory, ADI_XINT_MEMORY_SIZE)))
        {
            DEBUG_MESSAGE("adi_xint_Init failed\n");
            break;
        }

        /* Register the callback for XINT0 external interrupts  */
        if(ADI_XINT_SUCCESS != (xintResult = adi_xint_RegisterCallback (ADI_XINT_EVENT_INT1, xintCallback, NULL)))
        {
            DEBUG_MESSAGE("adi_xint_RegisterCallback failed\n");
            break;
        }

        /* Enable XINT0 for falling edge interrupt */
        if(ADI_XINT_SUCCESS != (xintResult = adi_xint_EnableIRQ (ADI_XINT_EVENT_INT1, ADI_XINT_IRQ_FALLING_EDGE)))
        {
            DEBUG_MESSAGE("adi_xint_EnableExIRQ failed\n");
            break;
        }

    } while(0);

    if (ADI_GPIO_SUCCESS != gpioResult) {
        common_Fail("GPIO configuration failed.");
        return 1;
    }

	if (ADI_XINT_SUCCESS != xintResult) {
		common_Fail("XINT configuration failed.");
        return 1;
	}

	DEBUG_MESSAGE("Push BTN1 to trigger an external interrupt.");
    nMilliseconds = 0;
    nInterrupts = 0;
    while (nMilliseconds < 1000*EXAMPLE_TIMEOUT_SEC)
    {
        if (nInterrupts > 0) {
            DEBUG_MESSAGE("Push button pressed!\r\n");
            break;
        }
    }

    if (nInterrupts == 0) {
    	common_Fail("You did not press BTN1 before timeout.");
    	return 1;

    } else {
    	common_Pass();
    	return 0;
    }
}
