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
 * Description:     This is the primary include file for the push button test
 */


#ifndef _PBLED_TEST_H_
#define _PBLED_TEST_H_


/* header files */
#include "post_common.h"

/* NOTE: 1st EZ-Kits have the programmable LEDs numbered 3/4/5.
   So assume they will be relabeled as 1/2/3, respectively, on subsequent boards
*/

/* LED port & pin defines */
#define LED1_PORT ADI_GPIO_PORT0
#define LED2_PORT ADI_GPIO_PORT1

#define LED3_PORT ADI_GPIO_PORT1
#define LED1_PIN  ADI_GPIO_PIN_13

#define LED2_PIN  ADI_GPIO_PIN_12
#define LED3_PIN  ADI_GPIO_PIN_13

/* Pushbutton port and pin defines */
#define PB0_PORT_REV_0_1 ADI_GPIO_PORT1
#define PB0_PIN_REV_0_1  ADI_GPIO_PIN_14
#define PB0_PORT ADI_GPIO_PORT2
#define PB0_PIN ADI_GPIO_PIN_9

#define PB1_PORT ADI_GPIO_PORT2
#define PB1_PIN  ADI_GPIO_PIN_6

/* PB interrupts */
#define PB0_INTERRUPT
#define PB1_INTERRUPT

/* LED actions */
typedef enum {
	LED_OFF, LED_ON, LED_TOGGLE
} LED_ACTION;

/* function prototypes */
void Init_LEDs(void);
void Init_PushButtons(void);

void Strobe_LEDs(unsigned int pattern_a, unsigned int pattern_b, unsigned int delay, bool *pbDone);
void Blink_LED(const int iSpeed);
void Blink_LED_Bank(const int iSpeed);
void Drive_LED(const int led, const LED_ACTION ledAction);
void Drive_LED_Bank(const int iState);

#endif /* _PBLED_TEST_H_ */
