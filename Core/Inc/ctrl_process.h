/*
 * ctrl_process.h
 *
 *  Created on: 30 paź 2022
 *      Author: x300
 */

#ifndef INC_CTRL_PROCESS_H_
#define INC_CTRL_PROCESS_H_

#include "main.h"
#include "ctrl_measure.h"
#include "ctrl_output.h"
#include "ctrl_rtc.h"
#include "ctrl_timing.h"

typedef enum {PLANT_IS_OFF=0, PLANT_IS_ON} plantIsOn_t;
typedef enum {PLANT_STATE_OFF= 0, PLANT_STATE_STANDBY, PLANT_STATE_WATERING, PLANT_STATE_CHECKING, PLANT_STATE_WAITING} plantState_t;

/*
 * +PLANT_STATE_OFF: 		when plant is toggled to off state and not used, process isnt running, watter wont flow and adc readouts are ignored
 * +PLANT_STATE_STANDBY:	when plant is toggled on state and process is running but soil humidity level is higher than watering threshold so nothing than updating adc to screen is needed
 * +PLANT_STATE_WATERING:   when plant is toggled on state and no other plant isnt being watered and time is within time window so water is being pumped into the plant pot by the pump
 * +PLANT_STATE_CHECKING:   when plant is toggled on state and plant has been in WATERING state up to 20 mins before so we check if water ammount pumped to plant was sufficient and if humidity level
 * 							required hasnt been reached we try to water the plant again in hope tat humidity will increase enough
 * +PLANT_STATE_WAITING		when plant is toggled on state and humidty level is lover than required but cannot be switched to WATERIGN state becouse other pump is being watered or current time
 * 							isnt within specified time widnow for watering
 */
typedef struct PLANT_T{
	plantIsOn_t isOn;
	plantState_t plantState;
	uint8_t moisture_level;					//current soil moisture level read rom sensor and converted to % values 0-100% range
	uint8_t moisture_threshold;				//specified soil humidity level when watering will start in % 0-100% range
	uint8_t time_window_start;
	uint8_t time_window_end;
	uint8_t pump_power;						//specified pump power when running
	uint8_t pump_duration;					//specified pump running time
	uint16_t pump_life;						//read from memory

	uint8_t wateringIsDone;					//this flag when @1->we can enter checking cycle as watering has just finished, when @0->we can enter watering couse we heave already waited for moisture lvl to rise or its first watering that day
	uint8_t watering_cycle_cnt;				//number of times pump was on this day
	uint8_t watering_cycle_max;				//max number of watering cycles ofr this plant per day
	uint8_t watering_cycle_day;				//date day number on which cycle count was last incremented, based on this resetting cycle no @00:00 each day is done

	uint16_t moisture_level_raw;			//raw adc readout 0-4095


	PWM_OUT_t Pwm_out;						//pump pwm output control structure
	tims_t *Timing_watering;				//pointer to the timer to keep track of watering timeout
	tims_t *Timing_checking;				//pointer to the timer to keep track of checking timeout after watering cycle
	tims_t *Timing_life;					//pointer to the timer to keep track of pump life (set to be up @1s)
}PLANT_t;

extern PLANT_t PLANT1;
extern PLANT_t PLANT2;

void ctrl_plant_init(PLANT_t *plant);
void plant_load_settings(PLANT_t *plant);			//load settings from non volatile memory after bootup
void ctrl_plant_ctrl(PLANT_t *plant);

void plant_switch_off(PLANT_t *plant);
void plant_switch_on(PLANT_t *plant);

void plant_mode_OFF(PLANT_t *plant);
void plant_mode_STANDBY(PLANT_t *plant);
void plant_mode_WATERING(PLANT_t *plant);
void plant_mode_CHECKING(PLANT_t *plant);
void plant_mode_WAITING(PLANT_t *plant);

void plant_keep_track_of_life(PLANT_t *plant);
void plant_reset_watering_cycle_count(PLANT_t *plant);




#endif /* INC_CTRL_PROCESS_H_ */
