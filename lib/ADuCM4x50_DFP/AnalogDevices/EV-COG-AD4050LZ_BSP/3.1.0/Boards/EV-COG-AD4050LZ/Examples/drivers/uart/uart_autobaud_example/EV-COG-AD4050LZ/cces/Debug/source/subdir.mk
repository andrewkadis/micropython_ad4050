################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/kadds/Dev/micropython/AnalogDevices/EV-COG-AD4050LZ_BSP/3.1.0/Boards/EV-COG-AD4050LZ/Examples/drivers/uart/uart_autobaud_example/autobaud.c

SRC_OBJS += \
./source/autobaud.o 

C_DEPS += \
./source/autobaud.d 


# Each subdirectory must supply rules for building sources it contributes
source/autobaud.o: $(ANALOG_ROOT)/EV-COG-AD4050LZ_BSP/3.1.0/Boards/EV-COG-AD4050LZ/Examples/drivers/uart/uart_autobaud_example/autobaud.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -D__EVCOG__ -D_RTE_ -D__ADUCM4050__ -D__SILICON_REVISION__=0xffff @include_directories.txt -Wall -c -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '




