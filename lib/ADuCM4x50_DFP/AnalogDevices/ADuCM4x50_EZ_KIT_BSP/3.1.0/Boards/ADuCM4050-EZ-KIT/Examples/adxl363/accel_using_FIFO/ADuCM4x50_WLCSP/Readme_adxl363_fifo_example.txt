            Analog Devices, Inc. ADuCM4x50 Application Example

Project Name: accel_fifo

Description:  Demonstrate how to use the ADXL363 driver, specifically using the on-chip FIFO 
              to collect data.
 

Overview:
=========
    In this example, the ADXL363 driver is used to configure the ADXL363 to produce a stream 
    of data at a known rate, store that data into the on-chip FIFO, and then produce an 
    interrupt when a limit is reached.  The application will then query the number of samples 
    held in the FIFO, and then extract that amount. 
    

User Configuration Macros:
==========================
    Test configuration in accel_fifo.c: 
    TEST_ITERATIONS can configure how many times the fifo is emptied.
    
    Hardware configuration in accel_fifo.c:
    ADXL363_INTx_GPIO_PORT can specify which GPIO port to configure for INT1 or INT2 
    ADXL363_INTx_GPIO_PIN  can specify which GPIO pin to configure for INT1 or INT2

    Hardware configuration in adi_adxl363_config.h:
    ADXL363_CFG_SPI_DEV_NUM and ADXL363_CFG_SPI_DEV_CS to set the SPI and chip select lines used.
    
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
    The following should be printed to the terminal:
      "Entering FIFO mode
      Fifo successfully emptied
      Fifo successfully emptied
      Fifo successfully emptied
      Fifo successfully emptied
      Fifo successfully emptied
      Fifo successfully emptied
      Fifo successfully emptied
      Fifo successfully emptied
      Fifo successfully emptied
      Fifo successfully emptied
      All done!"

References:
===========
    ADuCM4x50 Hardware Reference Manual
