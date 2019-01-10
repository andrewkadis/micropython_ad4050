          Analog Devices, Inc. EV-COG-AD4050LZ Application Example

Project Name: uart_callback_example

Description:
============
  Demonstrates how to use the UART driver.
  The example transfers the content of one buffer to another by using the
  loopback feature of the device.  The example also demonstrates how to enable DMA
  operation, PIO operation and register a callback.


Overview:
=========
  This example shows how to use UART device for transmitting/receiving data.
  It opens a UART device and configures the device to perform loopback.
  A data buffer is filled with known values and submitted to the UART device for
  transmitting.  Similarly, an empty buffer is submitted to UART device
  for storing the received data.  At the end of the example, content of received
  buffers are verified against the content of transmit buffers.  This example runs
  in callback mode.  A counter in the callback is checked to
  make sure it was entered the correct number of times.

  Please note that the external hardware connection for this loopback example
  is not the same as testing the internal loopback hardware on the device.


User Configuration Macros:
==========================

  UART_DEVICE_NUM
    Selects physical UART device instance.  Configured in uart_loop_back.h.
    Default setting is "0", designating UART device instance 0.
    Change this as-needed, but note that this example relies on pin I/O for UART0.

  UART_INTERNAL_LOOPBACK
    Selects internal loopback UART mode.  Configured in uart_callback.h.
    Default setting is defined, designating use of internal loopback UART
    mode, avoiding need for physical external loopback jumper settings.
    Undefine this macro to force use of physical external loopback mode (see
    further description in Hardware Setup section).



Hardware Setup:
===============
  Two physical scenarios are possible: internal or external loopback mode.

  INTERNAL LOOPBACK MODE
    Define the UART_INTERNAL_LOOPBACK macro (defined above) and build/run the application.
    No hardware setup required.
    Build, load, run example.

  EXTERNAL LOOPBACK MODE
    Note: in order to use external loopback mode UART_DEVICE_NUM must be set to 0.



External connections:
=====================
  None.

How to build and run:
=====================
  Set the baud rate using the fractional divide macros listed in 'adi_uart_config.h' file.
  Please use the utility "UartDivCalculator.exe" provided along with the BSP package
  to generate the optimum values used to configure the device for different baud rates.

  Prepare hardware as explained in the Hardware Setup section.

  Build the project, load the executable to ADuCM4x50, and run it.

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
