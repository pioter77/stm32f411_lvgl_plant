/*
 * initialize.c
 *
 *  Created on: Oct 5, 2022
 *      Author: x280
 */



#include <ctrl_initialize.h>

#include "ctrl_default_params_defines.h"
#include "rtc.h"


params_plant_autoSave_t 	PARAMS_PLANT1_AUTOSAVE={

};

params_plant_autoSave_t PARAMS_PLANT2_AUTOSAVE={

};

params_device_autoSave_t PARAMS_DEVICE_AUTOSAVE={

};


static void ctrl_load_saved_prev_settings(void)
{
	/*
	 * we have 20 RTC backup registers for our disposal:
	 */
	//reg 0: device settings
	uint32_t readRegVal= 0;
	readRegVal = LL_RTC_BAK_GetRegister(RTC, LL_RTC_BKP_DR0);
	if(readRegVal)
	{
		//sth written so we proceed
		params_device_autoSave_t p_readDev={};
		memcpy(&p_readDev, &readRegVal, 1);

		PARAMS_DEVICE_AUTOSAVE.screenBrigtnIsAuto= 	p_readDev.screenBrigtnIsAuto;
		if(p_readDev.screenBrigntnLvl<=100 && p_readDev.screenBrigntnLvl) PARAMS_DEVICE_AUTOSAVE.screenBrigntnLvl=	p_readDev.screenBrigntnLvl;
		else  PARAMS_DEVICE_AUTOSAVE.screenBrigntnLvl= DEF_DEV_PARAM_SCREEN_BRIGNTNESS_LVL;

		PARAMS_DEVICE_AUTOSAVE.screenTimeIsOn= 	p_readDev.screenTimeIsOn;
		if(p_readDev.screenTimeVal<= 300 && p_readDev.screenTimeVal>= 30) PARAMS_DEVICE_AUTOSAVE.screenTimeVal=	p_readDev.screenTimeVal;
		else  PARAMS_DEVICE_AUTOSAVE.screenTimeVal= DEF_DEV_PARAM_SCREEN_TIME_SET;
	}
	//reg 1: plant 1 part 1 settings
	readRegVal= 0;
	readRegVal = LL_RTC_BAK_GetRegister(RTC, LL_RTC_BKP_DR1);
	if(readRegVal)
	{
		//sth written so we proceed
		params_plant_autoSave_t p_readPlant;
		memcpy(&p_readPlant, &readRegVal, 1);
	}
	//reg 2: plant 1 part 2 settings
	readRegVal= 0;
	readRegVal = LL_RTC_BAK_GetRegister(RTC, LL_RTC_BKP_DR2);
	if(readRegVal)
	{
		//sth written so we proceed
		params_plant_autoSave_t p_readPlant;
		memcpy(&p_readPlant+1, &readRegVal, 1);
	}

	//reg 3: plant 2 part 1 settings
	readRegVal= 0;
	readRegVal = LL_RTC_BAK_GetRegister(RTC, LL_RTC_BKP_DR3);
	if(readRegVal)
	{
		//sth written so we proceed
		params_plant_autoSave_t p_readPlant;
		memcpy(&p_readPlant, &readRegVal, 1);
	}
	//reg 4: plant 2 part 2 settings
	readRegVal= 0;
	readRegVal = LL_RTC_BAK_GetRegister(RTC, LL_RTC_BKP_DR4);
	if(readRegVal)
	{
		//sth written so we proceed
		params_plant_autoSave_t p_readPlant;
		memcpy(&p_readPlant+1, &readRegVal, 1);
	}
}

static void ctrl_initialize_device_parameters(void)
{

	/*
	 * here values read from RTC backup registers and written to PARAMS_DEVICE_AUTOSAVE, PARAMS_PLANT1_AUTOSAVE, PARAMS_PLANT2_AUTOSAVE are being applied
	 * to ui elements and process and device variables
	 * (settigs set to the previous ones)
	 *
	 */

	LCD_PWM.fill= 100;//PARAMS_DEVICE_AUTOSAVE.screenBrigntnLvl;


}


void ctrl_initialize(void)
{

//	dma_initialize();
	//adc_initialize();
	//adc_start_conv();

//	i2c_initialize(I2C1);
	ctrl_load_saved_prev_settings();
	ctrl_initialize_device_parameters();


}



