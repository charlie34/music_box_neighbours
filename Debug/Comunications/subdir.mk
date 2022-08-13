################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Comunications/frame_coder.c \
../Comunications/frame_decoder.c 

OBJS += \
./Comunications/frame_coder.o \
./Comunications/frame_decoder.o 

C_DEPS += \
./Comunications/frame_coder.d \
./Comunications/frame_decoder.d 


# Each subdirectory must supply rules for building sources it contributes
Comunications/%.o: ../Comunications/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DUSE_HAL_DRIVER -DSTM32F411xE -I"C:/Users/Carlos Martín/project/music_box_neighbours/Core/Inc" -I"C:/Users/Carlos Martín/project/music_box_neighbours/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Carlos Martín/project/music_box_neighbours/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Carlos Martín/project/music_box_neighbours/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Carlos Martín/project/music_box_neighbours/Drivers/CMSIS/Include" -I"C:/Users/Carlos Martín/project/music_box_neighbours/DFPlayer" -I"C:/Users/Carlos Martín/project/music_box_neighbours/Comunications"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


