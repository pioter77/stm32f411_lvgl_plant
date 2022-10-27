/*
 * ctrl_timers.h
 *
 *  Created on: 18 paź 2022
 *      Author: x300
 */

#ifndef INC_CTRL_TIMERS_H_
#define INC_CTRL_TIMERS_H_

#include "main.h"
#include "tim.h"

//void hardware_initialize(void);

typedef struct LCD_PWM_T{
	TIM_TypeDef *tim;
	uint32_t channel;
	volatile uint16_t fill;	//in % 0-100%
}LCD_PWM_t;

extern LCD_PWM_t LCD_PWM;

void lcd_pwm_init(LCD_PWM_t *lcd_pwm, uint8_t fill);			//init sceen brigntness control with % level specified
void lcd_pwm_set_fill(LCD_PWM_t *lcd_pwm, uint8_t fill);		//set screen brigntnesss 0-100%
#endif /* INC_CTRL_TIMERS_H_ */
