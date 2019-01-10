################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Root Analog Devices directory
ANALOG_ROOT = /Users/kadds/Dev/micropython/AnalogDevices

# Use the ARM gcc compiler rather than native gcc (Clang on OSX)
CC='/usr/local/Cellar/arm-none-eabi-gcc/7-2018-q2-update/bin/arm-none-eabi-gcc'

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include system/subdir.mk
-include source/subdir.mk
-include RTE/Device/ADuCM4050/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
OBJS := $(SRC_OBJS)
# Quote makefile variable : OBJS 
OBJS := $(subst \ ,@, $(OBJS))
OBJS := $(foreach var, $(OBJS), "$(subst @, ,$(var))")
# Quote makefile variable : C_DEPS 
C_DEPS := $(subst \ ,@, $(C_DEPS))
C_DEPS := $(foreach var, $(C_DEPS), "$(subst @, ,$(var))")

# All Target
all: autobaud_example

# Tool invocations
autobaud_example: $(USER_OBJS) $(SRC_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Linker'
	arm-none-eabi-gcc -T$(ANALOG_ROOT)/ADuCM4x50_DFP/3.2.0/Source/GCC/ADuCM4050.ld -Wl,--gc-sections -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -o  "autobaud" @input-file.txt -lm -v /usr/local/Cellar/arm-none-eabi-gcc/7-2018-q2-update/gcc/arm-none-eabi/lib/thumb/v7e-m/fpv4-sp/hard/libnosys.a /usr/local/Cellar/arm-none-eabi-gcc/7-2018-q2-update/gcc/arm-none-eabi/lib/thumb/v7e-m/fpv4-sp/hard/libc.a /usr/local/Cellar/arm-none-eabi-gcc/7-2018-q2-update/gcc/arm-none-eabi/lib/thumb/v7e-m/fpv4-sp/hard/libm.a
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) autobaud_example
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
