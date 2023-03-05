/*
 * device_ctrl.c
 *
 *  Created on: 17 paź 2022
 *      Author: x300
 */


#include "ctrl_device.h"
#include "ctrl_rtc.h"
#include "ctrl_measure.h"
#include "stdio.h"
#include "ctrl_process.h"
#include "ctrl_timing.h"
#include "ctrl_htu21d.h"

LCD_PWM_t LCD_PWM={
		.tim= TIM2,
		.channel= LL_TIM_CHANNEL_CH1,
		.fill=0		// current fill value
};



void ctrl_device_init(void)
{
	lcd_pwm_init(&LCD_PWM,50);
	rtc_init();
//	htu21d_init(&HTU21D, &hi2c1);
//	rtc_allow_set();
//	rtc_set();
}

void ctrl_device(void)
{

	  if(timingIsUp(&TIMING.tims_1000ms1))
	  {
		 // LL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
		ctrl_device_dateTimeTempHumiUpdate();
		ctrl_device_humiUpdate();
		timingRestart(&TIMING.tims_1000ms1);

	  }
	  ctrl_htu21d(&HTU21D);
}



void ctrl_device_ui_lcdbrightness(void)
{
	if(LCD_PWM.fill != (uint16_t)(lv_slider_get_value(ui_ScreenBrigtSlider)))
	{
		lcd_pwm_set_fill(&LCD_PWM, (uint16_t)(lv_slider_get_value(ui_ScreenBrigtSlider)));
	}
}

void ctrl_device_ui_lcdtime(void)
{
//	if(LCD_PWM.fill != (uint16_t)(lv_slider_get_value(ui_ScreenBrigtSlider)))
//	{
//		lcd_pwm_set_fill(&LCD_PWM, (uint16_t)(lv_slider_get_value(ui_ScreenBrigtSlider)));
//	}
}

void ctrl_device_dateTimeTempHumiUpdate(void)
{
	rtc_update();
	char buff[37] = "hh:mm:ss  dd:mm:yy +24*C 100%";
	sprintf((char *)buff, "%.2d:%.2d:%.2d  %.2d.%.2d.%.2d %.2d*C %.2d%%", RTC_CTRL.hour_c, RTC_CTRL.minutes_c, RTC_CTRL.seconds_c, RTC_CTRL.day_c, RTC_CTRL.month_c, RTC_CTRL.year_c, HTU21D.HTU21_temp_cut, HTU21D.HTU21_humi_cut);
	lv_label_set_text(ui_MainScreenParamLabel, buff);
}

void ctrl_device_humiUpdate(void)
{
	ctrl_measure();
	char buff1[16] = "21% / 48%";
	char buff2[16] = "21% / 48%";
	sprintf((char *)buff1, "%.2d%% / %.2d%%", PLANT1.moisture_level, PLANT1.moisture_threshold);
	sprintf((char *)buff2, "%.2d%% / %.2d%%", PLANT2.moisture_level, PLANT2.moisture_threshold);
	lv_label_set_text(ui_Out1Label, buff1);
	lv_label_set_text(ui_Out2Label, buff2);
}




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

