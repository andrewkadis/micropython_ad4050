################################################################################
# A. Kadis, Uni of Cambridge Physical Computing Lab 28th December 2018
# Based on a makefile auto-genreated from CrossCOre originally but now heavily modified
################################################################################

###########################################################################
######### Toolchain location - SET APPROPRIATELY !!!!! ####################
###########################################################################
# ARM GCC root directory
ARM_GCC_ROOT        = /usr/local/Cellar/arm-none-eabi-gcc/7-2018-q2-update
# Use the ARM gcc compiler rather than native gcc (Clang on OSX)
CC='/usr/local/Cellar/arm-none-eabi-gcc/7-2018-q2-update/bin/arm-none-eabi-gcc'

# Relative directory addresses for COTS libraries
# Root Analog Devices directory
ANALOG_DEVICES_ROOT = ../../lib/ADuCM4x50_DFP/AnalogDevices
# ARM CMSIS Root Directory
ARM_CMSIS_ROOT      = ../../lib/ADuCM4x50_DFP/ARM/
# Micropython Root Directory
MICROPYTHON_ROOT    = ../..
# include py core make definitions
include $(MICROPYTHON_ROOT)/py/py.mk


# Overwritten Warnings - disabled these in the compiler so don't get warnings at runtime.
# Naughty, naughty, Analog Devices, really shouldn't be shipping your code with these warnings in them
DISABLED_WARNINGS=-Wno-format-overflow
# Set our compilation Flags here for all included libraries + source files
CFLAGS=-Wall $(DISABLED_WARNINGS) -g -O0 -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -D__EVCOG__ -D_RTE_ -D__ADUCM4050__ -D__SILICON_REVISION__=0xffff $(INCLUDE_PATH) -Wall -c -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" 



