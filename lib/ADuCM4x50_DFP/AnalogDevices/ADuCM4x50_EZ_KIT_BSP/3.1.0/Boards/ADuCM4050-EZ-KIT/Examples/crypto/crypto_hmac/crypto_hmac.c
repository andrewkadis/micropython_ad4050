/*********************************************************************************

Copyright(c) 2013-2017 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/
/*!
 * @file      crypto_hmac.c
 * @brief     Example to demonstrate CRYPTO Driver
 *
 * @details
 *            This is the primary source file for the CRYPTO example demonstrating
 *            encryption and decryption
 *
 */

/*=============  I N C L U D E S   =============*/

#include "crypto_hmac.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <assert.h>
#include <common.h>
#include <drivers/pwr/adi_pwr.h>


/*=============  D A T A  =============*/

/* Memory Required by the crypto driver instance */
ADI_ALIGNED_PRAGMA(4)
static uint8_t DeviceMemory[ADI_CRYPTO_MEMORY_SIZE] ADI_ALIGNED_ATTRIBUTE(4);

#ifdef CRYPTO_ENABLE_CALLBACK
static volatile int numBuffersReturned = 0;
#endif

/* buffer used to store the generated digest */
ADI_ALIGNED_PRAGMA(4)
static uint8_t  hmac[ADI_CRYPTO_HMAC_HASH_BYTES] ADI_ALIGNED_ATTRIBUTE(4);

/* buffer used to store the 512-bit key */
ADI_ALIGNED_PRAGMA(4)
static uint8_t key[64] ADI_ALIGNED_ATTRIBUTE(4)= { 0xd9, 0x1b, 0xde, 0xab, 0xf4, 0x3f, 0x5c, 0xb8, 0x76, 0xf8, 0xb2, 0x72, 0x55, 0x78, 0x1c, 0xb7, 0x42, 0xba, 0x7a, 0x71, 0xd1, 0x13, 0x9c, 0xc9, 0xdb, 0x0a, 0xbc, 0x97, 0x21, 0x69, 0x4c, 0x1c, 0x31, 0x94, 0xf3, 0xf3, 0x8e, 0x1a, 0xd2, 0x45, 0x0b, 0x8a, 0x0b, 0x3d, 0x78, 0x88, 0x84, 0xbb, 0x80, 0x1f, 0xe8, 0x4d, 0xd2, 0x59, 0xef, 0x5b, 0x7f, 0x0d, 0xe0, 0xa1, 0xa3, 0xf9, 0x54, 0xe2 };

#define MSG_DIM (128)
/* buffer used to store the message to be hashed */
ADI_ALIGNED_PRAGMA(4)
static uint8_t message[MSG_DIM] ADI_ALIGNED_ATTRIBUTE(4)= { 0x03, 0xc1, 0xa5, 0xd2, 0x2b, 0x2e, 0xef, 0x81, 0xb8, 0x03, 0x41, 0x57, 0x16, 0x86, 0x1b, 0xdf, 0x75, 0xbd, 0xb9, 0x7b, 0x85, 0x26, 0xf2, 0xb1, 0x7e, 0xa9, 0x60, 0xc6, 0x64, 0xcb, 0xc1, 0x8e, 0x89, 0x24, 0x9d, 0x82, 0x53, 0x13, 0x2a, 0x13, 0x3f, 0xb0, 0x6c, 0x3e, 0x26, 0x02, 0xa0, 0x61, 0xc0, 0x73, 0xdb, 0x4d, 0x66, 0x80, 0xef, 0x9c, 0x1c, 0xb5, 0x8e, 0x45, 0xce, 0xd9, 0xb2, 0x6d, 0xda, 0x66, 0x3b, 0x80, 0xcf, 0x3c, 0xda, 0x81, 0x74, 0x95, 0x2f, 0x9e, 0x0d, 0x3c, 0x2e, 0x08, 0xd9, 0xfa, 0xc7, 0x01, 0xdf, 0x51, 0xc6, 0x37, 0xeb, 0x6d, 0xf8, 0x50, 0xd3, 0x58, 0x8f, 0xc6, 0xfe, 0x6d, 0xc7, 0xf5, 0x27, 0x0f, 0xca, 0x72, 0x5f, 0x9b, 0xd1, 0x9f, 0x51, 0x9a, 0x8d, 0x7c, 0xca, 0x3c, 0xc5, 0xc0, 0x79, 0x02, 0x40, 0x29, 0xf3, 0xba, 0xe5, 0x10, 0xf9, 0xb0, 0x21, 0x40 };

