/*
 * ctrl_autosave.c
 *
 *  Created on: 20 mar 2023
 *      Author: X280
 */

#include "ctrl_autosave.h"
#include "ctrl_timing.h"
#include "ctrl_default_params_defines.h"
#include <stdio.h>
#include "ctrl_device.h"
#include "ctrl_process.h"
/*
 * autosave kept in RTC backup registers so Vbat must be connected when device is off
 */





static void ctrl_autosave_load_Dev(void *from, ctrl_autosave_t *autosave)
{
	_Bool isDataOk =1;
	ctrl_autosave_regDev_t *readReg = from;
	//if any of te variables read from register is out of its bounds then we have a reason to suspect all data is wrong so we load defaults
	if(readReg->screenBrigntnLvl==0 || readReg->screenBrigntnLvl>100) 	isDataOk= 0;
	if(readReg->screenTimeVal==0 || readReg->screenTimeVal>255) 		isDataOk= 0;
	if(readReg->screenBrigtnIsAuto >1) 									isDataOk= 0;
	if(readReg->screenTimeIsOn >1) 										isDataOk= 0;

	if(isDataOk)
	{
		//load readout data
		autosave->autoSaveDev.screenBrigntnLvl= 	readReg->screenBrigntnLvl;
		autosave->autoSaveDev.screenBrigtnIsAuto= 	readReg->screenBrigtnIsAuto;
		autosave->autoSaveDev.screenTimeVal= 		readReg->screenTimeVal;
		autosave->autoSaveDev.screenTimeIsOn= 		readReg->screenTimeIsOn;
	}else{
		//load default
		autosave->autoSaveDev.screenBrigntnLvl= 	DEF_DEV_PARAM_SCREEN_BRIGNTNESS_LVL;
		autosave->autoSaveDev.screenBrigtnIsAuto= 	DEF_DEV_PARAM_SCREEN_BRIGHTNESS_AUTO_ON;
		autosave->autoSaveDev.screenTimeVal= 		DEF_DEV_PARAM_SCREEN_TIME_SET;
		autosave->autoSaveDev.screenTimeIsOn= 		DEF_DEV_PARAM_SCREEN_TIME_ISON;
	}

	LCD_PWM.fill= 			autosave->autoSaveDev.screenBrigntnLvl;
	LCD_PWM.isAuto=			autosave->autoSaveDev.screenBrigtnIsAuto;
	LCD_PWM.timeVal=		autosave->autoSaveDev.screenTimeVal;
	LCD_PWM.isTimeOutOn=	autosave->autoSaveDev.screenTimeIsOn;
}

static void ctrl_autosave_load_Plant1(void *from, ctrl_autosave_t *autosave)
{
	_Bool isDataOk =1;
	ctrl_autosave_regPlant_t *readReg = from;
	//if any of te variables read from register is out of its bounds then we have a reason to suspect all data is wrong so we load defaults
	if(readReg->plantIsOn>1) 													isDataOk= 0;
	if(readReg->plantMoistthrshld==0 || readReg->plantMoistthrshld>100) 		isDataOk= 0;
	if(readReg->plantTimeWindowEnd<6 || readReg->plantTimeWindowEnd>23) 		isDataOk= 0;
	if(readReg->plantTimeWindowStart<6 || readReg->plantTimeWindowStart>23) 	isDataOk= 0;

	if(isDataOk)
	{
		//load readout data
		autosave->autoSavePlant1.plantIsOn= 				readReg->plantIsOn;
		autosave->autoSavePlant1.plantMoistthrshld= 		readReg->plantMoistthrshld;
		autosave->autoSavePlant1.plantTimeWindowStart= 		readReg->plantTimeWindowStart;
		autosave->autoSavePlant1.plantTimeWindowEnd= 		readReg->plantTimeWindowEnd;
	}else{
		//load default
		autosave->autoSavePlant1.plantIsOn= 				DEF_DEV_PARAM_PLANT_1_IS_ON;
		autosave->autoSavePlant1.plantMoistthrshld= 		DEF_DEV_PARAM_PLANT_1_MOIST_THRSHLD;
		autosave->autoSavePlant1.plantTimeWindowStart= 		DEF_DEV_PARAM_PLANT_1_TIME_WIND_START;
		autosave->autoSavePlant1.plantTimeWindowEnd= 		DEF_DEV_PARAM_PLANT_1_TIME_WIND_END;
	}

	PLANT1.isOn=					autosave->autoSavePlant1.plantIsOn;
	PLANT1.moisture_threshold=		autosave->autoSavePlant1.plantMoistthrshld;
	PLANT1.time_window_start=		autosave->autoSavePlant1.plantTimeWindowStart;
	PLANT1.time_window_end=			autosave->autoSavePlant1.plantTimeWindowEnd;
}