# Include Directories
INCLUDE_PATH = 
# ARM CMSIS
INCLUDE_PATH += -I$(ARM_CMSIS_ROOT)/CMSIS/5.4.0/CMSIS/Core/Include
INCLUDE_PATH += -I$(ARM_CMSIS_ROOT)/CMSIS/5.4.0/CMSIS/RTOS2/RTX/Library/IAR/IDE/
# DFP for the microcontroller
INCLUDE_PATH += -I$(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Include
INCLUDE_PATH += -I$(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Include/drivers/adc
INCLUDE_PATH += -I$(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Include/drivers/beep
INCLUDE_PATH += -I$(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Include/drivers/crc
INCLUDE_PATH += -I$(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Include/drivers/crypto
INCLUDE_PATH += -I$(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Include/drivers/dma
INCLUDE_PATH += -I$(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Include/drivers/flash
INCLUDE_PATH += -I$(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Include/drivers/general
INCLUDE_PATH += -I$(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Include/drivers/i2c
INCLUDE_PATH += -I$(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Include/drivers/pwr
INCLUDE_PATH += -I$(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Include/drivers/rng
INCLUDE_PATH += -I$(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Include/drivers/rtc
INCLUDE_PATH += -I$(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Include/drivers/spi
INCLUDE_PATH += -I$(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Include/drivers/sport
INCLUDE_PATH += -I$(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Include/drivers/tmr
INCLUDE_PATH += -I$(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Include/drivers/uart
INCLUDE_PATH += -I$(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Include/drivers/wdt
INCLUDE_PATH += -I$(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Include/drivers/xint
INCLUDE_PATH += -I$(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Include/config
# BSP for the Eval Board
INCLUDE_PATH += -I$(ANALOG_DEVICES_ROOT)/EV-COG-AD4050LZ_BSP/3.1.0/Boards/EV-COG-AD4050LZ/Examples/drivers/gpio/blinky_example/EV-COG-AD4050LZ/cces/system
INCLUDE_PATH += -I$(ANALOG_DEVICES_ROOT)/EV-COG-AD4050LZ_BSP/3.1.0/Boards/EV-COG-AD4050LZ/Examples/drivers/gpio/blinky_example/EV-COG-AD4050LZ/cces/RTE"
INCLUDE_PATH += -I$(ANALOG_DEVICES_ROOT)/EV-COG-AD4050LZ_BSP/3.1.0/Boards/EV-COG-AD4050LZ/Examples/drivers/gpio/blinky_exampleEV-COG-AD4050LZ/cces/RTE/Device/ADuCM4050"
# Micropython
INCLUDE_PATH += -I$(MICROPYTHON_ROOT)
INCLUDE_PATH += -I$(MICROPYTHON_ROOT)/py
INCLUDE_PATH += -I$(MICROPYTHON_ROOT)/ports/ad4050
INCLUDE_PATH += -I$(MICROPYTHON_ROOT)/mpy-cross/build
export INCLUDE_PATH



# Libraries
# ARM GCC Libraries
LIBRARIES = 
LIBRARIES += $(ARM_GCC_ROOT)/gcc/arm-none-eabi/lib/thumb/v7e-m/fpv4-sp/hard/libnosys.a
LIBRARIES += $(ARM_GCC_ROOT)/gcc/arm-none-eabi/lib/thumb/v7e-m/fpv4-sp/hard/libc.a
LIBRARIES += $(ARM_GCC_ROOT)/gcc/arm-none-eabi/lib/thumb/v7e-m/fpv4-sp/hard/libm.a
export LIBRARIES
# Wrap up into a single variable to capture both location and library
export LIBS = $(LIBRARIES)



##########################################################################
########################### Executable Target ############################
##########################################################################

# Executable Name
EXE := port

# All Target
all: dir DFP mpy sys src exe

# Directories to put generated files into
BIN     = ./bin
DFP_BIN = $(BIN)/dfp
MPY_BIN = $(BIN)/mpy
SYS_BIN = $(BIN)/sys
SRC_BIN = $(BIN)/src
dir: 
	mkdir -p $(BIN)
	mkdir -p $(DFP_BIN)
	mkdir -p $(MPY_BIN)
	mkdir -p $(SYS_BIN)
	mkdir -p $(SRC_BIN)



##########################################################################
############ Drivers - DFP (Device Family Pack) for ADuCM4x50 ############
##########################################################################

# DFP Layer - calls rules for individual drivers defined explicitly below
DFP: drivers startup

# Drivers come from DFP - we load them all in here
DRIVER_OBJS = $(DFP_BIN)/adi_adc.o $(DFP_BIN)/adi_beep.o $(DFP_BIN)/adi_crc.o $(DFP_BIN)/adi_crypto.o $(DFP_BIN)/adi_dma.o $(DFP_BIN)/adi_flash.o $(DFP_BIN)/adi_gpio.o $(DFP_BIN)/adi_i2c.o $(DFP_BIN)/adi_pwr.o $(DFP_BIN)/adi_rng.o $(DFP_BIN)/adi_rtc.o $(DFP_BIN)/adi_spi.o $(DFP_BIN)/adi_sport.o $(DFP_BIN)/adi_tmr.o $(DFP_BIN)/adi_uart.o $(DFP_BIN)/adi_wdt.o $(DFP_BIN)/adi_xint.o $(DFP_BIN)/common.o
drivers: $(DRIVER_OBJS)

bin/dfp/adi_adc.o: $(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Source/drivers/adc/adi_adc.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/dfp/adi_beep.o: $(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Source/drivers/beep/adi_beep.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/dfp/adi_crc.o: $(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Source/drivers/crc/adi_crc.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/dfp/adi_crypto.o: $(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Source/drivers/crypto/adi_crypto.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/dfp/adi_dma.o: $(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Source/drivers/dma/adi_dma.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/dfp/adi_flash.o: $(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Source/drivers/flash/adi_flash.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/dfp/adi_gpio.o: $(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Source/drivers/gpio/adi_gpio.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/dfp/adi_i2c.o: $(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Source/drivers/i2c/adi_i2c.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/dfp/adi_pwr.o: $(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Source/drivers/pwr/adi_pwr.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/dfp/adi_rng.o: $(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Source/drivers/rng/adi_rng.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/dfp/adi_rtc.o: $(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Source/drivers/rtc/adi_rtc.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/dfp/adi_spi.o: $(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Source/drivers/spi/adi_spi.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/dfp/adi_sport.o: $(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Source/drivers/sport/adi_sport.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/dfp/adi_tmr.o: $(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Source/drivers/tmr/adi_tmr.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/dfp/adi_uart.o: $(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Source/drivers/uart/adi_uart.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/dfp/adi_wdt.o: $(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Source/drivers/wdt/adi_wdt.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/dfp/adi_xint.o: $(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Source/drivers/xint/adi_xint.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/dfp/common.o: $(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Source/common.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



# System startup code also comes from DFP
STARTUP_OBJS = $(DFP_BIN)/startup_ADuCM4050.o $(DFP_BIN)/system_ADuCM4050.o $(DFP_BIN)/reset_ADuCM4050.o
startup: $(STARTUP_OBJS)

bin/dfp/startup_ADuCM4050.o: $(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Source/GCC/startup_ADuCM4050.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/dfp/system_ADuCM4050.o: $(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Source/system_ADuCM4050.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

# Reset Assembler script
bin/dfp/reset_ADuCM4050.o: $(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Source/GCC/reset_ADuCM4050.S
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Assembler'
	$(CC) $(CFLAGS) -c -x assembler-with-cpp -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



##########################################################################
######################### Micropython Files ##############################
##########################################################################

# Files from the micropython source
MPY_OBJS = $(MPY_BIN)/compile.o $(MPY_BIN)/runtime.o $(MPY_BIN)/repl.o $(MPY_BIN)/gc.o $(MPY_BIN)/pyexec.o $(MPY_BIN)/mpstate.o $(MPY_BIN)/qstr.o $(MPY_BIN)/obj.o $(MPY_BIN)/objdict.o $(MPY_BIN)/objtype.o
mpy: $(MPY_OBJS)

# Majority of micro-python source comes from ../../py
bin/mpy/compile.o : ../../py/compile.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/runtime.o : ../../py/runtime.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/repl.o : ../../py/repl.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/gc.o : ../../py/gc.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/mpstate.o : ../../py/mpstate.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/qstr.o : ../../py/qstr.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/obj.o : ../../py/obj.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objdict.o : ../../py/objdict.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objtype.o : ../../py/objtype.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

# Executable comes from the lib directory
bin/mpy/pyexec.o : ../../lib/utils/pyexec.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


##########################################################################
############################ System Files ################################
##########################################################################

# System Files - Example have these separate to the DFP so we maintain this separation here
SYS_OBJS = $(SYS_BIN)/adi_initialize.o 
sys: $(SYS_OBJS)

# Each subdirectory must supply rules for building sources it contributes
bin/sys/adi_initialize.o : ./sys/adi_initialize.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



##########################################################################
############################ Source Files ################################
##########################################################################

# Source Files - call whatever we've written
SRC_OBJS = $(SRC_BIN)/$(EXE).o  $(SRC_BIN)/PinMux.o
src: $(SRC_OBJS)

# Executable
$(SRC_BIN)/$(EXE).o: ./src/$(EXE).c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

# Other src files...
$(SRC_BIN)/PinMux.o: ./src/PinMux.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



##########################################################################
############################ Source Files ################################
##########################################################################

# # Source Files - call whatever we've written
# # main.o = main.o  $(SRC_BIN)/PinMux.o
# python: main.o

# # Executable
# main.o: ./src/main.c
# 	@echo 'Building file: $<'
# 	@echo 'Invoking: ARM GCC Compiler'
# 	$(CC) $(CFLAGS) -o  "$@" "$<"
# 	@echo 'Finished building: $<'
# 	@echo ' '

# # Other src files...
# $(SRC_BIN)/PinMux.o: ./src/PinMux.c
# 	@echo 'Building file: $<'
# 	@echo 'Invoking: ARM GCC Compiler'
# 	$(CC) $(CFLAGS) -o  "$@" "$<"
# 	@echo 'Finished building: $<'
# 	@echo ' '



##########################################################################
############################## Linker ####################################
##########################################################################

# Call Linker to generated Executable
exe: $(USER_OBJS) $(SRC_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM GCC Linker'
	arm-none-eabi-gcc -T$(ANALOG_DEVICES_ROOT)/ADuCM4x50_DFP/3.2.0/Source/GCC/ADuCM4050.ld -Wl,--gc-sections -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -o  '$(BIN)/$(EXE).elf' -Xlinker -Map='$(BIN)/$(EXE).map' $(DRIVER_OBJS) $(MPY_OBJS) $(STARTUP_OBJS) $(SYS_OBJS) $(SRC_OBJS) $(LIBS) 
	# Generate srec, bin and hex formats
	arm-none-eabi-objcopy -Osrec '$(BIN)/$(EXE).elf' '$(BIN)/$(EXE).srec'
	arm-none-eabi-objcopy -Oihex '$(BIN)/$(EXE).elf' '$(BIN)/$(EXE).hex'
	arm-none-eabi-objcopy -Obinary '$(BIN)/$(EXE).elf' '$(BIN)/$(EXE).bin'
	@echo 'Finished building target: $@'
	@echo ' '



##########################################################################
############################## Clean #####################################
##########################################################################

# Cleanup
RM := rm -rf
clean:
	-$(RM) ./$(BIN).elf ./$(BIN).srec ./$(BIN).hex ./$(BIN).bin ./$(BIN).map
	-$(RM) $(DFP_BIN)/*.d $(DFP_BIN)/*.o
	-$(RM) $(SYS_BIN)/*.d $(SYS_BIN)/*.o
	-$(RM) $(SRC_BIN)/*.d $(SRC_BIN)/*.o
	-$(RM) $(BIN) $(DFP_BIN) $(SYS_BIN) $(SRC_BIN)

.PHONY: all clean dependents

-include ../makefile.targets
