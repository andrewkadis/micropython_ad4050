/*********************************************************************************

Copyright(c) 2016 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/
/*!
 * @file      adc_example.h
 * @brief     Example to demonstrate ADC driver
 * @details
 *            This is the primary include file for the ADC example.
 *
 */

/*=============  I N C L U D E S   =============*/

/* ADC Driver includes */
#include <drivers/adc/adi_adc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*=============  D E F I N E S  =============*/

/* Write samples to file */
#ifndef __CC_ARM
#define WRITE_SAMPLES_TO_FILE
#endif

/* ADC Device number */
#define ADC_DEV_NUM                (0u)

/* Number of samples to sample for ADC */
#define ADC_NUM_SAMPLES             (100u)

/*****/
