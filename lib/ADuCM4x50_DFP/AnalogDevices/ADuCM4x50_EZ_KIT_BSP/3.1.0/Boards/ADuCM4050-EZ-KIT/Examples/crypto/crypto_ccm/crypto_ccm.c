/*********************************************************************************

Copyright(c) 2013-2017 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/
/*!
 * @file      crypto_ccm.c
 * @brief     Example to demonstrate CRYPTO Driver
 *
 * @details
 *            This is the primary source file for the CRYPTO example demonstrating
 *            encryption and decryption
 *
 */

/*=============  I N C L U D E S   =============*/

/* CRYPTO example include */
#include "crypto_ccm.h"

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

/* CCM Message and other buffers */
ADI_ALIGNED_PRAGMA(4)
static uint8_t ccmAuthenticationText [CCM_AUTH_BUFF_SIZE] ADI_ALIGNED_ATTRIBUTE(4);
ADI_ALIGNED_PRAGMA(4)
static uint8_t ccmPlainText          [CCM_PAYLOAD_BUFF_SIZE] ADI_ALIGNED_ATTRIBUTE(4);
ADI_ALIGNED_PRAGMA(4)
static uint8_t ccmComputedCipher     [CCM_PAYLOAD_BUFF_SIZE + CCM_DIGEST_SIZE] ADI_ALIGNED_ATTRIBUTE(4);
ADI_ALIGNED_PRAGMA(4)
static uint8_t ccmDecryptedText      [CCM_PAYLOAD_BUFF_SIZE + CCM_DIGEST_SIZE] ADI_ALIGNED_ATTRIBUTE(4);


/* Crypto test vectors are from: National Institute of Standards and Technology Special Publication 800-38A 2001 ED */
/* vectors are modified in-place, so reinitialize on stack for each test... */

/* define four 128-bit blocks (4 x 16-bytes) of test data for each test */
#define TEST_BYTES 64

/*#define USE_256*/    /* uncomment to use 256 bit key */
#ifndef USE_256
#define AES_KEY_LEN ADI_CRYPTO_AES_KEY_LEN_128_BIT
/* AES128.Encrypt. Same key used by many of the crypto ciphers */
ADI_ALIGNED_PRAGMA(4)
static uint8_t Key[] ADI_ALIGNED_ATTRIBUTE(4) = {
  0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c
} ;
#else
#define AES_KEY_LEN ADI_CRYPTO_AES_KEY_LEN_256_BIT

/* AES256.Encrypt. Same key used by many of the crypto ciphers */
ADI_ALIGNED_PRAGMA(4)
static uint8_t Key[] ADI_ALIGNED_ATTRIBUTE(4)= {
  0x60, 0x3d, 0xeb, 0x10, 0x15, 0xca, 0x71, 0xbe, 0x2b, 0x73, 0xae, 0xf0, 0x85, 0x7d, 0x77, 0x81,
  0x1f, 0x35, 0x2c, 0x07, 0x3b, 0x61, 0x08, 0xd7, 0x2d, 0x98, 0x10, 0xa3, 0x09, 0x14, 0xdf, 0xf4
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
#endif /*__ADUCM4x50__*/
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
    Buffer.pAesKey        = &Key[0];
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

    /* Do a CCM Encryption and Decryption */
    CCM_Encrypt_Decrypt();

    /* Verify the transfer */
    if (VerifyBuffers())
    {
        DEBUG_MESSAGE("All done! Crypto example completed successfully");
    }
}


static void InitBuffers(void)
{
    /* initialize the CCM authentication data */
    for (int x = 0; x < CCM_AUTH_BUFF_SIZE; x++) {
        ccmAuthenticationText[x] = rand() % 256;
    }

    /* initialize CCM plaintext and zero out ComputedCipher/decryptedtext */
    for (int x = 0; x < CCM_PAYLOAD_BUFF_SIZE; x++)
    {
        ccmPlainText[x]     = rand() % 256;
        ccmComputedCipher[x] = 0;
        ccmDecryptedText[x] = 0;
    }

    /* zero out CCM authentication tags (digest) in both output buffers */
    for (int x = CCM_PAYLOAD_BUFF_SIZE; x < (CCM_PAYLOAD_BUFF_SIZE + CCM_DIGEST_SIZE); x++) {
        ccmComputedCipher[x] = 0;
        ccmDecryptedText[x] = 0;
    }
}


static bool VerifyBuffers (void)
{
    int bufferIndex;

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
    return true;
}

/*****/
