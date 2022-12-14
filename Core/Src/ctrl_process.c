/*
 * ctrl_process.c
 *
 *  Created on: 30 paź 2022
 *      Author: x300
 */

#include "ctrl_process.h"


PLANT_t PLANT1= {
	.moisture_threshold= 		0,
	.moisture_level= 			0,
	.moisture_level_raw= 		0,
	.pump_power= 				0,
	.isOn=						PLANT_IS_OFF,
	.time_window_end=			23,
	.time_window_start=			6,
	.watering_cycle_cnt=		0,
	.watering_cycle_max=		3,
	.Pwm_out={
			.tim=				TIM1,
			.tim_channel= 		LL_TIM_CHANNEL_CH1,
	}
};

PLANT_t PLANT2= {
	.moisture_threshold= 		0,
	.moisture_level= 			0,
	.moisture_level_raw= 		0,
	.pump_power= 				0,
	.isOn=						PLANT_IS_OFF,
	.time_window_end=			23,
	.time_window_start=			6,
	.watering_cycle_cnt=		0,
	.watering_cycle_max=		3,
	.Pwm_out={
			.tim=				TIM1,
			.tim_channel= 		LL_TIM_CHANNEL_CH2,
	}

};
void ctrl_plant_init(PLANT_t *plant)
{

	co_pwm_init(&(plant->Pwm_out));
	co_pwm_set_power(&(plant->Pwm_out), plant->pump_power);
}

void ctrl_plant_ctrl(PLANT_t *plant)
{
	if(plant->isOn == PLANT_IS_OFF) plant->plantState= PLANT_STATE_OFF;
	else if(plant->isOn == PLANT_IS_ON)
	{
		//switch is turned to on posiion so plant process is running
		if(plant->moisture_level < plant->moisture_threshold)				//watering is neeed
		{
			if(RTC_CTRL.hour_c >= plant->time_window_start && RTC_CTRL.hour_c < plant->time_window_end && plant->watering_cycle_cnt == 0)	//watering can only start when whithin specified time window
			{
				plant->plantState= PLANT_STATE_WATERING;
			}else if(RTC_CTRL.hour_c >= plant->time_window_start && RTC_CTRL.hour_c < plant->time_window_end && plant->watering_cycle_cnt < plant->watering_cycle_max){
				plant->plantState= PLANT_STATE_CHECKING;
			}else {		//not high enough moisture level but  number of watering cycles per day exceeded or noth within time window so we wait for condition to start pumping water
				plant->plantState= PLANT_STATE_WAITING;
			}
		}else{  //high enough moisture level no watering is needed or number of watering cycles per day exceeded
			plant->plantState= PLANT_STATE_STANDBY;
		}



	}
	else{
#if DEBUG_DEVICE
		printf("\n plant on of switch state out of range");
#endif
	}

	switch(plant->plantState)
	{
		case  PLANT_STATE_OFF:
			plant_mode_OFF(plant);
			break;
		case  PLANT_STATE_STANDBY:
			plant_mode_STANDBY(plant);
			break;
		case  PLANT_STATE_WATERING:
			plant_mode_WATERING(plant);
			break;
		case  PLANT_STATE_CHECKING:
			plant_mode_CHECKING(plant);
			break;
		case  PLANT_STATE_WAITING:
			plant_mode_WAITING(plant);
			break;
		default:
#if DEBUG_DEVICE
	printf("\n plant state cannot be determined");
#endif

	}
}


void plant_load_settings(PLANT_t *plant)
{

}

void plant_switch_off(PLANT_t *plant)
{
	plant->isOn= PLANT_IS_OFF;
	co_pwm_output_turn_on(&(plant->Pwm_out));
}

void plant_switch_on(PLANT_t *plant)
{
	plant->isOn= PLANT_IS_ON;
	co_pwm_output_turn_on(&(plant->Pwm_out));
}

void plant_mode_OFF(PLANT_t *plant)
{
	co_pwm_set_power(&(plant->Pwm_out), 0);
}

void plant_mode_STANDBY(PLANT_t *plant)
{
	co_pwm_set_power(&(plant->Pwm_out), 0);
}

void plant_mode_WATERING(PLANT_t *plant)
{
	co_pwm_set_power(&(plant->Pwm_out), plant->pump_power);
}

void plant_mode_CHECKING(PLANT_t *plant)
{
	co_pwm_set_power(&(plant->Pwm_out), 0);
}

void plant_mode_WAITING(PLANT_t *plant)
{
	co_pwm_set_power(&(plant->Pwm_out), 0);
}

