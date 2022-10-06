################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../UI/ui.c \
../UI/ui_helpers.c 

OBJS += \
./UI/ui.o \
./UI/ui_helpers.o 

C_DEPS += \
./UI/ui.d \
./UI/ui_helpers.d 


# Each subdirectory must supply rules for building sources it contributes
UI/%.o UI/%.su: ../UI/%.c UI/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../UI -I../lvgl -I../ILI9341 -I../XPT2064 -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-UI

clean-UI:
	-$(RM) ./UI/ui.d ./UI/ui.o ./UI/ui.su ./UI/ui_helpers.d ./UI/ui_helpers.o ./UI/ui_helpers.su

.PHONY: clean-UI

