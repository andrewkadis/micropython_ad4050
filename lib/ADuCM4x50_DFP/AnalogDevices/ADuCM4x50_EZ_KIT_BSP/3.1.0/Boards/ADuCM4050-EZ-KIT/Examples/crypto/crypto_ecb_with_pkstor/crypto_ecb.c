/*********************************************************************************

Copyright(c) 2013-2017 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/
/*!
 * @file      crypto_ecb.c
 * @brief     Example to demonstrate CRYPTO Driver
 *
 * @details
 *            This is the primary source file for the CRYPTO example demonstrating
 *            encryption and decryption
 *
 */

/*=============  I N C L U D E S   =============*/

/* CRYPTO example include */
#include "crypto_ecb.h"

/* Managed drivers and/or services include */
#include <drivers/crypto/adi_crypto.h>
#include <drivers/general/adi_drivers_general.h>
#include <assert.h>
#include <common.h>
#include <drivers/pwr/adi_pwr.h>


#if (1 != ADI_CRYPTO_ENABLE_PKSTOR_SUPPORT)
/* make sure we have PKSTOR enabled */
#error "Required PKSTOR configuration macro not enabled\n"
#endif


/* key indexes */
#define KEY_INDEX_128 1
#define KEY_INDEX_256 2


/* PKSTOR key validation strings */
uint8_t val128[8] = "valid128";
uint8_t val256[8] = "valid256";


/*=============  D A T A  =============*/

/* Memory Required for crypto driver */
ADI_ALIGNED_PRAGMA(4)
static uint8_t DeviceMemory          [ADI_CRYPTO_MEMORY_SIZE] ADI_ALIGNED_ATTRIBUTE(4);

/* ECB Message and other buffers */
ADI_ALIGNED_PRAGMA(4)
static uint8_t ecbComputedCipher     [ECB_BUFF_SIZE] ADI_ALIGNED_ATTRIBUTE(4);
ADI_ALIGNED_PRAGMA(4)
static uint8_t ecbDecryptedText      [ECB_BUFF_SIZE] ADI_ALIGNED_ATTRIBUTE(4);

/* Crypto test vectors are from: National Institute of Standards and Technology Special Publication 800-38A 2001 ED */
/* vectors are modified in-place, so reinitialize on stack for each test... */

/* define four 128-bit blocks (4 x 16-bytes) of test data for each test */
#define TEST_BYTES 64
/* Initial data - 4 x 16 from NIST. Used by many of the crypto ciphers */
ADI_ALIGNED_PRAGMA(4)
static uint8_t plainText [TEST_BYTES] ADI_ALIGNED_ATTRIBUTE(4)= {
  0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a,
  0xae, 0x2d, 0x8a, 0x57, 0x1e, 0x03, 0xac, 0x9c, 0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf, 0x8e, 0x51,
  0x30, 0xc8, 0x1c, 0x46, 0xa3, 0x5c, 0xe4, 0x11, 0xe5, 0xfb, 0xc1, 0x19, 0x1a, 0x0a, 0x52, 0xef,
  0xf6, 0x9f, 0x24, 0x45, 0xdf, 0x4f, 0x9b, 0x17, 0xad, 0x2b, 0x41, 0x7b, 0xe6, 0x6c, 0x37, 0x10
} ;

/* define both keys for storage into flash */
ADI_ALIGNED_PRAGMA(4)
static uint8_t Key128[] ADI_ALIGNED_ATTRIBUTE(4) = {
  0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c
} ;
ADI_ALIGNED_PRAGMA(4)
static uint8_t Key256[] ADI_ALIGNED_ATTRIBUTE(4)= {
  0x60, 0x3d, 0xeb, 0x10, 0x15, 0xca, 0x71, 0xbe, 0x2b, 0x73, 0xae, 0xf0, 0x85, 0x7d, 0x77, 0x81,
  0x1f, 0x35, 0x2c, 0x07, 0x3b, 0x61, 0x08, 0xd7, 0x2d, 0x98, 0x10, 0xa3, 0x09, 0x14, 0xdf, 0xf4
} ;


//#define USE_256    /* uncomment to use 256 bit key */
#ifndef USE_256
#define AES_KEY_LEN ADI_CRYPTO_AES_KEY_LEN_128_BIT
/* AES128.Encrypt. Same key used by many of the crypto ciphers */
#define Key Key128

