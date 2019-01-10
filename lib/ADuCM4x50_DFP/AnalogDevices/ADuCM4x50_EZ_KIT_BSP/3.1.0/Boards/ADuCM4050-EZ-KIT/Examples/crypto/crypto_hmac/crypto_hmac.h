/*********************************************************************************

Copyright(c) 2013-2017 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/
/*!
 * @file      crypto_hmac.h
 * @brief     Example to demonstrate Crypto driver
 *
 * @details
 *            This is the primary include file for the Crypto example.
 *
 */
#ifndef CRYPTO_HMAC_H
#define CRYPTO_HMAC_H

/*=============  I N C L U D E S   =============*/

/* Crypto Driver includes */
#include <drivers/crypto/adi_crypto.h>

/* pick up compiler-specific alignment directives */
#include <drivers/general/adi_drivers_general.h>

/*=============  D E F I N E S  =============*/

/* Enable macro to build example in callback mode */
#define CRYPTO_ENABLE_CALLBACK

/* CRYPTO Device number */
#define CRYPTO_DEV_NUM               (0u)

#endif /* CRYPTO_HMAC_H */

/*****/
