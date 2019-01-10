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
 * Description:     This examples tests the RGB LED on the ADuCM4x50 EZKIT.
 */


/*=============  I N C L U D E S   =============*/



#include "tmr_example_rgb.h"
#include "post_common.h"

/* LFOSC runs at 32768 Hz / 256 prescaler = 128 */
#define LOAD_VALUE (128u)
#define INFO(s) test_Info(s)
int test_Info(char *InfoString);

/* Pinmux */
extern int32_t rgb_initpinmux(void);
extern int32_t adi_initpinmux(void);

/* Helper macros */
#define CHECK_ERROR(result, expected, message) \
do {\
	if ( (expected) != (result))\
	{\
        test_Fail(message); \
	}\
} while (0);

/* Count the number of events that occur */
static volatile uint32_t gRGBTimerTimeouts;  

/* RGB Callback function */
void RGBCallbackFunction(void *pCBParam, uint32_t Event, void  * pArg) {
  if ((Event & ADI_TMR_EVENT_TIMEOUT) == ADI_TMR_EVENT_TIMEOUT) {
    gRGBTimerTimeouts++;
  }
}

/******************************************************************************************** 
                                            TEST
*********************************************************************************************/
void runForTenSeconds(void) {
    ADI_TMR_RESULT eResult;
  
    gRGBTimerTimeouts = 0u;
    
    eResult = adi_tmr_Enable(ADI_TMR_DEVICE_RGB, true);
    CHECK_ERROR(eResult, ADI_TMR_SUCCESS, "RGB enable function failed.") 
      
    /* WHILE(Ten seconds have not elapsed) */
    while(gRGBTimerTimeouts < 3u) { 
        ;
    } /* ENDWHILE */  

    eResult = adi_tmr_Enable(ADI_TMR_DEVICE_RGB, false);
    CHECK_ERROR(eResult, ADI_TMR_SUCCESS, "RGB enable function failed.")      
}

void configureRgbOutput(ADI_TMR_PWM_OUTPUT eOutput, uint16_t matchValue){
    ADI_TMR_PWM_CONFIG pwmConfig;
    ADI_TMR_RESULT     eResult;
    
    pwmConfig.eOutput     = eOutput;
    pwmConfig.bMatch      = true;
    /* If this is set to false, then LEDs will be lit when we try to turn them off */
    pwmConfig.bIdleHigh   = true;
    pwmConfig.nMatchValue = matchValue;  
    
    eResult = adi_tmr_ConfigPwm(ADI_TMR_DEVICE_RGB, &pwmConfig);
    CHECK_ERROR(eResult, ADI_TMR_SUCCESS, "ConfigPwm function failed.") 
}

/******************************************************************************************** 
                                            MAIN
*********************************************************************************************/
int TEST_RGB(void) {
    ADI_TMR_CONFIG       tmrConfig;
    ADI_TMR_RESULT       eResult;
    int                  nPinmuxError;

    /* Pinmuxing */
    nPinmuxError = rgb_initpinmux();
    CHECK_ERROR(nPinmuxError, 0u, "Pinmux failed.");    
    
    /* Initialize driver */
    eResult = adi_tmr_Init(ADI_TMR_DEVICE_RGB, RGBCallbackFunction, NULL, true);
    CHECK_ERROR(eResult, ADI_TMR_SUCCESS, "Init function failed.")

    /* Configure timer for 1 second period */
    tmrConfig.bCountingUp      = false;
    tmrConfig.bPeriodic        = true;
    tmrConfig.ePrescaler       = ADI_TMR_PRESCALER_256;
    tmrConfig.eClockSource     = ADI_TMR_CLOCK_LFOSC;
    tmrConfig.nLoad            = LOAD_VALUE;
    tmrConfig.nAsyncLoad       = LOAD_VALUE;
    tmrConfig.bReloading       = false;
    tmrConfig.bSyncBypass      = false;
    eResult = adi_tmr_ConfigTimer(ADI_TMR_DEVICE_RGB, &tmrConfig);
    CHECK_ERROR(eResult, ADI_TMR_SUCCESS, "ConfigTimer function failed.")
      
    /* set them all up so everything is initialized */
    configureRgbOutput(ADI_TMR_PWM_OUTPUT_0, LOAD_VALUE / 2u);  
    configureRgbOutput(ADI_TMR_PWM_OUTPUT_0, LOAD_VALUE + 1u);
    configureRgbOutput(ADI_TMR_PWM_OUTPUT_1, LOAD_VALUE / 2u);  
    configureRgbOutput(ADI_TMR_PWM_OUTPUT_1, LOAD_VALUE + 1u);
    configureRgbOutput(ADI_TMR_PWM_OUTPUT_2, LOAD_VALUE / 2u);  
    configureRgbOutput(ADI_TMR_PWM_OUTPUT_2, LOAD_VALUE + 1u);

    INFO("Set PWM output 0 to a 50 duty cycle, run for 3 seconds, and then turn it off.\r\n");
    configureRgbOutput(ADI_TMR_PWM_OUTPUT_0, LOAD_VALUE / 2u);  
    runForTenSeconds();    
    configureRgbOutput(ADI_TMR_PWM_OUTPUT_0, LOAD_VALUE + 1u);
       
    INFO("Set PWM output 1 to a 50 duty cycle, run for 3 seconds, and then turn it off.\r\n");
    configureRgbOutput(ADI_TMR_PWM_OUTPUT_1, LOAD_VALUE / 2u);  
    runForTenSeconds();    
    configureRgbOutput(ADI_TMR_PWM_OUTPUT_1, LOAD_VALUE + 1u);

    INFO("Set PWM output 2 to a 50 duty cycle, run for 3 seconds, and then turn it off.\r\n");
    configureRgbOutput(ADI_TMR_PWM_OUTPUT_2, LOAD_VALUE / 2u);  
    runForTenSeconds();    
    configureRgbOutput(ADI_TMR_PWM_OUTPUT_2, LOAD_VALUE + 1u);
    adi_initpinmux();
    return 0;
}
