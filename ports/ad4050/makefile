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
MPY_OBJS = $(MPY_BIN)/argcheck.o $(MPY_BIN)/asmarm.o $(MPY_BIN)/asmbase.o $(MPY_BIN)/asmthumb.o $(MPY_BIN)/asmx64.o $(MPY_BIN)/asmx86.o $(MPY_BIN)/asmxtensa.o $(MPY_BIN)/bc.o $(MPY_BIN)/binary.o $(MPY_BIN)/builtinevex.o $(MPY_BIN)/builtinhelp.o $(MPY_BIN)/builtinimport.o $(MPY_BIN)/compile.o $(MPY_BIN)/emitbc.o $(MPY_BIN)/emitcommon.o $(MPY_BIN)/emitglue.o $(MPY_BIN)/emitinlinethumb.o $(MPY_BIN)/emitinlinextensa.o $(MPY_BIN)/emitnarm.o $(MPY_BIN)/emitnative.o $(MPY_BIN)/emitnthumb.o $(MPY_BIN)/emitnx64.o $(MPY_BIN)/emitnx86.o $(MPY_BIN)/emitnxtensa.o $(MPY_BIN)/formatfloat.o $(MPY_BIN)/frozenmod.o $(MPY_BIN)/gc.o $(MPY_BIN)/lexer.o $(MPY_BIN)/malloc.o $(MPY_BIN)/map.o $(MPY_BIN)/compile.o $(MPY_BIN)/runtime.o $(MPY_BIN)/repl.o $(MPY_BIN)/gc.o $(MPY_BIN)/pyexec.o $(MPY_BIN)/mpstate.o $(MPY_BIN)/qstr.o $(MPY_BIN)/obj.o $(MPY_BIN)/objdict.o $(MPY_BIN)/objtype.o $(MPY_BIN)/modarray.o $(MPY_BIN)/modcmath.o $(MPY_BIN)/modcollections.o $(MPY_BIN)/modgc.o $(MPY_BIN)/modio.o $(MPY_BIN)/modmath.o $(MPY_BIN)/modmicropython.o $(MPY_BIN)/modstruct.o $(MPY_BIN)/modsys.o $(MPY_BIN)/modthread.o $(MPY_BIN)/moduerrno.o $(MPY_BIN)/mpprint.o $(MPY_BIN)/mpstate.o $(MPY_BIN)/mpz.o $(MPY_BIN)/nativeglue.o $(MPY_BIN)/nlr.o $(MPY_BIN)/nlrsetjmp.o $(MPY_BIN)/nlrthumb.o $(MPY_BIN)/nlrx64.o $(MPY_BIN)/nlrx86.o $(MPY_BIN)/nlrxtensa.o $(MPY_BIN)/obj.o $(MPY_BIN)/objarray.o $(MPY_BIN)/objattrtuple.o $(MPY_BIN)/objbool.o $(MPY_BIN)/objboundmeth.o $(MPY_BIN)/objcell.o $(MPY_BIN)/objclosure.o $(MPY_BIN)/objcomplex.o $(MPY_BIN)/objdeque.o $(MPY_BIN)/objdict.o $(MPY_BIN)/objenumerate.o $(MPY_BIN)/objexcept.o $(MPY_BIN)/objfilter.o $(MPY_BIN)/objfloat.o $(MPY_BIN)/objfun.o $(MPY_BIN)/objgenerator.o $(MPY_BIN)/objgetitemiter.o $(MPY_BIN)/objint.o $(MPY_BIN)/objint_longlong.o $(MPY_BIN)/objint_mpz.o $(MPY_BIN)/objlist.o $(MPY_BIN)/objmap.o $(MPY_BIN)/objnamedtuple.o $(MPY_BIN)/objnone.o $(MPY_BIN)/objobject.o $(MPY_BIN)/objpolyiter.o $(MPY_BIN)/objproperty.o $(MPY_BIN)/objrange.o $(MPY_BIN)/objreversed.o $(MPY_BIN)/objset.o $(MPY_BIN)/objsingleton.o $(MPY_BIN)/objslice.o $(MPY_BIN)/objstr.o $(MPY_BIN)/objstringio.o $(MPY_BIN)/objstrunicode.o $(MPY_BIN)/objtuple.o $(MPY_BIN)/objtype.o $(MPY_BIN)/objzip.o $(MPY_BIN)/opmethods.o $(MPY_BIN)/parse.o $(MPY_BIN)/parsenum.o $(MPY_BIN)/parsenumbase.o $(MPY_BIN)/persistentcode.o $(MPY_BIN)/pystack.o $(MPY_BIN)/qstr.o $(MPY_BIN)/reader.o $(MPY_BIN)/repl.o $(MPY_BIN)/runtime.o $(MPY_BIN)/runtime_utils.o $(MPY_BIN)/scheduler.o $(MPY_BIN)/scope.o $(MPY_BIN)/sequence.o $(MPY_BIN)/showbc.o $(MPY_BIN)/smallint.o $(MPY_BIN)/stackctrl.o $(MPY_BIN)/stream.o $(MPY_BIN)/unicode.o $(MPY_BIN)/vm.o $(MPY_BIN)/vstr.o $(MPY_BIN)/warning
mpy: $(MPY_OBJS)

