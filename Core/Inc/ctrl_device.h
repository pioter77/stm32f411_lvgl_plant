/*
 * device_ctrl.h
 *
 *  Created on: 17 paź 2022
 *      Author: x300
 */

#ifndef INC_DEVICE_CTRL_H_
#define INC_DEVICE_CTRL_H_

#include <ctrl_timing.h>
#include "defines.h"
#include "../UI/ui.h"
#include "../UI/ui_helpers.h"

void ctrl_device_init(void);
void ctrl_device(void);
void ctrl_device_ui_lcdbrightness(void);
void ctrl_device_ui_lcdtime(void);
void ctrl_device_humiUpdate(void);
void ctrl_device_LabelStateUpdate(void);
void ctrl_device_dateTimeTempHumiUpdate(void);

typedef struct LCD_PWM_T{
	TIM_TypeDef *tim;
	uint32_t channel;
	volatile uint8_t fill;				//in % 0-100%
	_Bool isAuto;						//when @1 then brightness is controlled based on light sensor readouts
	_Bool isTimeOutOn;					//when @1 then screen goes black after timeout value has been reached
	volatile uint16_t timeVal;			//timeout value set in seconds
	volatile uint16_t timeCnt;			//time that has passed since last touch event when  == timeVal && isTimeOutOn==1 then switch screen backlight off
	volatile uint16_t adcReadFilt;		//filtered adc readout based on that automatic control is based
}LCD_PWM_t;

extern LCD_PWM_t LCD_PWM;

void lcd_pwm_init(LCD_PWM_t *lcd_pwm, uint8_t fill);						//init sceen brigntness control with % level specified
void lcd_pwm_set_fill(LCD_PWM_t *lcd_pwm, uint8_t fill);					//set screen brigntnesss 0-100%
void lcd_pwm_enable_autoBrigntness(LCD_PWM_t *lcd_pwm, _Bool state);		//enable or disable automatic brightness control
void lcd_pwm_set_timeout(LCD_PWM_t *lcd_pwm, uint8_t timeOutVal);			//set time value (in seconds) of screen timeout
void lcd_pwm_enable_timeout(LCD_PWM_t *lcd_pwm, _Bool state);				//enable or disable screen timeout

#endif /* INC_DEVICE_CTRL_H_ */
