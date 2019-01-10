/*********************************************************************************

Copyright(c) 2016-2017 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/
/*!
 * @file      flash_block_protect.c
 * @brief     Example to demonstrate block protection using the flash driver
 * @date:     $Date: 2015-11-08 13:00:01 -0500 (Sun, 08 Nov 2015) $
 *
 * @details
 *            This is the primary source file for the flash example demonstrating
 *            writing and reading from the flash.
 *
 */

/*=============  I N C L U D E S   =============*/

/* Managed drivers and/or services include */
#include <drivers/flash/adi_flash.h>
#include <drivers/gpio/adi_gpio.h>
#include <drivers/general/adi_drivers_general.h>
#include <common.h>
/* Flash example include */
#include "flash_block_protect.h"

#if defined(__ADUCM4x50__)
#define PB1_PORT_NUM        ADI_GPIO_PORT2
#define PB1_PIN_NUM         ADI_GPIO_PIN_6
#elif defined(__ADUCM302x__)
#define PB1_PORT_NUM        ADI_GPIO_PORT1
#define PB1_PIN_NUM         ADI_GPIO_PIN_14
#else
#error The example is not ported to this processor
#endif

/*=============  D A T A  =============*/

/* Memory Required for flash driver */
ADI_ALIGNED_PRAGMA(4)
static uint8_t Memory[ADI_FEE_MEMORY_SIZE] ADI_ALIGNED_ATTRIBUTE(4);

/* Buffer */
ADI_ALIGNED_PRAGMA(4)
uint8_t Buffer[BUFF_SIZE] ADI_ALIGNED_ATTRIBUTE(4);


/* define "FEE_ENABLE_CALLBACK" for callback mode                  */
/* avoid callback in this test so the expected flash erase failure */
/* does not exit in the callback handler, but rather allows a      */
/* graceful failure with more meaningful error reporting.          */
#define xFEE_ENABLE_CALLBACK

#ifdef FEE_ENABLE_CALLBACK
/* Callback flag */
static volatile int numCallbacks = 0;
#endif

/* delay counter */
static uint32_t delay = 0x00bfffff;

/* pushbutton flag */
volatile bool bPushbuttonPressed = false;

/*=============  L O C A L    F U N C T I O N S  =============*/

void InitBuffer(void);
ADI_FEE_RESULT VerifyBuffer(void);

/*=============  C O D E  =============*/

/* IF (Callback mode enabled) */
#ifdef FEE_ENABLE_CALLBACK

/* Callback from flash controller */
static void FlashCallback(void *pCBParam, uint32_t Event, void *pArg)
{
    switch (Event) {
        case ADI_FEE_CALLBACK_EVENT_BUFFER_PROCESSED:
            numCallbacks++;
            break;

		case ADI_FEE_CALLBACK_EVENT_DEVICE_ERROR:
			DEBUG_RESULT("Internal Flash HW error detected.", pArg, 0);
            break;

		case ADI_FEE_ERR_DMA_BUS_FAULT:
			DEBUG_RESULT("Flash DMA bus fault detected.", Event, 0);
            break;

		case ADI_FEE_ERR_DMA_INVALID_DESCR:
			DEBUG_RESULT("Flash DMA invalid descriptor detected.", Event, 0);
			break;

		case ADI_FEE_ERR_DMA_UNKNOWN_ERROR:
			DEBUG_RESULT("Unknown flash DMA error detected.", Event, 0);
			break;

		default:
			DEBUG_MESSAGE("Unknown event.\n");
			break;
    }
}

#endif

/* GPIO event Callback function */
static void pfPushbuttonCallback(void* pCBParam, uint32_t Port,  void* PinIntData) {

    /* if its the GroupA interrupt... */
    if ((void*)ADI_GPIO_INTA_IRQ == pCBParam) {
        /* if its the port and pin for PB2... */
        if ((Port == (uint32_t)PB1_PORT_NUM) && (*(uint32_t*)PinIntData & PB1_PIN_NUM)) {
            bPushbuttonPressed = true;
        }
    }
}


