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
	.pump_duration=				0,
	.watering_cycle_day= 		0,
	.Pwm_out={
			.tim=				TIM1,
			.tim_channel= 		LL_TIM_CHANNEL_CH1,
	},
	.Timing_watering=			&TIMING.tims_plant1Water,
	.Timing_checking=			&TIMING.tims_plant1Check,
	.Timing_life=				&TIMING.tims_plant1Life,
	.wateringIsDone=			0,
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
	.pump_duration=				0,
	.watering_cycle_day= 		0,
	.Pwm_out={
			.tim=				TIM1,
			.tim_channel= 		LL_TIM_CHANNEL_CH2,
	},
	.Timing_watering=			&TIMING.tims_plant2Water,
	.Timing_checking=			&TIMING.tims_plant2Check,
	.Timing_life=				&TIMING.tims_plant2Life,
	.wateringIsDone=			0,
};

void ctrl_plant_init(PLANT_t *plant)
{

	co_pwm_init(&(plant->Pwm_out));
	co_pwm_set_power(&(plant->Pwm_out), plant->pump_power);

	timingSetLength(plant->Timing_watering, 5000);
	timingSetLength(plant->Timing_checking, 60000);
}

void ctrl_plant_ctrl(PLANT_t *plant)
{
	plant_reset_watering_cycle_count(plant);

	if(plant->isOn == PLANT_IS_OFF) plant->plantState= PLANT_STATE_OFF;
	else if(plant->isOn == PLANT_IS_ON)
	{
		//switch is turned to on posiion so plant process is running
		if(plant->moisture_level < plant->moisture_threshold)				//watering is neeed
		{
			if(RTC_CTRL.hour_c >= plant->time_window_start && RTC_CTRL.hour_c < plant->time_window_end && !plant->wateringIsDone)	//watering can only start when whithin specified time window
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
	plant->wateringIsDone= 0;
	plant->watering_cycle_cnt= 0;
	co_pwm_output_turn_off(&(plant->Pwm_out));
	if(timingIsOn(plant->Timing_checking))	timingStop(plant->Timing_checking);
	if(timingIsOn(plant->Timing_watering))	timingStop(plant->Timing_watering);
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
	if(timingIsOn(plant->Timing_checking))	timingStop(plant->Timing_checking);
	if(timingIsOn(plant->Timing_watering))	timingStop(plant->Timing_watering);

	co_pwm_set_power(&(plant->Pwm_out), 0);
}

void plant_mode_WATERING(PLANT_t *plant)
{

	if(!timingIsOn(plant->Timing_watering))
	{
		timingSetLength(plant->Timing_watering, plant->pump_duration*1000);
		timingStart(plant->Timing_watering);
		co_pwm_set_power(&(plant->Pwm_out), plant->pump_power);
	}

	if(timingIsUp(plant->Timing_watering))
	{
		plant->watering_cycle_cnt++;
		plant->watering_cycle_day= RTC_CTRL.day_c;
		co_pwm_set_power(&(plant->Pwm_out), 0);
		timingStop(plant->Timing_watering);
		plant->wateringIsDone= 1;			//so we can proceed to checking state
	}

}

void plant_mode_CHECKING(PLANT_t *plant)
{

	if(!timingIsOn(plant->Timing_checking))
	{
		timingSetLength(plant->Timing_checking, 60000);		//60s
		timingStart(plant->Timing_checking);
		co_pwm_set_power(&(plant->Pwm_out), 0);
	}

	if(timingIsUp(plant->Timing_checking))
	{
//		plant->watering_cycle_cnt++;
		co_pwm_set_power(&(plant->Pwm_out), 0);
		timingStop(plant->Timing_checking);
//		timingRestart(plant->Timing_checking);
		plant->wateringIsDone= 0;			//so we can proceed to watering state again becouse moisture level hasnt risen enough
	}
//	co_pwm_set_power(&(plant->Pwm_out), 0);
}

void plant_mode_WAITING(PLANT_t *plant)
{
	co_pwm_set_power(&(plant->Pwm_out), 0);
}

/*
 * when the pump is on increment every second of work to pump life variable in order to keep track of how many minutes pump was running
 */
void plant_keep_track_of_life(PLANT_t *plant)
{

}

/*
 * check if previous watering cycle increment day saved is different from current one, if so reset cycle count as new day started
 */
void plant_reset_watering_cycle_count(PLANT_t *plant)
{
	if(plant->watering_cycle_day != RTC_CTRL.day_c) {
		plant->watering_cycle_cnt= 0;
		plant->watering_cycle_day= RTC_CTRL.day_c;
		plant->wateringIsDone= 0;
	}
}