/* Encrypted data from NIST */
ADI_ALIGNED_PRAGMA(4)
static uint8_t ecbExpectedCipher[TEST_BYTES] ADI_ALIGNED_ATTRIBUTE(4)= {
  0x3a, 0xd7, 0x7b, 0xb4, 0x0d, 0x7a, 0x36, 0x60, 0xa8, 0x9e, 0xca, 0xf3, 0x24, 0x66, 0xef, 0x97,
  0xf5, 0xd3, 0xd5, 0x85, 0x03, 0xb9, 0x69, 0x9d, 0xe7, 0x85, 0x89, 0x5a, 0x96, 0xfd, 0xba, 0xaf,
  0x43, 0xb1, 0xcd, 0x7f, 0x59, 0x8e, 0xce, 0x23, 0x88, 0x1b, 0x00, 0xe3, 0xed, 0x03, 0x06, 0x88,
  0x7b, 0x0c, 0x78, 0x5e, 0x27, 0xe8, 0xad, 0x3f, 0x82, 0x23, 0x20, 0x71, 0x04, 0x72, 0x5d, 0xd4
} ;
#else
#define AES_KEY_LEN ADI_CRYPTO_AES_KEY_LEN_256_BIT

/* AES256.Encrypt. Same key used by many of the crypto ciphers */
#define Key Key256

