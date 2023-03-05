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
void ctrl_device_dateTimeTempHumiUpdate(void);

typedef struct LCD_PWM_T{
	TIM_TypeDef *tim;
	uint32_t channel;
	volatile uint16_t fill;	//in % 0-100%
}LCD_PWM_t;

extern LCD_PWM_t LCD_PWM;

void lcd_pwm_init(LCD_PWM_t *lcd_pwm, uint8_t fill);			//init sceen brigntness control with % level specified
void lcd_pwm_set_fill(LCD_PWM_t *lcd_pwm, uint8_t fill);		//set screen brigntnesss 0-100%

#endif /* INC_DEVICE_CTRL_H_ */
