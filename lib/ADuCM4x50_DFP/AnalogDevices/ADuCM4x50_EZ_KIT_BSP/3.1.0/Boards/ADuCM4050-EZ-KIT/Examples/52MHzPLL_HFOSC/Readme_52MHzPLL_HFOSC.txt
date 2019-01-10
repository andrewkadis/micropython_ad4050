            Analog Devices, Inc. ADuCM4x50 Application Example

Project Name: 52MHzPLL_HFOSC

Description:  This example programs the ADuCM4050 to operate at 52 MHz
 

Overview:
=========



User Configuration Macros:
==========================
    None
	

Hardware Setup:
===============
    There is no special hardware setting to manage other than default jumper settings for the EZ-Kit.
    
 
External connections:
=====================
    Emulator connection required. This test requires a live debugger session to run because it uses
    semi-hosted printf output to write to the Terminal I/O window. Therefore, the test will hard fault
    on the first printf write attempt if no debugger is attached.
    
    No other external connections are required.

Known Issues:
=====================
    After programming the part to operate at 52 MHz a subsequent debug session may result in an error message
    Power cycling the board will resolve any issues.
    
How to build and run:
=====================
    Open the project, build, load and run the example.  Open the terminal to view output.

Expected Result:
=====================
    Prints "All Done!" if success or Failure message (with result code and message) and exits.
		
  
References:
===========
    ADuCM4x50 Hardware Reference Manual