ADI_ALIGNED_PRAGMA(4)
static uint8_t ecbExpectedCipher[TEST_BYTES] ADI_ALIGNED_ATTRIBUTE(4)= {
  0xf3, 0xee, 0xd1, 0xbd, 0xb5, 0xd2, 0xa0, 0x3c, 0x06, 0x4b, 0x5a, 0x7e, 0x3d, 0xb1, 0x81, 0xf8,
  0x59, 0x1c, 0xcb, 0x10, 0xd4, 0x10, 0xed, 0x26, 0xdc, 0x5b, 0xa7, 0x4a, 0x31, 0x36, 0x28, 0x70,
  0xb6, 0xed, 0x21, 0xb9, 0x9c, 0xa6, 0xf4, 0xf9, 0xf1, 0x53, 0xe7, 0xb1, 0xbe, 0xaf, 0xed, 0x1d,
  0x23, 0x30, 0x4b, 0x7a, 0x39, 0xf9, 0xf3, 0xff, 0x06, 0x7d, 0x8d, 0x8f, 0x9e, 0x24, 0xec, 0xc7
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
    Buffer.pAesKey        = &Key[0];
    Buffer.pInputData     = (uint32_t*)&plainText[0];
    Buffer.numInputBytes  = ECB_BUFF_SIZE;
    Buffer.pOutputData    = (uint32_t*)&ecbComputedCipher[0];
    Buffer.numOutputBytes = ECB_BUFF_SIZE;

    /* program buffer to use key stored in PKSTOR-managed flash */
	Buffer.bUsePKSTOR = true;

	if (ADI_CRYPTO_AES_KEY_LEN_128_BIT == AES_KEY_LEN) {
        Buffer.pkKuwLen = ADI_PK_KUW_LEN_128;
		Buffer.pkIndex = KEY_INDEX_128;
	} else if (ADI_CRYPTO_AES_KEY_LEN_256_BIT == AES_KEY_LEN) {
        Buffer.pkKuwLen = ADI_PK_KUW_LEN_256;
		Buffer.pkIndex = KEY_INDEX_256;
	} else {
        DEBUG_MESSAGE("Invalid key length specified.\n");

	}

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


/* program both 128-bit and 256-bit keys into flash */
void program_keys()
{
    ADI_CRYPTO_HANDLE      hDevice = 0;
    ADI_CRYPTO_RESULT      eResult = ADI_CRYPTO_SUCCESS;

    /* Open the crypto device */
    eResult = adi_crypto_Open(CRYPTO_DEV_NUM, DeviceMemory, sizeof(DeviceMemory), &hDevice);
    DEBUG_RESULT("Failed to open crypto device", eResult, ADI_CRYPTO_SUCCESS);

    /* enable PKSTOR */
    eResult = adi_crypto_pk_EnablePKSTOR (hDevice, true);
    DEBUG_RESULT("Failed to enable PKSTOR", eResult, ADI_CRYPTO_SUCCESS);

    /* erase existing page 0 key storage */
    eResult = adi_crypto_pk_ErasePage (hDevice, 0);
    DEBUG_RESULT("Failed to erase page", eResult, ADI_CRYPTO_SUCCESS);

    /* Note: device key load and KUW key length must be set with each key change... */

	/* STORE 128-BIT KEY... */

        /* load device key into AES */
        eResult = adi_crypto_pk_LoadDeviceKey (hDevice);
        DEBUG_RESULT("Failed to load device key", eResult, ADI_CRYPTO_SUCCESS);

        /* set the KUW length */
		eResult = adi_crypto_pk_SetKuwLen (hDevice, ADI_PK_KUW_LEN_128);
		DEBUG_RESULT("Failed to set KUW length", eResult, ADI_CRYPTO_SUCCESS);

		/* load KUW data and length with 128-bit key */
		eResult = adi_crypto_pk_SetKuwReg (hDevice, Key128);
		DEBUG_RESULT("Failed to store user key", eResult, ADI_CRYPTO_SUCCESS);

		/* set validation string*/
		eResult = adi_crypto_pk_SetValString (hDevice, val128);
		DEBUG_RESULT("Failed to set validation string", eResult, ADI_CRYPTO_SUCCESS);

		/* wrap user key with device key */
		eResult = adi_crypto_pk_WrapKuwReg (hDevice);
		DEBUG_RESULT("Failed to wrap user key", eResult, ADI_CRYPTO_SUCCESS);

		/* store the wrapped key */
		eResult = adi_crypto_pk_StoreKey (hDevice, KEY_INDEX_128);
		DEBUG_RESULT("Failed to store wrapped user key", eResult, ADI_CRYPTO_SUCCESS);

	/* STORE 256-BIT KEY... */

        /* load device key into AES */
        eResult = adi_crypto_pk_LoadDeviceKey (hDevice);
        DEBUG_RESULT("Failed to load device key", eResult, ADI_CRYPTO_SUCCESS);

        /* set the KUW length */
		eResult = adi_crypto_pk_SetKuwLen (hDevice, ADI_PK_KUW_LEN_256);
		DEBUG_RESULT("Failed to set KUW length", eResult, ADI_CRYPTO_SUCCESS);

		/* load KUW data and length with 256-bit key */
		eResult = adi_crypto_pk_SetKuwReg (hDevice, Key256);
		DEBUG_RESULT("Failed to store user key", eResult, ADI_CRYPTO_SUCCESS);

		/* set validation string*/
		eResult = adi_crypto_pk_SetValString (hDevice, val256);
		DEBUG_RESULT("Failed to set validation string", eResult, ADI_CRYPTO_SUCCESS);

		/* wrap user key with device key */
		eResult = adi_crypto_pk_WrapKuwReg (hDevice);
		DEBUG_RESULT("Failed to wrap user key", eResult, ADI_CRYPTO_SUCCESS);

		/* store the wrapped key */
		eResult = adi_crypto_pk_StoreKey (hDevice, KEY_INDEX_256);
		DEBUG_RESULT("Failed to store wrapped user key", eResult, ADI_CRYPTO_SUCCESS);

    /* disable PKSTOR */
    eResult = adi_crypto_pk_EnablePKSTOR (hDevice, false);
    DEBUG_RESULT("Failed to CLOSE pkstor", eResult, ADI_CRYPTO_SUCCESS);

    /* Close the crypto device */
    eResult =  adi_crypto_Close(hDevice);
    DEBUG_RESULT("Failed to close crypto device", eResult, ADI_CRYPTO_SUCCESS);
}


/* verify both 128-bit and 256-bit keys */
void verify_keys()
{
    ADI_CRYPTO_HANDLE      hDevice = 0;
    ADI_CRYPTO_RESULT      eResult = ADI_CRYPTO_SUCCESS;

	/* validation string */
	uint8_t validationReadback[8] = {0};

    /* Open the crypto device */
    eResult = adi_crypto_Open(CRYPTO_DEV_NUM, DeviceMemory, sizeof(DeviceMemory), &hDevice);
    DEBUG_RESULT("Failed to open crypto device", eResult, ADI_CRYPTO_SUCCESS);

    /* enable PKSTOR */
    eResult = adi_crypto_pk_EnablePKSTOR (hDevice, true);
    DEBUG_RESULT("Failed to enable PKSTOR", eResult, ADI_CRYPTO_SUCCESS);

    /* Note: device key load and KUW key length must be set with each key change... */

	/* VERIFY 128-BIT KEY... */

        /* load device key into AES */
        eResult = adi_crypto_pk_LoadDeviceKey (hDevice);
        DEBUG_RESULT("Failed to load device key", eResult, ADI_CRYPTO_SUCCESS);

        /* set the KUW length */
		eResult = adi_crypto_pk_SetKuwLen (hDevice, ADI_PK_KUW_LEN_128);
		DEBUG_RESULT("Failed to set KUW length", eResult, ADI_CRYPTO_SUCCESS);

		/* retrieve the wrapped key */
		eResult = adi_crypto_pk_RetrieveKey (hDevice, KEY_INDEX_128);
		DEBUG_RESULT("Failed to retrieve wrapped key ", eResult, ADI_CRYPTO_SUCCESS);

		/* unwrap KUW */
		eResult = adi_crypto_pk_UnwrapKuwReg (hDevice);
		DEBUG_RESULT("Failed to unwrap key ", eResult, ADI_CRYPTO_SUCCESS);

		/* get validation string */
		eResult = adi_crypto_pk_GetValString (hDevice, validationReadback);
		DEBUG_RESULT("Failed to get validation string ", eResult, ADI_CRYPTO_SUCCESS);

		/* verify validation string */
		for (int i = 0; i < 8; i++) {
			if (val128[i] != validationReadback[i]) {
				DEBUG_MESSAGE("128-bit key verification failed\n");
                break;
            }
		}

	/* VERIFY 256-BIT KEY... */

        /* load device key into AES */
        eResult = adi_crypto_pk_LoadDeviceKey (hDevice);
        DEBUG_RESULT("Failed to load device key", eResult, ADI_CRYPTO_SUCCESS);

        /* set the KUW length */
		eResult = adi_crypto_pk_SetKuwLen (hDevice, ADI_PK_KUW_LEN_256);
		DEBUG_RESULT("Failed to set KUW length", eResult, ADI_CRYPTO_SUCCESS);

		/* retrieve the wrapped key */
		eResult = adi_crypto_pk_RetrieveKey (hDevice, KEY_INDEX_256);
		DEBUG_RESULT("Failed to retrieve wrapped key ", eResult, ADI_CRYPTO_SUCCESS);

		/* unwrap KUW */
		eResult = adi_crypto_pk_UnwrapKuwReg (hDevice);
		DEBUG_RESULT("Failed to unwrap key ", eResult, ADI_CRYPTO_SUCCESS);

		/* get validation string */
		eResult = adi_crypto_pk_GetValString (hDevice, validationReadback);
		DEBUG_RESULT("Failed to get validation string ", eResult, ADI_CRYPTO_SUCCESS);

		/* verify validation string */
		for (int i = 0; i < 8; i++) {
			if (val256[i] != validationReadback[i]) {
				DEBUG_MESSAGE("256-bit key verification failed\n");
                break;
            }
		}

    /* disable PKSTOR */
    eResult = adi_crypto_pk_EnablePKSTOR (hDevice, false);
    DEBUG_RESULT("Failed to CLOSE pkstor", eResult, ADI_CRYPTO_SUCCESS);

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

	/* store keys into flash with pkstore */
    program_keys();

	/* verify keys */
    verify_keys();

    /* Do a ECB Encryption and Decryption */
    ECB_Encrypt_Decrypt();

    /* Verify the transfer */
    if (VerifyBuffers())
    {
        DEBUG_MESSAGE("All done! Crypto example completed successfully");
    }
}


static void InitBuffers(void)
{
    /* ECB zero out ComputedCipher/decryptedtext */
    for (int x = 0; x < ECB_BUFF_SIZE; x++) {
      ecbComputedCipher[x] = 0;
      ecbDecryptedText[x] = 0;
    }
}


static bool VerifyBuffers (void)
{
    int bufferIndex;

    /* verify ECB decrypted data */
    for (bufferIndex = 0; bufferIndex < ECB_BUFF_SIZE; bufferIndex++) {
        if (plainText[bufferIndex] != ecbDecryptedText[bufferIndex]){
            DEBUG_MESSAGE("ECB decrypted mismatch at index %d\n", bufferIndex);
            return false;
        }
        /* Check encrypted data against NIST values */
        if (ecbComputedCipher[bufferIndex] != ecbExpectedCipher[bufferIndex]){
            DEBUG_MESSAGE("ECB encrypted mismatch at index %d\n", bufferIndex);
            return false;
        }
    }
    return true;
}

/*****/
