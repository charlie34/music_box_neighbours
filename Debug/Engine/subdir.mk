################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Engine/engine.c 

OBJS += \
./Engine/engine.o 

C_DEPS += \
./Engine/engine.d 


# Each subdirectory must supply rules for building sources it contributes
Engine/%.o: ../Engine/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DUSE_HAL_DRIVER -DSTM32F411xE -I"C:/Users/Carlos Martín/music_box_neighbours/Core/Inc" -I"C:/Users/Carlos Martín/music_box_neighbours/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Carlos Martín/music_box_neighbours/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Carlos Martín/music_box_neighbours/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Carlos Martín/music_box_neighbours/Drivers/CMSIS/Include" -I"C:/Users/Carlos Martín/music_box_neighbours/DFPlayer" -I"C:/Users/Carlos Martín/music_box_neighbours/Comunications" -I"C:/Users/Carlos Martín/music_box_neighbours/Engine"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