static void ctrl_autosave_load_Plant1Cd1(void *from, ctrl_autosave_t *autosave)
{
	_Bool isDataOk =1;
	ctrl_autosave_regPlantCd1_t *readReg = from;
	//if any of te variables read from register is out of its bounds then we have a reason to suspect all data is wrong so we load defaults
	if(readReg->plantPumpPower<70 || readReg->plantPumpPower>100) 	isDataOk= 0;
	if(readReg->plantPumpTime==0 || readReg->plantPumpTime>50) 		isDataOk= 0;

	if(isDataOk)
	{
		//load readout data
		autosave->autoSavePlant1Cd1.plantPumpPower= 		readReg->plantPumpPower;
		autosave->autoSavePlant1Cd1.plantPumpTime= 			readReg->plantPumpTime;
	}else{
		//load default
		autosave->autoSavePlant1Cd1.plantPumpPower= 		DEF_DEV_PARAM_PLANT_1_PUMP_POWER;
		autosave->autoSavePlant1Cd1.plantPumpTime= 			DEF_DEV_PARAM_PLANT_1_PUMP_TIME;
	}

	PLANT1.pump_power=			autosave->autoSavePlant1Cd1.plantPumpPower;
	PLANT1.pump_duration=		autosave->autoSavePlant1Cd1.plantPumpTime;
}


static void ctrl_autosave_load_Plant1Cd2(void *from, ctrl_autosave_t *autosave)
{
	_Bool isDataOk =1;
	ctrl_autosave_regPlantCd2_t *readReg = from;
	//if any of te variables read from register is out of its bounds then we have a reason to suspect all data is wrong so we load defaults
	if(readReg->plantLastDayWatered==0 || readReg->plantLastDayWatered>31) 		isDataOk= 0;
	if(readReg->plantLastWateringCycles > 3) 									isDataOk= 0;
	if(readReg->plantPumpLife > 40000) 											isDataOk= 0;

	if(isDataOk)
	{
		//load readout data
		autosave->autoSavePlant1Cd2.plantLastDayWatered= 			readReg->plantLastDayWatered;
		autosave->autoSavePlant1Cd2.plantLastWateringCycles= 		readReg->plantLastWateringCycles;
		autosave->autoSavePlant1Cd2.plantPumpLife= 					readReg->plantPumpLife;
	}else{
		//load default
		autosave->autoSavePlant1Cd2.plantLastDayWatered= 			DEF_DEV_PARAM_PLANT_1_LAST_DAY_WATER;
		autosave->autoSavePlant1Cd2.plantLastWateringCycles= 		DEF_DEV_PARAM_PLANT_1_LAST_DAY_CYCLE_CNT;
		autosave->autoSavePlant1Cd2.plantPumpLife= 					DEF_DEV_PARAM_PLANT_1_PUMP_LIFE;
	}

	PLANT1.watering_cycle_day=		autosave->autoSavePlant1Cd2.plantLastDayWatered;
	PLANT1.watering_cycle_cnt=		autosave->autoSavePlant1Cd2.plantLastWateringCycles;
	PLANT1.pump_life=				autosave->autoSavePlant1Cd2.plantPumpLife;
}

static void ctrl_autosave_load_Plant2(void *from, ctrl_autosave_t *autosave)
{
	_Bool isDataOk =1;
	ctrl_autosave_regPlant_t *readReg = from;
	//if any of te variables read from register is out of its bounds then we have a reason to suspect all data is wrong so we load defaults
	if(readReg->plantIsOn>1) 													isDataOk= 0;
	if(readReg->plantMoistthrshld==0 || readReg->plantMoistthrshld>100) 		isDataOk= 0;
	if(readReg->plantTimeWindowEnd<6 || readReg->plantTimeWindowEnd>23) 		isDataOk= 0;
	if(readReg->plantTimeWindowStart<6 || readReg->plantTimeWindowStart>23) 	isDataOk= 0;

	if(isDataOk)
	{
		//load readout data
		autosave->autoSavePlant2.plantIsOn= 				readReg->plantIsOn;
		autosave->autoSavePlant2.plantMoistthrshld= 		readReg->plantMoistthrshld;
		autosave->autoSavePlant2.plantTimeWindowStart= 		readReg->plantTimeWindowStart;
		autosave->autoSavePlant2.plantTimeWindowEnd= 		readReg->plantTimeWindowEnd;
	}else{
		//load default
		autosave->autoSavePlant2.plantIsOn= 				DEF_DEV_PARAM_PLANT_2_IS_ON;
		autosave->autoSavePlant2.plantMoistthrshld= 		DEF_DEV_PARAM_PLANT_2_MOIST_THRSHLD;
		autosave->autoSavePlant2.plantTimeWindowStart= 		DEF_DEV_PARAM_PLANT_2_TIME_WIND_START;
		autosave->autoSavePlant2.plantTimeWindowEnd= 		DEF_DEV_PARAM_PLANT_2_TIME_WIND_END;
	}

	PLANT2.isOn=					autosave->autoSavePlant2.plantIsOn;
	PLANT2.moisture_threshold=		autosave->autoSavePlant2.plantMoistthrshld;
	PLANT2.time_window_start=		autosave->autoSavePlant2.plantTimeWindowStart;
	PLANT2.time_window_end=			autosave->autoSavePlant2.plantTimeWindowEnd;
}

