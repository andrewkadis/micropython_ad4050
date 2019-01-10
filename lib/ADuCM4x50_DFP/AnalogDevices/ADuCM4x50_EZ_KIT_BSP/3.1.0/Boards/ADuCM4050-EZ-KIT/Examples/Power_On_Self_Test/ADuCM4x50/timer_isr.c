/*
 *  (C) Copyright 2016-2017 - Analog Devices, Inc. All Rights Reserved.
 *
 * This software is proprietary and confidential.  By using this software
 * you agree to the terms of the associated Analog Devices License Agreement.
 *
 * Project Name:        Power_On_Self_Test
 *
 * Hardware:                ADuCM4x50 EZKIT
 *
 * Description:     This file provides timer functions for the Power On Self Test
 */


/*=============  I N C L U D E S   =============*/

#include <adi_processor.h>
#include <drivers/tmr/adi_tmr.h>

#include "post_common.h"
#include "Timer_ISR.h"

/* this timer file is driven by a 1ms timer tick and is used to delay various parts of the POST test */

/* timer device instance ID */
#define TIMER_DEVICE_ID   0
#define GP0_LOAD_VALUE_FOR_10MS_PERIOD (4063u)

/* clocking defines */
/* use 26KHz HF oscillator and unity divider for best resolution */
#define CLOCK_SOURCE      (ADI_TMR_CLOCK_HFOSC)
#define CLOCK_PRESCALER   (ADI_GPT_PRESCALER_1)
#define CLOCK_RATE        (26000000/4)  /* HF has default clock divider of 4 */

/* desired interrupt rate is 1ms */
#define INTERRUPT_RATE    (1000)
#define PRELOAD_VALUE     (CLOCK_RATE/INTERRUPT_RATE)


/* Timer callback function */
static void timerCallback(void *pCBParam, uint32_t Event, void *pArg);

/* interrupt counter */
static volatile unsigned long milliseconds;



/*
 *  Function:    Init_Timer
 *  Description: This function initializes the dedicated POST GP timer.
 */
void Init_Timer(void)
{
  
    ADI_TMR_CONFIG        tmrConfig;
    ADI_TMR_RESULT        eResult;

 /*--------------------- GP TIMER INITIALIZATION --------------------------*/

    /* Set up GP0 callback function */
    eResult = adi_tmr_Init(ADI_TMR_DEVICE_GP0, timerCallback, NULL, true);
    DEBUG_RESULT("Error initializing GP0.", eResult, ADI_TMR_SUCCESS);

    /*------------------ GP TIMER CONFIGURATION --------------------------------

    Timer periods are set based on the following equation:

    PERIOD [sec] = (1 / (eClockSource [Hz] / ePrescaler)) * LOAD [16-bit]

    Where LOAD is given by nLoad and nAsyncLoad depending on the clock settings.

    PCLK will vary depending on which root clock is selected and what prescaler is
    applied to the PCLK. The PCLK can be set-up using the PWR driver. The HFOSC and
    LFOSC are fixed values and are enabled by default at start-up. These clock sources
    are used in the timer examples in order to avoid a dependency on the PWR driver.

    @TODO: Explain how to use LFXTAL

        ================================================
        | Clock Source |  Default    |  Equation        |
        ================================================
        |    PCLK      |   6.5 MHz   | root_clk / PDIV  |
        |    HFOSC     |   26  MHz   |  Constant        |
        |    LFOSC     |   32  kHz   |  Constant        |
        |    LFXTL     |   32  kHz   |  ???             |
        ================================================

    There are several boolean options that also effect timer period and behavior:

    - bCountingUp : Determines the direction of the count.
                        - true  increments
                        - false decrements

    - bPeriodic   : Determines the mode of the timer.
                        - true  PERIODIC
                        - false FREE-RUNNING

        ================================================
        | bCountingUp |  bPeriodic  |  Count Sequence  |
        ================================================
        |    false    |   false     | 0xFFFF -> 0x0000 |
        |    false    |   true      |  LOAD  -> 0x0000 |
        |    true     |   false     | 0x0000 -> 0xFFFF |
        |    true     |   true      |  LOAD  -> 0xFFFF |
        ================================================

    - bReloading  : Only relevent for periodic mode, allows user to reset timer before timeout.
                        - true  adi_tmr_Reload can be called to reload the timer
                        - false adi_tmr_Reload can not be called to reload the timer


    - bSyncBypass : Only relevent if PCLK is selected, allows a prescale of 4 to be used.
                        - true  ADI_TMR_PRESCALER_1 = PCLK / 1
                        - false ADI_TMR_PRESCALER_1 = PCLK / 4

    --------------------------------------------------------------------------*/

    /* Configure GP0 to have a period of 1 ms */
    tmrConfig.bCountingUp  = false;
    tmrConfig.bPeriodic    = true;
    tmrConfig.ePrescaler   = ADI_TMR_PRESCALER_64;
    tmrConfig.eClockSource = ADI_TMR_CLOCK_HFOSC;
    tmrConfig.nLoad        = GP0_LOAD_VALUE_FOR_10MS_PERIOD/10;
    tmrConfig.nAsyncLoad   = GP0_LOAD_VALUE_FOR_10MS_PERIOD/10;
    tmrConfig.bReloading   = false;
    tmrConfig.bSyncBypass  = false;
    eResult = adi_tmr_ConfigTimer(ADI_TMR_DEVICE_GP0, &tmrConfig);
    DEBUG_RESULT("Error configuring GP0.", eResult, ADI_TMR_SUCCESS);

    /*------------------------- GP TIMER ENABLE ------------------------------*/

    eResult = adi_tmr_Enable(ADI_TMR_DEVICE_GP0, true);
    DEBUG_RESULT("Error starting GP0.", eResult, ADI_TMR_SUCCESS);


}


/*
 *   Function:    Delay
 *   Description: Blocking delay for a fixed number of milliseconds
 */
void Delay(const unsigned long ulMs)
{
	/* reset millisecond counter (driven by timer interrupt) and set future time count */
	milliseconds = 0;
	unsigned long ulEnd = (milliseconds + ulMs);


    while( milliseconds < ulEnd )
	{

	}

}


/*
 *   Function:    void Timer_ISR( void *, uint_32, void *)
 *   Description: Timer ISR
 */
static void timerCallback(void *pCBParam, uint32_t Event, void *pArg)
{
    milliseconds++;
}
