       Analog Devices, Inc. ADuCM4x50 Application Example


Project Name: RTOS_Callback

Description:  This example demonstrates how to use the SPI device driver both in Master 
============  and Slave mode, with an RTOS and using Callbacks.


Overview:
=========
              The example transfers the content of one buffer to another 
              by using the two different SPI devices where one acts as the master while 
              another one as the slave. 
              
              Both the Master and the Slave are implemented as separate tasks. The Slave
              task must have a higher priority than the Master. This allows the Slave to
              setup its transactions in advance of the Master talking to it.
              
              Data received by "slave" is transferred back to 
              master SPI and validated with the original content transmitted by Master SPI.
              
              The example also demonstrates how to use Callbacks for both the Master
              and the Slave. 



User Configuration Macros:
==========================

              This example relies on the configuration of SPI1 as a SPI Slave device.
              The file adi_spi_config has been included into the project. In this file
              the macro 
                   ADI_SPI1_MASTER_MODE
              has been changed from it default setting of '1' (master mode) to '0' (slave mode).
              

Hardware Setup:
===============
             ADuCM4050 EZ Kit configured using default settings.
             
External connections:
=====================
              This example requires the ADZ-BRKOUT-EX3 extender card. This product does
              not come with the ADuCM4050 EZ-Kit and can be purchased online. Once the 
              extender card is obtained, make the following connections:
              * Connect J1 of the ADZ-BRKOUT-EX3 to P1A of the ADuCM4050 EZ-Kit.
                
              Then make the following connections on the ADZ-BRKOUT-EX3:
              * Connect P6.92 (SPI0_CLOCK) to P5.82 (SPI1_CLOCK).
              * Connect P6.91 (SPI0_MISO) to P5.83 (SPI1_MISO).
              * Connect P5.90 (SPI0_MOSI) to P5.84 (SPI1_MOSI).
              * Connect P5.54 (SPI0_CS0) to P5.39 (SPI1_CS0).

How to build and run:
=====================    
              Prepare hardware as explained in the Hardware Setup section and in
              the External Connection section.
              Build the project, load the executable to ADuCM4x50, and run it.

Expected Result:
================= 
              After successful run the example prints out "All Done" in the output terminal.

References:
===========
              ADuCM4x50 Hardware Reference Manual
