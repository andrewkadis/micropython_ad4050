/*********************************************************************************
Copyright(c) 2016-2017 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/
/*!
 * @file        dma_driven_crc_without_callback.h
 *
 * @brief       Example to demonstrate dma-driven CRC operations for computing
 *              the CRC of given block of data without a callback function.
 *
 * @details     This is the primary header file for the CRC example that shows
 *              how to use dma-driven CRC operations for computing the CRC of
 *              given block of data with no callback function registered in the
 *              interrupt handler attached to the DMA channel used to drive the
 *              CRC hardware engine.
 */
#ifndef DMA_DRIVEN_CRC_WITHOUT_CALLBACK_H
#define DMA_DRIVEN_CRC_WITHOUT_CALLBACK_H

/*=============  I N C L U D E S   =============*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*=============  D E F I N E S  =============*/

/* CRC Device number to work on */
#define	CRC_DEV_NUM                     (0u)

/* 32-bit data used to test CRC Data fill mode */
#define CRC32_POLYNOMIAL_BE             (0x04C11DB7)
#define CRC32_POLYNOMIAL_LE             (0xEDB88320)

/* 32-bit data used to test CRC Data fill mode */
#define CRC32_SEED_VALUE                (0xFFFFFFFF)

/* 32-bit CRC expected value based on msbfirst or lsbfirst */
#define CRC32_EXPECTED_VAL_BE           (0x270EECAFu)
#define CRC32_EXPECTED_VAL_LE           (0xAAB2E79Fu)

/* Number of bytes in CRC Buffer used for testing (requires multiple DMA requests) */
#define CRC_BUF_NUM_DATA                (2048)
#endif /* DMA_DRIVEN_CRC_WITHOUT_CALLBACK_H */
