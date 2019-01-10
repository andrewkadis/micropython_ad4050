################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/kadds/Dev/micropython/AnalogDevices/ADuCM4x50_DFP/3.2.0/Source/drivers/gpio/adi_gpio.c \
/Users/kadds/Dev/micropython/AnalogDevices/ADuCM4x50_DFP/3.2.0/Source/drivers/pwr/adi_pwr.c \
/Users/kadds/Dev/micropython/AnalogDevices/ADuCM4x50_DFP/3.2.0/Source/drivers/wdt/adi_wdt.c \
/Users/kadds/Dev/micropython/AnalogDevices/ADuCM4x50_DFP/3.2.0/Source/common.c \
/Users/kadds/Dev/micropython/AnalogDevices/ADuCM4x50_DFP/3.2.0/Source/GCC/startup_ADuCM4050.c \
/Users/kadds/Dev/micropython/AnalogDevices/ADuCM4x50_DFP/3.2.0/Source/system_ADuCM4050.c 

S_UPPER_SRCS += \
/Users/kadds/Dev/micropython/AnalogDevices/ADuCM4x50_DFP/3.2.0/Source/GCC/reset_ADuCM4050.S 

SRC_OBJS += \
./RTE/Device/ADuCM4050/adi_gpio.o \
./RTE/Device/ADuCM4050/adi_pwr.o \
./RTE/Device/ADuCM4050/adi_wdt.o \
./RTE/Device/ADuCM4050/common.o \
./RTE/Device/ADuCM4050/reset_ADuCM4050.o \
./RTE/Device/ADuCM4050/startup_ADuCM4050.o \
./RTE/Device/ADuCM4050/system_ADuCM4050.o 

C_DEPS += \
./RTE/Device/ADuCM4050/adi_gpio.d \
./RTE/Device/ADuCM4050/adi_pwr.d \
./RTE/Device/ADuCM4050/adi_wdt.d \
./RTE/Device/ADuCM4050/common.d \
./RTE/Device/ADuCM4050/startup_ADuCM4050.d \
./RTE/Device/ADuCM4050/system_ADuCM4050.d 


# Each subdirectory must supply rules for building sources it contributes
RTE/Device/ADuCM4050/adi_gpio.o: $(ANALOG_ROOT)/ADuCM4x50_DFP/3.2.0/Source/drivers/gpio/adi_gpio.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -D__EVCOG__ -D_RTE_ -D__ADUCM4050__ -D__SILICON_REVISION__=0xffff @include_directories.txt -Wall -c -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

RTE/Device/ADuCM4050/adi_pwr.o: $(ANALOG_ROOT)/ADuCM4x50_DFP/3.2.0/Source/drivers/pwr/adi_pwr.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -D__EVCOG__ -D_RTE_ -D__ADUCM4050__ -D__SILICON_REVISION__=0xffff @include_directories.txt -Wall -c -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

RTE/Device/ADuCM4050/adi_wdt.o: $(ANALOG_ROOT)/ADuCM4x50_DFP/3.2.0/Source/drivers/wdt/adi_wdt.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -D__EVCOG__ -D_RTE_ -D__ADUCM4050__ -D__SILICON_REVISION__=0xffff @include_directories.txt -Wall -c -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

RTE/Device/ADuCM4050/common.o: $(ANALOG_ROOT)/ADuCM4x50_DFP/3.2.0/Source/common.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -D__EVCOG__ -D_RTE_ -D__ADUCM4050__ -D__SILICON_REVISION__=0xffff @include_directories.txt -Wall -c -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

RTE/Device/ADuCM4050/reset_ADuCM4050.o: $(ANALOG_ROOT)/ADuCM4x50_DFP/3.2.0/Source/GCC/reset_ADuCM4050.S
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded Assembler'
	arm-none-eabi-gcc -c -x assembler-with-cpp -g -gdwarf-2 -DCORE0 -D_DEBUG -D__EVCOG__ -D_RTE_ -D__ADUCM4050__ -D__SILICON_REVISION__=0xffff @include_directories.txt -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -o  "$@" "$<" 
	@echo 'Finished building: $<'
	@echo ' '

RTE/Device/ADuCM4050/startup_ADuCM4050.o: $(ANALOG_ROOT)/ADuCM4x50_DFP/3.2.0/Source/GCC/startup_ADuCM4050.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -D__EVCOG__ -D_RTE_ -D__ADUCM4050__ -D__SILICON_REVISION__=0xffff @include_directories.txt -Wall -c -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

RTE/Device/ADuCM4050/system_ADuCM4050.o: $(ANALOG_ROOT)/ADuCM4x50_DFP/3.2.0/Source/system_ADuCM4050.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -D__EVCOG__ -D_RTE_ -D__ADUCM4050__ -D__SILICON_REVISION__=0xffff @include_directories.txt -Wall -c -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


