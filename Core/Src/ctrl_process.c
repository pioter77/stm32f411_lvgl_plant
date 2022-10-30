/*
 * ctrl_process.c
 *
 *  Created on: 30 paź 2022
 *      Author: x300
 */

#include "ctrl_process.h"
#include  "ctrl_measure.h"

PLANT_t PLANT1= {
	.moisture_threshold= 0,
	.moisture_level= 0,
	.moisture_level_raw= 0,
};

PLANT_t PLANT2= {
		.moisture_threshold= 0,
		.moisture_level= 0,
		.moisture_level_raw= 0,
};
void ctrl_plant_init(PLANT_t *plant);
void ctrl_plant_ctrl(PLANT_t *plant);

void plant_switch_off(PLANT_t *plant);
void plant_switch_on(PLANT_t *plant);

void plant_mode_OFF(PLANT_t *plant);
void plant_mode_STANDBY(PLANT_t *plant);
void plant_mode_WATERING(PLANT_t *plant);
void plant_mode_CHECKING(PLANT_t *plant);
void plant_mode_WAITING(PLANT_t *plant);
