/*********************************************************************************

Copyright(c) 2013-2017 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/
/*!
 * @file      crypto_ctr.c
 * @brief     Example to demonstrate CRYPTO Driver
 *
 * @details
 *            This is the primary source file for the CRYPTO example demonstrating
 *            encryption and decryption
 *
 */

/*=============  I N C L U D E S   =============*/

/* CRYPTO example include */
#include "crypto_ctr.h"

/* Managed drivers and/or services include */
#include <drivers/crypto/adi_crypto.h>
#include <drivers/general/adi_drivers_general.h>    
#include <assert.h>
#include <common.h>
#include <drivers/pwr/adi_pwr.h>

/*=============  D A T A  =============*/

/* Memory Required for crypto driver */
ADI_ALIGNED_PRAGMA(4)
static uint8_t DeviceMemory          [ADI_CRYPTO_MEMORY_SIZE] ADI_ALIGNED_ATTRIBUTE(4);

/* CTR Message and other buffers */
ADI_ALIGNED_PRAGMA(4)
static uint8_t ctrComputedCipher     [CTR_BUFF_SIZE] ADI_ALIGNED_ATTRIBUTE(4);
ADI_ALIGNED_PRAGMA(4)
static uint8_t ctrDecryptedText      [CTR_BUFF_SIZE] ADI_ALIGNED_ATTRIBUTE(4);


/* Crypto test vectors are from: National Institute of Standards and Technology Special Publication 800-38A 2001 ED */
/* vectors are modified in-place, so reinitialize on stack for each test... */

/* define four 128-bit blocks (4 x 16-bytes) of test data for each test */
#define TEST_BYTES 64

ADI_ALIGNED_PRAGMA(4)
static uint8_t initial_counter[] ADI_ALIGNED_ATTRIBUTE(4)= {0xcf, 0xbf, 0xaf, 0x9f, 0x8f, 0x7f, 0x6f, 0x5f, 0x4f, 0x3f, 0x2f, 0x1f, 0x0f, 0x0f} ;


/* Initial data - 4 x 16 from NIST. Used by many of the crypto ciphers */
ADI_ALIGNED_PRAGMA(4)
static uint8_t plainText [TEST_BYTES] ADI_ALIGNED_ATTRIBUTE(4)= {
  0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a,
  0xae, 0x2d, 0x8a, 0x57, 0x1e, 0x03, 0xac, 0x9c, 0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf, 0x8e, 0x51,
  0x30, 0xc8, 0x1c, 0x46, 0xa3, 0x5c, 0xe4, 0x11, 0xe5, 0xfb, 0xc1, 0x19, 0x1a, 0x0a, 0x52, 0xef,
  0xf6, 0x9f, 0x24, 0x45, 0xdf, 0x4f, 0x9b, 0x17, 0xad, 0x2b, 0x41, 0x7b, 0xe6, 0x6c, 0x37, 0x10
} ;

/*#define USE_256*/    /* uncomment to use 256 bit key */
#ifndef USE_256
#define AES_KEY_LEN ADI_CRYPTO_AES_KEY_LEN_128_BIT
/* AES128.Encrypt. Same key used by many of the crypto ciphers */
ADI_ALIGNED_PRAGMA(4)
static uint8_t Key[] ADI_ALIGNED_ATTRIBUTE(4) = {
  0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c
} ;

ADI_ALIGNED_PRAGMA(4)
static uint8_t ctrExpectedCipher[TEST_BYTES] ADI_ALIGNED_ATTRIBUTE(4)= {
  0x87, 0x4d, 0x61, 0x91, 0xb6, 0x20, 0xe3, 0x26, 0x1b, 0xef, 0x68, 0x64, 0x99, 0x0d, 0xb6, 0xce, 
  0x98, 0x06, 0xf6, 0x6b, 0x79, 0x70, 0xfd, 0xff, 0x86, 0x17, 0x18, 0x7b, 0xb9, 0xff, 0xfd, 0xff, 
  0x5a, 0xe4, 0xdf, 0x3e, 0xdb, 0xd5, 0xd3, 0x5e, 0x5b, 0x4f, 0x09, 0x02, 0x0d, 0xb0, 0x3e, 0xab, 
  0x1e, 0x03, 0x1d, 0xda, 0x2f, 0xbe, 0x03, 0xd1, 0x79, 0x21, 0x70, 0xa0, 0xf3, 0x00, 0x9c, 0xee 
} ;
#else
#define AES_KEY_LEN ADI_CRYPTO_AES_KEY_LEN_256_BIT

/* AES256.Encrypt. Same key used by many of the crypto ciphers */
ADI_ALIGNED_PRAGMA(4)
static uint8_t Key[] ADI_ALIGNED_ATTRIBUTE(4)= {
  0x60, 0x3d, 0xeb, 0x10, 0x15, 0xca, 0x71, 0xbe, 0x2b, 0x73, 0xae, 0xf0, 0x85, 0x7d, 0x77, 0x81,
  0x1f, 0x35, 0x2c, 0x07, 0x3b, 0x61, 0x08, 0xd7, 0x2d, 0x98, 0x10, 0xa3, 0x09, 0x14, 0xdf, 0xf4
} ;

