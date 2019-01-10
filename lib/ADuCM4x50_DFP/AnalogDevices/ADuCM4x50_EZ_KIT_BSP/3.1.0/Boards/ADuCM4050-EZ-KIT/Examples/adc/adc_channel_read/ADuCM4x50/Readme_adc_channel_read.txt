         Analog Devices, Inc. ADuCM4x50 Application 


Overview:
=========    
  This example demonstrate how to use the ADC Controller driver. 
  The example uses the ADC to sample the input signal at channel 0 and write the acquired samples 
  to a file (when the WRITE_SAMPLES_TO_FILE macro is defined). 
  This examples operates on non-blocking mode. 

User Configuration Macros:
==========================
    This example sets ADI_ADC_ENABLE_MULTI_ACQUIRE to 1, in adi_adc_config.h, which 
    means that DMA transfers will be used to extract data from the ADC. 
    Using DMA is the advised method of data transfer when:
     - reading multiple channels at the same time
     - successively reading multiple values from the same channel
     - or a combination of both.  
     
    Setting this macro to 0 will force interrupt-driven data transfers, which
    is best-suited to reading a single values from a single channel.
    
    The number of samples to read can be changed in adc_channel_read.h, using
    the ADC_NUM_SAMPLES macro.  The default is 100.
    
Hardware Setup:
===============
    ADuCM4x50 EZ Kit configured with default settings.

External connections:
=====================
    Connect a signal generator signal to pin 0 of J5, marked A0.  Ensure that the 
    signal does not exceed 2.5V (Internal reference set in the example).  
    
    A suggested input signal would be a 1KHz sine wave, offset by 1.25V with an 
    amplitude of 1.25V.  This will produce an input range of 0V to 2.5V. The 
    collected readings by the ADC will be an unsigned decimal between 0 and 4095, 
    i.e. the 12-bit ADC range.  
    
    Emulator connection is required. This test requires a live debugger session 
    to run because it uses semi-hosted printf output to write to the 
    Terminal I/O window. Therefore, the test will hard fault on the first printf 
    write attempt if no debugger is attached.  The connection is also required 
    for File I/O of the gathered results.

   
How to build and run:
=====================
    Build the project, load the executable to ADuCM4x50, open a "Terminal I/O" window and run it. 

Expected Result:
=====================
    Upon successful completion the example will produce an output file called ADC_Out.dat in:
      .\ADuCM4x50\iar - for the IAR environment.
      .\ADuCM4x50\cces\Debug or Release - for the CCES environment.
      Note: Saving of ADC data is not performed in Keil as it currently does not support File IO.
      However, the data can be seen in memory, by viewing the contents of the "ADC_DataBuffer" 
      array.

    The ADC_Out.dat file will contain the collected samples in a single column, and can be opened 
    using many text editor programs.  It can also be easily opened by MS Excel as a delimited 
    data file.  Data can also be plotted graphically using MS Excel, "Line Chart" being the most
    useful for this example - please consult the Help section in MS Excel for assistance on how
    to do this.
    
    
References:
===========
    ADuCM4x50 Hardware Reference Manual
