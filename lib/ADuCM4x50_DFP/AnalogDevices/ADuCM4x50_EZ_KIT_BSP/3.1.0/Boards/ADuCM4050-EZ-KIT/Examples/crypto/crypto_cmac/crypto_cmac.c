/*********************************************************************************

Copyright(c) 2013-2017 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/
/*!
 * @file      crypto_cmac.c
 * @brief     Example to demonstrate CRYPTO Driver
 *
 * @details
 *            This is the primary source file for the CRYPTO example demonstrating
 *            encryption and decryption
 *
 */

/*=============  I N C L U D E S   =============*/

/* CRYPTO example include */
#include "crypto_cmac.h"

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

/* CMAC Message */
ADI_ALIGNED_PRAGMA(4)
static uint8_t cmacComputedCipher    [CMAC_BUFF_SIZE] ADI_ALIGNED_ATTRIBUTE(4);

/* Crypto test vectors are from: National Institute of Standards and Technology Special Publication 800-38A 2001 ED */
/* vectors are modified in-place, so reinitialize on stack for each test... */

/* define four 128-bit blocks (4 x 16-bytes) of test data for each test */
#define TEST_BYTES 64

ADI_ALIGNED_PRAGMA(4)
static uint8_t cmacXorBuffer[16] ADI_ALIGNED_ATTRIBUTE(4);

/*#define USE_256*/    /* uncomment to use 256 bit key */
#ifndef USE_256
#define AES_KEY_LEN ADI_CRYPTO_AES_KEY_LEN_128_BIT
/* AES128.Encrypt. Same key used by many of the crypto ciphers */
ADI_ALIGNED_PRAGMA(4)
static uint8_t Key[] ADI_ALIGNED_ATTRIBUTE(4) = {
  0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c
} ;

/* Encrypted data from NIST */
ADI_ALIGNED_PRAGMA(4)
static uint8_t cmacExpectedCipher[16] ADI_ALIGNED_ATTRIBUTE(4)= {
    0x07, 0x0a, 0x16, 0xb4, 0x6b, 0x4d, 0x41, 0x44, 0xf7, 0x9b, 0xdd, 0x9d, 0xd0, 0x4a, 0x28, 0x7c, 
} ;

ADI_ALIGNED_PRAGMA(4)
static uint8_t CMAC_Test_K1[16] ADI_ALIGNED_ATTRIBUTE(4)= {
    0xfb, 0xee, 0xd6, 0x18, 0x35, 0x71, 0x33, 0x66, 0x7c, 0x85, 0xe0, 0x8f, 0x72, 0x36, 0xa8, 0xde, 
} ;

