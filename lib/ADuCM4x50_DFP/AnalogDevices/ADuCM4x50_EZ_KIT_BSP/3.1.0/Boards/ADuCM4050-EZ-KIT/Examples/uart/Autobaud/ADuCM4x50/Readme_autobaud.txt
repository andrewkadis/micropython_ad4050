              Analog Devices, Inc. ADuCM4x50 Application Example
            
Project Name: autobaud

Description:  Demonstrates how to use the UART driver for autobaud detection 

Overview:
=========
    This example shows how to use UART device driver for baudrate detection. 
    The example opens a UART device, configures the device for baudrate detection. 
    After receiving the key character (carrige return), it configures the UART device to the detected baudrate. 
    This example has been tested for baudrates 300 to 921600. In order to detect baudrates lower than 300, 
    decrease the clock speed. 

User Configuration Macros:
==========================
    - UART_DEVICE_NUM: Choose which UART to use for the example. If the the UART to USB connector is used (P6) 
      to communicate with the host PC, then this macro must be set to 0.
    - UART_AUTOBAUD_TIMEOUT: Number of cycles to wait for a character to be sent prior to reporting an error. 

Hardware Setup:
===============
    ADuCM4x50 EZ Kit configured with default settings.
 
External connections:
=====================
    Connect host terminal to the "USB to UART" connector on the evaluation board using a USB cable. 

How to build and run:
=====================
    Build the project, load the executable to ADuCM4x50, and run it. 

    Open host utility, such as teraterm. Connect to the corresponding serial port. 

    Hit the "Enter" key (carrige return) to detect the baud rate. 

    Type any character and it will be echoed on host terminal. Enter "Q" to end the example. 

Expected Result:
=====================
    The following string should be printed to the terminal if you press 'ENTER' in Terminal: 

    "If you can read this then the baudrate was successfully detected!
    The baudrate is: xxxxxxxx.
    Note: This is using integer precision so it could vary slightly from the actual baudrate.
    Please enter any character to echo back on terminal

    Enter 'Q' to end the example:"
    
    Note: Any errors will be printed to terminal IO.
 
References:
===========
    ADuCM4x50 Hardware Reference Manual
