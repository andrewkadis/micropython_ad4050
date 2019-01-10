/*
 *******************************************************************************

 Copyright(c) 2017 Analog Devices, Inc. All Rights Reserved.

 This software is proprietary and confidential.  By using this software you agree
 to the terms of the associated Analog Devices License Agreement.

 ******************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <adi_processor.h>
#include <drivers/spi/adi_spi.h>
#include <drivers/gpio/adi_gpio.h>
#include <drivers/dma/adi_dma.h>
#include "common.h"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "spi_loopback_freertos.h"


/*=============  R T O S D A T A   =============*/



/* slave buffers */
uint8_t slaveRxTx[BUFFERSIZE];

/* Device memory required for operate Slave SPI device */
static uint8_t SlaveSpidevicemem[ADI_SPI_MEMORY_SIZE];

/* Slave device handle */
static ADI_SPI_HANDLE hSDevice;

/* SPI Master semaphore used by the Slave task to synchronize with its callbacks */
static StaticQueue_t Slave_Semaphore;

/* Configure the SPI device in Slave mode */
static ADI_SPI_RESULT ConfigureSlaveSPI()
{
    ADI_SPI_RESULT eResult;
    
    /* Open the SPI device. It opens in Master mode by default */    
    eResult = adi_spi_Open(SPI_SLAVE_DEVICE_NUM,SlaveSpidevicemem,ADI_SPI_MEMORY_SIZE,&hSDevice);
    DEBUG_RESULT("Failed to init SPI driver",eResult,ADI_SPI_SUCCESS);
    
    eResult = adi_spi_SetMasterMode(hSDevice,false);
    DEBUG_RESULT("Failed to set the device in Slave mode",eResult,ADI_SPI_SUCCESS);
    
    /* throttle bitrate to something the controller can reach */
    eResult = adi_spi_SetBitrate(hSDevice, 1000000); 
    DEBUG_RESULT("Failed to set Bitrate",eResult,ADI_SPI_SUCCESS);
    
    eResult =  adi_spi_SetChipSelect (hSDevice, ADI_SPI_CS0);
    DEBUG_RESULT("Failed to set chipselect",eResult,ADI_SPI_SUCCESS);
    
    memset(slaveRxTx, 0, sizeof(slaveRxTx));
    
    return(ADI_SPI_SUCCESS);
}

static 
void Slave_Callback(  
    void      *pCBParam,         
    uint32_t   Event,            
    void      *pArg)           
{
    BaseType_t xHigherPriorityTaskWoken = pdTRUE;

    BaseType_t freeRtosResult = xSemaphoreGiveFromISR (&Slave_Semaphore, &xHigherPriorityTaskWoken);
    DEBUG_RESULT("SPI Slave Callback Semaphore POST failed", (uint16_t)freeRtosResult, pdTRUE);

}


void spiSlaveTask(void *pvParameters) 
{

    ADI_SPI_RESULT eResult;
    ADI_SPI_TRANSCEIVER Stransceive;

    /* Configure the Slave */    
    eResult = ConfigureSlaveSPI();
    DEBUG_RESULT("Failed to configure Slave SPI",eResult,ADI_SPI_SUCCESS);    
    
    eResult = adi_spi_RegisterCallback (hSDevice, Slave_Callback, NULL);
    DEBUG_RESULT("Failed to register the Slave callback",eResult,ADI_SPI_SUCCESS);    

    /* Slave SEM used to synchronize the Slave task and the Slave callback     */
    /* Create the Master SEM used to synchronize the task with the callback      */
    QueueHandle_t slaveSemaphoreHandle  = xSemaphoreCreateBinaryStatic( &Slave_Semaphore); 
    if( slaveSemaphoreHandle == 0)
    {
      DEBUG_RESULT("Failed to create the SPI Semaphore", (int)slaveSemaphoreHandle, -1);    
    }
    
    /*--------------  Step 1 -------------------------- */
    /* Prepare the buffers for submitting to slave      */ 
    Stransceive.pTransmitter = NULL;
    Stransceive.TransmitterBytes = 0u;
    Stransceive.nTxIncrement = 0u;
    Stransceive.pReceiver = slaveRxTx ;    
    Stransceive.nRxIncrement = 1u;
    Stransceive.ReceiverBytes = BUFFERSIZE;
    Stransceive.bDMA = false;
    Stransceive.bRD_CTL = false;
    /* Submit the buffer toSlave */   
    /* Must use the non-blocking API to allow the application to continue */
    eResult= adi_spi_SlaveSubmitBuffer(hSDevice,&Stransceive);
    DEBUG_RESULT("Slave - Data failure",eResult,ADI_SPI_SUCCESS);
  


    /* Synchronize with (wait for) the callback */
    BaseType_t freeRtosResult = xSemaphoreTake( &Slave_Semaphore, portMAX_DELAY);  /* No time out. Wait forever. */
    DEBUG_RESULT("SPI Slave Semaphore PEND failed", (uint16_t)freeRtosResult, pdTRUE);

    
    /*--------------  Step 2 -------------------------- */
    /* Write the data back to the master                */ 

    Stransceive.pTransmitter = slaveRxTx;
    Stransceive.TransmitterBytes =  BUFFERSIZE;
    Stransceive.nTxIncrement = 1u;
    Stransceive.pReceiver = NULL;    
    Stransceive.nRxIncrement = 0u;
    Stransceive.ReceiverBytes = 0u;
    Stransceive.bDMA = false;
    Stransceive.bRD_CTL = false;
    /* Submit the buffer to the Slave */   
    /* Must use the non-blocking API to allow the application to continue */
    eResult= adi_spi_SlaveSubmitBuffer(hSDevice,&Stransceive);
    DEBUG_RESULT("Slave - Data failure",eResult,ADI_SPI_SUCCESS);
  
    /* Now wait the transaction to finish. In callback mode, one approach      */
    /* for synchronizing with the SPI transaction finish is to PEND on a semaphore. */                                              
    freeRtosResult = xSemaphoreTake( &Slave_Semaphore, portMAX_DELAY);  /* No time out. Wait forever. */
    DEBUG_RESULT("SPI Slave Semaphore PEND failed", (uint16_t)freeRtosResult, pdTRUE);

    /* Cannot exit here. Wait forever */
    while(1)
    {
        vTaskDelay(100); /*  Delay execution of a task for “n” ticks. Allows lower priority tasks to run */
    }

}

 
               
/*****/

