/*
 * initialize.h
 *
 *  Created on: Oct 5, 2022
 *      Author: x280
 */

#ifndef INC_CTRL_INITIALIZE_H_
#define INC_CTRL_INITIALIZE_H_

#include "ctrl_measure.h"
#include "ctrl_output.h"
#include "ctrl_device.h"
//
//typedef struct params_plant_autoSave_T{
//	//1st register
//
//	uint32_t plantIsOn					:1;
//	uint32_t plantMoistthrshld			:7;
//	uint32_t plantTimeWindowStart		:5;
//	uint32_t plantTimeWindowEnd			:5;
//	uint32_t plantPumpPower				:7;
//	uint32_t plantPumpTime				:6;
//	uint32_t dummy						:1;					//place holder
//
//	//2nd register
//	uint32_t plantLastDayWatered		:5;					//holds the day of last watering took place in order not to overwater in case of power outage and reboot
//	uint32_t plantLastWateringCycles	:3;					//holds last recorded watering cycles count, updated every watering cycle
//	uint32_t dummy2						:8;					//place hodler 2
//	uint32_t plantPumpLife				:16;
//}params_plant_autoSave_t;
//
//typedef struct params_device_autoSave_T{
//	uint32_t screenBrigntnLvl			:7;
//	uint32_t screenBrigtnIsAuto			:1;
//	uint32_t screenTimeVal				:9;
//	uint32_t screenTimeIsOn				:1;
//	uint32_t dummy						:14;				//place holder
//}params_device_autoSave_t;
//
//extern params_plant_autoSave_t 			PARAMS_PLANT1_AUTOSAVE;
//extern params_plant_autoSave_t 			PARAMS_PLANT2_AUTOSAVE;
//extern params_device_autoSave_t 		PARAMS_DEVICE_AUTOSAVE;



void ctrl_initialize(void);


#endif /* INC_CTRL_INITIALIZE_H_ */
