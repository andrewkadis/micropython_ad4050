/*! *****************************************************************************
 * @file    tmr_example_rgb.c
 * @brief   Example showing how to use the RGB timer device driver.
 -----------------------------------------------------------------------------
Copyright (c) 2016-2017 Analog Devices, Inc.

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


#include "tmr_example_rgb.h"

extern int32_t adi_initpinmux(void);

volatile static uint32_t gNumRgbTimeouts = 0u;

void RGBCallbackFunction(void *pCBParam, uint32_t Event, void  * pArg)
{   
    /* IF(Interrupt occurred because of a timeout) */
    if ((Event & ADI_TMR_EVENT_TIMEOUT) == ADI_TMR_EVENT_TIMEOUT) {
        gNumRgbTimeouts++;
    } /* ENDIF */

    /* IF(Interrupt occurred because of an event capture) */
    if ((Event & ADI_TMR_EVENT_CAPTURE) == ADI_TMR_EVENT_CAPTURE) {
    } /* ENDIF */
}

int main(void)
{
    ADI_TMR_PWM_CONFIG   pwmConfig;
    ADI_PWR_RESULT       ePwrResult;
    ADI_TMR_CONFIG       tmrConfig;
    ADI_TMR_RESULT       eResult;
    uint32_t             nTimeout;
    uint32_t             nPinmuxError;

    common_Init();

    ePwrResult = adi_pwr_Init();
    DEBUG_RESULT("adi_pwr_Init failed.", ePwrResult, ADI_PWR_SUCCESS);

    ePwrResult = adi_pwr_SetClockDivider(ADI_CLOCK_HCLK, 1u);
    DEBUG_RESULT("adi_pwr_SetClockDivider (HCLK) failed.", ePwrResult, ADI_PWR_SUCCESS);

    ePwrResult = adi_pwr_SetClockDivider(ADI_CLOCK_PCLK, 1u);
    DEBUG_RESULT("adi_pwr_SetClockDivider (PCLK) failed.", ePwrResult, ADI_PWR_SUCCESS);    

    /* Multiplex the output pin for the RGB PWM0 signal */
    nPinmuxError = adi_initpinmux();
    DEBUG_RESULT("Error initializing pinmux.", (uint16_t)nPinmuxError, 0u);  

    /*--------------------- RGB TIMER INITIALIZATION --------------------------*/
      
    /* Set up RGB callback function */
    eResult = adi_tmr_Init(ADI_TMR_DEVICE_RGB, RGBCallbackFunction, NULL, true);
    DEBUG_RESULT("Error initializing RGB.", eResult, ADI_TMR_SUCCESS);

    /*-------------------- RGB TIMER CONFIGURATION ----------------------------*/

    /* Configure RGB to have a period of 1 second, please see the GP timer example for configuration details */
    tmrConfig.bCountingUp  = false;
    tmrConfig.bPeriodic    = true;
    tmrConfig.ePrescaler   = ADI_TMR_PRESCALER_256;
    tmrConfig.eClockSource = ADI_TMR_CLOCK_LFOSC;
    tmrConfig.nLoad        = RGB_LOAD_VALUE_FOR_1SEC_PERIOD;
    tmrConfig.nAsyncLoad   = RGB_LOAD_VALUE_FOR_1SEC_PERIOD;
    tmrConfig.bReloading   = false;
    tmrConfig.bSyncBypass  = false;                        
    eResult = adi_tmr_ConfigTimer(ADI_TMR_DEVICE_RGB, &tmrConfig);
    DEBUG_RESULT("Error configuring RGB.", eResult, ADI_TMR_SUCCESS);

    /*------------------ RGB TIMER PWM CONFIGURATION ----------------------------

    The timers can be configured to generate pulse width modulation (PWM) output
    signals. All GP timers only have 1 PWM output (ADI_TMR_PWM_OUTPUT_0), however
    the RGB timer differs by having 3 PWM output signals (ADI_TMR_PWM_OUTPUT_0,
    ADI_TMR_PWM_OUTPUT_1, and ADI_TMR_PWM_OUTPUT_2). The period of all PWM 
    outputs is the same: the timeout period of the hardware timer. However, each
    PWM output can be configured for a different duty cycle and polarity. The duty 
    cycle is determined by the match value, which is the value the counter
    will toggle the PWM signal at.

    There are several boolean options that also effect PWM output:

    - bMatch    : Set the mode of the PWM output. In TOGGLE mode the duty cycle 
                  is 50% and the period is twice as long. In MATCH mode the duty
                  cycle is configured by the user using the match value, and the 
                  period is simply the period of the timer.
                    - true  MATCH 
                    - false TOGGLE

    - bIdleHigh : Determines the polarity of the PWM output.
                    - true  PWM output is HIGH when idling (the longer portion)
                    - false PWM output is LOW when idling (the longer portion) 
             
    --------------------------------------------------------------------------*/ 

    /* Configure RGB PWM0 to have a PWM duty cycle of 10% */
    pwmConfig.eOutput      = ADI_TMR_PWM_OUTPUT_0;
    pwmConfig.bMatch       = true;
    pwmConfig.bIdleHigh    = true;
    pwmConfig.nMatchValue  = (uint16_t) (RGB_LOAD_VALUE_FOR_1SEC_PERIOD / RGB_PWM0_DUTY_CYCLE_LOAD_DIV);
    eResult = adi_tmr_ConfigPwm(ADI_TMR_DEVICE_RGB, &pwmConfig);
    DEBUG_RESULT("Error configuring RGB PWM0.", eResult, ADI_TMR_SUCCESS); 

    /* Configure RGB PWM1 to have a PWM duty cycle of 25% */
    pwmConfig.eOutput      = ADI_TMR_PWM_OUTPUT_1;
    pwmConfig.bMatch       = true;
    pwmConfig.bIdleHigh    = true;
    pwmConfig.nMatchValue  = (uint16_t) (RGB_LOAD_VALUE_FOR_1SEC_PERIOD / RGB_PWM1_DUTY_CYCLE_LOAD_DIV);
    eResult = adi_tmr_ConfigPwm(ADI_TMR_DEVICE_RGB, &pwmConfig);
    DEBUG_RESULT("Error configuring RGB PWM0.", eResult, ADI_TMR_SUCCESS); 

    /* Configure RGB PWM1 to have a PWM duty cycle of 20% */
    pwmConfig.eOutput      = ADI_TMR_PWM_OUTPUT_2;
    pwmConfig.bMatch       = true;
    pwmConfig.bIdleHigh    = true;
    pwmConfig.nMatchValue  = (uint16_t) (RGB_LOAD_VALUE_FOR_1SEC_PERIOD / RGB_PWM2_DUTY_CYCLE_LOAD_DIV);
    eResult = adi_tmr_ConfigPwm(ADI_TMR_DEVICE_RGB, &pwmConfig);
    DEBUG_RESULT("Error configuring RGB PWM0.", eResult, ADI_TMR_SUCCESS);

    /*------------------------- RGB TIMER ENABLE ------------------------------*/     
     
    eResult = adi_tmr_Enable(ADI_TMR_DEVICE_RGB, true);
    DEBUG_RESULT("Error starting RGB.", eResult, ADI_TMR_SUCCESS);

    /*-------------------------- EXECUTE TEST ---------------------------------*/

    nTimeout = 0u;
    while(gNumRgbTimeouts < EXAMPLE_TIME) {
        /* IF(Maximum number of spin loops is reached, error out to avoid infinite loop) */
        if (nTimeout == TIMEOUT_SPIN_LOOPS) {
            /* Failure will be caught later */
            break;
        } /* ENDIF */
        nTimeout++;
    } /* ENDWHILE */  

    /*------------------------- RGB TIMER DISABLE -----------------------------*/

    eResult = adi_tmr_Enable(ADI_TMR_DEVICE_RGB, false);
    DEBUG_RESULT("Error starting RGB.", eResult, ADI_TMR_SUCCESS);

    /*-------------------------- VERIFY TEST ----------------------------------*/

    /* IF(Unexpected outcome) */
    if (gNumRgbTimeouts != EXAMPLE_TIME) {
        common_Fail("RGB did not run properly.");
        return 1;
    } /* ENDIF */

    /*------------------------ RGB TIMER UNINITIALIZE -------------------------*/

    /* Disable RGB interrupts and callback function */
    eResult = adi_tmr_Init(ADI_TMR_DEVICE_RGB, NULL, NULL, false);
    DEBUG_RESULT("Error uninitializing RGB.", eResult, ADI_TMR_SUCCESS);

    common_Pass();
    return 0u;
}