ADI_ALIGNED_PRAGMA(4)
static uint8_t ctrExpectedCipher[TEST_BYTES] ADI_ALIGNED_ATTRIBUTE(4)= {
  0x60, 0x1e, 0xc3, 0x13, 0x77, 0x57, 0x89, 0xa5, 0xb7, 0xa7, 0xf5, 0x04, 0xbb, 0xf3, 0xd2, 0x28, 
  0xf4, 0x43, 0xe3, 0xca, 0x4d, 0x62, 0xb5, 0x9a, 0xca, 0x84, 0xe9, 0x90, 0xca, 0xca, 0xf5, 0xc5, 
  0x2b, 0x09, 0x30, 0xda, 0xa2, 0x3d, 0xe9, 0x4c, 0xe8, 0x70, 0x17, 0xba, 0x2d, 0x84, 0x98, 0x8d, 
  0xdf, 0xc9, 0xc5, 0x8d, 0xb6, 0x7a, 0xad, 0xa6, 0x13, 0xc2, 0xdd, 0x08, 0x45, 0x79, 0x41, 0xa6 
} ;
#endif


#ifdef CRYPTO_ENABLE_CALLBACK
static volatile int numBuffersReturned = 0;
#endif

/*=============  L O C A L    F U N C T I O N S  =============*/

static void InitBuffers(void);
static bool VerifyBuffers (void);

/*=============  C O D E  =============*/

/* IF (Callback mode enabled) */
#ifdef CRYPTO_ENABLE_CALLBACK

ADI_CRYPTO_TRANSACTION *pcbReturnedBuffer;

/* Callback from the device */
static void CryptoCallback(void *pCBParam, uint32_t Event, void *pArg)
{
    /* process callback event */
    switch (Event) {

        /* success events */
        case ADI_CRYPTO_EVENT_STATUS_CBC_DONE:
        case ADI_CRYPTO_EVENT_STATUS_CCM_DONE:
        case ADI_CRYPTO_EVENT_STATUS_CMAC_DONE:
        case ADI_CRYPTO_EVENT_STATUS_CTR_DONE:
        case ADI_CRYPTO_EVENT_STATUS_ECB_DONE:
#if defined (__ADUCM4x50__)
        case ADI_CRYPTO_EVENT_STATUS_HMAC_DONE:
#endif /*__ADUCMX50__*/
        case ADI_CRYPTO_EVENT_STATUS_SHA_DONE:
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
            //exit(0);
            break;

        /* UNDEFINED */
        default:
            printf("Undefined callback event\n");
            //exit(0);
            break;
        }
}
#else
static ADI_CRYPTO_TRANSACTION *pGottenBuffer;
#endif /* CRYPTO_ENABLE_CALLBACK */

