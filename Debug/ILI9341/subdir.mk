################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ILI9341/core.c \
../ILI9341/lv_driver.c 

OBJS += \
./ILI9341/core.o \
./ILI9341/lv_driver.o 

C_DEPS += \
./ILI9341/core.d \
./ILI9341/lv_driver.d 


# Each subdirectory must supply rules for building sources it contributes
ILI9341/%.o ILI9341/%.su: ../ILI9341/%.c ILI9341/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../UI -I../lvgl -I../ILI9341 -I../XPT2064 -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ILI9341

clean-ILI9341:
	-$(RM) ./ILI9341/core.d ./ILI9341/core.o ./ILI9341/core.su ./ILI9341/lv_driver.d ./ILI9341/lv_driver.o ./ILI9341/lv_driver.su

.PHONY: clean-ILI9341

