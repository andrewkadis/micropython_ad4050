/*
 *  (C) Copyright 2016 - Analog Devices, Inc. All Rights Reserved.
 *
 * This software is proprietary and confidential.  By using this software
 * you agree to the terms of the associated Analog Devices License Agreement.
 *
 * Project Name:        Power_On_Self_Test
 *
 * Hardware:                ADuCM4x50 EZKIT
 *
 * Description:     This examples tests the wakeup button on the ADuCM4x50 EZKIT.
 */


/*=============  I N C L U D E S   =============*/


/*
* Use the XINT and GPIO driver to toggle LED when the wakeup button is pressed
* on the ADuCM4x50 EZ-Kit.
*/

#include <drivers/gpio/adi_gpio.h>
#include <drivers/xint/adi_xint.h>
#include <drivers/general/adi_drivers_general.h>
#include "wakeup_button.h"
#include "post_common.h"

/* used for exit timeout */
#define MAXCOUNT (10000000u)

static volatile uint64_t count;
static ADI_GPIO_RESULT eToggleResult;
ADI_ALIGNED_PRAGMA(4)
static uint8_t gpioMemory[ADI_GPIO_MEMORY_SIZE]	ADI_ALIGNED_ATTRIBUTE(4);
ADI_ALIGNED_PRAGMA(4)
static uint8_t xintMemory[ADI_XINT_MEMORY_SIZE]	ADI_ALIGNED_ATTRIBUTE(4);

volatile int WakeCount;



/*
 * External event Callback function
 */
static void pinIntCallback(void* pCBParam, uint32_t nEvent,  void* pEventData)
{
    /* If wakeup button is pressed */
    if((ADI_XINT_EVENT)nEvent == ADI_XINT_EVENT_INT0)
    {
        /* toggle LED 4 */
        WakeCount++;
        eToggleResult = adi_gpio_Toggle(LED_PORT_NUM, LED_PIN_NUM);       
        /* advise we saw button press */
        sprintf(gPrintString,"    \"WAKE\" button pressed %d times", WakeCount);
        INFO(gPrintString);

    }

}

/*
 * TEST_WAKEUP
 */
int TEST_WAKEUP(void)
{
    ADI_GPIO_RESULT eResult = ADI_GPIO_FAILURE;
    ADI_XINT_RESULT eXintResult;

    
    /* test system initialization */

    do
    {       
        /* revert WAKE0 (P0.15) mux setting to GPIO mode */
        pADI_GPIO0->CFG &= 0x3fffffff;  // clear config bits 31:30 to zero

        /*
        ** Configure the external interrupt 0 to generate an interrupt  
        */
        
        /* Initialize the external interrupt driver */
        if(ADI_XINT_SUCCESS != (eXintResult = adi_xint_Init(xintMemory, ADI_XINT_MEMORY_SIZE)))
        {
            FAIL("adi_xint_Init failed\n");
            break;
        }
        
        /* Register the callback for external interrupt 0 */
        if(ADI_XINT_SUCCESS != (eXintResult = adi_xint_RegisterCallback (XINT_EVT_NUM, pinIntCallback, NULL)))
        {
            FAIL("adi_xint_RegisterCallback failed\n");
            break;           
        }

        /* Enable external interrupt 0 and configure it to generate interrupt for a rising edge */
        if(ADI_XINT_SUCCESS != (eXintResult = adi_xint_EnableIRQ (XINT_EVT_NUM, ADI_XINT_IRQ_FALLING_EDGE)))
        {
            FAIL("adi_xint_EnableExIRQ failed\n");
            break;                       
        }
        
        /* init the GPIO service */
        if(ADI_GPIO_SUCCESS != (eResult = adi_gpio_Init(gpioMemory, ADI_GPIO_MEMORY_SIZE)))
        {
            FAIL("adi_gpio_Init failed\n");
            break;
        }

        /*
         * Setup Wakeup button
         */

        /* set GPIO input */
        if(ADI_GPIO_SUCCESS != (eResult = adi_gpio_InputEnable(PB_PORT_NUM, PB_PIN_NUM, true)))
        {
            FAIL("adi_gpio_InputEnable failed\n");
            break;
        }

        /* set GPIO output LED 4 */
        if(ADI_GPIO_SUCCESS != (eResult = adi_gpio_OutputEnable(LED_PORT_NUM, LED_PIN_NUM, true)))
        {
            FAIL("adi_gpio_SetDirection failed\n");
            break;
        }
    }while(0);

    WakeCount = 0u;
    INFO("\nPress SW3 3 times on the ADuCM4x50 EZ-Kit and observe LED4 turn ON and OFF \n\n");

    /* wait for push button interrupts - exit the loop after a while */
    while(WakeCount < 3)
    {
    }

    if(ADI_XINT_SUCCESS != eXintResult)
    {
      DEBUG_RESULT("Xint configuration failed \n",eXintResult,ADI_XINT_SUCCESS);
    }
    
    if (ADI_GPIO_SUCCESS != eResult)
    {
        FAIL("Failed to configure the push buttons or LED's\n");
    }
    else if(ADI_GPIO_SUCCESS != eToggleResult)
    {
        FAIL("Failed to run GPIO example using LED/Pushbutton\n");
    }
    else
    {
        PASS();
    }

    return 0;
}
