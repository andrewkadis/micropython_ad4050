/*!
 *****************************************************************************
 * @file:    MasterSlaveLoopback.c
 * @brief:   SPI Device Example for ADuCM4x50
 * @version: $Revision$
 * @date:    $Date$
 *-----------------------------------------------------------------------------
 *
Copyright (c) 2016-2017 Analog Devices, Inc.

All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:
  - Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.
  - Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.
  - Modified versions of the software must be conspicuously marked as such.
  - This software is licensed solely and exclusively for use with processors
    manufactured by or for Analog Devices, Inc.
  - This software may not be combined or merged with other code in any manner
    that would cause the software to become subject to terms and conditions
    which differ from those listed here.
  - Neither the name of Analog Devices, Inc. nor the names of its
    contributors may be used to endorse or promote products derived
    from this software without specific prior written permission.
  - The use of this software may or may not infringe the patent rights of one
    or more patent holders.  This license does not release you from the
    requirement that you obtain separate licenses from these patent holders
    to use this software.

THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES, INC. AND CONTRIBUTORS "AS IS" AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-INFRINGEMENT,
TITLE, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN
NO EVENT SHALL ANALOG DEVICES, INC. OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, PUNITIVE OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, DAMAGES ARISING OUT OF CLAIMS OF INTELLECTUAL
PROPERTY RIGHTS INFRINGEMENT; PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *****************************************************************************/

/*! \addtogroup SPI_Test SPI Test
 *  Example code demonstrating use of the SPI device driver.
 *  @{
 */

/* Apply ADI MISRA Suppressions */

#include <stddef.h>		/* for 'NULL' */
#include <string.h>		/* for strlen */
#include "common.h"
#include <drivers/general/adi_drivers_general.h>

#include <drivers/spi/adi_spi.h>
#include <drivers/pwr/adi_pwr.h>
#include <drivers/dma/adi_dma.h>
#include "SpiMasterSlaveLoopBack.h"
int32_t adi_initpinmux(void);

#if defined(__ADUCM4x50__)
#define FAILURE 1
#define SUCCESS 0
#endif

/* This code does the data transfer between two different SPI devices. */
/* SPI Master is configured using SPI0                         */
/* SPI Slave is configured using SPI1                          */
/* Requires                                                    */
/* (2) EI3 Breakout expansions boards                              */
/* (4)  Connect J1 connector of EI3 probing adopter to P1A of ADuCM4x50 EZ-Kit. */
/*                                                             */
/* Jumper/Cable connections.                                                 */
/*    Master                    Slave  */
/* MOSI [P5.90]  ------------> MOSI [P5.84]       */
/* MISO [P6.91]  <------------ MISO [P5.83]       */
/* CLK  [P6.92]  ------------> CLK  [P5.82]       */
/* SSEL [P5.54]  ------------> SSEL [P5.39]       */
/*                                                        */
/* a. Master clocks the slave                             */
/* b. Master sends the data to slave. Slave receives .    */
/* c. Slave sends same data back to Master.               */
/* d. Master verify the received data with data which it sent to slave  */
/*                                                        */

/* master buffers */
ADI_ALIGNED_PRAGMA(4)
uint8_t masterTx[BUFFERSIZE] ADI_ALIGNED_ATTRIBUTE(4);
ADI_ALIGNED_PRAGMA(4)
uint8_t masterRx[BUFFERSIZE] ADI_ALIGNED_ATTRIBUTE(4);

/* slave buffers */
ADI_ALIGNED_PRAGMA(4)
uint8_t slaveRx[BUFFERSIZE] ADI_ALIGNED_ATTRIBUTE(4);

/* Device memory required for operate Master SPI device */
ADI_ALIGNED_PRAGMA(4)
uint8_t MasterSpidevicemem[ADI_SPI_MEMORY_SIZE] ADI_ALIGNED_ATTRIBUTE(4);

/* Device memory required for operate Slave SPI device */
ADI_ALIGNED_PRAGMA(4)
uint8_t SlaveSpidevicemem[ADI_SPI_MEMORY_SIZE] ADI_ALIGNED_ATTRIBUTE(4);

/* Slave device handle */
ADI_SPI_HANDLE hSDevice;

