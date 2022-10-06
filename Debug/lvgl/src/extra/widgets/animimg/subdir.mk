################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/extra/widgets/animimg/lv_animimg.c 

OBJS += \
./lvgl/src/extra/widgets/animimg/lv_animimg.o 

C_DEPS += \
./lvgl/src/extra/widgets/animimg/lv_animimg.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/extra/widgets/animimg/%.o lvgl/src/extra/widgets/animimg/%.su: ../lvgl/src/extra/widgets/animimg/%.c lvgl/src/extra/widgets/animimg/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../UI -I../lvgl -I../ILI9341 -I../XPT2064 -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-extra-2f-widgets-2f-animimg

clean-lvgl-2f-src-2f-extra-2f-widgets-2f-animimg:
	-$(RM) ./lvgl/src/extra/widgets/animimg/lv_animimg.d ./lvgl/src/extra/widgets/animimg/lv_animimg.o ./lvgl/src/extra/widgets/animimg/lv_animimg.su

.PHONY: clean-lvgl-2f-src-2f-extra-2f-widgets-2f-animimg

