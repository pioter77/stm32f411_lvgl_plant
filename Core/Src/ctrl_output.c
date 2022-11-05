/*
 * output_ctrl.c
 *
 *  Created on: 17 paź 2022
 *      Author: x300
 */


#include "ctrl_output.h"



void co_pwm_init(PWM_OUT_t *out)
{
	  out->arr_val= LL_TIM_GetAutoReload(out->tim);
	  out->oc_compare_val= 0;						//power to 0
	  out->output_is_on= PWM_OUTPUT_OFF;
	  out->power= 0;
	  co_pwm_output_turn_on(out);
	  LL_TIM_EnableCounter(out->tim);
#if DEBUG_DEVICE
	  printf("\n IF OUTPUT IS ASSIGNED TO ADVANCED TIMER ENABLE AUTOMATIC OUTPUT BIT MUST BE SET FOR PWM OUTPUT TO WORK!");

#endif
	  LL_TIM_EnableAutomaticOutput(out->tim);		// ONLY needed when using so called advanced timer
}


void co_pwm_set_power(PWM_OUT_t *out, uint8_t power)
{
	out->oc_compare_val= (uint16_t)(power*out->arr_val/100.0);
	out->power= power;

	switch(out->tim_channel)
	{
	case LL_TIM_CHANNEL_CH1:
		LL_TIM_OC_SetCompareCH1(out->tim, out->oc_compare_val);
		break;
	case LL_TIM_CHANNEL_CH2:
		LL_TIM_OC_SetCompareCH2(out->tim, out->oc_compare_val);
		break;
	case LL_TIM_CHANNEL_CH3:
		LL_TIM_OC_SetCompareCH3(out->tim, out->oc_compare_val);
		break;
	case LL_TIM_CHANNEL_CH4:
		LL_TIM_OC_SetCompareCH4(out->tim, out->oc_compare_val);
		break;
	default:
#if DEBUG_DEVICE
		printf("\n timer channel assigned value out of range or no value power cannot be set");
#endif
	}
}

void co_pwm_output_turn_off(PWM_OUT_t *out)
{
	co_pwm_set_power(out,0);
	LL_TIM_CC_DisableChannel(out->tim, out->tim_channel);
	out->output_is_on= PWM_OUTPUT_OFF;
}

void co_pwm_output_turn_on(PWM_OUT_t *out)
{
	LL_TIM_CC_EnableChannel(out->tim, out->tim_channel);
	out->output_is_on= PWM_OUTPUT_ON;
}

_Bool co_pwm_output_isOn(PWM_OUT_t *out)
{
	return (_Bool) out->output_is_on;
}

uint8_t co_pwm_get_power(PWM_OUT_t *out)
{
	uint16_t ret_val=0;

	switch(out->tim_channel)
	{
		case LL_TIM_CHANNEL_CH1:
			ret_val= LL_TIM_OC_GetCompareCH1(out->tim);
			break;
		case LL_TIM_CHANNEL_CH2:
			ret_val= LL_TIM_OC_GetCompareCH2(out->tim);
			break;
		case LL_TIM_CHANNEL_CH3:
			ret_val= LL_TIM_OC_GetCompareCH3(out->tim);
			break;
		case LL_TIM_CHANNEL_CH4:
			ret_val= LL_TIM_OC_GetCompareCH4(out->tim);
			break;
		default:
	#if DEBUG_DEVICE
			printf("\n timer channel assigned value out of range or no value power cannot be determined");
	#endif
			return 0;
	}

	ret_val= ret_val*100/LL_TIM_GetAutoReload(out->tim);

	return ((uint8_t)ret_val);
}