ADI_ALIGNED_PRAGMA(4)
static uint8_t CMAC_Test_Input[16] ADI_ALIGNED_ATTRIBUTE(4)= {
    0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a, 
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
static uint8_t cmacExpectedCipher[16] ADI_ALIGNED_ATTRIBUTE(4)= {
    0x28, 0xa7, 0x02, 0x3f, 0x45, 0x2e, 0x8f, 0x82, 0xbd, 0x4b, 0xf2, 0x8d, 0x8c, 0x37, 0xc3, 0x5c, 
} ;

ADI_ALIGNED_PRAGMA(4)
static uint8_t CMAC_Test_K1[16] ADI_ALIGNED_ATTRIBUTE(4)= {
    0xca, 0xd1, 0xed, 0x03, 0x29, 0x9e, 0xed, 0xac, 0x2e, 0x9a, 0x99, 0x80, 0x86, 0x21, 0x50, 0x2f, 
} ;

ADI_ALIGNED_PRAGMA(4)
static uint8_t CMAC_Test_Input[16] ADI_ALIGNED_ATTRIBUTE(4)= {
    0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a, 
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
#endif          
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

#if 0

void SHA_Compute(void)
{
    ADI_CRYPTO_HANDLE hDevice;
    ADI_CRYPTO_RESULT eResult = ADI_CRYPTO_SUCCESS;
    ADI_CRYPTO_TRANSACTION Buffer1;
    ADI_CRYPTO_TRANSACTION Buffer2;
    ADI_CRYPTO_TRANSACTION Buffer3;

    /* Open the crypto device */
    eResult = adi_crypto_Open(CRYPTO_DEV_NUM, DeviceMemory, sizeof(DeviceMemory), &hDevice);
    DEBUG_RESULT("Failed to open crypto device", eResult, ADI_CRYPTO_SUCCESS);

#ifdef CRYPTO_ENABLE_CALLBACK
    /* Register Callback */
    eResult = adi_crypto_RegisterCallback (hDevice, CryptoCallback, NULL);
#endif


/****************************************BUFFER1****************************************/

    /* prepair submit */
    memset( &Buffer1, 0, sizeof(ADI_CRYPTO_TRANSACTION) );

    Buffer1.eCipherMode    = ADI_CRYPTO_MODE_SHA;
    Buffer1.eCodingMode    = ADI_CRYPTO_ENCODE;
    Buffer1.eShaByteSwap   = ADI_CRYPTO_SHA_BIG_ENDIAN;
    Buffer1.pInputData     = (uint32_t*)&Sha1_Message[0];
    Buffer1.numInputBytes  = sizeof(Sha1_Message);
    Buffer1.numShaBits     = (strlen((const char *)Sha1_Message)*8);
    Buffer1.pOutputData    = (uint32_t*)&Sha1_ComputedHash[0];
    Buffer1.numOutputBytes = ADI_CRYPTO_SHA_HASH_BYTES;

    /* Submit the buffer for SHA hashing */
    eResult = adi_crypto_SubmitBuffer (hDevice, &Buffer1);
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
    if (&Buffer1 != pGottenBuffer) {
        DEBUG_RESULT("Returned buffer from callback mismatch", eResult, ADI_CRYPTO_ERR_BAD_BUFFER);
    }
#else
    /* await the callback */
    while (0 == numBuffersReturned)
        ;
    if (&Buffer1 != pcbReturnedBuffer) {
        DEBUG_RESULT("Returned buffer from callback mismatch", eResult, ADI_CRYPTO_ERR_BAD_BUFFER);
    }
#endif

    /* Disable the device */
    eResult =  adi_crypto_Enable (hDevice, false);
    DEBUG_RESULT("Failed to disable crypto device", eResult, ADI_CRYPTO_SUCCESS);


/****************************************BUFFER2****************************************/

    /* prepare submit */
    memset( &Buffer2, 0, sizeof(ADI_CRYPTO_TRANSACTION) );

    Buffer2.eCipherMode    = ADI_CRYPTO_MODE_SHA;
    Buffer2.eCodingMode    = ADI_CRYPTO_ENCODE;
    Buffer2.eShaByteSwap   = ADI_CRYPTO_SHA_BIG_ENDIAN;
    Buffer2.pInputData     = (uint32_t*)&Sha2_Message[0];
    Buffer2.numInputBytes  = sizeof(Sha2_Message);
    Buffer2.numShaBits     = sizeof(Sha2_Message)*8u;
    Buffer2.pOutputData    = (uint32_t*)&Sha2_ComputedHash[0];
    Buffer2.numOutputBytes = ADI_CRYPTO_SHA_HASH_BYTES;

    /* Submit the buffer for SHA hashing */
    eResult = adi_crypto_SubmitBuffer (hDevice, &Buffer2);
    DEBUG_RESULT("Failed to submit SHA buffer 2 to crypto device", eResult, ADI_CRYPTO_SUCCESS);

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
    if (&Buffer2 != pGottenBuffer) {
        DEBUG_RESULT("Returned buffer from callback mismatch", eResult, ADI_CRYPTO_ERR_BAD_BUFFER);
    }
#else
    /* await the callback */
    while (0 == numBuffersReturned)
        ;
    if (&Buffer2 != pcbReturnedBuffer) {
        DEBUG_RESULT("Returned buffer from callback mismatch", eResult, ADI_CRYPTO_ERR_BAD_BUFFER);
    }
#endif

    /* Disable the device */
    eResult =  adi_crypto_Enable (hDevice, false);
    DEBUG_RESULT("Failed to disable crypto device", eResult, ADI_CRYPTO_SUCCESS);


/****************************************BUFFER3****************************************/

    /* prepare submit */
    memset( &Buffer3, 0, sizeof(ADI_CRYPTO_TRANSACTION) );

    Buffer3.eCipherMode    = ADI_CRYPTO_MODE_SHA;
    Buffer3.eCodingMode    = ADI_CRYPTO_ENCODE;
    Buffer3.eShaByteSwap   = ADI_CRYPTO_SHA_BIG_ENDIAN;
    Buffer3.pInputData     = (uint32_t*)&Sha3_Message[0];
    Buffer3.numInputBytes  = sizeof(Sha3_Message);
    Buffer3.numShaBits     = sizeof(Sha3_Message)*8u;
    Buffer3.pOutputData    = (uint32_t*)&Sha3_ComputedHash[0];
    Buffer3.numOutputBytes = ADI_CRYPTO_SHA_HASH_BYTES;

    /* Submit the buffer for SHA hashing */
    eResult = adi_crypto_SubmitBuffer (hDevice, &Buffer3);
    DEBUG_RESULT("Failed to submit SHA buffer 2 to crypto device", eResult, ADI_CRYPTO_SUCCESS);

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
    if (&Buffer3 != pGottenBuffer) {
        DEBUG_RESULT("Returned buffer from callback mismatch", eResult, ADI_CRYPTO_ERR_BAD_BUFFER);
    }
#else
    /* await the callback */
    while (0 == numBuffersReturned)
        ;
    if (&Buffer3 != pcbReturnedBuffer) {
        DEBUG_RESULT("Returned buffer from callback mismatch", eResult, ADI_CRYPTO_ERR_BAD_BUFFER);
    }
#endif

    /* Disable the device */
    eResult =  adi_crypto_Enable (hDevice, false);
    DEBUG_RESULT("Failed to disable crypto device", eResult, ADI_CRYPTO_SUCCESS);


/***************************************************************************************/

    /* Close the crypto device */
    eResult =  adi_crypto_Close(hDevice);
    DEBUG_RESULT("Failed to close crypto device", eResult, ADI_CRYPTO_SUCCESS);
}


void ECB_Encrypt_Decrypt(void)
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

    Buffer.eCipherMode    = ADI_CRYPTO_MODE_ECB;
    Buffer.eCodingMode    = ADI_CRYPTO_ENCODE;
    Buffer.eAesByteSwap   = ADI_CRYPTO_AES_LITTLE_ENDIAN;
    Buffer.eAesKeyLen     = AES_KEY_LEN;
    Buffer.pKey           = &Key[0];
    Buffer.pInputData     = (uint32_t*)&plainText[0];
    Buffer.numInputBytes  = ECB_BUFF_SIZE;
    Buffer.pOutputData    = (uint32_t*)&ecbComputedCipher[0];
    Buffer.numOutputBytes = ECB_BUFF_SIZE;

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
    /* Get ECB ComputedCipher */
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
    Buffer.pInputData     = (uint32_t*)&ecbComputedCipher[0];
    Buffer.pOutputData    = (uint32_t*)&ecbDecryptedText[0];

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
    /* Get ECB plaintext */
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

void CBC_Encrypt_Decrypt(void)
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

    Buffer.eCipherMode    = ADI_CRYPTO_MODE_CBC;
    Buffer.pNonceIV       = (uint8_t*)&initial_vector[0];
    Buffer.eCodingMode    = ADI_CRYPTO_ENCODE;
    Buffer.eAesByteSwap   = ADI_CRYPTO_AES_LITTLE_ENDIAN;
    Buffer.eAesKeyLen     = AES_KEY_LEN;
    Buffer.pKey           = &Key[0];
    Buffer.pInputData     = (uint32_t*)&plainText[0];
    Buffer.numInputBytes  = ECB_BUFF_SIZE;
    Buffer.pOutputData    = (uint32_t*)&cbcComputedCipher[0];
    Buffer.numOutputBytes = ECB_BUFF_SIZE;

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
    /* Get ECB ComputedCipher */
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
    Buffer.pInputData     = (uint32_t*)&cbcComputedCipher[0];
    Buffer.pOutputData    = (uint32_t*)&cbcDecryptedText[0];

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
    /* Get ECB plaintext */
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

void CCM_Encrypt_Decrypt(void)
{
    ADI_CRYPTO_HANDLE     hDevice;
    ADI_CRYPTO_TRANSACTION Buffer;
    ADI_CRYPTO_RESULT     eResult = ADI_CRYPTO_SUCCESS;

    uint8_t nOnce[13] = {0,1,2,3,4,5,6,7,8,9,10,11,12};

    /* Open the crypto device */
    eResult = adi_crypto_Open(CRYPTO_DEV_NUM, DeviceMemory, sizeof(DeviceMemory), &hDevice);
    DEBUG_RESULT("Failed to open crypto device", eResult, ADI_CRYPTO_SUCCESS);

#ifdef CRYPTO_ENABLE_CALLBACK
    /* Register Callback */
    eResult = adi_crypto_RegisterCallback (hDevice, CryptoCallback, NULL);
#endif

    /* prepare submit */
    memset( &Buffer, 0, sizeof(ADI_CRYPTO_TRANSACTION) );

    Buffer.eCipherMode    = ADI_CRYPTO_MODE_CCM;
    Buffer.eCodingMode    = ADI_CRYPTO_ENCODE;
    Buffer.eAesByteSwap   = ADI_CRYPTO_AES_LITTLE_ENDIAN;
    Buffer.eAesKeyLen     = AES_KEY_LEN;
    Buffer.pKey           = &Key[0];
    Buffer.pAuthData      = (uint32_t*)&ccmAuthenticationText[0];
    Buffer.numAuthBytes   = CCM_AUTH_BUFF_SIZE;
    Buffer.pInputData     = (uint32_t*)&ccmPlainText[0];
    Buffer.numInputBytes  = CCM_PAYLOAD_BUFF_SIZE;
    Buffer.pOutputData    = (uint32_t*)&ccmComputedCipher[0];
    Buffer.numOutputBytes = CCM_PAYLOAD_BUFF_SIZE + CCM_DIGEST_SIZE;
    Buffer.pNonceIV       = &nOnce[0];
    Buffer.CounterInit    = 0u;
    Buffer.numValidBytes  = 16u;

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
    /* Get CCM encoded Buffer */
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

    /* swich buffers for decode */
    Buffer.eCodingMode    = ADI_CRYPTO_DECODE;
    Buffer.pInputData     = (uint32_t*)&ccmComputedCipher[0];
    Buffer.pOutputData    = (uint32_t*)&ccmDecryptedText[0];

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
    /* Get CCM decoded Buffer */
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
#endif //0

static void xor_buf32 (uint32_t* out, uint32_t* buff1, uint32_t* buff2, uint32_t lenInBytes)
{
    uint32_t x;
    
    for (x = 0 ; x < (lenInBytes/4); x++) {
        out[x] = buff1[x] ^ buff2[x];
    }
}

void CMAC_Encrypt_Decrypt(void)
{
    ADI_CRYPTO_HANDLE      hDevice;
    ADI_CRYPTO_TRANSACTION Buffer;
    ADI_CRYPTO_RESULT      eResult = ADI_CRYPTO_SUCCESS;

    // Format the input buffer as required by the crypto accelerator
    xor_buf32 (
               (uint32_t*)&cmacXorBuffer[0], 
               (uint32_t*)&CMAC_Test_Input[0], 
               (uint32_t*)&CMAC_Test_K1[0],
               CMAC_BUFF_SIZE
               );

    /* Open the crypto device */
    eResult = adi_crypto_Open(CRYPTO_DEV_NUM, DeviceMemory, sizeof(DeviceMemory), &hDevice);
    DEBUG_RESULT("Failed to open crypto device", eResult, ADI_CRYPTO_SUCCESS);

#ifdef CRYPTO_ENABLE_CALLBACK
    /* Register Callback */
    eResult = adi_crypto_RegisterCallback (hDevice, CryptoCallback, NULL);
#endif

    /* prepare encode submit */
    memset( &Buffer, 0, sizeof(ADI_CRYPTO_TRANSACTION) );

    Buffer.eCipherMode    = ADI_CRYPTO_MODE_CMAC;
    Buffer.eCodingMode    = ADI_CRYPTO_ENCODE;
    Buffer.eAesByteSwap   = ADI_CRYPTO_AES_LITTLE_ENDIAN;
    Buffer.eAesKeyLen     = AES_KEY_LEN;
    Buffer.CounterInit    = (uint32_t)0x0;
    Buffer.pAesKey        = &Key[0];
    Buffer.pInputData     = (uint32_t*)&cmacXorBuffer[0];
    Buffer.numInputBytes  = CMAC_BUFF_SIZE;
    Buffer.pOutputData    = (uint32_t*)&cmacComputedCipher[0];
    Buffer.pNonceIV       = NULL;
    Buffer.numOutputBytes = CMAC_BUFF_SIZE;

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
    /* Get CMAC ciphertext */
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
    /* CMAC can't be decoded, just encoded see http://cache.freescale.com/files/32bit/doc/app_note/AN4234.pdf for more info */
#if 0
    Buffer.eCodingMode    = ADI_CRYPTO_DECODE;
    Buffer.pInputData     = (uint32_t*)&cmacCipherText[0];
    Buffer.pOutputData    = (uint32_t*)&cmacDecryptedText[0];
    
    
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
    /* Get ECB plaintext */
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
#endif//0

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

    /* Do a CMAC Encryption and Decryption */
    CMAC_Encrypt_Decrypt();

    /* Verify the transfer */
    if (VerifyBuffers())
    {
        DEBUG_MESSAGE("All done! Crypto example completed successfully");
    }
}


static void InitBuffers(void)
{
    /* CMAC zero out ciphertext/decryptedtext */
    for (int x = 0; x < CMAC_BUFF_SIZE; x++) {
      cmacComputedCipher[x]    = 0;
    }
}


static bool VerifyBuffers (void)
{
    int bufferIndex;
    /* Check encrypted data against NIST values */
    for (bufferIndex = 0; bufferIndex < CMAC_BUFF_SIZE; bufferIndex++) {
        if (cmacComputedCipher[bufferIndex] != cmacExpectedCipher[bufferIndex]){
            DEBUG_MESSAGE("CMAC encryped mismatch at index %d\n", bufferIndex);
            return false;
        }
    }
#if 0
    
    /* verify ECB decrypted data */
    for (bufferIndex = 0; bufferIndex < ECB_BUFF_SIZE; bufferIndex++) {
        if (plainText[bufferIndex] != ecbDecryptedText[bufferIndex]){
            DEBUG_MESSAGE("ECB mismatch at index %d\n", bufferIndex);
            return false;
        }
        /* Check encrypted data against NIST values */
        if (ecbComputedCipher[bufferIndex] != ecbExpectedCipher[bufferIndex]){
            DEBUG_MESSAGE("ECB encryped mismatch at index %d\n", bufferIndex);
            return false;
        }
    }

    /* verify CBC decrypted data */
    for (bufferIndex = 0; bufferIndex < ECB_BUFF_SIZE; bufferIndex++) {
        if (plainText[bufferIndex] != cbcDecryptedText[bufferIndex]){
            DEBUG_MESSAGE("CBC mismatch at index %d\n", bufferIndex);
            return false;
        }
        /* Check encrypted data against NIST values */
        if (cbcComputedCipher[bufferIndex] != cbcExpectedCipher[bufferIndex]){
            DEBUG_MESSAGE("CBC encryped mismatch at index %d\n", bufferIndex);
            return false;
        }
    }

    /* verify CCM decrypted plaintext against origional plaintext */
    for (bufferIndex = 0; bufferIndex < CCM_PAYLOAD_BUFF_SIZE; bufferIndex++) {
        if (ccmPlainText[bufferIndex] != ccmDecryptedText[bufferIndex]){
            DEBUG_MESSAGE("CCM mismatch at index %d\n", bufferIndex);
            return false;
        }
    }

    /* compare CCM authentication digests (tags) of cyphertext and recovered decrypted text */
    for (bufferIndex = CCM_PAYLOAD_BUFF_SIZE; bufferIndex < (CCM_PAYLOAD_BUFF_SIZE + CCM_DIGEST_SIZE); bufferIndex++) {
        if (ccmComputedCipher[bufferIndex] != ccmDecryptedText[bufferIndex]){
            DEBUG_MESSAGE("MAC mismatch at index %d\n", bufferIndex);
            return false;
        }
    }

    /* Verify SHA results */
    uint8_t expectedByte;  /* unpack bytes from 32-bit words */
    for (hashIndex = 0; hashIndex < ADI_CRYPTO_SHA_HASH_BYTES; hashIndex++) {

        expectedByte = Sha1_ExpectedHash[hashIndex/4] >> (24 - ((hashIndex%4)*8));
        if (Sha1_ComputedHash[hashIndex] != expectedByte) {
            DEBUG_MESSAGE("SHA hash1 mismatch at index %d\n", hashIndex);
            return false;
        }

        expectedByte = Sha2_ExpectedHash[hashIndex/4] >> (24 - ((hashIndex%4)*8));
        if (Sha2_ComputedHash[hashIndex] != expectedByte) {
            DEBUG_MESSAGE("SHA hash2 mismatch at index %d\n", hashIndex);
            return false;
        }

        expectedByte = Sha3_ExpectedHash[hashIndex/4] >> (24 - ((hashIndex%4)*8));
        if (Sha3_ComputedHash[hashIndex] != expectedByte) {
            DEBUG_MESSAGE("SHA hash3 mismatch at index %d\n", hashIndex);
            return false;
        }
    }
#endif
    return true;
}

/*****/
