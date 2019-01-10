/*********************************************************************************

Copyright(c) 2016 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/
/*!
 * @file      SPI_Master.c
 * @brief     SPI Master task primary source file.
 */

/*=============  I N C L U D E S   =============*/

#include "os.h"
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include <drivers/spi/adi_spi.h>
#include "RTOS_Callback.h"


/* master buffers */
uint8_t masterTx[BUFFERSIZE];
uint8_t masterRx[BUFFERSIZE];

/* Device memory required for operate Master SPI device */
uint8_t MasterSpidevicemem[ADI_SPI_MEMORY_SIZE];

/* Master device handle */
ADI_SPI_HANDLE hMDevice;

/* SPI Master semaphore used by the Master Slave task to synchronize with its callbacks */
static OS_SEM Master_Semaphore;

/* Validate the  content of the buffers */
static uint32_t ValidateData(uint8_t *pInbuf,uint8_t *pOutBuf,uint32_t nSize)
{
  uint16_t i;
  for(i=0;i<nSize;i++)
  {
      if(*pInbuf++ != *pOutBuf++)
      { 
        pInbuf--;
        pOutBuf--;
        DEBUG_MESSAGE("Failed on i = %d is %d \n", i, *pOutBuf );
        return(FAILURE);
      }
  }
  return(SUCCESS);
}
/* Intialize the buffer with data to be sent */
static void InitBuffer(uint8_t *pBuffer,uint32_t nSize)
{
  uint16_t i;
  for(i=0;i<nSize;i++)
      *pBuffer++ = (uint8_t)(i+1);
  
}
/* Configure the SPI device in Master mode */
ADI_SPI_RESULT ConfigureMasterSPI()
{
    ADI_SPI_RESULT eResult;
    
    /* Open the SPI device. It opens in Master mode by default */
    eResult = adi_spi_Open(SPI_MASTER_DEVICE_NUM, MasterSpidevicemem, ADI_SPI_MEMORY_SIZE, &hMDevice);
    DEBUG_RESULT("Failed to init SPI driver",eResult,ADI_SPI_SUCCESS);
    
    /* Set the bit rate  */
    eResult = adi_spi_SetBitrate(hMDevice, 1000000); 
    DEBUG_RESULT("Failed to set Bitrate",eResult,ADI_SPI_SUCCESS);
    
    /* Set the chip select. */    
    adi_spi_SetChipSelect (hMDevice, ADI_SPI_CS0);
    DEBUG_RESULT("Failed to set chipselect",eResult,ADI_SPI_SUCCESS);
    
    return(ADI_SPI_SUCCESS);
}

static 
void Master_Callback(  
    void      *pCBParam,         
    uint32_t   Event,            
    void      *pArg)           
{
    OS_ERR  os_error;
    
    OSSemPost (&Master_Semaphore,
                 OS_OPT_POST_NONE,
                 &os_error);
    DEBUG_RESULT("SPI Master Callback Semaphore POST failed", os_error, OS_ERR_NONE);    

}

void MasterTask(void *pa)
{
    volatile bool bMasterComplete= false;
    ADI_SPI_RESULT eResult;
    ADI_SPI_TRANSCEIVER Mtransceive;

    /* Initialize the buffer with known values */
    InitBuffer(masterTx,BUFFERSIZE);
    
    /* Configure the master */
    eResult = ConfigureMasterSPI();
    DEBUG_RESULT("Failed to configure Master SPI",eResult,ADI_SPI_SUCCESS);    

    eResult = adi_spi_RegisterCallback (hMDevice, Master_Callback, NULL);
    DEBUG_RESULT("Failed to register the Master callback",eResult,ADI_SPI_SUCCESS);    

    /* Create the Master SEM used to synchronize the task with the callback      */
    OS_ERR  os_error;
    OSSemCreate( &Master_Semaphore, "Master SEM", 0u, &os_error); 
    DEBUG_RESULT("Failed to create the SPI Slave Semaphore", os_error, OS_ERR_NONE);    

     /* Prepare the buffers for submitting to Master */     
    Mtransceive.pTransmitter = masterTx;
    Mtransceive.TransmitterBytes = BUFFERSIZE;
    Mtransceive.nTxIncrement = 1u;
    Mtransceive.pReceiver = NULL;    
    Mtransceive.ReceiverBytes = 0u;
    Mtransceive.nRxIncrement = 0u;
    Mtransceive.bDMA = false;
    Mtransceive.bRD_CTL = false;
   
    /* Submit the buffer to Master */         
    eResult= adi_spi_MasterSubmitBuffer(hMDevice,&Mtransceive);
    DEBUG_RESULT("Master - Data failure",eResult,ADI_SPI_SUCCESS);


    
    /* Synchronize with (wait for) the callback */
    OSSemPend( &Master_Semaphore,
                 0,                      /* No time out. Wait forever. */
                 OS_OPT_PEND_BLOCKING,
                 NULL,                   /* No Timestamp needed */
                 &os_error);
    DEBUG_RESULT("SPI Slave Semaphore PEND failed", os_error, OS_ERR_NONE);    

    
    /*--------------  Step 2 -------------------------- */
    /* Read the data back from the slave                */ 
    Mtransceive.pTransmitter = NULL;
    Mtransceive.TransmitterBytes = 0u;
    Mtransceive.nTxIncrement = 0u;
    Mtransceive.pReceiver = masterRx;    
    Mtransceive.ReceiverBytes = BUFFERSIZE;
    Mtransceive.nRxIncrement = 1;
    Mtransceive.bDMA = false;
    Mtransceive.bRD_CTL = false;

    eResult= adi_spi_MasterSubmitBuffer(hMDevice,&Mtransceive);
    DEBUG_RESULT("Master - Data failure",eResult,ADI_SPI_SUCCESS);
 
    /* Synchronize with (wait for) the callback */
    OSSemPend( &Master_Semaphore,
                 0,                      /* No time out. Wait forever. */
                 OS_OPT_PEND_BLOCKING,
                 NULL,                   /* No Timestamps needed */
                 &os_error);
    DEBUG_RESULT("SPI Slave Semaphore PEND failed", os_error, OS_ERR_NONE);    
    
    /* Now see if everything was transmitted correctly */
    uint32_t vres = ValidateData(masterRx , masterTx, BUFFERSIZE);
    if( vres == SUCCESS )
    {
      common_Pass();
      exit(0);
    }
    else
    {
      common_Fail("Transmitted and Received data differ");
      exit(1);
    }
    
   
    while(1)
    {
        OS_ERR  os_error;
        OSTimeDly(100, OS_OPT_TIME_DLY, &os_error); /*  Delay execution of a task for “n” ticks. Allows lower priority tasks to run */
        DEBUG_RESULT("SPI Slave Semaphore PEND failed", os_error, OS_ERR_NONE);    
    }

}

               
/*****/

