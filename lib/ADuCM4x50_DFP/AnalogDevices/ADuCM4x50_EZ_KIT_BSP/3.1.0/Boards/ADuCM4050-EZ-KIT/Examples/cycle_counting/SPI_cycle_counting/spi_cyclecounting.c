/*

Copyright (c) 2011-2017 Analog Devices, Inc.

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

#include <stddef.h>		/* for 'NULL' */
#include <string.h>		/* for strlen */
#include "common.h"

#include <drivers/spi/adi_spi.h>
#include <drivers/pwr/adi_pwr.h>
#include <drivers/gpio/adi_gpio.h>
#include <drivers/dma/adi_dma.h>
#include <adi_cyclecount.h>

#include "spi_cyclecounting.h"

 /* Transmit data buffer */
static uint8_t overtx[BUFFERSIZE];
/* Receieve data buffer a */
static uint8_t overrx[BUFFERSIZE];


/* Allocate memort for an instance of the SPI driver */
uint8_t spidevicemem[ADI_SPI_MEMORY_SIZE];


/* Forward declarations */
static ADI_SPI_RESULT run_the_loopback_nonBlockingMode(ADI_SPI_HANDLE hDevice, bool useDma);
static ADI_SPI_RESULT run_the_loopback_blockingMode(ADI_SPI_HANDLE hDevice, bool useDma);

/* Cycle counting IDs for application specified API for which cycle counts are to be obtained */
static uint32_t cycleCountId_blockingMode = 0;
static uint32_t cycleCountId_nonBlockingMode = 0;

int main(void)
{
    ADI_SPI_HANDLE hDevice;
    ADI_SPI_RESULT eResult;

    adi_initpinmux();

    /* Common system initialization */
    common_Init();

#if defined(ADI_CYCLECOUNT_ENABLED) && (ADI_CYCLECOUNT_ENABLED == 1u)
    /* Initialize cycle counting */
    ADI_CYCLECOUNT_INITIALIZE();
    
    /* Obtain cycle counting IDs for both blocking and non-blocking modes */
    ADI_CYCLECOUNT_RESULT eCyclecountResult = adi_cyclecount_addEntity("Blocking", &cycleCountId_blockingMode);
    DEBUG_RESULT("Failed to add cycle counting ID for run_the_loopback_nonBlockingMode_API", eCyclecountResult, ADI_CYCLECOUNT_SUCCESS);
    
    eCyclecountResult = adi_cyclecount_addEntity("Non-blocking", &cycleCountId_nonBlockingMode);
    DEBUG_RESULT("Failed to add cycle counting ID for run_the_loopback_nonBlockingMode_API", eCyclecountResult, ADI_CYCLECOUNT_SUCCESS);
#endif
    
    
    /* Power initialization */
    if(ADI_PWR_SUCCESS != adi_pwr_Init())
    {
        DEBUG_MESSAGE("Failed to intialize the power service");
    }
    if(ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_HCLK,1))
    {
        DEBUG_MESSAGE("Failed to intialize the power service");
    }
    if(ADI_PWR_SUCCESS != adi_pwr_SetClockDivider(ADI_CLOCK_PCLK,1))
    {
        DEBUG_MESSAGE("Failed to intialize the power service\n");
    }

    /* Initialize SPI */
    eResult = adi_spi_Open(SPI_DEVICE_NUM,spidevicemem, ADI_SPI_MEMORY_SIZE, &hDevice);
    DEBUG_RESULT("Failed to init SPI driver",eResult,ADI_SPI_SUCCESS);

    /* throttle bitrate to something the controller can reach */
    eResult = adi_spi_SetBitrate(hDevice, SPI_BIT_RATE);
    DEBUG_RESULT("Failed to set Bitrate",eResult,ADI_SPI_SUCCESS);

    
    /* set the chip select */
    eResult = adi_spi_SetChipSelect(hDevice, ADI_SPI_CS0);
    DEBUG_RESULT("Failed to set the chip select",eResult,ADI_SPI_SUCCESS);

    /* non-dma blocking mode with and without RD_CTL */
    eResult = run_the_loopback_blockingMode(hDevice, false);
    DEBUG_RESULT("SPI interrupt-driven blocking mode example failed",eResult,ADI_SPI_SUCCESS);


    /* blocking mode with and without RD_CTL */
    eResult = run_the_loopback_nonBlockingMode(hDevice, false);
    DEBUG_RESULT("SPI interrupt-driven blocking mode example failed",eResult,ADI_SPI_SUCCESS);
 
    /* Close the SPI device  */
    eResult = adi_spi_Close(hDevice);
    DEBUG_RESULT("Failed to uninit SPI driver",eResult,ADI_SPI_SUCCESS);

    /* Print the cycle counts obtained */
    ADI_CYCLECOUNT_REPORT();

    /* The example has successfully completed */
    common_Pass();
}



/*
 *
 * This routine will use the following fatures of the SPI driver
 *    1. Non-blocking mode of operation via the adi_spi_MasterSubmitBuffer API
 *    2. DMA is either true/false based on the value of the useDma parameter
 *    3. Blocking for transaction completion using the adi_spi_GetBuffer API
 *
 */