static void ctrl_autosave_load_Plant2Cd1(void *from, ctrl_autosave_t *autosave)
{
	_Bool isDataOk =1;
	ctrl_autosave_regPlantCd1_t *readReg = from;
	//if any of te variables read from register is out of its bounds then we have a reason to suspect all data is wrong so we load defaults
	if(readReg->plantPumpPower<70 || readReg->plantPumpPower>100) 	isDataOk= 0;
	if(readReg->plantPumpTime==0 || readReg->plantPumpTime>50) 		isDataOk= 0;

	if(isDataOk)
	{
		//load readout data
		autosave->autoSavePlant2Cd1.plantPumpPower= 		readReg->plantPumpPower;
		autosave->autoSavePlant2Cd1.plantPumpTime= 			readReg->plantPumpTime;
	}else{
		//load default
		autosave->autoSavePlant2Cd1.plantPumpPower= 		DEF_DEV_PARAM_PLANT_2_PUMP_POWER;
		autosave->autoSavePlant2Cd1.plantPumpTime= 			DEF_DEV_PARAM_PLANT_2_PUMP_TIME;
	}

	PLANT2.pump_power=			autosave->autoSavePlant2Cd1.plantPumpPower;
	PLANT2.pump_duration=		autosave->autoSavePlant2Cd1.plantPumpTime;
}

static void ctrl_autosave_load_Plant2Cd2(void *from, ctrl_autosave_t *autosave)
{
	_Bool isDataOk =1;
	ctrl_autosave_regPlantCd2_t *readReg = from;
	//if any of te variables read from register is out of its bounds then we have a reason to suspect all data is wrong so we load defaults
	if(readReg->plantLastDayWatered==0 || readReg->plantLastDayWatered>31) 		isDataOk= 0;
	if(readReg->plantLastWateringCycles > 3) 									isDataOk= 0;
	if(readReg->plantPumpLife > 40000) 											isDataOk= 0;

	if(isDataOk)
	{
		//load readout data
		autosave->autoSavePlant2Cd2.plantLastDayWatered= 			readReg->plantLastDayWatered;
		autosave->autoSavePlant2Cd2.plantLastWateringCycles= 		readReg->plantLastWateringCycles;
		autosave->autoSavePlant2Cd2.plantPumpLife= 					readReg->plantPumpLife;
	}else{
		//load default
		autosave->autoSavePlant2Cd2.plantLastDayWatered= 			DEF_DEV_PARAM_PLANT_2_LAST_DAY_WATER;
		autosave->autoSavePlant2Cd2.plantLastWateringCycles= 		DEF_DEV_PARAM_PLANT_2_LAST_DAY_CYCLE_CNT;
		autosave->autoSavePlant2Cd2.plantPumpLife= 					DEF_DEV_PARAM_PLANT_2_PUMP_LIFE;
	}

	PLANT2.watering_cycle_day=		autosave->autoSavePlant2Cd2.plantLastDayWatered;
	PLANT2.watering_cycle_cnt=		autosave->autoSavePlant2Cd2.plantLastWateringCycles;
	PLANT2.pump_life=				autosave->autoSavePlant2Cd2.plantPumpLife;
}

static void ctrl_autosave_track_variable8b(uint32_t adr, void *regPtr, uint8_t *prevVal, uint8_t *currVal)
{
	if(*prevVal != *currVal) {
		*prevVal= *currVal;
		ctrl_autosave_save_register(adr, (uint32_t *)regPtr);
	}
}

static void ctrl_autosave_track_variable16b(uint32_t adr, void *regPtr, uint16_t *prevVal, uint16_t *currVal)
{
	if(*prevVal != *currVal) *prevVal= *currVal;
}

