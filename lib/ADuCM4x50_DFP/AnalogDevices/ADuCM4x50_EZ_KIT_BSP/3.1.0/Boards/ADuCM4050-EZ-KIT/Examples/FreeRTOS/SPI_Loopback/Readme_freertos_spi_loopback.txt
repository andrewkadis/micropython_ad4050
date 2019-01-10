         Analog Devices, Inc. ADuCM4x50 Application Example

Project Name: Readme_freertos_spi_loopback

Description:
=========== 
             The primary purpose of this example is to show how to integrate the BSP with the FreeRTOS V9.0.0.
             
             This example also demonstrates how to use the SPI driver in the context of the FreeRTOS
             

Overview:
=========
              This example demonstrates how to integrate the FreeRTOS into the ADuCM4x50 BSP.
              It also, optionally, includes the FreeRTOS+Trace code.
 
              To run the example you must first download the FreeRTOS source code V9.0.0 from
              http://www.freertos.org.
              
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
              
FreeRTOS Setup:
===============
              The FreeRTOS is configured by defining macros in the FreeRTOSConfig.h file.
              
           
              Since FreeRTOS uses the Cortex-M's BASEPRI register to create critical regions,
              the application must set
              
              #define configMAX_SYSCALL_INTERRUPT_PRIORITY    (7)
              
              to a non-zero value and it should be set to the lowest hardware priority. 
              
              This also means that the application must also change all
              of the default Cortex-M Hardware priorities to a value equal to or greater than 
              configMAX_SYSCALL_INTERRUPT_PRIORITY. This is accomplished in the routine
              
                   assignInterruptPriorities()
              
              which is called from main() before any FreeRTOS initialization.
              
FreeRTOS Setup IAR:
===================
              After downloading the source code your must set two environment variables which will be
              used by the IAR environment to locate the FreeRTOS source code.
              
			  Download path:  C:\FreeRTOS

              Environment Variable Value
              ADI_FREERTOS_PATH        The full path to the source directory. E.g.
                                       C:\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS\Source
              ADI_FREERTOS_PATH_PLUS   The full path to the FreeRTOS-Plus-Trace directory
                                       C:\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS-Plus\Source\FreeRTOS-Plus-Trace
 
              If you want to use the FreeRTOS Trace capabilities you need to modify the following line
              which is in the FreeRTOSConfig.h file
              
                    #define configUSE_TRACE_FACILITY 0
              
              changing this to
              
                    #define configUSE_TRACE_FACILITY 1
              
              will enable FreeRTOS Trace support.
                                       
FreeRTOS Setup CCES:
====================                                    
              
              After loading freertos_spi_loopback, the FreeRTOS folder has to be linked with the project. 
              
              This is done by the following steps:

              1. Drag and Drop the FreeRTOS folder (FreeRTOSv9.0.0\FreeRTOS) onto the freertos_spi_loopback project.
              2. Select "Link to files and folders" in File and Folder Operation window.
              3. Check the "Create link locations relative to:" box and select "PROJECT_LOC" from the drop down
                 menu.
              4. Click "ok".
               
              You should end up with a project hierarchy that looks like the following:
                   
                   freertos_spi_loopback\FreeRTOS
                   freertos_spi_loopback\FreeRTOS\Source
                   freertos_spi_loopback\FreeRTOS\Demo
                   freertos_spi_loopback\FreeRTOS\License
                   
              You then need to take the following steps
              
              1. The entire 'portable' directory should be excluded from the build
                 Right click on the 'portable' directory
                 Select 'Resource Configurations' -> 'Exclude from Build ...'
              2. The 'portable -> ARM_CM4F' should then be included in the build
              3. The 'Demo' directory should be excluded from the build
              
 FreeRTOS Setup Keil:
=====================                                     
              The FreeRTOS source files for the Keil environment have been added to this project's
              FreeRTOS folder
              
              1. The FreeRTOS folder contains the sources from FreeRTOS\FreeRTOSv9.0.0\FreeRTOS\Source
                 and from FreeRTOSv9.0.0\FreeRTOS\Source\portable\RVDS\ARM_CM4F

              2. The preprocessor options for C/C++ refer to 
                 C:\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS\Source\include
                 C:\FreeRTOS\FreeRTOSv9.0.0\FreeRTOS\Source\portable\RVDS\ARM_CM4F
                 
                 If the FreeRTOS sources are stored eleswhere, then these preprocessor options should
                 be changed to point to the correct directories. Also, the files contained in the 
                 FreeRTOS project group still assume the directory locations above, so you will need to 
                 manually change the path of each file (right-click on the file, select Options), or 
                 simply delete the contents of this group and re-add all the files.
                 
              3. There is a bug in the port.c file
                 In the function
                      BaseType_t xPortStartScheduler( void )
                 The following assert should be removed
                      configASSERT( ucMaxPriorityValue == ( configKERNEL_INTERRUPT_PRIORITY & ucMaxPriorityValue ) );
                 This assert assumes 8-bits of HW priority, but the ADuCM4x50 has only 3-bits for HW priorities      
                      
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
             Prepare hardware as explained in the Hardware Setup section.
             Build the project, load the executable to ADuCM4x50, and run it.


Expected Result:
=================    
             Should see "All Done" after the execution is complete.


References:
===========
             ADuCM4x50 Hardware Reference Manual
