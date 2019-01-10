         Analog Devices, Inc. ADuCM4x50 Application

Project Name: sport_loopback_dma

Description: This example demonstrates how to use the SPORT driver.
===========  The example transfers the content of one buffer to another
             using the SPORT peripheral in DMA mode.

Overview:    Basic SPORT loopback DMA example for ADuCM4x50.
=========    This example shows how to use SPORT device for
             transmitting/receiving the data using SPORT peripheral
             in DMA mode.

             The example opens a SPORT device, statically configures the data/frame
             sync/clock to perform the loopback. The transmit data buffer is filled
             with known values and submitted to the SPORT device which is opened in
             the TRANSMIT mode. Similarly, an empty buffer is submitted to SPORT device
             which is opened in RECEIVE mode to receive the data. At the end of the
             example, the content of the received buffer is verified against the
             content of transmit buffer.

User Configuration Macros:
==========================
             None.

Hardware Setup:
===============
             This example requires the ADZ-BRKOUT-EX3 extender card. This product does
             not come with the ADuCM4050 EZ-Kit and can be purchased online. Once the
             extender card is obtained, make the following connections:
             Connect J1 connector of the ADZ-BRKOUT-EX3 extender card to P1A of
             ADuCM4050 EZ-Kit.
             SPORT0-A-FS    (Pin no 89 on P5) => SPORT0-B-FS    (pin no 90 on P5)
             SPORT0-A-DATA  (Pin no 88 on P5) => SPORT0-B-DATA  (Pin no 91 on P6)
             The CLOCK pins don't need to be connected as SPORT-A gets its clock
             signal from SPORT-B through CKMUXSEL, so the following connection can
             be ignored:
             SPORT0-A-CLOCK (Pin no 87 on P5) => SPORT0-B-CLOCK (Pin no 92 on P6)

External connections:
=====================
             None.

How to build and run:
=====================
             Prepare hardware as explained in the Hardware Setup section.
             Build the project, load the executable to ADuCM4x50, and run it.

Expected Result:
=================
             Message "All done!" should be printed to the terminal

References:
===========
             ADuCM4x50 Hardware Reference Manual
