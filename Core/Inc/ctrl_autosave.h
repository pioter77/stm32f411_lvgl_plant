/*
 * ctrl_autosave.h
 *
 *  Created on: 20 mar 2023
 *      Author: X280
 */

#ifndef INC_CTRL_AUTOSAVE_H_
#define INC_CTRL_AUTOSAVE_H_

#include "rtc.h"
#include "ctrl_timing.h"

#define AUTOSAVE_TIME_THRESHOLD_MS		4000				//4 s delay after last variable change

typedef struct ctrl_autosve_regPlant_T{
	//1st register
	uint8_t plantIsOn;
	uint8_t plantMoistthrshld;
	uint8_t plantTimeWindowStart;
	uint8_t plantTimeWindowEnd;
}ctrl_autosave_regPlant_t;

typedef struct ctrl_autosve_regPlantCd1_T{
	//2nd register
	uint8_t plantPumpPower;
	uint8_t plantPumpTime;
	uint8_t dummy;					//place holder
	uint8_t dummy2;					//place holder
}ctrl_autosave_regPlantCd1_t;

typedef struct ctrl_autosve_regPlantCd2_T{
	//3rd register
	uint8_t plantLastDayWatered;							//holds the day of last watering took place in order not to overwater in case of power outage and reboot
	uint8_t plantLastWateringCycles;						//holds last recorded watering cycles count, updated every watering cycle
	uint16_t plantPumpLife;
}ctrl_autosave_regPlantCd2_t;

typedef struct ctrl_autosve_regDev_T{
	uint8_t screenBrigntnLvl;
	uint8_t screenBrigtnIsAuto;
	uint8_t screenTimeVal;
	uint8_t screenTimeIsOn;
}ctrl_autosave_regDev_t;

typedef struct ctrl_autosave_T{
	tims_t *tims_ptr;
	ctrl_autosave_regPlant_t 		autoSavePlant1;					//main parameters for plant 1
	ctrl_autosave_regPlant_t 		autoSavePlant2;					//main parameters for plant 2
	ctrl_autosave_regPlantCd1_t 	autoSavePlant1Cd1;				//rest of parameters for plant 1
	ctrl_autosave_regPlantCd1_t 	autoSavePlant2Cd1;				//rest of parameters for plant 2
	ctrl_autosave_regPlantCd2_t 	autoSavePlant1Cd2;				//rest of parameters for plant 1
	ctrl_autosave_regPlantCd2_t 	autoSavePlant2Cd2;				//rest of parameters for plant 2
	ctrl_autosave_regDev_t			autoSaveDev;					//parameters of the device that need saving
}ctrl_autosave_t;


extern ctrl_autosave_t AUTOSAVE_CTRL;

void ctrl_autosave_init(ctrl_autosave_t *autosave);
void ctrl_autosave(ctrl_autosave_t *autosave);
void ctrl_autosave_load_register(uint32_t adr, void *to, void(*compFcnPtr)(void *, ctrl_autosave_t *));
void ctrl_autosave_save_register(uint32_t adr, uint32_t *data);

#endif /* INC_CTRL_AUTOSAVE_H_ */