static ADI_SPI_RESULT run_the_loopback_nonBlockingMode(ADI_SPI_HANDLE hDevice, bool useDma)
{
    ADI_SPI_RESULT result;  
    ADI_SPI_TRANSCEIVER transceive;

    
    /* initialize both the RX and TX buffers */
    for (unsigned int i = 0u; i < BUFFERSIZE; i++) {
        overtx[i] = (unsigned char)i;
        overrx[i] = (uint8_t)0xdd;
    }


    /* link transceive data size to the remaining count */
    transceive.TransmitterBytes = BUFFERSIZE;
    /* link transceive data size to the remaining count */
    transceive.ReceiverBytes = BUFFERSIZE;
    /* initialize data attributes */
    transceive.pTransmitter = overtx;
    transceive.pReceiver = overrx;
    /* auto increment both buffers */
    transceive.nTxIncrement = 1;
    transceive.nRxIncrement = 1;
    transceive.bDMA = useDma;
    transceive.bRD_CTL = false;

#if defined(ADI_CYCLECOUNT_ENABLED) && (ADI_CYCLECOUNT_ENABLED==1u)
     if( adi_cyclecount_start() != ADI_CYCLECOUNT_SUCCESS)
     {
       return ADI_SPI_FAILURE;
     }
#endif
;


    /* Use the non-blocking API */
    if (ADI_SPI_SUCCESS != (result = adi_spi_MasterSubmitBuffer(hDevice, &transceive)))
    {
        return result;
    }

    /* When using non-blocking APIs the application can do useful work here */

#if defined(ADI_CYCLECOUNT_ENABLED) && (ADI_CYCLECOUNT_ENABLED==1u)
    ADI_CYCLECOUNT_STORE(cycleCountId_nonBlockingMode);
    if( adi_cyclecount_stop() != ADI_CYCLECOUNT_SUCCESS)
    {
      return ADI_SPI_FAILURE;
    }
#endif


    /* When the application calls adi_spi_GetBuffer it will block           */
    /* until the transaction completes                                      */

    uint32_t HWError;
    ADI_SPI_RESULT res = adi_spi_GetBuffer(hDevice, &HWError);
    if( (res != ADI_SPI_SUCCESS) || (HWError != (uint32_t)ADI_SPI_HW_ERROR_NONE)) {
        return ADI_SPI_FAILURE;
    }

    
    /* verify receive data                                                   */
    /* Since the data is simply looped back from MOSI to MISO we simply need */
    /* to verify that the tx and rx buffers are identical                    */
    for (unsigned int i = 0u; i < BUFFERSIZE; i++) {
        if (overtx[i] != overrx[i]) {
            return ADI_SPI_FAILURE;  /* failure */
        }
    }

    return ADI_SPI_SUCCESS;
}


/*
 *
 * This routine will use the following fatures of the SPI driver
 *    1. Blocking mode of operation via the adi_spi_MasterReadWrite API
 *    2. DMA is either true/false based on the value of the useDma parameter
 *
 */

static ADI_SPI_RESULT run_the_loopback_blockingMode(ADI_SPI_HANDLE hDevice, bool useDma)
{
    ADI_SPI_RESULT result;
    ADI_SPI_TRANSCEIVER transceive;

    
    
    /* initialize both the RX and TX buffers */
    for (unsigned int i = 0u; i < BUFFERSIZE; i++) {
        overtx[i] = (unsigned char)i;
        overrx[i] = (uint8_t)0xdd;
    }

    /* link transceive data size to the remaining count */
    transceive.TransmitterBytes = BUFFERSIZE;
    /* link transceive data size to the remaining count */
    transceive.ReceiverBytes = BUFFERSIZE;
    /* initialize data attributes */
    transceive.pTransmitter = overtx;
    transceive.pReceiver = overrx;
    /* auto increment both buffers */
    transceive.nTxIncrement = 1;
    transceive.nRxIncrement = 1;
    transceive.bDMA = useDma;
    transceive.bRD_CTL = false;

#if defined(ADI_CYCLECOUNT_ENABLED) && (ADI_CYCLECOUNT_ENABLED==1u)
     if( adi_cyclecount_start() != ADI_CYCLECOUNT_SUCCESS)
     {
       return ADI_SPI_FAILURE;
     }
#endif
  
    if (ADI_SPI_SUCCESS != (result = adi_spi_MasterReadWrite(hDevice, &transceive)))
    {
        return result;
    }

#if defined(ADI_CYCLECOUNT_ENABLED) && (ADI_CYCLECOUNT_ENABLED==1u)
    ADI_CYCLECOUNT_STORE(cycleCountId_blockingMode);
    if( adi_cyclecount_stop() != ADI_CYCLECOUNT_SUCCESS)
    {
      return ADI_SPI_FAILURE;
    }
#endif

    /* verify receive data                                                   */
    /* Since the data is simply looped back from MOSI to MISO we simply need */
    /* to verify that the tx and rx buffers are identical                    */
    for (unsigned int i = 0u; i < BUFFERSIZE; i++) {
        if (overtx[i] != overrx[i]) {
            return ADI_SPI_FAILURE;  /* failure */
        }
    }

    return ADI_SPI_SUCCESS;
}


