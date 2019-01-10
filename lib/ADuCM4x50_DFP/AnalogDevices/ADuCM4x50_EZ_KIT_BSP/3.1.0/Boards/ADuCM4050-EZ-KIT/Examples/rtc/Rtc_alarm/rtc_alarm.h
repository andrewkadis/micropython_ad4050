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

#ifndef RTC_ALARM_H
#define RTC_ALARM_H

#include <drivers/pwr/adi_pwr.h>

/* set lowest interrupt priority (highest number)
   according to number of priority bits on-chip */
#define LOWEST_PRIORITY ((1U << __NVIC_PRIO_BITS) -1)

/* bump UART interrupt priority by one (lower number = higher priority)
   so that UART output continues during low-power hibernation test */
#define UART_PRIORITY (LOWEST_PRIORITY - 1)

/* leap-year compute macro (ignores leap-seconds) */
#define LEAP_YEAR(x) (((0==x%4)&&(0!=x%100))||(0==x%400))

/* Which RTC device to use for wakeup */
#define RTC_DEVICE_NUM_FOR_WUT 1


/* Number of RTC alarms required to be registered for successfull completion of the example */
#define ADI_RTC_NUM_ALARMS      3

/* If the RTC needs to be calibrated */
#define ADI_RTC_CALIBRATE

#define RTC_ALARM_OFFSET 5

/* Trim interval */
#define ADI_RTC_TRIM_INTERVAL    ADI_RTC_TRIM_INTERVAL_14
/* Trim operation +/- */
#define ADI_RTC_TRIM_DIRECTION   ADI_RTC_TRIM_SUB
/* Trim  value */
#define ADI_RTC_TRIM_VALUE       ADI_RTC_TRIM_1

#define RTC_DEVICE_NUM    0

/* Device handle for RTC device-1*/
extern ADI_RTC_HANDLE hDevice0;
/* Device handle for RTC device-0 which act as wake up timer*/
extern  ADI_RTC_HANDLE hDevice1;

#endif /* RTC_ALARM_H */
