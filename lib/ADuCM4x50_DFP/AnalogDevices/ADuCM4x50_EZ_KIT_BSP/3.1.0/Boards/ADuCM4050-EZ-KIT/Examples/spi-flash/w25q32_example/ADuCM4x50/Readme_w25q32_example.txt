            Analog Devices, Inc. ADuCM4x50 Application Example

Project Name: w25q32_example

Description:  Demonstrate how to use the W25Q32 driver.
 

Overview:
=========
    In this example, the W25Q32 driver is used to erase the chip, write a page of random values, and then read 
    back that page. The only API not demonstrated in this example is W25Q32_ChipErase. The W25Q32 uses the SPI
    driver, so adi_spi.c must be included in projects that use the W25Q32 driver.

User Configuration Macros:
==========================
    None.

Hardware Setup:
===============
    None.
 
External connections:
=====================
    None.


How to build and run:
=====================
    Build the project and download to a single ADuCM4x50 target. Open the output terminal and run.

Expected Result:
=====================
    The string "All done!" should be printed to the terminal.
 
References:
===========
    ADuCM4x50 Hardware Reference Manual
