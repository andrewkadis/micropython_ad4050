/*********************************************************************************

Copyright(c) 2016 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/
/*!
 * @file      rtos_ucos_iii_example.c
 * @brief     uCOS-III RTOS Example
 *
 * @details
 *            Primary source file for the uCOS-III RTOS example. The
 *            example demonstrate how to create tasks and semaphores and
 *            also demonstrate task switching.
 *
 */

/*=============  I N C L U D E S   =============*/
#include <os.h>
#include <stdio.h>
#include <assert.h>
#include "common.h"

/* Include for the crypto task */
#include <drivers/crypto/adi_crypto.h>

#include <drivers/pwr/adi_pwr.h>
#include <drivers/gpio/adi_gpio.h>
#include <drivers/general/adi_drivers_general.h>

/*=============  D E F I N E S   =============*/
#define TASK_CRYPTO_STK_SIZE   (200u)
#define TASK_CRYPTO_PRIO        (10u)

#define TASK_LED_ON_STK_SIZE   (200u)
#define TASK_LED_ON_PRIO         (8u)

#define TASK_LED_OFF_STK_SIZE  (200u)
#define TASK_LED_OFF_PRIO        (9u)

#define NUM_ENCRYPT_DECRYPT     (50u)
#define CRYPTO_DEV_NUM           (0u)

#define ECB_BUFF_SIZE          (800u)
#define KEY_SIZE                (16u)

/*=============  D A T A   =============*/

static uint8_t g_GPIOMemory           [ADI_GPIO_MEMORY_SIZE];

/* This data needs to be aligned. To maintain the alignment for all supported
 * toolchains, we use the macros that are meant to be used by the drivers.
 */
/* Memory Required for crypto driver */
ADI_ALIGNED_PRAGMA(4)
static uint8_t CryptoDeviceMemory[ADI_CRYPTO_MEMORY_SIZE] ADI_ALIGNED_ATTRIBUTE(4);

/* Message */
ADI_ALIGNED_PRAGMA(4)
static uint8_t ECB_Message[ECB_BUFF_SIZE] ADI_ALIGNED_ATTRIBUTE(4) ;

/* Encrypted Message */
ADI_ALIGNED_PRAGMA(4)
static uint8_t ECBEncMessage[ECB_BUFF_SIZE] ADI_ALIGNED_ATTRIBUTE(4);

/* Decrypted Message */
ADI_ALIGNED_PRAGMA(4)
static uint8_t ECBDecMessage[ECB_BUFF_SIZE] ADI_ALIGNED_ATTRIBUTE(4);

/* Key for the encryption and decryption */
ADI_ALIGNED_PRAGMA(4)
static uint8_t Key[KEY_SIZE] ADI_ALIGNED_ATTRIBUTE(4);

/*=============  R T O S D A T A   =============*/

static OS_TCB g_Task_LED_ON_TCB;
static OS_TCB g_Task_LED_OFF_TCB;
static OS_TCB g_Task_CRYPTO_TCB;

static CPU_STK g_Task_LED_ON_Stack  [TASK_LED_ON_STK_SIZE];
static CPU_STK g_Task_LED_OFF_Stack [TASK_LED_OFF_STK_SIZE];
static CPU_STK g_Task_CRYPTO_Stack  [TASK_CRYPTO_STK_SIZE];

static OS_SEM g_SemOnPend;
static OS_SEM g_SemOffPend;
static OS_SEM *pSemOnPend = &g_SemOnPend;
static OS_SEM *pSemOffPend = &g_SemOffPend;

/*=============  C O D E  =============*/

/* Wait for some time in  a loop. This is busy waiting not to be confused with a delay */
void sleep (void)
{
    int volatile x = 100000;
    while (x-- > 0) {}
}

