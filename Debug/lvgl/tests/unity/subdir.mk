################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/tests/unity/unity.c \
../lvgl/tests/unity/unity_support.c 

OBJS += \
./lvgl/tests/unity/unity.o \
./lvgl/tests/unity/unity_support.o 

C_DEPS += \
./lvgl/tests/unity/unity.d \
./lvgl/tests/unity/unity_support.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/tests/unity/%.o lvgl/tests/unity/%.su: ../lvgl/tests/unity/%.c lvgl/tests/unity/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../UI -I../lvgl -I../ILI9341 -I../XPT2064 -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-tests-2f-unity

clean-lvgl-2f-tests-2f-unity:
	-$(RM) ./lvgl/tests/unity/unity.d ./lvgl/tests/unity/unity.o ./lvgl/tests/unity/unity.su ./lvgl/tests/unity/unity_support.d ./lvgl/tests/unity/unity_support.o ./lvgl/tests/unity/unity_support.su

.PHONY: clean-lvgl-2f-tests-2f-unity

