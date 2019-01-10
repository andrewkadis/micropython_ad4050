/*
 *  (C) Copyright 2016 - Analog Devices, Inc. All Rights Reserved.
 *
 * This software is proprietary and confidential.  By using this software
 * you agree to the terms of the associated Analog Devices License Agreement.
 *
 * Project Name:   Power_On_Self_Test
 *
 * Hardware:       ADuCM4x50 EZKIT
 *
 * Description:    This examples performs pushbutton and LED tests on the ADuCM4x50 EZKIT.
 */

#include <signal.h>
#include <drivers/general/adi_drivers_general.h>
#include "post_common.h"
#include <drivers/gpio/adi_gpio.h>



/*******************************************************************
*  global variables
*******************************************************************/
int g_LEDs[] = {LED1, LED2, LED3};

volatile bool g_button_0_pushed = false;
volatile bool g_button_1_pushed = false; 
int g_bounce=0;
int g_bounce_i=0;

extern bool g_bIsTestChosen;
extern int g_nSelectedTest;
extern volatile int g_nPostState;


/* interrupt ID holders */
//static IRQn_Type pb0_IRQ, pb1_IRO;
ADI_ALIGNED_PRAGMA(4)
static uint8_t gpioMemory[ADI_GPIO_MEMORY_SIZE] ADI_ALIGNED_ATTRIBUTE(4);


/* pushbutton callback prototype */
void pbCallback(void*, uint32_t, void*);

/*
 *   Function:    Init_LEDs
 *   Description: This function configures PORTx for LEDs.
 */
void Init_LEDs(void)
{
    /* three seperate calls, in case LEDs are on different ports (as they are on GlueMicro) */
    adi_gpio_OutputEnable( LED1_PORT, LED1_PIN, true);
    adi_gpio_OutputEnable( LED2_PORT, LED2_PIN, true);
    adi_gpio_OutputEnable( LED3_PORT, LED3_PIN, true);
}

/*
 *   Function:    Init_PushButtons
 *   Description: This function configures the push button interrupts.
 */
void Init_PushButtons(void)
{
    /* Two pushbuttons: PB1 & PB2. Configure GroupA for PB0 & GroupB for PB2 */

    /* initialize the GPIO service */
    if (adi_gpio_Init( (void*)gpioMemory, ADI_GPIO_MEMORY_SIZE))
        return;

    /* configure PB0... */

    /* enable input driver */
    if (adi_gpio_InputEnable(PB0_PORT, PB0_PIN, true))
        return;

    /* set low-to-high polarity */
    if (adi_gpio_SetGroupInterruptPolarity(PB0_PORT, PB0_PIN))
        return;

#ifdef EZKIT_REV_0_1
    /* configure PB0... */

    /* enable input driver */
    if (adi_gpio_InputEnable(PB0_PORT_REV_0_1, PB0_PIN_REV_0_1, true))
        return;

    /* set low-to-high polarity */
    if (adi_gpio_SetGroupInterruptPolarity(PB0_PORT_REV_0_1, PB0_PIN_REV_0_1))
        return;

    /* configure PB0 interrupts over the GroupA interrupt group */
    if (adi_gpio_SetGroupInterruptPins(PB0_PORT_REV_0_1, ADI_GPIO_INTA_IRQ, PB0_PIN_REV_0_1))
        return;
#endif

    /* enable input driver */
    if (adi_gpio_InputEnable(PB1_PORT, PB1_PIN, true))
        return;

    /* set low-to-high polarity */
    if (adi_gpio_SetGroupInterruptPolarity(PB1_PORT, PB1_PIN))
        return;

    /* configure PB0 interrupts over the GroupA interrupt group */
    if (adi_gpio_SetGroupInterruptPins(PB0_PORT, ADI_GPIO_INTA_IRQ, PB0_PIN))
        return;

    /* configure PB1 interrupts over the GroupB interrupt group */
    if (adi_gpio_SetGroupInterruptPins(PB1_PORT, ADI_GPIO_INTB_IRQ, PB1_PIN))
        return;

    /* register the callback */
    if (adi_gpio_RegisterCallback(ADI_GPIO_INTA_IRQ, pbCallback, (void*)ADI_GPIO_INTA_IRQ))
        return;

    /* register the callback */
    if (adi_gpio_RegisterCallback(ADI_GPIO_INTB_IRQ, pbCallback, (void*)ADI_GPIO_INTB_IRQ))
        return;
}