/* buffer used to store the expected 256-bit hash */
ADI_ALIGNED_PRAGMA(4)
static uint8_t hash[ADI_CRYPTO_HMAC_HASH_BYTES] ADI_ALIGNED_ATTRIBUTE(4)= { 0xaf, 0xb0, 0x38, 0xd7, 0xa0, 0x57, 0x3e, 0xb8, 0xb1, 0x1a, 0x74, 0x68, 0xd4, 0x84, 0x18, 0x93, 0x1e, 0x17, 0xc1, 0xc4, 0xb4, 0xb0, 0x78, 0xa5, 0x5e, 0x31, 0xfe, 0xf0, 0xf8, 0x7a, 0x51, 0x36 };

/*=============  L O C A L    F U N C T I O N S  =============*/

static bool VerifyDigest (void);
static void HMAC_Request (void);

/*=============  C O D E  =============*/

/*********************************************************************
*
*   Function:   main
*
*********************************************************************/
int main (void)
{
    /* test system initialization */
    common_Init();

    if(adi_pwr_Init()!= ADI_PWR_SUCCESS) {
        DEBUG_MESSAGE("\n Failed to intialize the power service \n");
    }

    if(ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_HCLK,1)) {
        DEBUG_MESSAGE("Failed to intialize the power service\n");
    }

    if(ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_PCLK,1))
    {
        DEBUG_MESSAGE("Failed to intialize the power service\n");
    }

    HMAC_Request();
    
    return 0;
}


/* IF (Callback mode enabled) */
#ifdef CRYPTO_ENABLE_CALLBACK

ADI_CRYPTO_TRANSACTION *pcbReturnedBuffer;

/* Callback from the device */
static void CryptoCallback(void *pCBParam, uint32_t Event, void *pArg)
{
    /* process callback event */
    switch (Event) {

        /* success events */
        case ADI_CRYPTO_EVENT_STATUS_HMAC_DONE:
            pcbReturnedBuffer = pArg;
            numBuffersReturned++;
            break;

        /* other events */
        case ADI_CRYPTO_EVENT_DMA_BUS_ERROR:
        case ADI_CRYPTO_EVENT_DMA_DESCRIPTOR_ERROR:
        case ADI_CRYPTO_EVENT_DMA_UNKNOWN_ERROR:
        case ADI_CRYPTO_EVENT_STATUS_INPUT_OVERFLOW:
        case ADI_CRYPTO_EVENT_STATUS_UNKNOWN:
            printf("Non-success callback event 0x%04lx\n", Event);
            break;

        /* UNDEFINED */
        default:
            printf("Undefined callback event\n");
            break;
        }
}

#else

static ADI_CRYPTO_TRANSACTION *pGottenBuffer;

#endif /* CRYPTO_ENABLE_CALLBACK */