/* ECB Ecrypt and Decrypt */
void ECB_Encrypt_Decrypt(void)
{
    OS_ERR OSRetVal;

    ADI_CRYPTO_RESULT    eResult = ADI_CRYPTO_SUCCESS;
    ADI_CRYPTO_TRANSACTION  Buffer;
    ADI_CRYPTO_HANDLE      hDevice;

    /* Open the crypto device */
    eResult = adi_crypto_Open(CRYPTO_DEV_NUM, CryptoDeviceMemory, sizeof(CryptoDeviceMemory), &hDevice);
    DEBUG_RESULT("Failed to open crypto device",eResult, ADI_CRYPTO_SUCCESS);

	OSSemPost(pSemOnPend, OS_OPT_POST_1, &OSRetVal);

    if (OSRetVal != OS_ERR_NONE)
    {
        DEBUG_MESSAGE("OSSemPost failed\n");
        exit(0);
    }

    /* The buffer needs to be set to 0 before we set the fields that we are
     * interested in because there are some members which, they are not part of
     * the ECB mode but still need to be cleared.
     */
    memset( &Buffer, 0, sizeof(ADI_CRYPTO_TRANSACTION) );

    /* Fill in the buffer structures */
    Buffer.eCipherMode    = ADI_CRYPTO_MODE_ECB;
    Buffer.eCodingMode    = ADI_CRYPTO_ENCODE;
#if defined (__ADUCM4x50__)   
    Buffer.eKeyByteSwap   = ADI_CRYPTO_KEY_LITTLE_ENDIAN;
    Buffer.eAesByteSwap   = ADI_CRYPTO_AES_LITTLE_ENDIAN;
#endif /*__ADUCM4x50__*/    
    Buffer.pAesKey        = Key;
    Buffer.eAesKeyLen     = ADI_CRYPTO_AES_KEY_LEN_128_BIT;
    Buffer.pInputData     = (uint32_t*)ECB_Message;
    Buffer.numInputBytes  = ECB_BUFF_SIZE;
    Buffer.pOutputData    = (uint32_t*)ECBEncMessage;
    Buffer.numOutputBytes = ECB_BUFF_SIZE;


    /* Submit the buffer for encryption */
    eResult = adi_crypto_SubmitBuffer (hDevice, &Buffer);
    DEBUG_RESULT("Failed to submit buffer to crypto device",eResult,ADI_CRYPTO_SUCCESS);

    /* Enable the device */
    eResult =  adi_crypto_Enable (hDevice, true);
    DEBUG_RESULT("Failed to enable crypto device",eResult,ADI_CRYPTO_SUCCESS);

    ADI_CRYPTO_TRANSACTION *pBuffer;
    /* Get ECB Buffer */
    eResult =  adi_crypto_GetBuffer (hDevice, &pBuffer);
    DEBUG_RESULT("Failed to get buffer from the crypto device",eResult,ADI_CRYPTO_SUCCESS);

    /* Disable the device */
    eResult =  adi_crypto_Enable (hDevice, false);
    DEBUG_RESULT("Failed to enable crypto device",eResult,ADI_CRYPTO_SUCCESS);

	OSSemPost(pSemOffPend, OS_OPT_POST_1, &OSRetVal);
    if (OSRetVal != OS_ERR_NONE)
    {
        DEBUG_MESSAGE("OSSemPost failed\n");
        exit(0);
    }

    /* Fill in the buffer structures for decryption */
    Buffer.eCipherMode    = ADI_CRYPTO_MODE_ECB;
    Buffer.eCodingMode    = ADI_CRYPTO_DECODE;
#if defined (__ADUCM4x50__)    
    Buffer.eKeyByteSwap   = ADI_CRYPTO_KEY_LITTLE_ENDIAN;
    Buffer.eAesByteSwap   = ADI_CRYPTO_AES_LITTLE_ENDIAN;
#endif /*__ADUCM4x50__*/
    Buffer.pAesKey        = Key;
    Buffer.eAesKeyLen     = ADI_CRYPTO_AES_KEY_LEN_128_BIT;
    Buffer.pInputData     = (uint32_t*)ECBEncMessage;
    Buffer.numInputBytes  = ECB_BUFF_SIZE;
    Buffer.pOutputData    = (uint32_t*)ECBDecMessage;
    Buffer.numOutputBytes = ECB_BUFF_SIZE;

    /* These fields are not related to ECB mode but they need to be set to 0 */
    Buffer.numAuthBytes   = 0u;
    Buffer.pAuthData = NULL;

    /* Submit the buffer for encryption */
    eResult = adi_crypto_SubmitBuffer (hDevice, &Buffer);
    DEBUG_RESULT("Failed to submit buffer to crypto device",eResult,ADI_CRYPTO_SUCCESS);

    /* Enable the device */
    eResult =  adi_crypto_Enable (hDevice, true);
    DEBUG_RESULT("Failed to enable crypto device",eResult,ADI_CRYPTO_SUCCESS);

    /* Get ECB Buffer */
    eResult =  adi_crypto_GetBuffer (hDevice, &pBuffer);
    DEBUG_RESULT("Failed to get buffer from the crypto device",eResult,ADI_CRYPTO_SUCCESS);

    /* Disable the device */
    eResult =  adi_crypto_Enable (hDevice, false);
    DEBUG_RESULT("Failed to enable crypto device",eResult,ADI_CRYPTO_SUCCESS);

    /* Close the crypto device */
    eResult =  adi_crypto_Close(hDevice);
    DEBUG_RESULT("Failed to close crypto device",eResult,ADI_CRYPTO_SUCCESS);
}

