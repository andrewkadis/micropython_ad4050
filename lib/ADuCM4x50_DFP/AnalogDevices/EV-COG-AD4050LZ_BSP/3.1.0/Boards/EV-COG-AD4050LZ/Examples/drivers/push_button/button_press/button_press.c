/*********************************************************************************

Copyright(c) 2017 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/

/*
* Use the GPIO service to Toggle LED's when the push buttons are pressed
* on the EV-COG-AD3029LZ.
*/

#include <drivers/pwr/adi_pwr.h>
#include <drivers/gpio/adi_gpio.h>
#include "common.h"

/* used for exit timeout */
#define MAXCOUNT (10000000u)

static volatile uint64_t count;
static ADI_GPIO_RESULT eToggleResult;

#ifdef __EVCOG__

#define PB1_PORT_NUM        ADI_GPIO_PORT1
#define PB1_PIN_NUM         ADI_GPIO_PIN_0


#define PB2_PORT_NUM        ADI_GPIO_PORT0
#define PB2_PIN_NUM         ADI_GPIO_PIN_9


#define LED1_PORT_NUM       ADI_GPIO_PORT2
#define LED1_PIN_NUM        ADI_GPIO_PIN_2


#define LED2_PORT_NUM       ADI_GPIO_PORT2
#define LED2_PIN_NUM        ADI_GPIO_PIN_10


#define PB1_LABEL           "BTN1"
#define PB2_LABEL           "BTN2"

#define LED1_LABEL          "LED1"
#define LED2_LABEL          "LED2"

#else
#error the test is not ported to this processor
#endif

/*
 * GPIO event Callback function
 */
static void pinIntCallback(void* pCBParam, uint32_t Port,  void* PinIntData)
{
    /* push button 1 */
    if((Port == (uint32_t)PB1_PORT_NUM) && (*(uint32_t*)PinIntData & PB1_PIN_NUM))
    {
        /* toggle LED 1 */
          eToggleResult = adi_gpio_Toggle(LED1_PORT_NUM, LED1_PIN_NUM);
    }

    /* push button 2 */
     if((Port == (uint32_t)PB2_PORT_NUM) && (*(uint32_t*)PinIntData & PB2_PIN_NUM))
    {
        /* toggle LED 2 */
       eToggleResult = adi_gpio_Toggle(LED2_PORT_NUM, LED2_PIN_NUM);
    }

    /* reset the exit counter */
    count = 0u;
}

/*
 * main
 */
int main(void)
{
    ADI_GPIO_RESULT eResult;
    static uint8_t gpioMemory[ADI_GPIO_MEMORY_SIZE];

    /* example system initialization */
    common_Init();

    do
    {
        if(adi_pwr_Init()!= ADI_PWR_SUCCESS)
        {
            DEBUG_MESSAGE("\n Failed to initialize the power service \n");
            eResult = ADI_GPIO_FAILURE;
            break;
        }
        if(ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_HCLK,1))
        {
            DEBUG_MESSAGE("Failed to initialize the power service\n");
            eResult = ADI_GPIO_FAILURE;
            break;
        }
        if(ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_PCLK,1))
        {
            DEBUG_MESSAGE("Failed to initialize the power service\n");
            eResult = ADI_GPIO_FAILURE;
            break;
        }

        /* init the GPIO service */
        if(ADI_GPIO_SUCCESS != (eResult = adi_gpio_Init(gpioMemory, ADI_GPIO_MEMORY_SIZE)))
        {
            DEBUG_MESSAGE("adi_gpio_Init failed\n");
            break;
        }

        /*
         * Setup Push Button
         */

        /* set GPIO input */
        if(ADI_GPIO_SUCCESS != (eResult = adi_gpio_InputEnable(PB1_PORT_NUM, PB1_PIN_NUM, true)))
        {
            DEBUG_MESSAGE("adi_gpio_InputEnable failed\n");
            break;
        }

        /* set GPIO input */
        if(ADI_GPIO_SUCCESS != (eResult = adi_gpio_InputEnable(PB2_PORT_NUM, PB2_PIN_NUM, true)))
        {
            DEBUG_MESSAGE("adi_gpio_InputEnable failed\n");
            break;
        }

        /* set Pin polarity as rising edge */
        if(ADI_GPIO_SUCCESS != (eResult = adi_gpio_SetGroupInterruptPolarity(PB1_PORT_NUM, PB1_PIN_NUM)))
        {
            DEBUG_MESSAGE("adi_gpio_SetGroupInterruptPolarity failed\n");
            break;
        }

        /* set Pin polarity as rising edge */
        if(ADI_GPIO_SUCCESS != (eResult = adi_gpio_SetGroupInterruptPolarity(PB2_PORT_NUM, PB2_PIN_NUM)))
        {
            DEBUG_MESSAGE("adi_gpio_SetGroupInterruptPolarity failed\n");
            break;
        }

        if(PB1_PORT_NUM == PB2_PORT_NUM)
        {
            /* Enable pin interrupt on group interrupt A */
            if(ADI_GPIO_SUCCESS != (eResult = adi_gpio_SetGroupInterruptPins(PB1_PORT_NUM, ADI_GPIO_INTA_IRQ, PB1_PIN_NUM | PB2_PIN_NUM)))
            {
                DEBUG_MESSAGE("adi_gpio_SetGroupInterruptPins failed\n");
                break;
            }
        }

        else
       {
            /* Enable pin interrupt on group interrupt A */
            if(ADI_GPIO_SUCCESS != (eResult = adi_gpio_SetGroupInterruptPins(PB1_PORT_NUM, ADI_GPIO_INTA_IRQ, PB1_PIN_NUM)))
            {
                DEBUG_MESSAGE("adi_gpio_SetGroupInterruptPins failed\n");
                break;
            }

            /* Enable pin interrupt on group interrupt A */
            if(ADI_GPIO_SUCCESS != (eResult = adi_gpio_SetGroupInterruptPins(PB2_PORT_NUM, ADI_GPIO_INTA_IRQ, PB2_PIN_NUM)))
            {
                DEBUG_MESSAGE("adi_gpio_SetGroupInterruptPins failed\n");
                break;
            }
        }

        /* Register the callback */
        if(ADI_GPIO_SUCCESS != (eResult = adi_gpio_RegisterCallback (ADI_GPIO_INTA_IRQ, pinIntCallback, (void*)ADI_GPIO_INTA_IRQ)))
        {
            DEBUG_MESSAGE("adi_gpio_RegisterCallback failed\n");
            break;
        }

        /* set GPIO output LED 1 and 2 */
        if(ADI_GPIO_SUCCESS != (eResult = adi_gpio_OutputEnable(LED1_PORT_NUM , LED1_PIN_NUM, true)))
        {
            DEBUG_MESSAGE("adi_gpio_SetDirection failed\n");
            break;
        }

        if(ADI_GPIO_SUCCESS != (eResult = adi_gpio_OutputEnable(LED2_PORT_NUM, LED2_PIN_NUM , true)))
        {
            DEBUG_MESSAGE("adi_gpio_SetDirection failed\n");
            break;
        }
    }while(0);

    count = 0u;
    DEBUG_MESSAGE("\nPress %s or %s to toggle %s and %s on the COG Board\n\n", PB1_LABEL, PB2_LABEL, LED1_LABEL, LED2_LABEL);

    /* wait for push button interrupts - exit the loop after a while */
    while(count < MAXCOUNT)
    {
        count++;
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
