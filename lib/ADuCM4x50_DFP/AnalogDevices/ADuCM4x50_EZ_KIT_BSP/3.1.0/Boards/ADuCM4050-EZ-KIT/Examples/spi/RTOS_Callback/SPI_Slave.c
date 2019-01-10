/*********************************************************************************

Copyright(c) 2016 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/
/*!
 * @file      SPI_Slave.c
 * @brief     SPI Slave task primary source file. 
 */

/*=============  I N C L U D E S   =============*/

#include "os.h"
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include <drivers/spi/adi_spi.h>
#include "RTOS_Callback.h"

/*=============  D E F I N E S   =============*/
#if defined(__ADUCM302x__)
#define TASK_STK_SIZE   (100u)
#elif defined(__ADUCM4x50__)
#define TASK_STK_SIZE   (200u)
#else
#error SPI is not ported for this processor
#endif

#define TASK_SLAVE_PRIO        (11u)
#define TASK_MASTER_PRIO        (12u)

/*=============  R T O S D A T A   =============*/



/* slave buffers */
uint8_t slaveRxTx[BUFFERSIZE];

/* Slave device handle */
ADI_SPI_HANDLE hSDevice;

/* Device memory required for operate Slave SPI device */
static uint8_t SlaveSpidevicemem[ADI_SPI_MEMORY_SIZE];

/* Slave device handle */
static ADI_SPI_HANDLE hSDevice;

/* SPI Slave mutex used by the SPI Slave task to synchronize with its callbacks */
static OS_SEM Slave_Semaphore;

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
    OS_ERR  os_error;
    
    OSSemPost (&Slave_Semaphore,
                 OS_OPT_POST_NONE,
                 &os_error);
    DEBUG_RESULT("SPI Slave Callback Mutex POST failed", os_error, OS_ERR_NONE);    

}


 void SlaveTask(void *pa)
{
    volatile bool bMasterComplete= false;
    ADI_SPI_RESULT eResult;
    ADI_SPI_TRANSCEIVER Stransceive;

    /* Configure the Slave */    
    eResult = ConfigureSlaveSPI();
    DEBUG_RESULT("Failed to configure Slave SPI",eResult,ADI_SPI_SUCCESS);    
    
    eResult = adi_spi_RegisterCallback (hSDevice, Slave_Callback, NULL);
    DEBUG_RESULT("Failed to register the Slave callback",eResult,ADI_SPI_SUCCESS);    

    /* Slave SEM used to synchronize the Slave task and the Slave callback     */
    OS_ERR  os_error;
    OSSemCreate( &Slave_Semaphore, "Slave SEM", 0u, &os_error); 
    DEBUG_RESULT("Failed to create the SPI Slave Semaphore", os_error, OS_ERR_NONE);    
    
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
    OSSemPend( &Slave_Semaphore,
                 0,                      /* No time out. Wait forever. */
                 OS_OPT_PEND_BLOCKING,
                 NULL,                   /* No Time stamp needed */
                 &os_error);
    DEBUG_RESULT("SPI Slave Semaphore PEND failed", os_error, OS_ERR_NONE);    

    
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
    OSSemPend( &Slave_Semaphore,
                 0,                      /* No time out. Wait forever. */
                 OS_OPT_PEND_BLOCKING,
                 NULL,                   /* No Timestamps needed */
                 &os_error);
    DEBUG_RESULT("SPI Slave Semaphore PEND failed", os_error, OS_ERR_NONE);    


    /* Cannot exit here. Wait forever */
    while(1)
    {
        OSTimeDly(100, OS_OPT_TIME_DLY, &os_error); /*  Delay execution of a task for “n” ticks. Allows lower priority tasks to run */
        DEBUG_RESULT("SPI Slave Semaphore PEND failed", os_error, OS_ERR_NONE);    
    }

}

 
               
/*****/