bin/mpy/argcheck.o : ../../py/argcheck.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/asmarm.o : ../../py/asmarm.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/asmbase.o : ../../py/asmbase.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/asmthumb.o : ../../py/asmthumb.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/asmx64.o : ../../py/asmx64.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/asmx86.o : ../../py/asmx86.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/asmxtensa.o : ../../py/asmxtensa.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/bc.o : ../../py/bc.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/binary.o : ../../py/binary.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/builtinevex.o : ../../py/builtinevex.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/builtinhelp.o : ../../py/builtinhelp.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/builtinimport.o : ../../py/builtinimport.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/compile.o : ../../py/compile.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/emitbc.o : ../../py/emitbc.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/emitcommon.o : ../../py/emitcommon.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/emitglue.o : ../../py/emitglue.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/emitinlinethumb.o : ../../py/emitinlinethumb.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/emitinlinextensa.o : ../../py/emitinlinextensa.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/emitnarm.o : ../../py/emitnarm.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/emitnative.o : ../../py/emitnative.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/emitnthumb.o : ../../py/emitnthumb.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/emitnx64.o : ../../py/emitnx64.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/emitnx86.o : ../../py/emitnx86.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/emitnxtensa.o : ../../py/emitnxtensa.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/formatfloat.o : ../../py/formatfloat.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/frozenmod.o : ../../py/frozenmod.c 
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

bin/mpy/lexer.o : ../../py/lexer.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/malloc.o : ../../py/malloc.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/map.o : ../../py/map.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/modarray.o : ../../py/modarray.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

# bin/mpy/modbuiltins.o : ../../py/modbuiltins.c 
# 	@echo 'Building file: $<'
# 	@echo 'Invoking: ARM GCC Compiler'
# 	$(CC) $(CFLAGS) -o  "$@" "$<"
# 	@echo 'Finished building: $<'
# 	@echo ' '

bin/mpy/modcmath.o : ../../py/modcmath.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/modcollections.o : ../../py/modcollections.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/modgc.o : ../../py/modgc.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/modio.o : ../../py/modio.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/modmath.o : ../../py/modmath.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/modmicropython.o : ../../py/modmicropython.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/modstruct.o : ../../py/modstruct.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/modsys.o : ../../py/modsys.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/modthread.o : ../../py/modthread.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/moduerrno.o : ../../py/moduerrno.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/mpprint.o : ../../py/mpprint.c 
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

bin/mpy/mpz.o : ../../py/mpz.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/nativeglue.o : ../../py/nativeglue.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/nlr.o : ../../py/nlr.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/nlrsetjmp.o : ../../py/nlrsetjmp.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/nlrthumb.o : ../../py/nlrthumb.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/nlrx64.o : ../../py/nlrx64.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/nlrx86.o : ../../py/nlrx86.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/nlrxtensa.o : ../../py/nlrxtensa.c 
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

bin/mpy/objarray.o : ../../py/objarray.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objattrtuple.o : ../../py/objattrtuple.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objbool.o : ../../py/objbool.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objboundmeth.o : ../../py/objboundmeth.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objcell.o : ../../py/objcell.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objclosure.o : ../../py/objclosure.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objcomplex.o : ../../py/objcomplex.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objdeque.o : ../../py/objdeque.c 
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

bin/mpy/objenumerate.o : ../../py/objenumerate.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objexcept.o : ../../py/objexcept.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objfilter.o : ../../py/objfilter.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objfloat.o : ../../py/objfloat.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objfun.o : ../../py/objfun.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objgenerator.o : ../../py/objgenerator.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objgetitemiter.o : ../../py/objgetitemiter.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objint.o : ../../py/objint.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objint_longlong.o : ../../py/objint_longlong.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objint_mpz.o : ../../py/objint_mpz.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objlist.o : ../../py/objlist.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objmap.o : ../../py/objmap.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objnamedtuple.o : ../../py/objnamedtuple.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objnone.o : ../../py/objnone.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objobject.o : ../../py/objobject.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objpolyiter.o : ../../py/objpolyiter.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objproperty.o : ../../py/objproperty.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objrange.o : ../../py/objrange.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objreversed.o : ../../py/objreversed.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objset.o : ../../py/objset.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objsingleton.o : ../../py/objsingleton.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objslice.o : ../../py/objslice.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objstr.o : ../../py/objstr.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objstringio.o : ../../py/objstringio.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objstrunicode.o : ../../py/objstrunicode.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/objtuple.o : ../../py/objtuple.c 
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