static void HMAC_Request(void)
{
    ADI_CRYPTO_HANDLE hDevice;                        /* handle for crypto driver */
    ADI_CRYPTO_RESULT eResult = ADI_CRYPTO_SUCCESS;   /* crypto driver result */
    ADI_CRYPTO_TRANSACTION cryptoTransaction;         /* data structure for crypto transactions */

    /* Open the crypto device */
    eResult = adi_crypto_Open(CRYPTO_DEV_NUM, DeviceMemory, sizeof(DeviceMemory), &hDevice);
    DEBUG_RESULT("Failed to open crypto device", eResult, ADI_CRYPTO_SUCCESS);

#ifdef CRYPTO_ENABLE_CALLBACK
    /* Register Callback */
    eResult = adi_crypto_RegisterCallback (hDevice, CryptoCallback, NULL);
    DEBUG_RESULT("Failed to register callback", eResult, ADI_CRYPTO_SUCCESS);
#endif

    /* prepair submission of i-th HMAC transaction */
    memset( &cryptoTransaction, 0, sizeof(ADI_CRYPTO_TRANSACTION) );

    /* reset computed HMAC digest */
    memset( &hmac[0], 0, sizeof(hmac) );

    cryptoTransaction.eCipherMode    = ADI_CRYPTO_MODE_HMAC;
    cryptoTransaction.eCodingMode    = ADI_CRYPTO_ENCODE;
    cryptoTransaction.eShaByteSwap   = ADI_CRYPTO_SHA_BIG_ENDIAN;    
    cryptoTransaction.eKeyByteSwap   = ADI_CRYPTO_KEY_LITTLE_ENDIAN;
    cryptoTransaction.pHmacKey       = &key[0];
    cryptoTransaction.pInputData     = (uint32_t*)&message[0];

    cryptoTransaction.numInputBytes  = MSG_DIM;
    cryptoTransaction.numShaBits     = MSG_DIM * 8;
    cryptoTransaction.pOutputData    = (uint32_t*)&hmac[0];
    cryptoTransaction.numOutputBytes = ADI_CRYPTO_HMAC_HASH_BYTES;

    /* Submit the buffer for SHA hashing */
    eResult = adi_crypto_SubmitBuffer (hDevice, &cryptoTransaction);
    DEBUG_RESULT("Failed to submit SHA buffer 1 to crypto device", eResult, ADI_CRYPTO_SUCCESS);

#ifdef CRYPTO_ENABLE_CALLBACK
    /* reset callback counter */
    numBuffersReturned = 0;
#endif

    /* Enable the device */
    eResult =  adi_crypto_Enable (hDevice, true);
    DEBUG_RESULT("Failed to enable crypto device", eResult, ADI_CRYPTO_SUCCESS);

#ifndef CRYPTO_ENABLE_CALLBACK

    /* retrieve the submitted buffer from the driver */
    eResult =  adi_crypto_GetBuffer (hDevice, &pGottenBuffer);
    DEBUG_RESULT("Failed to get buffer from the crypto device", eResult, ADI_CRYPTO_SUCCESS);

    if (&cryptoTransaction != pGottenBuffer) {
        DEBUG_RESULT("Returned buffer from callback mismatch", eResult, ADI_CRYPTO_ERR_BAD_BUFFER);
    }

#else
    /* await the callback */
    while (0 == numBuffersReturned)
      ;

    if (&cryptoTransaction != pcbReturnedBuffer) {
        DEBUG_RESULT("Returned buffer from callback mismatch", eResult, ADI_CRYPTO_ERR_BAD_BUFFER);
    }

#endif

    /* Disable the device */
    eResult =  adi_crypto_Enable (hDevice, false);
    DEBUG_RESULT("Failed to disable crypto device", eResult, ADI_CRYPTO_SUCCESS);

    /* Verify the transfer */
    if (VerifyDigest())
    {
        DEBUG_MESSAGE("All done! Crypto example completed successfully");
    }
}

static bool VerifyDigest(void)
{
    size_t hashIndex;

    for (hashIndex=0u; hashIndex<ADI_CRYPTO_HMAC_HASH_BYTES; hashIndex++) {

        if (hmac[hashIndex] != hash[hashIndex]) {

            DEBUG_MESSAGE("HMAC hash mismatch at index %d\n", hashIndex);
            return false;

        }

    }

    return true;
}

/*****/
