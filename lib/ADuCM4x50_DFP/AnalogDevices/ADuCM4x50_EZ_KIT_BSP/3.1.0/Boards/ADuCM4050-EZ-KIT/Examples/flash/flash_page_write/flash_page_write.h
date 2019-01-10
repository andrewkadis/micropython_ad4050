/*********************************************************************************

Copyright(c) 2016-2017 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/
/*!
 * @file      flash_example.h
 * @brief     Example to demonstrate I2C driver
 * @date:     $Date: 2014-12-06 10:37:26 -0500 (Sat, 06 Dec 2014) $
 *
 * @details
 *            This is the primary include file for the flash example.
 *
 */

/*=============  I N C L U D E S   =============*/

/* Flash  Driver includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*=============  D E F I N E S  =============*/

/* Enable macro to build example in callback mode */
//#define FEE_ENABLE_CALLBACK

/* FEE Device number */
#define FEE_DEV_NUM              (0u)

#if defined (__ADUCM4x50__)
/* Page Address to write the value */
#define PAGE_ADDR                (0x40000u)

#elif defined (__ADUCM302x__)
/* Page Address to write the value */
#define PAGE_ADDR                (0x20000u)

#else
#error Flash driver is not ported for this processor
#endif

/* Buffer Size */
#define BUFF_SIZE                (2048u)

/*****/