/*********************************************************************
*
*   Function:   main
*
*********************************************************************/
int main (void)
{
    /* Flash Handle */
    ADI_FEE_HANDLE hDevice;

    /* transaction struct */
    ADI_FEE_TRANSACTION transfer;

    uint32_t hwError = 0u;

    uint32_t nStartPage, nEndPage, nBlockNum;

    /* Flash controller  Return code */
    ADI_FEE_RESULT eResult = ADI_FEE_SUCCESS;

    /* test system initialization */
    common_Init();

    /* power init */
    if(adi_pwr_Init()!= ADI_PWR_SUCCESS) {
        DEBUG_MESSAGE("Failed to intialize the power service.\n");
    }

    if(ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_HCLK,1)) {
        DEBUG_MESSAGE("Failed to set HCLK.\n");
    }

    if(ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_PCLK,1)) {
        DEBUG_MESSAGE("Failed to set PCLK.\n");
    }

    /* Init the buffers */
    InitBuffer();

    /* Open Flash Controller Device */
    eResult = adi_fee_Open(FEE_DEV_NUM, Memory, sizeof(Memory), &hDevice);
    DEBUG_RESULT("Failed to open flash driver.", eResult, ADI_FEE_SUCCESS);

    /* Get the start page */
    eResult = adi_fee_GetPageNumber(hDevice, PAGE_ADDR, &nStartPage);
    DEBUG_RESULT("Failed to get start page number.", eResult, ADI_FEE_SUCCESS);

    /* Get the start page */
    eResult = adi_fee_GetPageNumber(hDevice, (PAGE_ADDR + BUFF_SIZE - 1), &nEndPage);
    DEBUG_RESULT("Failed to get end page number.", eResult, ADI_FEE_SUCCESS);

    /* Clear the Pages */
    eResult = adi_fee_PageErase (hDevice, nStartPage, nEndPage, &hwError);
    DEBUG_RESULT("Failed to erase flash page(s).", eResult, ADI_FEE_SUCCESS);

#ifdef FEE_ENABLE_CALLBACK
    eResult = adi_fee_RegisterCallback(hDevice, FlashCallback, NULL);
    DEBUG_RESULT("Failed to register callback handler.", eResult, ADI_FEE_SUCCESS);
#endif

    /* configure write buffer */
    transfer.pWriteAddr = (uint32_t*)PAGE_ADDR;
    transfer.pWriteData = (uint32_t*)Buffer;
    transfer.nSize      = sizeof(Buffer);
    transfer.bUseDma    = false;

    /* Submit a buffer for writing */
    eResult =  adi_fee_SubmitBuffer (hDevice, &transfer);
    DEBUG_RESULT("Failed to submit the buffer.", eResult, ADI_FEE_SUCCESS);

#ifndef FEE_ENABLE_CALLBACK
    /* Get the buffer back */
    eResult = adi_fee_GetBuffer(hDevice, &hwError);
    DEBUG_RESULT("Failed to get the buffer.", eResult, ADI_FEE_SUCCESS);
#else
    while (numCallbacks == 0u) {;}
