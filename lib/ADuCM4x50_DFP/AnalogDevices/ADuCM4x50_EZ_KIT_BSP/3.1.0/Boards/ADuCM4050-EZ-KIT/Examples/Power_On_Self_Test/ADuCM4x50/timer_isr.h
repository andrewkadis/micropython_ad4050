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
 * Description:     This is the primary include file for the real time timer test
 */


#ifndef _TIMER_ISR_H_
#define _TIMER_ISR_H_

#include "post_common.h"



/*
 *  function prototypes
 */
void Init_Timer(void);
void Delay(const unsigned long ulMs);
#endif /* _TIMER_ISR_H_ */