/*
 *   Function:    Blink_LED_Bank
 *   Description: Display a blinking LED bar
 */
void Blink_LED_Bank(const int iSpeed)
{
    int n;

    for( n = 0; n < NUM_LEDS; n++ )
    {
        Drive_LED(g_LEDs[n], LED_TOGGLE);
        Delay(iSpeed);
    }
}


/*
 *   Function:    Strobe_LEDs
 *   Description: This strobes the LEDs based on the pattern provide
 *                 with a specified delay until the condition is met.
 *                 If the condition is NULL, we strobe once and exit.
 */
void Strobe_LEDs(unsigned int pattern_a, unsigned int pattern_b, unsigned int delay, bool *pbDone)
{
    unsigned int i = 0;
    volatile bool b = false;

    /* use a copy in case pbDone is NULL */
    if ( NULL != pbDone )
    {
        b = *pbDone;
    }

    while (!b)
    {
        g_bounce++;
        for(i = delay; i > 0; i--)
        {
            Drive_LED_Bank( pattern_a );
            Delay(i);                /* delay decreasing */

            Drive_LED_Bank( pattern_b );
            Delay(delay - i);        /* delay increasing */
        }

        /* check it again */
        if ( NULL != pbDone )
        {
            b = *pbDone;
            if (b)
            {
                break;        /* if not NULL see if condition has now been met */
            }
        }
        else
        {
            b = true;    /* after one time break out if NULL */
        }

        for(i = 0; i < delay; i++)
        {
            Drive_LED_Bank( pattern_a );
            Delay(i);                /* delay increasing */

            Drive_LED_Bank( pattern_b );
            Delay(delay - i);        /* delay decreasing */
        }
        if (g_bounce != g_bounce_i)
            g_button_0_pushed=false; //re-enable

    }
}

/*
 *   Function:    Blink_LED
 *   Description: Blink various LEDs
 */
void Blink_LED(const int iSpeed)
{
    int n;

    while( 1 )
    {
        for( n = 0; n < NUM_LEDS; n++ )
        {
            Drive_LED(g_LEDs[n], LED_TOGGLE);
        }

        Delay(iSpeed);
    }
}

/*
 *   Function:    Drive_LED_Bank
 *   Description: Clear or sets the group of LEDs based on specified state.
 */
void Drive_LED_Bank(const int iState)
{
    int n;
    int nTempState = iState;

    for( n = 0; n < NUM_LEDS; n++ )
    {
        /* drive each LED with last two bits of changing temp state */
        Drive_LED(g_LEDs[n], (LED_ACTION)(nTempState & 0x3) );
        nTempState >>= 2;
    }
}

/*
 *   Function:    Drive_LED
 *   Description: Clear or set a particular LED (NOT A GROUP).
 */
void Drive_LED(const int led, const LED_ACTION ledAction)
{
    ADI_GPIO_PORT port;
    ADI_GPIO_DATA pin;
    bool bInvert =
#ifdef NEGATIVE_LED_LOGIC
		true;
#else
		false;
#endif

    /* if ledAction is 0 we clear the LED,
       if ledAction is 1 we set the LED,
       else we toggle the LED */
    /* LEDx_PORT and LEDx_PIN defined in pbled_test.h */

    /* NOTE: depending on hardware logic, turning an LED
      or/off may require setting the GPIO pin high or low,
      so the NEGATIVE_LED_LOGIC macro is defined to invert
      the below logic accordingly.
    */

    switch (led) {
        case LED1:
            port = LED1_PORT;
            pin = LED1_PIN;
            break;
        case LED2:
            port = LED2_PORT;
            pin = LED2_PIN;
            break;
        case LED3:
            port = LED3_PORT;
            pin = LED3_PIN;
            break;
        default:							
        	port = LED1_PORT;
        	pin = LED1_PIN;
        	break;
    }

    /* turn the LED off/on/toggle, depending on the hardware logic */
    switch (ledAction) {
		case LED_OFF:
			if (bInvert)
				adi_gpio_SetHigh(port, pin);
			else
				adi_gpio_SetLow(port, pin);
			break;
		case LED_ON:
			if (bInvert)
				adi_gpio_SetLow(port, pin);
			else
				adi_gpio_SetHigh(port, pin);
			break;
		case LED_TOGGLE:
            adi_gpio_Toggle(port, pin);
			break;
	}
}