/* Master device handle */
ADI_SPI_HANDLE hMDevice;

/* Validate the  content of the buffers */
uint32_t ValidateData(uint8_t *pInbuf,uint8_t *pOutBuf,uint32_t nSize)
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
void InitBuffer(uint8_t *pBuffer,uint32_t nSize)
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

/* Configure the SPI device in Slave mode */
ADI_SPI_RESULT ConfigureSlaveSPI()
{
    ADI_SPI_RESULT eResult;
    
    /* Open the SPI device. It opens in Master mode by default */    
    eResult = adi_spi_Open(SPI_SLAVE_DEVICE_NUM,SlaveSpidevicemem,ADI_SPI_MEMORY_SIZE,&hSDevice);
    DEBUG_RESULT("Failed to init SPI driver",eResult,ADI_SPI_SUCCESS);
    
    eResult = adi_spi_SetMasterMode(hSDevice,false);
    DEBUG_RESULT("Failed to set the device in Slave mode",eResult,ADI_SPI_SUCCESS);
    
    eResult =  adi_spi_SetChipSelect (hSDevice, ADI_SPI_CS0);
    DEBUG_RESULT("Failed to set chipselect",eResult,ADI_SPI_SUCCESS);
    
    memset(slaveRx, 0, sizeof(slaveRx));
    
    return(ADI_SPI_SUCCESS);
}

