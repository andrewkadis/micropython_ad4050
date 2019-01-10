            Analog Devices, Inc. ADuCM4x50 Application Example

Project Name: uart_callback

Description:  Demonstrates how to use the UART driver. 
              The example transfers the content of one buffer to another by using the
              loopback feature of the device. The example also demonstrates how to enable DMA
              operation, PIO operation and register a callback. 
 

Overview:
=========
    This example shows how to use UART device for transmitting/receiving data. 
    It opens a UART device and configures the device to perform loopback. 
    A data buffer is filled with known values and submitted to the UART device for 
    transmitting. Similarly, an empty buffer is submitted to UART device 
    for storing the received data. At the end of the example, content of received 
    buffers are verified against the content of transmit buffers. This example runs
    in callback mode. A counter in the callback is checked to
    make sure it was entered the correct number of times. 
    
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

    UART callback example completed successfully.

    Successfully tested:

            * Callback mode

            * Interrupt transfers

            * DMA transfers

        
References:
===========
    ADuCM4x50 Hardware Reference Manual
