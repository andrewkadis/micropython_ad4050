         Analog Devices, Inc. ADuCM4x50 Application 


Project Name: rtc_alarm


Description:  This example demonstrates how to configure an RTC device to generate the input capture and Sensor 
              Strobe features of RTC device.


Overview:
=========    
    This example demonstrates how to configure an RTC device to generate the input capture and Sensor Strobe features of RTC device.
    In this example the Sensor Strobe signal is looped back to the Input Capture Event signal. 

    The example enables the Sensor Strobe event with auto reload feature enabled.
    LED-4 is toggled for every Sensor Strobe event which occurs periodically.
    LED-5 is toggle for every Input Capture event.
    The Frequency of Sensor Strobe event can be controlled by using "AUTO_RELOAD_VALUE" macro which is
    defined in rtc_io_example.h.

    Note: The RTC driver supports only call back mode of operation to notify the application of events.

User Configuration Macros:
==========================
    AUTO_RELOAD_VALUE which controls the frequency of the events. 

Hardware Setup:
===============
    ADuCM4x50 EZ Kit configured with default settings.
    
    Connect RTC "Sensor Strobe pulse" (RTC1_SS1) to the GPIO "input capture signal" (P2.1) by adding a jumper on
    J6 connector across pins 4 and 5 (schematic numbering), which correlates to pins 3 and 4 (silk-screen numbering).
   
    Note: Schematic J6 pin numbering is 1-based, while the silk-screen equivalent numbering is 0-based.

    Also note that the pinmuxing code will MUX GPIO Port 2 Pin 11 as the RTC_SS1 signal.


External connections:
=====================
    None. 

How to build and run:
=====================
    Build the project, load the executable to ADuCM4x50, open a "Terminal Window" and run it. 
    
Expected Result:
=====================
    Upon successful completion the example will print the following to the terminal.
    "EVENT-NO : xxxx         : INPUT-COUNT SNAP-SHOT :  xxxx"
	                     .
						 .
						 .
	"EVENT-NO : xxxx         : INPUT-COUNT SNAP-SHOT :  xxxx"
    "All done!" 

References:
===========
    ADuCM4x50 Hardware Reference Manual
