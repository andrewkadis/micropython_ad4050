Analog Devices DFP
=============================================================================

This repository contains the code required to up and running with the AD4050 Examples from Analog Devices

Original sources
================

Obtained from CrossCore using the inbuilt package manager and copied across


Original Readme from https://github.com/physical-computation/AD4050LZ-Port
==========================================================================

# AD4050LZ-Port
Repository to Hold Port of EV-COG-AD4050LZ to MacOSX without CrossCore

A. Kadis 24th December 2018

Notes:
  - This repository is to represent a 'current state' of the task of porting the proprietrary enviornments to compile code for the Analog Devices EV-COG-AD4050LZ Board to a Unix, non-proprietrary environment
  - This work has currently been tested for MacOS X, but it should extend to all UNIX environments with a bit of tweaking
  - At the initial commit, this repository is able to compile, flash and successfully run the blinky example form the SDK (quite a lot of porting work was done prior to the inital commit, but it was not mature enough for version control). This repository represents the first 'stablish' release.
  - Can exercise this by doing a make clean and a make all
  - Notet here are some absolute path references here, so they will not simply work ‘as-is’. Will have to change them to get it working.
  - Plan is as follows:
    - Get more examples working
    - Build up a more apporpriate makefile structure to pull in most of the Analog Device's SDK
    - Get the minimum Micropython base port working 
    - Cleanup as we go
  - I've put the SDKs taken directly from the vendors (in this case ARM + Analog Devices) directly in an unmodified 'cots'


## Demo

Instructions to try it out, tryout 'port' which is the HelloWorld program. It also represents the latest and greatest makefile as of 3rd Jan 2019:

`cd ./projects/port/`

Ensure that the first 2 lines of the Makefile point to the appropriate Addresses, ARM_GCC_ROOT and CC

`make clean && make all`

Now Program it using the JLink using the following commands:
```
JLinkExe
connect
ADUCM4050
SWD
Default Speed
erase all
loadfile ./bin/port.srec
```

You should now have a helloworld program transmitting over the USB-Uart at 9600 baud