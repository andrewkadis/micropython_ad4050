            Analog Devices, Inc. EV-COG-AD4050LZ Application Example

Project Name: uart_autobaud_example

Description:
============
  Demonstrates how to use the UART driver for autobaud detection

Overview:
=========
  This example shows how to use UART device driver for baudrate detection.
  The example opens a UART device, configures the device for baudrate detection.
  After receiving the key character (carrige return), it configures the UART device to the detected baudrate.
  This example has been tested for baudrates 300 to 921600.  In order to detect baudrates lower than 300,
  decrease the clock speed.


User Configuration Macros:
==========================
  - UART_DEVICE_NUM: Choose which UART to use for the example.  If the the UART to USB connector is used
    to communicate with the host PC, then this macro must be set to 0.
  - UART_AUTOBAUD_TIMEOUT: Number of cycles to wait for a character to be sent prior to reporting an error.


Hardware Setup:
===============
   None.


External connections:
=====================
  Attach a USB cable from the hosting/debugging PC to the USB connector on the EV-COG-AD4050LZ board.


How to build and run:
=====================
  With the MBED USB cable connected between the EV-COG-AD4050LZ and the PC, download and run the
  Windows "mbed Serial Port" driver from:  https://developer.mbed.org/handbook/Windows-serial-configuration

  With the USB cable still connected, browse the Windows Device Manager to the "Ports (COM & PLT)" section
  and note the virtual serial port COM# assigned to named port "mbed Serial Port".

  Build the project, load the executable to EV-COG-AD4050LZ, and run it.

  Run a host-based serial emulator utility, such as teraterm or PuTTY.

  Open a session on the virtual serial port reported by Windows Device Manager.

  Hit the "Enter" key (carrige return) to detect the baud rate.

  Type any character and it will be echoed on host terminal.  Enter "Q" to end the example.


Expected Result:
=====================
  The following message should be printed to the terminal if you press 'ENTER' in Terminal:

		"If you can read this then the baudrate was successfully detected!
		The baudrate is: xxxxxxxx.
		Note: This is using integer precision so it could vary slightly from the actual baudrate.
		Please enter any character to echo back on terminal

		Enter 'Q' to end the example:"

		Note: Any errors will be printed to terminal IO.


References:
===========
  ADuCM4X50 Hardware Reference Manual
  EV-COG-AD4050LZ evaluation board schematic
