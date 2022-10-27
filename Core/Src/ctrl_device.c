/*
 * device_ctrl.c
 *
 *  Created on: 17 paź 2022
 *      Author: x300
 */


#include "ctrl_device.h"
#include "ctrl_rtc.h"
#include "stdio.h"

void ctrl_device_init(void)
{
	lcd_pwm_init(&LCD_PWM,50);
	rtc_init();
	rtc_allow_set();
	rtc_set();
}

void ctrl_device(void)
{
	ctrl_device_lcdbrightness();
	ctrl_device_dateTime();
}



void ctrl_device_lcdbrightness(void)
{
	if(LCD_PWM.fill != (uint16_t)(lv_slider_get_value(ui_ScreenBrigtSlider)))
	{
		lcd_pwm_set_fill(&LCD_PWM, (uint16_t)(lv_slider_get_value(ui_ScreenBrigtSlider)));
	}
}

void ctrl_device_dateTime(void)
{
	rtc_update();
	char buff[34] = "hh:mm:ss  dd:mm:yy 24*C 48%";
	sprintf((char *)buff, "%.2d:%.2d:%.2d  %.2d.%.2d.%.2d 24*C 47%%", RTC_CTRL.hour_c, RTC_CTRL.minutes_c, RTC_CTRL.seconds_c, RTC_CTRL.day_c, RTC_CTRL.month_c, RTC_CTRL.year_c);
	lv_label_set_text(ui_MainScreenParamLabel, buff);
}

