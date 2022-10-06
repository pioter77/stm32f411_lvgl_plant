################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/demos/benchmark/lv_demo_benchmark.c 

OBJS += \
./lvgl/demos/benchmark/lv_demo_benchmark.o 

C_DEPS += \
./lvgl/demos/benchmark/lv_demo_benchmark.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/demos/benchmark/%.o lvgl/demos/benchmark/%.su: ../lvgl/demos/benchmark/%.c lvgl/demos/benchmark/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../UI -I../lvgl -I../ILI9341 -I../XPT2064 -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-demos-2f-benchmark

clean-lvgl-2f-demos-2f-benchmark:
	-$(RM) ./lvgl/demos/benchmark/lv_demo_benchmark.d ./lvgl/demos/benchmark/lv_demo_benchmark.o ./lvgl/demos/benchmark/lv_demo_benchmark.su

.PHONY: clean-lvgl-2f-demos-2f-benchmark

