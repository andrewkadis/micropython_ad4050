/*! *****************************************************************************
 * @file    w25q32_example.c
 * @brief   Example showing how to use the W25Q32 driver.
 -----------------------------------------------------------------------------
Copyright (c) 2016 Analog Devices, Inc.

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

THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES, INC. AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-
INFRINGEMENT, TITLE, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL ANALOG DEVICES, INC. OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, PUNITIVE OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, DAMAGES ARISING OUT OF
CLAIMS OF INTELLECTUAL PROPERTY RIGHTS INFRINGEMENT; PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

*****************************************************************************/


#include <common.h>
#include <drivers/pwr/adi_pwr.h>
#include <drivers/spi-flash/w25q32/adi_w25q32.h>

/* Buffers */
static uint8_t txBuf[ADI_W25Q32_PAGE_SIZE];
static uint8_t rxBuf[ADI_W25Q32_PAGE_SIZE];

/* Driver */
ADI_W25Q32_HANDLE hDevice;
uint8_t           aDeviceMemory[ADI_W25Q32_MEMORY_SIZE];

extern int32_t adi_initpinmux(void);

int main(void)
{
    ADI_PWR_RESULT ePwrResult;
    uint8_t        nW25Q32Error;
    
    common_Init();
    
    adi_initpinmux();
    
    ePwrResult = adi_pwr_Init();
    DEBUG_RESULT("adi_pwr_Init failed.", ePwrResult, ADI_PWR_SUCCESS);
    ePwrResult = adi_pwr_SetClockDivider(ADI_CLOCK_HCLK, 1u);
    DEBUG_RESULT("adi_pwr_SetClockDivider (HCLK) failed.", ePwrResult, ADI_PWR_SUCCESS);
    ePwrResult = adi_pwr_SetClockDivider(ADI_CLOCK_PCLK, 1u);
    DEBUG_RESULT("adi_pwr_SetClockDivider (PCLK) failed.", ePwrResult, ADI_PWR_SUCCESS);
    
    nW25Q32Error = adi_w25q32_Open(aDeviceMemory, ADI_W25Q32_MEMORY_SIZE, &hDevice);
    DEBUG_RESULT("adi_w25q32_Open failed.", nW25Q32Error, 0u);
    
    /* Fill TX buffer with random values */
    for (uint32_t i = 0u; i < ADI_W25Q32_PAGE_SIZE; i++) 
    {
        txBuf[i] = rand() % 256u;
    }
    
    /* Erase */
    nW25Q32Error = adi_w25q32_SectorErase(hDevice, 0x0000u);
    DEBUG_RESULT("adi_w25q32_SectorErase failed.", nW25Q32Error, 0u);

    /* Read */
    nW25Q32Error = adi_w25q32_Read(hDevice, rxBuf, ADI_W25Q32_PAGE_SIZE, 0x100u);
    DEBUG_RESULT("adi_w25q32_Read failed.", nW25Q32Error, 0u);
    
    /* Verify the operation */
    for (uint32_t i = 0u; i < ADI_W25Q32_PAGE_SIZE; i++) 
    {
      DEBUG_RESULT("Erase-Read Mismatch: Expected %d but got %d.\r\n", 0xFF, rxBuf[i]);
    }
    
    /* Write */
    nW25Q32Error = adi_w25q32_Write(hDevice, txBuf, ADI_W25Q32_PAGE_SIZE, 0x100u);
    DEBUG_RESULT("adi_w25q32_Write failed.", nW25Q32Error, 0u);
    
    /* Read */
    nW25Q32Error = adi_w25q32_Read(hDevice, rxBuf, ADI_W25Q32_PAGE_SIZE, 0x100u);
    DEBUG_RESULT("adi_w25q32_Read failed.", nW25Q32Error, 0u);
    
    /* Verify the operation */
    for (uint32_t i = 0u; i < ADI_W25Q32_PAGE_SIZE; i++) 
    {
    	DEBUG_RESULT("Write-Read Mismatch: Expected %d but got %d.\r\n", txBuf[i], rxBuf[i]);
    }
    
    nW25Q32Error = adi_w25q32_Close(hDevice);
    DEBUG_RESULT("adi_w25q32_Close failed.", nW25Q32Error, 0u);
  
    common_Pass();
    return 0;
}
