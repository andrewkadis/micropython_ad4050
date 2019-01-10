/*********************************************************************************

Copyright(c) 2016 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/
/*!
 * @file      rng_example.h
 * @brief     Example to demonstrate RNG driver
 * @details
 *            This is the primary include file for the RNG example that shows
 *            how to use  RNG engine to get a random number.
 *
 */

/*=============  I N C L U D E S   =============*/

/* RNG Driver includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*=============  D E F I N E S  =============*/

/* Enable macro to build example in callback mode.
 * We allow the macro to be defined outside the header for ease of testing
 */
#if !defined (RNG_ENABLE_CALLBACK)
   #define RNG_ENABLE_CALLBACK      (0u)
#endif


/* Number of random numbers to read */
#define NUM_RANDOM_NUMS          (5u)

/* RNG Device number */
#define RNG_DEV_NUM              (0u)

/* Sample Len Prescaler value to be set. This value is only required if the
 * value needs to be changed dynamically. Otherwise, RNG0_CFG_LENGTH_RELOAD
 * in adi_rng_config.h can be used.
 */
#define RNG_DEV_LEN_PRESCALER    (1u)

/* Sample Len Reload value to be set. This value is only required if the
 * value needs to be changed dynamically. Otherwise, RNG0_CFG_LENGTH_RELOAD
 * in adi_rng_config.h can be used. */
#define RNG_DEV_LEN_RELOAD       (256u)

/*****/
