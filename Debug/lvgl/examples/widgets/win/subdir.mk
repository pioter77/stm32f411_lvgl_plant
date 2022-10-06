################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/examples/widgets/win/lv_example_win_1.c 

OBJS += \
./lvgl/examples/widgets/win/lv_example_win_1.o 

C_DEPS += \
./lvgl/examples/widgets/win/lv_example_win_1.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/examples/widgets/win/%.o lvgl/examples/widgets/win/%.su: ../lvgl/examples/widgets/win/%.c lvgl/examples/widgets/win/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../UI -I../lvgl -I../ILI9341 -I../XPT2064 -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-examples-2f-widgets-2f-win

clean-lvgl-2f-examples-2f-widgets-2f-win:
	-$(RM) ./lvgl/examples/widgets/win/lv_example_win_1.d ./lvgl/examples/widgets/win/lv_example_win_1.o ./lvgl/examples/widgets/win/lv_example_win_1.su

.PHONY: clean-lvgl-2f-examples-2f-widgets-2f-win

