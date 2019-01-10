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
 * Description:     This is the primary include file for the rgb timer test
 */


#ifndef ADI_TMR_EXAMPLE_RGB
#define ADI_TMR_EXAMPLE_RGB

#include <stdint.h>
//#include <common.h>
#include <drivers/tmr/adi_tmr.h>
#include <drivers/gpio/adi_gpio.h>

/* User configuration: Number of seconds to wait before finishing the example */
#define EXAMPLE_TIME                   (5u)

/* Private, non-modifiable macros */ 
#define RGB_LOAD_VALUE_FOR_1SEC_PERIOD (128u)
#define RGB_PWM0_DUTY_CYCLE_LOAD_DIV   (10u)
#define RGB_PWM1_DUTY_CYCLE_LOAD_DIV   (4u)
#define RGB_PWM2_DUTY_CYCLE_LOAD_DIV   (5u)
#define TIMEOUT_SPIN_LOOPS             (EXAMPLE_TIME*1000000u)

#endif /* ADI_TMR_EXAMPLE_RGB */
