       Analog Devices, Inc. ADuCM4x50 Application Example


Project Name: Readme_MasterSlave_loopback

Overview:
=========
              This example shows how to use SPI device for transmitting/receiving the 
              data both in master and slave mode. The example opens two a SPI device, 
              configured as master and slave. The transmit buffer is filled with known
              values into it and submitted to the SPI  Master for transfer to Slave SPI. 
              Upon receiving the data, Slave will transmit back the same buffer to Master 
              which will validate it with the original buffer it transmitted. Thus both 
              Master and Slave mode operation  are  demonstrated using this example.
              
              This example uses NON blocking mode of operation for the Slave. It use
              both non-blocking and blocking modes of operation for the Master.


User Configuration Macros:
==========================

              This example relies on the configuration of SPI1 as a SPI Slave device.
              The file adi_spi_config has been included into the project. In this file
              the macro 
                   ADI_SPI1_MASTER_MODE
              has been changed from it default setting of '1' (master mode) to '0' (slave mode).
              


Hardware Setup:
===============

              This example requires the ADZ-BRKOUT-EX3 extender card. This product does
              not come with the ADuCM4050 EZ-Kit and can be purchased online. Once the 
              extender card is obtained, make the following connections:
			  
			  * The JP9 jumper should be disconnected. This jumper routes SPI1 signals to the RGB LED.
              * Connect J1 of the ADZ-BRKOUT-EX3 to P1A of the ADuCM4050 EZ-Kit.
                
              Then make the following connections on the ADZ-BRKOUT-EX3:
			  
              * Connect P6.92 (SPI0_CLOCK) to P5.82 (SPI1_CLOCK).
              * Connect P6.91 (SPI0_MISO) to P5.83 (SPI1_MISO).
              * Connect P5.90 (SPI0_MOSI) to P5.84 (SPI1_MOSI).
              * Connect P5.54 (SPI0_CS0) to P5.39 (SPI1_CS0).

External connections:
=====================
               Emulator connection required.  	This test requires a live debugger session to run because it uses
               semi-hosted printf output to write to the Terminal I/O window.  Therefore, the test will hard fault
               on the first printf write attempt if no debugger is attached.  This can be seen on the logic analyzer
               as a failure in steps 2 and 3, below, due to the missing debugger interrupt handler (i.e., emulator
               attached) to handle the semi-hosted printf calls (debugger interrupts).


How to build and run:
=====================    
              Prepare hardware as explained in the Hardware Setup section.
              Build the project, load the executable to ADuCM4x50, and run it.

Expected Result:
================= 
              After successful run the example prints out "All Done" in the output terminal.

References:
===========
              ADuCM4x50 Hardware Reference Manual
