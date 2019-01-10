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
 * Description:     This is the primary include file for the spi flash test 
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

/* Page Address to write the value */
#define PAGE_ADDR                (0x50000u)

/* Buffer Size */
#define BUFF_SIZE                (2048u)

/*****/