static void ctrl_autosave_track_variable32b(uint32_t adr, void *regPtr, uint32_t *prevVal, uint32_t *currVal)
{
	if(*prevVal != *currVal) *prevVal= *currVal;
}



static void ctrl_autosave_init_timing(ctrl_autosave_t *autosave)
{
	autosave->tims_ptr= &TIMING.tims_autosave;

	timingStop(autosave->tims_ptr);
	timingSetLength(autosave->tims_ptr, AUTOSAVE_TIME_THRESHOLD_MS);
	timingStart(autosave->tims_ptr);
}

ctrl_autosave_t AUTOSAVE_CTRL={

};

static void ctrl_autosave_load_storedBackup(ctrl_autosave_t *autosave)
{
	/*
	 * we have 20 RTC backup registers for our disposal:
	 */

	ctrl_autosave_load_register(LL_RTC_BKP_DR1, 	&autosave->autoSaveDev, 		&ctrl_autosave_load_Dev );
	ctrl_autosave_load_register(LL_RTC_BKP_DR2, 	&autosave->autoSavePlant1, 		&ctrl_autosave_load_Plant1);
	ctrl_autosave_load_register(LL_RTC_BKP_DR3, 	&autosave->autoSavePlant1Cd1, 	&ctrl_autosave_load_Plant1Cd1);
	ctrl_autosave_load_register(LL_RTC_BKP_DR4, 	&autosave->autoSavePlant1Cd2, 	&ctrl_autosave_load_Plant1Cd2);
	ctrl_autosave_load_register(LL_RTC_BKP_DR5, 	&autosave->autoSavePlant2, 		&ctrl_autosave_load_Plant2);
	ctrl_autosave_load_register(LL_RTC_BKP_DR6, 	&autosave->autoSavePlant2Cd1, 	&ctrl_autosave_load_Plant2Cd1);
	ctrl_autosave_load_register(LL_RTC_BKP_DR7, 	&autosave->autoSavePlant2Cd2, 	&ctrl_autosave_load_Plant2Cd2);



}

/*
 * init timing used for keeping track of designed variables
 * load variables from RTC regs
 */
void ctrl_autosave_init(ctrl_autosave_t *autosave)
{
	ctrl_autosave_init_timing(autosave);
	//now load regosters from memory:
	ctrl_autosave_load_storedBackup(autosave);
}

void ctrl_autosave_load_register(uint32_t adr, void *to, void(*compFcnPtr)(void *, ctrl_autosave_t *))
{
		uint32_t readRegVal= 0;

		if(adr>19)
		{
			#ifdef DEBUG_DEVICE
						printf("\n RTC register address out of bounds");
						return;
			#endif
		}
		readRegVal = LL_RTC_BAK_GetRegister(RTC, adr);
		if(compFcnPtr == NULL){
			#ifdef DEBUG_DEVICE
						printf("\n RTC register load register compare function pointer not assigned");
						return;
			#endif
		}
		(*compFcnPtr)(&readRegVal, to);

}

void ctrl_autosave_save_register(uint32_t adr, uint32_t *data)
{
	LL_RTC_DisableWriteProtection(RTC);	//enable access to rtc domain regs
	LL_RTC_BAK_SetRegister(RTC, adr, *data);
	LL_RTC_EnableWriteProtection(RTC);	//locks access to rtc domain regs
}

