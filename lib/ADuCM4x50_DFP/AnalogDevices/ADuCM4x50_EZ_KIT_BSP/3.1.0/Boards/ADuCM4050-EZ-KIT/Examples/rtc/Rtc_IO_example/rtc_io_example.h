/*********************************************************************************

Copyright(c) 2016 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/
/*!
* @file     rtc_alarm.h
*
* @brief    Primary header file for RTC  example.
*
* @details  Primary header file for RTC driver example which contains the
*           processor specific defines.
*
*/

#ifndef RTC_IO_EXAMPLE_H_
#define RTC_IO_EXAMPLE_H_
/* set lowest interrupt priority (highest number)
   according to number of priority bits on-chip */
#define LOWEST_PRIORITY ((1U << __NVIC_PRIO_BITS) -1)

/* bump UART interrupt priority by one (lower number = higher priority)
   so that UART output continues during low-power hibernation test */
#define UART_PRIORITY (LOWEST_PRIORITY - 1)


#define RTC_DEVICE_NUM   1

#define INIT_RTC_COUNT   0

#define AUTO_RELOAD_VALUE  32768/2

#define MAX_OUTCOMP  30

#define INPUT_CHANNEL_INT ADI_RTC_INPUT_CAPTURE_CH4_INT

#define INPUT_CHANNEL  ADI_RTC_INPUT_CHANNEL_4

/* prototypes for RTC initialization */
ADI_RTC_RESULT rtc_Init(void);
/* prototypes for clock initialization */
ADI_PWR_RESULT InitClock(void);
/* prototypes for clock initialization */
ADI_GPIO_RESULT InitGPIO(void);

void rtc1Callback (void *pCBParam, uint32_t Event, void *EventArg);


#endif /* RTC_IO_EXAMPLE_H_ */