/* Initiaze the ECB buffer */
static void InitBuffers(void)
{
    for (int x=0; x < ECB_BUFF_SIZE;x++)
    {
        ECB_Message[x] = 10 + (x%30);
    }
}

/* Verify the decrypted buffer */
static bool VerifyBuffers (void)
{
    for (int x=0; x < ECB_BUFF_SIZE; x++) {
        if (ECB_Message[x] != ECBDecMessage[x]){
            DEBUG_MESSAGE("Mismatch for ECB at  at %d\n",x);
            return false;
        }
    }

    return true;
}

/* Crypto Task */
void Task_Encrypt_Decrypt(void* arg)
{
    uint32_t x = 0;

    while (x++ < NUM_ENCRYPT_DECRYPT)
    {
        InitBuffers();

        ECB_Encrypt_Decrypt();

        if (!VerifyBuffers()) {
            break;
        }
    }

    if (x >= NUM_ENCRYPT_DECRYPT) {
        DEBUG_MESSAGE("All done!\n");
        DEBUG_MESSAGE("Example with RTOS is completed successfully\n");
    }

    exit(0);
}

/* LED switch on task */
void Task_LED_On(void* arg)
{
    OS_ERR OSRetVal;

    while (1)
    {
	    OSSemPend(pSemOnPend, 0u, OS_OPT_PEND_BLOCKING, NULL,&OSRetVal);
        if (OSRetVal != OS_ERR_NONE)
        {
            DEBUG_MESSAGE("OSSemPend failed\n");
            break;
        }

        if (ADI_GPIO_SUCCESS != adi_gpio_SetLow(ADI_GPIO_PORT1, ADI_GPIO_PIN_12))
        {
            DEBUG_MESSAGE("adi_gpio_SetHigh failed\n");
        }

        sleep();
    }
}

/* LED switch off task */
void Task_LED_Off(void* arg)
{
    OS_ERR OSRetVal;

    while (1)
    {
	    OSSemPend(pSemOffPend, 0u, OS_OPT_PEND_BLOCKING, NULL,	&OSRetVal);
        if (OSRetVal != OS_ERR_NONE)
        {
            DEBUG_MESSAGE("OSSemPend failed\n");
            break;
        }

        if (ADI_GPIO_SUCCESS != adi_gpio_SetHigh(ADI_GPIO_PORT1, ADI_GPIO_PIN_12))
        {
            DEBUG_MESSAGE("adi_gpio_SetHigh failed\n");
        }

        sleep();
    }
}

