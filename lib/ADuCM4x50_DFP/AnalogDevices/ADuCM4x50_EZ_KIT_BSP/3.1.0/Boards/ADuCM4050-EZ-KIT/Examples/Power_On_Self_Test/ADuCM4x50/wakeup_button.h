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
 * Description:     This is the primary include file for the wakeup button test
 */


#ifndef __WAKEUP_BUTTON_H__
#define __WAKEUP_BUTTON_H__

/* Port and Pin number for LED which is turned on/off when the wakeup button is pressed */
#define LED_PORT_NUM    ADI_GPIO_PORT1
#define LED_PIN_NUM     ADI_GPIO_PIN_12

/* Port and Pin number for wakeup button */
#define PB_PORT_NUM     ADI_GPIO_PORT0
#define PB_PIN_NUM      ADI_GPIO_PIN_15

/* Wakeup interrupt tied to the push button */
#define XINT_EVT_NUM    ADI_XINT_EVENT_INT0

#endif /* __WAKEUP_BUTTON_H__ */