void CTR_Encrypt_Decrypt(void)
{
    ADI_CRYPTO_HANDLE      hDevice;
    ADI_CRYPTO_TRANSACTION Buffer;
    ADI_CRYPTO_RESULT      eResult = ADI_CRYPTO_SUCCESS;

    /* Open the crypto device */
    eResult = adi_crypto_Open(CRYPTO_DEV_NUM, DeviceMemory, sizeof(DeviceMemory), &hDevice);
    DEBUG_RESULT("Failed to open crypto device", eResult, ADI_CRYPTO_SUCCESS);

#ifdef CRYPTO_ENABLE_CALLBACK
    /* Register Callback */
    eResult = adi_crypto_RegisterCallback (hDevice, CryptoCallback, NULL);
#endif

    /* prepare encode submit */
    memset( &Buffer, 0, sizeof(ADI_CRYPTO_TRANSACTION) );

    Buffer.eCipherMode    = ADI_CRYPTO_MODE_CTR;
    Buffer.pNonceIV       = (uint8_t*)&initial_counter[0];
    Buffer.CounterInit    = (uint32_t)0xDFEFF;
    Buffer.eCodingMode    = ADI_CRYPTO_ENCODE;
    Buffer.eAesByteSwap   = ADI_CRYPTO_AES_LITTLE_ENDIAN;
    Buffer.eAesKeyLen     = AES_KEY_LEN;
    Buffer.pAesKey        = Key;
    Buffer.pInputData     = (uint32_t*)&plainText[0];
    Buffer.numInputBytes  = CTR_BUFF_SIZE;
    Buffer.pOutputData    = (uint32_t*)&ctrComputedCipher[0];
    Buffer.numOutputBytes = CTR_BUFF_SIZE;

    /* Submit the buffer for encryption */
    eResult = adi_crypto_SubmitBuffer (hDevice, &Buffer);
    DEBUG_RESULT("Failed to submit buffer to crypto device", eResult, ADI_CRYPTO_SUCCESS);

#ifdef CRYPTO_ENABLE_CALLBACK
    /* reset callback counter */
    numBuffersReturned = 0;
#endif

    /* Enable the device */
    eResult =  adi_crypto_Enable (hDevice, true);
    DEBUG_RESULT("Failed to enable crypto device", eResult, ADI_CRYPTO_SUCCESS);

#ifndef CRYPTO_ENABLE_CALLBACK
    /* Get ECB ciphertext */
    eResult =  adi_crypto_GetBuffer (hDevice, &pGottenBuffer);
    DEBUG_RESULT("Failed to get buffer from the crypto device", eResult, ADI_CRYPTO_SUCCESS);
    if (&Buffer != pGottenBuffer) {
        DEBUG_RESULT("Returned buffer from callback mismatch", eResult, ADI_CRYPTO_ERR_BAD_BUFFER);
    }
#else
    /* await any callback */
    while (numBuffersReturned == 0)
        ;
    if (&Buffer != pcbReturnedBuffer) {
        DEBUG_RESULT("Returned buffer from callback mismatch", eResult, ADI_CRYPTO_ERR_BAD_BUFFER);
    }
#endif

    /* Disable the device */
    eResult =  adi_crypto_Enable (hDevice, false);
    DEBUG_RESULT("Failed to disable crypto device", eResult, ADI_CRYPTO_SUCCESS);
   
    /* switch buffers for decode */
    Buffer.eCodingMode    = ADI_CRYPTO_DECODE;
    Buffer.pInputData     = (uint32_t*)&ctrComputedCipher[0];
    Buffer.pOutputData    = (uint32_t*)&ctrDecryptedText[0];

    /* Submit the buffer for decryption */
    eResult = adi_crypto_SubmitBuffer (hDevice, &Buffer);
    DEBUG_RESULT("Failed to submit buffer to crypto device", eResult, ADI_CRYPTO_SUCCESS);

#ifdef CRYPTO_ENABLE_CALLBACK
    /* reset callback counter */
    numBuffersReturned = 0;
#endif

    /* Enable the device */
    eResult =  adi_crypto_Enable (hDevice, true);
    DEBUG_RESULT("Failed to enable crypto device", eResult, ADI_CRYPTO_SUCCESS);

#ifndef CRYPTO_ENABLE_CALLBACK
    /* Get CTR plaintext */
    eResult =  adi_crypto_GetBuffer (hDevice, &pGottenBuffer);
    DEBUG_RESULT("Failed to get buffer from the crypto device", eResult, ADI_CRYPTO_SUCCESS);
    if (&Buffer != pGottenBuffer) {
        DEBUG_RESULT("Returned buffer from callback mismatch", eResult, ADI_CRYPTO_ERR_BAD_BUFFER);
    }
#else
    /* await any callback */
    while (numBuffersReturned == 0)
        ;
    if (&Buffer != pcbReturnedBuffer) {
        DEBUG_RESULT("Returned buffer from callback mismatch", eResult, ADI_CRYPTO_ERR_BAD_BUFFER);
    }
#endif

    /* Disable the device */
    eResult =  adi_crypto_Enable (hDevice, false);
    DEBUG_RESULT("Failed to disable crypto device", eResult, ADI_CRYPTO_SUCCESS);

    /* Close the crypto device */
    eResult =  adi_crypto_Close(hDevice);
    DEBUG_RESULT("Failed to close crypto device", eResult, ADI_CRYPTO_SUCCESS);
}

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

    /* Init the buffers */
    InitBuffers();

    /* Do a CTR Encryption and Decryption */
    CTR_Encrypt_Decrypt();

    /* Verify the transfer */
    if (VerifyBuffers())
    {
        DEBUG_MESSAGE("All done! Crypto example completed successfully");
    }
}


static void InitBuffers(void)
{
    /* CTR zero out ciphertext/decryptedtext */
    for (int x = 0; x < CTR_BUFF_SIZE; x++) {
      ctrComputedCipher[x] = 0;
      ctrDecryptedText[x] = 0;
    }
}


static bool VerifyBuffers (void)
{
    int bufferIndex;

    /* verify CTR decrypted data */
    for (bufferIndex = 0; bufferIndex < CTR_BUFF_SIZE; bufferIndex++) {
        if (plainText[bufferIndex] != ctrDecryptedText[bufferIndex]){
            DEBUG_MESSAGE("CTR mismatch at index %d\n", bufferIndex);
            return false;
        }
        /* Check encrypted data against NIST values */
        if (ctrComputedCipher[bufferIndex] != ctrExpectedCipher[bufferIndex]){
            DEBUG_MESSAGE("CTR encryped mismatch at index %d\n", bufferIndex);
            return false;
        }
    }
    return true;
}

/*****/