int main(void)
{
    ADI_SPI_RESULT eResult;
    ADI_SPI_TRANSCEIVER Mtransceive,Stransceive;
    uint32_t nResult;
    uint32_t slaveHWErrors;
    uint32_t masterHWErrors;

    adi_initpinmux();

    /* test system initialization */
    common_Init();

    /* Initialize power service */
    if((adi_pwr_Init())!= ADI_PWR_SUCCESS )
    {
        DEBUG_MESSAGE("Power-init  failed");
        exit(0);
    }
    /* Set core clock divider to "1" which sets it to 26Mhz*/
    if(ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_HCLK,1))
    {
        DEBUG_MESSAGE("Failed to intialize the power service\n");
        exit(0);
    }
    /* Set peripheral clock  divider to "1" which sets it to 26Mhz*/    
    if(ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_PCLK,1))
    {
        DEBUG_MESSAGE("Failed to intialize the power service\n");
        exit(0);
    }
    /* Initialize the buffer with known values */
    InitBuffer(masterTx,BUFFERSIZE);
    
    /* Configure the master */
    eResult = ConfigureMasterSPI();
    DEBUG_RESULT("Failed to configure Master SPI",eResult,ADI_SPI_SUCCESS);    

    /* Configure the Slave */    
    eResult = ConfigureSlaveSPI();
    DEBUG_RESULT("Failed to configure Slave SPI",eResult,ADI_SPI_SUCCESS);    
		
    /*--------------  Step 1 -------------------------- */
    /* Prepare the buffers for submitting to slave */ 
    Stransceive.pTransmitter = NULL;
    Stransceive.TransmitterBytes = 0 ;
    Stransceive.nTxIncrement = 0;
    Stransceive.pReceiver = slaveRx ;    
    Stransceive.nRxIncrement = 1;
    Stransceive.ReceiverBytes = BUFFERSIZE;
    Stransceive.bDMA = true;
    Stransceive.bRD_CTL = false;
    
    /* Prepare the buffers for submitting to Master */     
    Mtransceive.pTransmitter = masterTx;
    Mtransceive.TransmitterBytes = BUFFERSIZE;
    Mtransceive.nTxIncrement = 1;
    Mtransceive.pReceiver = NULL;    
    Mtransceive.ReceiverBytes = 0;
    Mtransceive.nRxIncrement = 0;
    Mtransceive.bDMA = true;
    Mtransceive.bRD_CTL = false;
    
    
    /* Submit the buffer to Slave */   
    /* Must use the non-blocking API to allow the application to continue */
    eResult= adi_spi_SlaveSubmitBuffer(hSDevice,&Stransceive);
    DEBUG_RESULT("Slave - Data failure",eResult,ADI_SPI_SUCCESS);
  
     /* Submit the buffer to Master */         
    eResult= adi_spi_MasterSubmitBuffer(hMDevice,&Mtransceive);
    DEBUG_RESULT("Master - Data failure",eResult,ADI_SPI_SUCCESS);
    
    /* Now retrieve the master buffer */
    eResult = adi_spi_GetBuffer( hMDevice, &masterHWErrors);
    DEBUG_RESULT("Master - adi_spi_GetBuffer failure",eResult,ADI_SPI_SUCCESS);
    DEBUG_RESULT("Master - adi_spi_GetBuffer failure HW Error Occured",(uint16_t)masterHWErrors,ADI_SPI_HW_ERROR_NONE);

 		 /* Now retrieve the slave buffer */
    eResult = adi_spi_GetBuffer( hSDevice, &slaveHWErrors);
    DEBUG_RESULT("Slave - adi_spi_GetBuffer failure",eResult,ADI_SPI_SUCCESS);
    DEBUG_RESULT("Slave - adi_spi_GetBuffer failure HW Error Occured",(uint16_t)slaveHWErrors,ADI_SPI_HW_ERROR_NONE);

    /*--------------  End of step 1 -------------------------- */
    
    /*--------------  Start of step 2 -------------------------- */
   
    /* Now send the data back from the slave to the master */
    /*Prepare the buffers for submitting to slave */ 
    Stransceive.pTransmitter = slaveRx;
    Stransceive.TransmitterBytes = BUFFERSIZE;
    Stransceive.nTxIncrement = 1;
    Stransceive.pReceiver = NULL ;    
    Stransceive.ReceiverBytes = 0 ;
    Stransceive.nRxIncrement = 0;
    Stransceive.bDMA = true;
    Stransceive.bRD_CTL = false;
    
    /* Submit the buffer to Master */         
    Mtransceive.pTransmitter = NULL;
    Mtransceive.TransmitterBytes = 0 ;
    Mtransceive.nTxIncrement =0;
    Mtransceive.pReceiver =  masterRx;    
    Mtransceive.ReceiverBytes = BUFFERSIZE ;
    Mtransceive.nRxIncrement = 1;
    Mtransceive.bDMA = true;
    Mtransceive.bRD_CTL = false;
    
    /* Must use the non-blocking API to allow the application to continue */
    eResult= adi_spi_SlaveSubmitBuffer(hSDevice,&Stransceive);
    DEBUG_RESULT("Slave - Data failure",eResult,ADI_SPI_SUCCESS);

    
    eResult= adi_spi_MasterReadWrite(hMDevice,&Mtransceive);
    DEBUG_RESULT("Master - Data failure",eResult,ADI_SPI_SUCCESS);

    eResult = adi_spi_GetBuffer( hSDevice, &slaveHWErrors);
    DEBUG_RESULT("Slave - adi_spi_GetBuffer failure",eResult,ADI_SPI_SUCCESS);
    DEBUG_RESULT("Slave - adi_spi_GetBuffer failure HW Error Occured",(uint16_t)slaveHWErrors,ADI_SPI_HW_ERROR_NONE);
    
    /* Validate the buffer */
    nResult = ValidateData(masterTx,masterRx,BUFFERSIZE-1); 
    if(nResult != SUCCESS)
    {
        common_Fail("MASTER-SLAVE loopback example failed\n");
        exit(1);
    }

    /*--------------  End of step 2 -------------------------- */

    /*--------------  Start of step 3 -------------------------- */
    
    /* Now do it all again, but in interrupt mode */
    /* Prepare the buffers for submitting to slave */ 
    Stransceive.pTransmitter = NULL;
    Stransceive.TransmitterBytes = 0 ;
    Stransceive.nTxIncrement = 0;
    Stransceive.pReceiver = slaveRx ;    
    Stransceive.nRxIncrement = 1;
    Stransceive.ReceiverBytes = BUFFERSIZE;
    Stransceive.bDMA = false;
    Stransceive.bRD_CTL = false;
    
    /* Prepare the buffers for submitting to Master */     
    Mtransceive.pTransmitter = masterTx;
    Mtransceive.TransmitterBytes = BUFFERSIZE;
    Mtransceive.nTxIncrement = 1;
    Mtransceive.pReceiver = NULL;    
    Mtransceive.ReceiverBytes = 0;
    Mtransceive.nRxIncrement = 0;
    Mtransceive.bDMA = false;
    Mtransceive.bRD_CTL = false;
    
    
    /* Submit the buffer toSlave */   
    /* Must use the non-blocking API to allow the application to continue */
    eResult= adi_spi_SlaveSubmitBuffer(hSDevice,&Stransceive);
    DEBUG_RESULT("Slave - Data failure",eResult,ADI_SPI_SUCCESS);
  
     /* Submit the buffer to Master */         
    eResult= adi_spi_MasterSubmitBuffer(hMDevice,&Mtransceive);
    DEBUG_RESULT("Master - Data failure",eResult,ADI_SPI_SUCCESS);

    /* Now retrieve the master buffer */
    eResult = adi_spi_GetBuffer( hMDevice, &masterHWErrors);
    DEBUG_RESULT("Master - adi_spi_GetBuffer failure",eResult,ADI_SPI_SUCCESS);
    DEBUG_RESULT("Master - adi_spi_GetBuffer failure HW Error Occured",(uint16_t)masterHWErrors,ADI_SPI_HW_ERROR_NONE);

    /* Now retrieve the slave buffer */
    eResult = adi_spi_GetBuffer( hSDevice, &slaveHWErrors);
    DEBUG_RESULT("Slave - adi_spi_GetBuffer failure",eResult,ADI_SPI_SUCCESS);
    DEBUG_RESULT("Slave - adi_spi_GetBuffer failure HW Error Occured",(uint16_t)slaveHWErrors,ADI_SPI_HW_ERROR_NONE);

    /*--------------  End of step 3 -------------------------- */
   
    /*--------------  Start of step 4 -------------------------- */
    
    /* Now send the data back from the slave to the master */
    /*Prepare the buffers for submitting to slave */ 
    Stransceive.pTransmitter = slaveRx;
    Stransceive.TransmitterBytes = BUFFERSIZE-1;
    Stransceive.nTxIncrement = 1;
    Stransceive.pReceiver = NULL ;    
    Stransceive.ReceiverBytes = 0 ;
    Stransceive.nRxIncrement = 0;
    Stransceive.bDMA = false;
    Stransceive.bRD_CTL = false;
    
    /* Submit the buffer to Master */         
    Mtransceive.pTransmitter = NULL;
    Mtransceive.TransmitterBytes = 0 ;
    Mtransceive.nTxIncrement =0;
    Mtransceive.pReceiver =  masterRx;    
    Mtransceive.ReceiverBytes = BUFFERSIZE ;
    Mtransceive.nRxIncrement = 1;
    Mtransceive.bDMA = false;
    Mtransceive.bRD_CTL = false;
    
    /* Must use the non-blocking API to allow the application to continue */
    eResult= adi_spi_SlaveSubmitBuffer(hSDevice,&Stransceive);
    DEBUG_RESULT("Slave - Data failure",eResult,ADI_SPI_SUCCESS);

    
    eResult= adi_spi_MasterReadWrite(hMDevice,&Mtransceive);
    DEBUG_RESULT("Master - Data failure",eResult,ADI_SPI_SUCCESS);

    eResult = adi_spi_GetBuffer( hSDevice, &slaveHWErrors);
    DEBUG_RESULT("Slave - adi_spi_GetBuffer failure",eResult,ADI_SPI_SUCCESS);
    DEBUG_RESULT("Slave - adi_spi_GetBuffer failure HW Error Occured",(uint16_t)slaveHWErrors,ADI_SPI_HW_ERROR_NONE);

    /* shut  down  the Master*/
    if (ADI_SPI_SUCCESS != adi_spi_Close(hMDevice)) {
        DEBUG_MESSAGE("Failed to uninit SPI driver");
    }
    /* shut  down the Slave*/
    if (ADI_SPI_SUCCESS != adi_spi_Close(hSDevice)) {
        DEBUG_MESSAGE("Failed to uninit SPI driver");
    }
    
    common_Pass();
}



void PendSV_Handler( void );
void PendSV_Handler( void )
{
  /* stay here and allow the SPI to overflow/underflow */
  int i = 0;
  while( i < 10000000){
    i++;
  }
}

/*@}*/

/* Revert ADI MISRA Suppressions */

/*
** EOF
*/
