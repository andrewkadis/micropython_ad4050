A. Kadis
25/1/2019

# 'Frozen' Python Bytecode

This directory allows us to run 'frozen' python scripts. These are scripts which have been compiled to python bytecode at compile time and are then executed on the ad4050.

This functionality is still immmature (ie: fragile), so using it at the moment is quite prescriptive. You've been warned...

## Scripts

The script to execute should be in the file 'frozentest.py;. This is the only file which shall be executed. All other files are merely example and have been given the suffix '.frz' to indicate such. They are not used and their contents hshould be copied across manually to 'frozentest.py' if you wish to execute them.

# Warnings

## Built-in Micropython compiler
Due to the immaturity of the port, the only way in which to run these scripts is to disable the Micropython Compiler on the host. Hence set `MICROPY_ENABLE_COMPILER` to 0. This will force the module to run at startup.

## Warnings
The port is still immature, so it throws out a lot of rubbish when executing over the UART (it says maximum recursion depth exceeded and whatnot). However it does still work. Looking into this

## Exceeding heap limit
Depending on the script complexity, it is possible to exceed the heap limit when compiling bytecode. This warning will be flagged at compile-time.

You can increase the limit by doing the following:
Simply change the line 
`../../mpy-cross/mpy-cross -X heapsize=8000 modules/frozentest.py -o $(MOD_BIN)/frozentest.mpy` 
to 
`../../mpy-cross/mpy-cross -X heapsize=8000 modules/frozentest.py -o $(MOD_BIN)/frozentest.mpy` in the main Makefile

