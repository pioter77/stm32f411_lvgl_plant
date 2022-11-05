/*
 * output_ctrl.h
 *
 *  Created on: 17 paź 2022
 *      Author: x300
 */

#ifndef INC_OUTPUT_CTRL_H_
#define INC_OUTPUT_CTRL_H_

#include "main.h"
#include "tim.h"
#include "stdio.h"
#include "defines.h"

typedef enum {PWM_OUTPUT_OFF=0, PWM_OUTPUT_ON=1 }pwm_output_isOn_t;

												//structure used to control mosfet gate driving
typedef struct PWM_OUT_T{
	TIM_TypeDef *tim;							//timer used for this output
	uint32_t tim_channel;						//tim channel used for this output
	uint16_t arr_val;							//current arr val set - freqency of pwm and resolution
	uint16_t oc_compare_val;					//current oc compare reg val - trnslates to power
	pwm_output_isOn_t output_is_on;				//is output on or off
	uint8_t power;								//output power set 0-100%
}PWM_OUT_t;


void co_pwm_init(PWM_OUT_t *out);
void co_pwm_ctrl(PWM_OUT_t *out);
void co_pwm_set_power(PWM_OUT_t *out, uint8_t power);
void co_pwm_output_turn_off(PWM_OUT_t *out);
void co_pwm_output_turn_on(PWM_OUT_t *out);
_Bool co_pwm_output_isOn(PWM_OUT_t *out);
uint8_t co_pwm_get_power(PWM_OUT_t *out);



#endif /* INC_OUTPUT_CTRL_H_ */
