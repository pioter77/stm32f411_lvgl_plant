/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "i2c.h"
#include "spi.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "../../lvgl/lvgl.h"

#include "../../XPT2064/XPT2064.h"
#include "../../XPT2064/lv_drv.h"

#include "../../ILI9341/core.h"
#include "../../ILI9341/lv_driver.h"

//#include "logo.h"

#include "../../lvgl/examples/lv_examples.h"

#include "../UI/ui.h"

#include "control.h"
#include "fcnUi_chart.h"
//#include "../../lvgl/demos/lv_demos.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
static lv_disp_draw_buf_t disp_buf;
volatile uint16_t tim1Ch1_fill = 0;
volatile uint16_t tim1Ch2_fill = 0;
volatile uint8_t encoder_Pos=0;
 //The second buffer is optional*/

#define ILI_SCR_HORIZONTAL 320
#define ILI_SCR_VERTICAL   240
#define BUFFOR_SCR_ROWS 40

 static lv_color_t buf_1[ILI_SCR_HORIZONTAL * BUFFOR_SCR_ROWS] ;
 static lv_color_t buf_2[ILI_SCR_HORIZONTAL * BUFFOR_SCR_ROWS] ; //__attribute__ ((section (".LvBufferSection")))
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 //DMA don't have acces to CCMRAM :(
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 //I don't have so too much time on experiments
 static lv_disp_drv_t disp_drv;
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_SPI2_Init();
  MX_SPI5_Init();
  MX_ADC1_Init();
  MX_I2C1_Init();
  MX_SPI1_Init();
  MX_TIM4_Init();
  MX_TIM1_Init();
  MX_TIM5_Init();
  /* USER CODE BEGIN 2 */
  //timer init for pwm output:


  LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH1);
  LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH2);

  LL_TIM_EnableIT_UPDATE(TIM1);
  LL_TIM_EnableCounter(TIM1);
  LL_TIM_EnableAutomaticOutput(TIM1);


  LL_TIM_EnableCounter(TIM4);
  //LL_TIM_EnableAutomaticOutput(TIM1);




  //end of pwm timer init
  ILI9341_Init();
  XPT2046_Init(&hspi2, EXTI2_IRQn);
  HAL_Delay(30);

  	  lv_init();
  	  lv_disp_draw_buf_init(&disp_buf, buf_1, buf_2, ILI_SCR_HORIZONTAL * BUFFOR_SCR_ROWS);
  	  lv_disp_drv_init(&disp_drv);            /*Basic initialization*/
  	  disp_drv.draw_buf = &disp_buf;          /*Set an initialized buffer*/
  	  disp_drv.flush_cb = ILI9341_flush;        /*Set a flush callback to draw to the display*/
  	  disp_drv.hor_res = ILI_SCR_HORIZONTAL;                 /*Set the horizontal resolution in pixels*/
  	  disp_drv.ver_res = ILI_SCR_VERTICAL;                 /*Set the vertical resolution in pixels*/
    lv_disp_drv_register(&disp_drv); /*Register the driver and save the created display objects*/


    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type =LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = lvXPT2064_Read;
    lv_indev_drv_register(&indev_drv);
  HAL_Delay(10);

  //lv_example_get_started_1();
  //lv_example_textarea_2();
  //lv_example_win_1();
  //lv_example_animimg_1();
  //lv_example_flex_1();
  //lv_example_scroll_6();
 // lv_example_chart_5();
  //lv_example_btnmatrix_3();
  //lv_example_label_1(); //ciekawe przesuwanie tekstu!
  //lv_example_img_3();  //o to jest mocne :D sporo zasobów musi zrec
  //lv_example_table_2();
  //lv_demo_widgets();
 // lv_example_menu_5();
  //lv_example_tabview_1();
  ui_init();
  fcnUi_chart_init();
  fcnUi_chart_update();

//  uint32_t LedTim0;
  uint32_t lvglTime=0;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

	  if(HAL_GetTick()- lvglTime >=2)
	  {
		  lvglTime=HAL_GetTick();
		  lv_task_handler();
		  lv_timer_handler();

		  //tim1Ch1_fill=100;
		  //tim1Ch2_fill=900;
		  pump_ctrl();
		  encoder_Pos= TIM4->CNT;


	  }
	  XPT2046_Task();
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_3);
  while(LL_FLASH_GetLatency()!= LL_FLASH_LATENCY_3)
  {
  }
  LL_PWR_SetRegulVoltageScaling(LL_PWR_REGU_VOLTAGE_SCALE1);
  LL_RCC_HSE_Enable();

   /* Wait till HSE is ready */
  while(LL_RCC_HSE_IsReady() != 1)
  {

  }
  LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSE, LL_RCC_PLLM_DIV_12, 96, LL_RCC_PLLP_DIV_2);
  LL_RCC_PLL_Enable();

   /* Wait till PLL is ready */
  while(LL_RCC_PLL_IsReady() != 1)
  {

  }
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_2);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);

   /* Wait till System clock is ready */
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL)
  {

  }
  LL_SetSystemCoreClock(100000000);

   /* Update the time base */
  if (HAL_InitTick (TICK_INT_PRIORITY) != HAL_OK)
  {
    Error_Handler();
  }
  LL_RCC_SetTIMPrescaler(LL_RCC_TIM_PRESCALER_TWICE);
}

/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == T_IRQ_Pin)
	{
		XPT2046_IRQ();
	}
}

void SYSTICK_lvgl_handler(void)
{
	lv_tick_inc(1);

}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