//main loop function, monitors
void ctrl_autosave(ctrl_autosave_t *autosave)
{
	if(timingIsOn(autosave->tims_ptr))
	{
		if(timingIsUp(autosave->tims_ptr))
		{
			//check if monitored values changed from previous entry here if so then save them to RTC backup registers
			ctrl_autosave_track_variable8b(LL_RTC_BKP_DR1, &autosave->autoSaveDev, &autosave->autoSaveDev.screenBrigntnLvl, (uint8_t *)&LCD_PWM.fill);
			ctrl_autosave_track_variable8b(LL_RTC_BKP_DR1, &autosave->autoSaveDev, &autosave->autoSaveDev.screenTimeVal, (uint8_t *)&LCD_PWM.timeVal);

			//plant1:
			ctrl_autosave_track_variable8b(LL_RTC_BKP_DR2, &autosave->autoSavePlant1, &autosave->autoSavePlant1.plantIsOn, 				&PLANT1.isOn);
			ctrl_autosave_track_variable8b(LL_RTC_BKP_DR2, &autosave->autoSavePlant1, &autosave->autoSavePlant1.plantMoistthrshld, 		&PLANT1.moisture_threshold);
			ctrl_autosave_track_variable8b(LL_RTC_BKP_DR2, &autosave->autoSavePlant1, &autosave->autoSavePlant1.plantTimeWindowStart, 	&PLANT1.time_window_start);
			ctrl_autosave_track_variable8b(LL_RTC_BKP_DR2, &autosave->autoSavePlant1, &autosave->autoSavePlant1.plantTimeWindowEnd, 	&PLANT1.time_window_end);

			ctrl_autosave_track_variable8b(LL_RTC_BKP_DR3, &autosave->autoSavePlant1Cd1, &autosave->autoSavePlant1Cd1.plantPumpPower, 	&PLANT1.pump_power);
			ctrl_autosave_track_variable8b(LL_RTC_BKP_DR3, &autosave->autoSavePlant1Cd1, &autosave->autoSavePlant1Cd1.plantPumpTime, 	&PLANT1.pump_duration);
//			ctrl_autosave_track_variable8b(LL_RTC_BKP_DR3, &autosave->autoSavePlant1Cd1, &autosave->autoSavePlant1Cd1.dummy, &XX);
//			ctrl_autosave_track_variable8b(LL_RTC_BKP_DR3, &autosave->autoSavePlant1Cd1, &autosave->autoSavePlant1Cd1.dummy2, &XX);

			ctrl_autosave_track_variable8b(LL_RTC_BKP_DR4, &autosave->autoSavePlant1Cd2, &autosave->autoSavePlant1Cd2.plantLastDayWatered, 		&PLANT1.watering_cycle_day);
			ctrl_autosave_track_variable8b(LL_RTC_BKP_DR4, &autosave->autoSavePlant1Cd2, &autosave->autoSavePlant1Cd2.plantLastWateringCycles, 	&PLANT1.watering_cycle_cnt);
			ctrl_autosave_track_variable16b(LL_RTC_BKP_DR4, &autosave->autoSavePlant1Cd2, &autosave->autoSavePlant1Cd2.plantPumpLife, 			&PLANT1.pump_life);

			//plant2:
			ctrl_autosave_track_variable8b(LL_RTC_BKP_DR5, &autosave->autoSavePlant2, &autosave->autoSavePlant2.plantIsOn, 				&PLANT2.isOn);
			ctrl_autosave_track_variable8b(LL_RTC_BKP_DR5, &autosave->autoSavePlant2, &autosave->autoSavePlant2.plantMoistthrshld, 		&PLANT2.moisture_threshold);
			ctrl_autosave_track_variable8b(LL_RTC_BKP_DR5, &autosave->autoSavePlant2, &autosave->autoSavePlant2.plantTimeWindowStart, 	&PLANT2.time_window_start);
			ctrl_autosave_track_variable8b(LL_RTC_BKP_DR5, &autosave->autoSavePlant2, &autosave->autoSavePlant2.plantTimeWindowEnd, 	&PLANT2.time_window_end);

			ctrl_autosave_track_variable8b(LL_RTC_BKP_DR6, &autosave->autoSavePlant2Cd1, &autosave->autoSavePlant2Cd1.plantPumpPower, 	&PLANT2.pump_power);
			ctrl_autosave_track_variable8b(LL_RTC_BKP_DR6, &autosave->autoSavePlant2Cd1, &autosave->autoSavePlant2Cd1.plantPumpTime, 	&PLANT2.pump_duration);
//			ctrl_autosave_track_variable8b(LL_RTC_BKP_DR3, &autosave->autoSavePlant2Cd1, &autosave->autoSavePlant2Cd1.dummy, &XX);
//			ctrl_autosave_track_variable8b(LL_RTC_BKP_DR3, &autosave->autoSavePlant2Cd1, &autosave->autoSavePlant2Cd1.dummy2, &XX);

			ctrl_autosave_track_variable8b(LL_RTC_BKP_DR7, &autosave->autoSavePlant2Cd2, &autosave->autoSavePlant2Cd2.plantLastDayWatered, 		&PLANT2.watering_cycle_day);
			ctrl_autosave_track_variable8b(LL_RTC_BKP_DR7, &autosave->autoSavePlant2Cd2, &autosave->autoSavePlant2Cd2.plantLastWateringCycles, 	&PLANT2.watering_cycle_cnt);
			ctrl_autosave_track_variable16b(LL_RTC_BKP_DR7, &autosave->autoSavePlant2Cd2, &autosave->autoSavePlant2Cd2.plantPumpLife, 			&PLANT2.pump_life);

			timingRestart(autosave->tims_ptr);
		}
	}
}