#endif

    /* Verify the transfer */
    eResult = VerifyBuffer();
    DEBUG_RESULT("Unmatched readback data.", eResult, ADI_FEE_SUCCESS);

    DEBUG_MESSAGE("Page erased, programmed and verified...");


    /*********************************************************************************\
    |*****************************GATED PAGE PROTECT CODE*****************************|
    \*********************************************************************************/

    /* Delay write protection until user presses button.  Otherwise, page
       will be protected on each startup prior to debugger attaching,
       making it appear the page protection is never reset and that the
       data written above is persistent.
    */

    /* setup the GPIO service to capture PB2 (SW5) pushbutton event via pin P2.6 */
    static uint8_t gpioMemory[ADI_GPIO_MEMORY_SIZE];
    ADI_GPIO_RESULT gpioResult;

    gpioResult = adi_gpio_Init(gpioMemory, ADI_GPIO_MEMORY_SIZE);
    DEBUG_RESULT("Failed to open GPIO service.", gpioResult, ADI_GPIO_SUCCESS);

    gpioResult = adi_gpio_InputEnable(PB1_PORT_NUM,PB1_PIN_NUM, true);
    DEBUG_RESULT("Failed to set P2.6 for input.", gpioResult, ADI_GPIO_SUCCESS);

    gpioResult = adi_gpio_SetGroupInterruptPolarity(PB1_PORT_NUM, PB1_PIN_NUM);
    DEBUG_RESULT("Failed to set P2.6 inpterrupt polarity.", gpioResult, ADI_GPIO_SUCCESS);

    gpioResult = adi_gpio_SetGroupInterruptPins(PB1_PORT_NUM, ADI_GPIO_INTA_IRQ,PB1_PIN_NUM);
    DEBUG_RESULT("Failed to set P2.6 interrupt group.", gpioResult, ADI_GPIO_SUCCESS);

    gpioResult = adi_gpio_RegisterCallback (ADI_GPIO_INTA_IRQ, pfPushbuttonCallback, (void*)ADI_GPIO_INTA_IRQ);
    DEBUG_RESULT("Failed to register calback for P2.6 interrupt.", gpioResult, ADI_GPIO_SUCCESS);

    /* announce test phase */
    DEBUG_MESSAGE("Block Write-Protect: Press button(SW5) before timeout to test write protection.");
    DEBUG_MESSAGE("NOTE: Processor requires HARDWARE RESET to clear write-protection.");

    /* wait with ~10 second timeout for pushbutton press */
    while (delay--) {
        if (bPushbuttonPressed) {
            break;
        }
    }

    /* only do the write protect test if pushbutton has been pressed */
    if (bPushbuttonPressed) {

        DEBUG_MESSAGE("Setting flash block write-protect.");

        /* get the page's block number */
        eResult = adi_fee_GetBlockNumber(hDevice, PAGE_ADDR, &nBlockNum);
        DEBUG_RESULT("Failed to get block number.", eResult, ADI_FEE_SUCCESS);

        /* write-protect the block */
        eResult = adi_fee_WriteProtectBlock(hDevice, nBlockNum);
        DEBUG_RESULT("Failed to write protect block.", eResult, ADI_FEE_SUCCESS);

        /* expect page erase to fail */
        eResult = adi_fee_PageErase (hDevice, nStartPage, nEndPage, &hwError);
        
        /* verify expected API result code indicated a hardware failure */
        DEBUG_RESULT("Failed to erase flash page(s).", eResult, ADI_FEE_ERR_HW_ERROR_DETECTED);
        
        /* verify expected command failure detail is "command ignored" */
        DEBUG_RESULT("Page erase command not ignored.", (unsigned int)(hwError & BITM_FLCC_STAT_CMDFAIL), (1 << BITP_FLCC_STAT_CMDFAIL));

        /* re-verify the protected page data is still present */
        eResult = VerifyBuffer();
        DEBUG_RESULT("Unmatched readback data.\n", eResult, ADI_FEE_SUCCESS);

        DEBUG_MESSAGE("Flash block write protection verified; write data intact.");
        DEBUG_MESSAGE("HARDWARE RESET required to clear flash block write-protect.");

    } else {
        DEBUG_MESSAGE("Block write-protect timeout; no blocks protected.");
    }

    /*********************************************************************************\
    |***************************END GATED PAGE PROTECT CODE***************************|
    \*********************************************************************************/

    /* Close the flash controller */
    eResult = adi_fee_Close(hDevice);
    DEBUG_RESULT("Failed to close the flash driver.", eResult, ADI_FEE_SUCCESS);

    common_Pass();
}

void InitBuffer(void)
{    
    for (int x = 0; x < BUFF_SIZE; x++) {
      Buffer[x] = rand()%256;
    }
}

ADI_FEE_RESULT VerifyBuffer (void)
{
    uint8_t* pDataInFlash = (uint8_t*)PAGE_ADDR;
    for (int x = 0; x < BUFF_SIZE; x++) {
        if (Buffer[x] != *pDataInFlash++){
                return ADI_FEE_ERR_BUFFER_ERR;
        }
    }
    return ADI_FEE_SUCCESS;
}

/*****/
