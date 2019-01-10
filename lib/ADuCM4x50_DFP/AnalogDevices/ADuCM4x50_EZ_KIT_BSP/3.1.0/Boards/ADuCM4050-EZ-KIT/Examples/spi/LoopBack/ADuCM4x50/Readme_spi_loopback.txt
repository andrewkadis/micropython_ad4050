         Analog Devices, Inc. ADuCM4x50 Application Example

Project Name: spi_loopback

Description:
=========== 
             This example demonstrates how to use the SPI driver in the following modes of operation
             
               Blocking Mode
               Non-Blocking Mode 
                  Polling API used to detect transaction completion
                  Non-polling API to detect transaction completion
             
             And for each of the above modes of operation the following features are demonstrated 
               DMA        both DMA and non-DMA transactions are demonstrated
               RD_CTL     both RD_CTL and non-RD_CTL transactions are demonstrated 
               

Overview:
=========
             This example shows how to use SPI device for transmitting/receiving data.
             The transmit buffer is filled with known values and submitted to the SPI device 
             for transmitting.	Similarly, an empty buffer is also submitted to SPI  device 
             for storing the received data. The content of the received buffer is verified.
             for all modes of operation.

User Configuration Macros:
==========================
             None

Hardware Setup:
===============  
             The user must connect the MISO and MOSI pins of the SPI2 device to loop the data
             This is be done as follows:

             * Connect J5.8 (SPI2_MISO) to J5.7 (SPI2_MOSI).


External connections:
=====================
             None.             

How to build and run:
=====================    
             Prepare hardware as explained in the Hardware Setup section.
             Build the project, load the executable to ADuCM4x50, and run it.


Expected Result:
=================    
             Should see "All Done" after the execution is complete.


References:
===========
             ADuCM4x50 Hardware Reference Manual
