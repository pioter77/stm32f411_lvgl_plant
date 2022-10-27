/*
 * ctrl_timers.c
 *
 *  Created on: 18 paź 2022
 *      Author: x300
 */


#include "ctrl_timers.h"


//void hardware_initialize(void)
//{
	/*
	//enable led timers
		  LL_TIM_EnableIT_UPDATE(TIM3);
		  LL_TIM_CC_EnableChannel(TIM3, LL_TIM_CHANNEL_CH1);
		  LL_TIM_CC_EnableChannel(TIM3, LL_TIM_CHANNEL_CH2);
		  LL_TIM_CC_EnableChannel(TIM3, LL_TIM_CHANNEL_CH3);
		  LL_TIM_CC_EnableChannel(TIM3, LL_TIM_CHANNEL_CH4);
		  LL_TIM_OC_SetCompareCH1(TIM3, 0);
		  LL_TIM_OC_SetCompareCH2(TIM3, 0);
		  LL_TIM_OC_SetCompareCH3(TIM3, 0);
		  LL_TIM_OC_SetCompareCH4(TIM3, 0);
		  LL_TIM_EnableCounter(TIM3);
	//enable encoder timer:
		  //for advanced timers type only:
		  LL_TIM_EnableAutomaticOutput(TIM1);
		  //encoder:
		  LL_TIM_EnableCounter(TIM1);
		  TIM1->ARR=179;
		  TIM1->CNT=0;
		  */
//}



LCD_PWM_t LCD_PWM={
		.tim= TIM2,
		.channel= LL_TIM_CHANNEL_CH1,
		.fill=0		// current fill value
};

void lcd_pwm_init(LCD_PWM_t *lcd_pwm, uint8_t fill)
{
	//enable lcd pwm brightness controll timer
		  //LL_TIM_EnableIT_UPDATE(lcd_pwm->tim);
		  LL_TIM_CC_EnableChannel(lcd_pwm->tim, lcd_pwm->channel);
		//  LL_TIM_OC_SetCompareCH1(lcd_pwm->tim, 0);
		  LL_TIM_EnableAutomaticOutput(lcd_pwm->tim);
		  LL_TIM_EnableCounter(lcd_pwm->tim);

		  lcd_pwm_set_fill(lcd_pwm, fill);

}

void lcd_pwm_set_fill(LCD_PWM_t *lcd_pwm, uint8_t fill)
{
	  if((fill>= 0) && (fill <=100))
	  {
		  LL_TIM_OC_SetCompareCH1(lcd_pwm->tim,  (uint32_t)(LL_TIM_GetAutoReload(lcd_pwm->tim)*(uint32_t)fill/(uint32_t)100));	//convert % vals to arr timer values
		  lcd_pwm->fill= fill;
	  }else{
		  LL_TIM_OC_SetCompareCH1(lcd_pwm->tim, LL_TIM_GetAutoReload(lcd_pwm->tim));	//full blast when value out of range
		  lcd_pwm->fill= LL_TIM_GetAutoReload(lcd_pwm->tim);
	  }
}
