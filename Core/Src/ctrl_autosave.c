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

}

static void ctrl_autosave_load_Plant1Cd1(void *from, ctrl_autosave_t *autosave)
{

}


static void ctrl_autosave_load_Plant1Cd2(void *from, ctrl_autosave_t *autosave)
{

}

static void ctrl_autosave_load_Plant2(void *from, ctrl_autosave_t *autosave)
{

}

static void ctrl_autosave_load_Plant2Cd1(void *from, ctrl_autosave_t *autosave)
{

}

static void ctrl_autosave_load_Plant2Cd2(void *from, ctrl_autosave_t *autosave)
{

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
			timingRestart(autosave->tims_ptr);
		}
	}
}