int main()
{
    OS_ERR    OSRetVal;

    /* test system initialization */
    common_Init();

    do {

        /* Init Power */
        if(adi_pwr_Init()!= ADI_PWR_SUCCESS)
        {
            DEBUG_MESSAGE("\n Failed to intialize the power service \n");
            return(0);
        };
		if(ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_HCLK,1))
		{
			DEBUG_MESSAGE("Failed to intialize the power service");
		}
		if(ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_PCLK,1))
		{
			DEBUG_MESSAGE("Failed to intialize the power service\n");
		}

        /* init the GPIO service */
        if(ADI_GPIO_SUCCESS != adi_gpio_Init(g_GPIOMemory, ADI_GPIO_MEMORY_SIZE))
        {
            DEBUG_MESSAGE("adi_gpio_Init failed\n");
            return(0);
        }

        /* set GPIO output LED 4 and 5 */
        if(ADI_GPIO_SUCCESS != adi_gpio_OutputEnable(ADI_GPIO_PORT1, (ADI_GPIO_PIN_12 | ADI_GPIO_PIN_13), true))
        {
            DEBUG_MESSAGE("adi_gpio_SetDirection failed\n");
            return(0);
        }

        /* Initialize the RTOS */
        OSInit(&OSRetVal);
        if (OSRetVal != OS_ERR_NONE)
        {
            DEBUG_MESSAGE("Failed to initialize the RTOS \n");
            return(0);
        }

        /* Create the Crypto Task */
        OSTaskCreate (&g_Task_CRYPTO_TCB,          /* address of TCB */
                        "Crypto Task",                /* Task name */
                        Task_Encrypt_Decrypt,      /* Task "Run" function */
                        NULL,                        /* arg for the "Run" function*/
                        TASK_CRYPTO_PRIO,          /* priority */
                        g_Task_CRYPTO_Stack,       /* base of the stack */
                        TASK_CRYPTO_STK_SIZE - 1u ,/* limit for stack growth */
                        TASK_CRYPTO_STK_SIZE,      /* stack size in CPU_STK */
                        0u,                          /* number of messages allowed */
                        (OS_TICK)  0u,               /* time_quanta */
                        NULL,                        /* extension pointer */
                        (OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                        &OSRetVal);

        if (OSRetVal != OS_ERR_NONE)
        {
            DEBUG_MESSAGE("Failed to create crypto task\n");
            return(0);
        }

        /* Create the LED On Task */
        OSTaskCreate (&g_Task_LED_ON_TCB,            /* address of TCB */
                        "LED On Task",               /* Task name */
                        Task_LED_On,                 /* Task "Run" function */
                        NULL,                        /* arg for the "Run" function*/
                        TASK_LED_ON_PRIO,            /* priority */
                        g_Task_LED_ON_Stack,         /* base of the stack */
                        TASK_LED_ON_STK_SIZE - 1u ,  /* limit for stack growth */
                        TASK_LED_ON_STK_SIZE,        /* stack size in CPU_STK */
                        0u,                          /* number of messages allowed */
                        (OS_TICK)  0u,               /* time_quanta */
                        NULL,                        /* extension pointer */
                        (OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                        &OSRetVal);

        if (OSRetVal != OS_ERR_NONE)
        {
            DEBUG_MESSAGE("Failed to create LED On Task\n");
            return(0);
        }

        /* Create the LED Off Task */
        OSTaskCreate (&g_Task_LED_OFF_TCB,            /* address of TCB */
                        "LED Off Task",               /* Task name */
                        Task_LED_Off,                 /* Task "Run" function */
                        NULL,                         /* arg for the "Run" function*/
                        TASK_LED_OFF_PRIO,            /* priority */
                        g_Task_LED_OFF_Stack,         /* base of the stack */
                        TASK_LED_OFF_STK_SIZE - 1u ,  /* limit for stack growth */
                        TASK_LED_OFF_STK_SIZE,        /* stack size in CPU_STK */
                        0u,                           /* number of messages allowed */
                        (OS_TICK)  0u ,               /* time_quanta */
                        NULL,                         /* extension pointer */
                        (OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                        &OSRetVal);

        if (OSRetVal != OS_ERR_NONE)
        {
            DEBUG_MESSAGE("Failed to create LED Off Task\n");
            return(0);
        }

        /* Create Semaphore for On task */
        OSSemCreate(pSemOnPend,
               "SEM ON",
               0u,
               &OSRetVal);

        if (OSRetVal != OS_ERR_NONE)
        {
            DEBUG_MESSAGE("Failed to create LED On Semaphore\n");
            return(0);
        }

        /* Create Semaphore for Off task */
        OSSemCreate(pSemOffPend,
               "SEM OFF",
               0u,
               &OSRetVal);

        if (OSRetVal != OS_ERR_NONE)
        {
            DEBUG_MESSAGE("Failed to create LED Off Semaphore\n");
            return(0);
        }

        /* Start OS */
        OSStart(&OSRetVal);

        if (OSRetVal != OS_ERR_NONE)
        {
            DEBUG_MESSAGE("Failed to start RTOS\n");
            return(0);
        }
    } while (0);

    return(0);
}
