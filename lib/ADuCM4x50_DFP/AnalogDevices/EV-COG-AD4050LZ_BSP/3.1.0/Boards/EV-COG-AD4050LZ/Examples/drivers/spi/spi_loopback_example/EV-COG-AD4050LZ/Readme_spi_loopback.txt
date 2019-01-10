         Analog Devices, Inc. EV-COG-AD4050LZ Application Example

Project Name: spi_loopback

Description:
===========
  This example demonstrates how to use the SPI driver in the following modes of operation:

  Blocking Mode
  Non-Blocking Mode
      Polling API used to detect transaction completion.
      Non-polling API to detect transaction completion.

  And for each of the above modes of operation, the following features are demonstrated:
      DMA       both DMA and non-DMA transactions.
      RD_CTL    both RD_CTL and non-RD_CTL transactions .

  The example uses SPI0 internal loopback mode and no external connections are required.
  Loopback mode is controlled by configuration macro ENABLE_INTERNAL_SPI_LOOPBACK, which
  is enabled by default.

  If this macro is undefined, this example will require an extender card on C1 and C2
  such as the EV-GEAR-EXPANDER1Z.  On this extender card, SPI0 MOSI and SPI0 MISO will
  need to be jumpered together.  On this particular extender card, this can be done by
  connecting pins 1 and 4 on the A1 Arduino header.

  SPI pins (MISO, MOSI, and SCLK) are configured by PinMix.c file.  SPI-CS is driven manually.

Overview:
=========
  This example shows how to use SPI device for transmitting/receiving data.
  The transmit buffer is filled with known values and submitted to the SPI device
  for transmitting.  Similarly, an empty buffer is also submitted to SPI device
  for storing the received data.  The content of the received buffer is verified
  for all modes of operation.

User Configuration Macros:
==========================
  None.

Hardware Setup:
===============
  None.

External connections:
=====================
  None by default.

  If ENABLE_INTERNAL_SPI_LOOPBACK is undefined, this example will require an extender
  card on C1 and C2 such as the EV-GEAR-EXPANDER1Z.  On this extender card, SPI0 MOSI
  and SPI0 MISO will need to be jumpered together.  On this particular extender card,
  this can be done by connecting pins 1 and 4 on the A1 Arduino header.

How to build and run:
=====================
  Prepare hardware as explained in the Hardware Setup section.
  Build the project, load the executable to ADuCM4x50, and run it.

Expected Result:
=================
  The message "All Done" should be printed after the execution is complete.

References:
===========
  ADuCM4x50 Hardware Reference Manual
  EV-COG-AD4050LZ evaluation board schematic
