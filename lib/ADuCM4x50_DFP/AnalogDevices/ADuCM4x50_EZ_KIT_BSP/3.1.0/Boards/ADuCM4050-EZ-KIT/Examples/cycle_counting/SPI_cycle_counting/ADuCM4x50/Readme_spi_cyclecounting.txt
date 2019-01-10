         Analog Devices, Inc. ADuCM4x50 Application Example

Project Name: spi_cyclecounting

Description:
=========== 
             This example demonstrates how to obtain cycle counts for the SPI driver.
             
               

Overview:
=========
             The cycle counting APIs are used to obtain cycle counts for the SPI ISR. The cycle counting APIs are also
             used to add an application specified function for which cycle counts are to be obtained. In this
             example the cycle counts for non blocking and blocking mode are recorded and evaluated.


User Configuration Macros:
==========================
             To configure cycle counting the Cycle counting configuration the file adi_cycle_counting_config.h
             should be copied to the project directory and then modified. Specifically, the following macros
             must be configured

                      ADI_CYCLECOUNT_ENABLED                   Must be set to '1' to enable cycle counting
                      ADI_CYCLECOUNT_SPI_ISR_ENABLED           Must be set to '1' to enable SPI ISR cycle counts
                      ADI_CYCLECOUNT_NUMBER_USER_DEFINED_APIS  Changed to '1' for this example
                                                               The example will add one application specified API
                                                               to the list of API/ISRs for which cycle counts can
                                                               be obtained.

            SPI_BIT_RATE
               By default the example uses a bit rate of 100 KHz.
               
Hardware Setup:
===============  
             The user must connect the MISO and MOSI pins of the SPI2 device to loop the data
             This is be done as follows:

             * Connect J5.8 (SPI2_MISO) to J5.7 (SPI2_MOSI).


External connections:
=====================
             None.             

How to build and run:
=====================    
             Prepare hardware as explained in the Hardware Setup section.
             Build the project, load the executable to ADuCM4x50, and run it.


Expected Result:
=================    
             The cycle counts for both the SPI ISR and for the body of 'main' are printed to the console.
             Should see "All Done" after the execution is complete.
             
             Debug Mode Results:
             =================             
             At the default SPI bit rate of 100 KHz this example will display results similar to the following
             
 
                                          Adjusted Cycle Counts          Unadjusted Cycles Counts         No. Samples
                                     _____________________________      ____________________________      ___________

                ISR/API              Minimum    Maximum    Average      Minimum    Maximum    Average
                        ISR_SPI           222        291        243          222        291        243       2048
                       Blocking        219237     219237     219237       742463     742463     742463          1
                   Non-blocking           664        664        664          664        664        664          1

            The results show that the SPI ISR is triggered a total of 2048 times or 1024 times (which is thee size of the BUFFER, i.e. 
            one interrupt per character) for both modes of operation. 
            
            Note that Blocking mode consumes an adjusted 664 cycles. The 1024-byte transaction is not done at that point, but the application 
            would be able to peform other tasks while the transaction completes.
            Blocking mode, on the other hand, consumes an adjusted 219,237 cycles. This number represents the number of cycles
            spent waiting for the transaction to finish MINUS the cycles consumed by the SPI ISR (and by any other ISR, e.g. the
            Systick ISR). The Blocking mode's unadjusted count is 742,463. This represents the total elapsed time for the blocking call.
            
            One can conclude, therefore, that the non-blocking call would have approximately 219,237 - 664 = 218,573 cycles with which
            to perform some useful work versus the blocking mode of operation.
            
            Note that this discussion is relevant to only for non-RTOS based applications. For an RTOS based application any blocking mode
            operation would yeild the processor while waiting for the transaction to end.

            
            
            If the SPI bit rate is changed to 1 MHz the following results would be obtained


                                          Adjusted Cycle Counts          Unadjusted Cycles Counts         No. Samples
                                     _____________________________      ____________________________      ___________
                ISR/API              Minimum    Maximum    Average      Minimum    Maximum    Average
                        ISR_SPI           222        291        243          222        291        243       2048
                       Blocking        155458     155458     155458       678684     678684     678684          1
                   Non-blocking        155299     155299     155299       678456     678456     678456          1


           What this shows is that, for both modes, the SPI ISR is firing at such a high frequency that the application
           spends all of its time in the SPI ISR.

References:
===========
             ADuCM4x50 Hardware Reference Manual