bin/mpy/objzip.o : ../../py/objzip.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/opmethods.o : ../../py/opmethods.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/parse.o : ../../py/parse.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/parsenum.o : ../../py/parsenum.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/parsenumbase.o : ../../py/parsenumbase.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/persistentcode.o : ../../py/persistentcode.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/pystack.o : ../../py/pystack.c 
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

bin/mpy/reader.o : ../../py/reader.c 
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

bin/mpy/runtime.o : ../../py/runtime.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/runtime_utils.o : ../../py/runtime_utils.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/scheduler.o : ../../py/scheduler.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/scope.o : ../../py/scope.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/sequence.o : ../../py/sequence.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/showbc.o : ../../py/showbc.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/smallint.o : ../../py/smallint.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/stackctrl.o : ../../py/stackctrl.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/stream.o : ../../py/stream.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/unicode.o : ../../py/unicode.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/vm.o : ../../py/vm.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/vstr.o : ../../py/vstr.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bin/mpy/warning.o : ../../py/warning.c 
	@echo 'Building file: $<'
	@echo 'Invoking: ARM GCC Compiler'
	$(CC) $(CFLAGS) -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '













# # Majority of micro-python source comes from ../../py
# bin/mpy/compile.o : ../../py/compile.c 
# 	@echo 'Building file: $<'
# 	@echo 'Invoking: ARM GCC Compiler'
# 	$(CC) $(CFLAGS) -o  "$@" "$<"
# 	@echo 'Finished building: $<'
# 	@echo ' '

# bin/mpy/runtime.o : ../../py/runtime.c 
# 	@echo 'Building file: $<'
# 	@echo 'Invoking: ARM GCC Compiler'
# 	$(CC) $(CFLAGS) -o  "$@" "$<"
# 	@echo 'Finished building: $<'
# 	@echo ' '

# bin/mpy/repl.o : ../../py/repl.c 
# 	@echo 'Building file: $<'
# 	@echo 'Invoking: ARM GCC Compiler'
# 	$(CC) $(CFLAGS) -o  "$@" "$<"
# 	@echo 'Finished building: $<'
# 	@echo ' '

# bin/mpy/gc.o : ../../py/gc.c 
# 	@echo 'Building file: $<'
# 	@echo 'Invoking: ARM GCC Compiler'
# 	$(CC) $(CFLAGS) -o  "$@" "$<"
# 	@echo 'Finished building: $<'
# 	@echo ' '

# bin/mpy/mpstate.o : ../../py/mpstate.c 
# 	@echo 'Building file: $<'
# 	@echo 'Invoking: ARM GCC Compiler'
# 	$(CC) $(CFLAGS) -o  "$@" "$<"
# 	@echo 'Finished building: $<'
# 	@echo ' '

# bin/mpy/qstr.o : ../../py/qstr.c 
# 	@echo 'Building file: $<'
# 	@echo 'Invoking: ARM GCC Compiler'
# 	$(CC) $(CFLAGS) -o  "$@" "$<"
# 	@echo 'Finished building: $<'
# 	@echo ' '

# bin/mpy/obj.o : ../../py/obj.c 
# 	@echo 'Building file: $<'
# 	@echo 'Invoking: ARM GCC Compiler'
# 	$(CC) $(CFLAGS) -o  "$@" "$<"
# 	@echo 'Finished building: $<'
# 	@echo ' '

# bin/mpy/objdict.o : ../../py/objdict.c 
# 	@echo 'Building file: $<'
# 	@echo 'Invoking: ARM GCC Compiler'
# 	$(CC) $(CFLAGS) -o  "$@" "$<"
# 	@echo 'Finished building: $<'
# 	@echo ' '

# bin/mpy/objtype.o : ../../py/objtype.c 
# 	@echo 'Building file: $<'
# 	@echo 'Invoking: ARM GCC Compiler'
# 	$(CC) $(CFLAGS) -o  "$@" "$<"
# 	@echo 'Finished building: $<'
# 	@echo ' '











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
