            Analog Devices, Inc. ADuCM4x50 Application Example

Project Name: uart_loopback

Description:  Demonstrates how to use the UART driver. 
              The example transfers the content of one buffer to another by using the
              loopback feature of the device. The example also demonstrates how to enable DMA
              operation as well as PIO operation. 
 

Overview:
=========
    This example shows how to use UART device for transmitting/receiving data. 
    It opens a UART device and configures the device to perform loopback. 
    A data buffer is filled with known values and submitted to the UART device for 
    transmitting. Similarly, an empty buffer is submitted to UART device 
    for storing the received data. At the end of the example, content of received 
    buffers are verified against the content of transmit buffers. This example runs
    in nonblocking mode only and showcases the use of the DMA in addition to PIO mode.

    The UART driver supports both nonblocking and blocking calls, which are 
    demonstrated in this example. A nonblocking call is turned into a blocking
    call with "adi_uart_GetTxBuffer" and "adi_uart_GetRxBuffer". Please take note that
    this example is only using nonblocking mode, even though some of the calls may 
    block.  Refer to the ADuCM4x50 Device Driver User's Guide for more information on the
    various modes of operation. 
    
    Please note that the external hardware connection for this loopback example 
    is not the same as testing the internal loopback hardware on the device.


User Configuration Macros:
==========================


Hardware Setup:
===============
   ADuCM4050 EZ Kit configured using default hardware settings with the following jumper settings.
   For UART 0:
        J6 - Connect jumper between pins 1 and 2 (first two pins). 
   For UART 1:
        P7 - Connect jumper between pins 2 and 3 (middle two pins). 
 
   Note: By default the example is set to use UART 1 in the software. This means that the variable  
   UART_DEVICE_NUM in uart_loop_back.h is set to "1". To use UART 0 in the hardware, UART_DEVICE_NUM 
   would need to be changed to "0" in the software.  
   
External connections:
=====================
    None. 
    
How to build and run:
=====================
    Set the baud rate using the fractional divide macros listed in 'adi_uart_config.h' file. 
    Please use the utility "UartDivCalculator.exe" provided along with the BSP package 
    to generate the optimum values used to configure the device for different baud rates. 

    Prepare hardware as explained in the Hardware Setup section.

    Build the project, load the executable to ADuCM4050, and run it. 

    Look for the debug information displayed on terminal IO. 

Expected Result:
=====================
    Upon successful completion the program should output:
    
    All done!

    UART loop back example completed successfully.

    Successfully tested:

            * Nonblocking mode

            * Interrupt transfers

            * DMA transfers
        
References:
===========
    ADuCM4x50 Hardware Reference Manual
