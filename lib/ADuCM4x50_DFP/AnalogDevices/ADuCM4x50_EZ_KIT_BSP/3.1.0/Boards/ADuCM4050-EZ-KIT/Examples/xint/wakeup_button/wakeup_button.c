/*********************************************************************************
   @file:    wakeup_button.c
   @brief:   Wakeup button example source file.
             
 -------------------------------------------------------------------------------

Copyright(c) 2016-2017 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/

/*
* Use the XINT and GPIO driver to toggle LED when the wakeup button is pressed
* on the Kit.
*/

#include <drivers/pwr/adi_pwr.h>
#include <drivers/gpio/adi_gpio.h>
#include <drivers/xint/adi_xint.h>
#include "wakeup_button.h"
#include "common.h"

/* used for exit timeout */
#define MAXCOUNT (10000000u)

static volatile uint64_t count;
static ADI_GPIO_RESULT eToggleResult;
static uint8_t gpioMemory[ADI_GPIO_MEMORY_SIZE];
static uint8_t xintMemory[ADI_XINT_MEMORY_SIZE];


/*
 * External event Callback function
 */
static void pinIntCallback(void* pCBParam, uint32_t nEvent,  void* pEventData)
{
    /* If wakeup button is pressed */
    if((ADI_XINT_EVENT)nEvent == ADI_XINT_EVENT_INT0)
    {
        /* toggle LED 4 */
        eToggleResult = adi_gpio_Toggle(LED_PORT_NUM, LED_PIN_NUM);       
    }

    /* reset the exit counter */
    count = 0u;
}

/*
 * main
 */
int main(void)
{
    ADI_GPIO_RESULT eResult = ADI_GPIO_SUCCESS;
    ADI_XINT_RESULT eXintResult = ADI_XINT_SUCCESS;
    ADI_PWR_RESULT ePwrResult  = ADI_PWR_SUCCESS;
    
    /* test system initialization */
    common_Init();

    ePwrResult = adi_pwr_Init();
    DEBUG_RESULT("adi_pwr_Init failed.", ePwrResult, ADI_PWR_SUCCESS);

    ePwrResult = adi_pwr_SetClockDivider(ADI_CLOCK_HCLK, 1u);
    DEBUG_RESULT("adi_pwr_SetClockDivider (HCLK) failed.", ePwrResult, ADI_PWR_SUCCESS);

    ePwrResult = adi_pwr_SetClockDivider(ADI_CLOCK_PCLK, 1u);
    DEBUG_RESULT("adi_pwr_SetClockDivider (PCLK) failed.", ePwrResult, ADI_PWR_SUCCESS);    

    do
    {       
        /*
        ** Configure the external interrupt 0 to generate an interrupt  
        */
        
        /* Initialize the external interrupt driver */
        if(ADI_XINT_SUCCESS != (eXintResult = adi_xint_Init(xintMemory, ADI_XINT_MEMORY_SIZE)))
        {
            DEBUG_MESSAGE("adi_xint_Init failed\n");
            break;
        }
        
        /* Register the callback for external interrupt 0 */
        if(ADI_XINT_SUCCESS != (eXintResult = adi_xint_RegisterCallback (XINT_EVT_NUM, pinIntCallback, NULL)))
        {
            DEBUG_MESSAGE("adi_xint_RegisterCallback failed\n");
            break;           
        }

        /* Enable external interrupt 0 and configure it to generate interrupt for a rising edge */
        if(ADI_XINT_SUCCESS != (eXintResult = adi_xint_EnableIRQ (XINT_EVT_NUM, ADI_XINT_IRQ_FALLING_EDGE)))
        {
            DEBUG_MESSAGE("adi_xint_EnableExIRQ failed\n");
            break;                       
        }
        
        /* init the GPIO service */
        if(ADI_GPIO_SUCCESS != (eResult = adi_gpio_Init(gpioMemory, ADI_GPIO_MEMORY_SIZE)))
        {
            DEBUG_MESSAGE("adi_gpio_Init failed\n");
            break;
        }

        /*
         * Setup Wakeup button
         */

        /* set GPIO input */
        if(ADI_GPIO_SUCCESS != (eResult = adi_gpio_InputEnable(PB_PORT_NUM, PB_PIN_NUM, true)))
        {
            DEBUG_MESSAGE("adi_gpio_InputEnable failed\n");
            break;
        }

        /* set GPIO output LED 4 */
        if(ADI_GPIO_SUCCESS != (eResult = adi_gpio_OutputEnable(LED_PORT_NUM, LED_PIN_NUM, true)))
        {
            DEBUG_MESSAGE("adi_gpio_SetDirection failed\n");
            break;
        }
    }while(0);

    count = 0u;
    DEBUG_MESSAGE("\nPress SW3 on the Kit and observe LED4 turn ON and OFF \n\n");

    /* wait for push button interrupts - exit the loop after a while */
    while(count < MAXCOUNT)
    {
        count++;
    }

    if(ADI_XINT_SUCCESS != eXintResult)
    {
      DEBUG_RESULT("Xint configuration failed \n",eXintResult,ADI_XINT_SUCCESS);
    }
    
    if (ADI_GPIO_SUCCESS != eResult)
    {
        common_Fail("Failed to configure the push buttons or LED's\n");
    }
    else if(ADI_GPIO_SUCCESS != eToggleResult)
    {
        common_Fail("Failed to run GPIO example using LED/Pushbutton\n");
    }
    else
    {
        common_Pass();
    }

    return 0;
}