/*
 *   Function:    TEST_PBLED
 *   Description: test to make sure LEDs and PBs are working correctly
 */
int TEST_PBLED(void)
{
    bool bPB0 = false, bPB1 = false;    /* flags to see if button was pushed */

    HEAD( "Pushbutton & LED Test" );

    INFO("Visually inspect that LED1, LED2, and LED3 toggle when PBs are pressed");
    INFO("Waiting for PB1 and PB2 to be pressed...");

    /* init globals, do this each time because we may be called more than once */
    g_button_0_pushed = false;
    g_button_1_pushed = false;

    /* drive the LEDs to show binary code '010' */
    Drive_LED( LED1, LED_OFF);
    Drive_LED( LED2, LED_ON);
    Drive_LED( LED3, LED_OFF);

    /* loop until all pbs are pushed */
    while ( !bPB0 || !bPB1 )
    {
        /* was pb1 pushed? */
        if(g_button_0_pushed && !bPB0 )
        {
            /* pb0 was pressed, toggle all LEDs */
            bPB0 = true;
            Drive_LED_Bank( 0xaa );
            INFO("PB1 pressed...");
        }

        /* was pb2 pushed? */
        if(g_button_1_pushed && !bPB1 )
        {
            /* pb2 was pressed, toggle all LEDs */
            bPB1 = true;
            Drive_LED_Bank( 0xaa );
            INFO("PB2 pressed...");
        }
    }

    g_button_0_pushed = g_button_1_pushed = false;

    return PASS();
}


/* Pushbutton callback */
void pbCallback(void * pCBParam, uint32_t port,  void* pPins)
{
    static int pb0_ctr = 0;
    static int pb1_ctr = 0;
    static int unknown_ctr = 0;
    static char pressed[12];


    /* pCBParam is originating interrupt ID, via either pb0_IRQ or pb1_IRO */

    switch ((ADI_GPIO_IRQ)(intptr_t)pCBParam) {
        case ADI_GPIO_INTA_IRQ:
            g_bounce_i=g_bounce;
            if (g_button_0_pushed)
               return;  // debounce
            pb0_ctr++;
            g_button_0_pushed = true;
            break;
        case ADI_GPIO_INTB_IRQ:
            pb1_ctr++;
            g_button_1_pushed = true;
            break;
        default:
            unknown_ctr++;
            break;
    }

        /* if we are running tests already this may be the PB test so
       we update the global mirror register, clear it, and return */
    if ( STATE_SELECTED == g_nPostState )
    {
        return;
    }

    /* update the state machine */
    switch (g_nPostState)
    {
        case STATE_START:
            pressed[0] = '\0';  // (re)terminate with each new test selection
        case STATE_1:
        case STATE_2:
        case STATE_3:
        case STATE_4:

            /* pushing a 0 */
            if (g_button_0_pushed)
            {
                g_nPostState += 1;                /* update the state */
                g_nSelectedTest <<= 1;            /* shift it up */
                g_nSelectedTest |= 0;             /* OR in a 0 (nop) */
                //g_button_0_pushed = false;        /* clear flag */
                strcat(pressed, "0");             /* add to string */
                INFO("0");
            }

            /* pushing a 1 */
            if (g_button_1_pushed)
            {
                g_nPostState += 1;                /* update the state */
                g_nSelectedTest <<= 1;            /* shift it up */
                g_nSelectedTest |= 0x1;           /* OR in a 1 */
                g_button_1_pushed = false;        /* clear flag */
                strcat(pressed, "1");             /* add to string */
                INFO("1");
            }

            if ( (g_nPostState >= STATE_1) && (g_nPostState <= STATE_4) )
            {
                strcat(pressed, "-");             /* add to string */
            }

        break;
    }

    /* when we get to this state a test has been successfully entered */
    if ( STATE_SELECTED == g_nPostState )
    {
        INFO(pressed);   /* echo the buttons pressed */
        g_bIsTestChosen = true;
    }

    return;
}
