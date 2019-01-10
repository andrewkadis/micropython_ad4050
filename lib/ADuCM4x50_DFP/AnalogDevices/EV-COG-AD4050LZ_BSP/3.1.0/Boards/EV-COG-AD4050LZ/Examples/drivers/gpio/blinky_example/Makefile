################################################################################
# Automatically-generated file. Do not edit!
################################################################################

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
all: blinky_example

# Tool invocations
blinky_example: $(USER_OBJS) $(SRC_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Linker'
	arm-none-eabi-gcc -T/root/cces/2.8.1/examples/ev-cog-ad4050lz_bsp_3.1.0/blinky_example/EV-COG-AD4050LZ/cces/RTE/Device/ADuCM4050/ADuCM4050.ld -Wl,--gc-sections -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -o  "blinky_example" @input-file.txt -lm
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) blinky_example
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
