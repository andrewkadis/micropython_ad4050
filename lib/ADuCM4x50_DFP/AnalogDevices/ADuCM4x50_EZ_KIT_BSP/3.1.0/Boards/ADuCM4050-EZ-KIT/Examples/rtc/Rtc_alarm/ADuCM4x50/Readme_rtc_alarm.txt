         Analog Devices, Inc. ADuCM4x50 Application 


Project: rtc_alarm

Description:   This example demonstrates how to use and configure the RTC device
               for generating the alarm periodical.


Overview:
=========    
  This example demonstrates how to use and configure the RTC device
  for generating the alarm periodical.

  The example tries to register a finite number RTC ALARM event defined by macro
  ADI_RTC_NUM_ALARMS (set to 3 by default). The RTC ALARM is configured for
  five seconds and the part is put into hibernation mode. The ALARM wakeup
  reports success to the console and RTC ALARM is reconfigured to five
  seconds until specified number of RTC ALARM event is registered. The core
  will stay in hibernation until ADI_RTC_NUM_ALARMS number of ALARM is received.

  The RTC driver supports only call back mode of operation to notify the user. 

User Configuration Macros:
==========================
    ADI_RTC_NUM_ALARMS which controls the number of alarms. 

Hardware Setup:
===============
    ADuCM4x50 EZ Kit configured with default settings.

External connections:
=====================
    None. 

How to build and run:
=====================
    Build the project, load the executable to ADuCM4x50, open a "Terminal Window" and run it. 
    
    Note: The example should be let to run till completion, until "All done!" is seen. If the execution is stopped midway, then it will lock up the board. 

    Unlocking the board: Hold the Boot Button(SW1) and Toggle the Reset Button(SW2)  twice and then release the Boot Button(SW1).  

Expected Result:
=====================
    Upon successful completion the example will print the following :

    Resetting clock
    New time is:
    Raw time: 1475855577
    UTC time: Fri Oct  7 15:52:57 2016

    ALARM example starting at:
    Raw time: 1475855577
    UTC time: Fri Oct  7 15:52:57 2016

    ALARM example complete at:
    Raw time: 1475855592
    UTC time: Fri Oct  7 15:53:12 2016

    All done!

              
References:
===========
    ADuCM4x50 Hardware Reference Manual
