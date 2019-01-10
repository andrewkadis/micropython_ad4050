         Analog Devices, Inc. ADuCM4x50 Application Example

Project Name: dma_driven_crc_without_callback

Description: This example demonstrates how to use the CRC driver. It computes
===========  a CRC value using data stored in a buffer and compares the result 
             with the expected value.
             The CRC driver is statically configured to execute in dma-driven
             CRC operations, with no callback. (See adi_crc_config.h)

Overview:    This example shows how to use a CRC device on buffers of data.
=========    It opens a CRC device, configures this device to calculate the
             CRC, feeds the data stored in a buffer into the CRC hardware
             engine, and verifies the CRC value calculated.

             The CRC driver supports both core-driven operations, dma-driven
             operations with no callback function and dma-driven operations
             with a callback function registered.

             This example executes dma-driven CRC operations, without callback.

User Configuration Macros:
==========================
             The following macros can be used to configure the CRC driver.
             They can be found in adi_crc_config.h

             ADI_CRC_CFG_ENABLE_DMA_SUPPORT : 
               - 0    : core-driven CRC operations
               - else : dma-driven CRC operations

            ADI_CFG_CRC_SOFTWARE_DMA_CHANNEL_ID:
              expects a value between 0 and 7 to set the software DMA channel
              to be used when executing dma-driven CRC operations. (Default
              channel used is SIP7.)

            This example requires ADI_CRC_CFG_ENABLE_DMA_SUPPORT set to 1.
            ADI_CFG_CRC_SOFTWARE_DMA_CHANNEL_ID is needed.

Hardware Setup:
===============  
             By default, this example runs on HW with no specific setup required.

External connections:
=====================
             None.             

How to build and run:
=====================    
             Prepare hardware as explained in the Hardware Setup section.
             Build the project, load the executable to ADuCM4x50, and run it.


Expected Result:
=================
             Message "All done!" should appear when the test executes
             all the CRC operations successfully.

References:
===========
             ADuCM4x50 Hardware Reference Manual
