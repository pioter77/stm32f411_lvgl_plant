/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

#include "stm32f4xx_ll_adc.h"
#include "stm32f4xx_ll_dma.h"
#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_system.h"
#include "stm32f4xx_ll_exti.h"
#include "stm32f4xx_ll_cortex.h"
#include "stm32f4xx_ll_utils.h"
#include "stm32f4xx_ll_pwr.h"
#include "stm32f4xx_ll_spi.h"
#include "stm32f4xx_ll_tim.h"
#include "stm32f4xx_ll_gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LD1_Pin GPIO_PIN_13
#define LD1_GPIO_Port GPIOC
#define LCD_DC_Pin GPIO_PIN_14
#define LCD_DC_GPIO_Port GPIOC
#define LCD_RES_Pin GPIO_PIN_15
#define LCD_RES_GPIO_Port GPIOC
#define BTN_0_Pin GPIO_PIN_0
#define BTN_0_GPIO_Port GPIOA
#define BTN_0_EXTI_IRQn EXTI0_IRQn
#define LCD_SCK_Pin GPIO_PIN_0
#define LCD_SCK_GPIO_Port GPIOB
#define LCD_CS_Pin GPIO_PIN_1
#define LCD_CS_GPIO_Port GPIOB
#define T_IRQ_Pin GPIO_PIN_2
#define T_IRQ_GPIO_Port GPIOB
#define T_IRQ_EXTI_IRQn EXTI2_IRQn
#define T_SCK_Pin GPIO_PIN_10
#define T_SCK_GPIO_Port GPIOB
#define T_CS_Pin GPIO_PIN_12
#define T_CS_GPIO_Port GPIOB
#define LCD_LED_Pin GPIO_PIN_13
#define LCD_LED_GPIO_Port GPIOB
#define T_MISO_Pin GPIO_PIN_14
#define T_MISO_GPIO_Port GPIOB
#define T_MOSI_Pin GPIO_PIN_15
#define T_MOSI_GPIO_Port GPIOB
#define LCD_MOSI_Pin GPIO_PIN_10
#define LCD_MOSI_GPIO_Port GPIOA
#define ENCODER_P2_Pin GPIO_PIN_6
#define ENCODER_P2_GPIO_Port GPIOB
#define ENCODER_P1_Pin GPIO_PIN_7
#define ENCODER_P1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
extern volatile uint16_t tim1Ch1_fill;
extern volatile uint16_t tim1Ch2_fill;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
