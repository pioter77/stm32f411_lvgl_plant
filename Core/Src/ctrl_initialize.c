/*
 * initialize.c
 *
 *  Created on: Oct 5, 2022
 *      Author: x280
 */



#include <ctrl_initialize.h>

//#include "ctrl_default_params_defines.h"
#include "rtc.h"
#include "ctrl_autosave.h"


//static void ctrl_initialize_device_parameters(void)
//{
//
//	/*
//	 * here values read from RTC backup registers and written to PARAMS_DEVICE_AUTOSAVE, PARAMS_PLANT1_AUTOSAVE, PARAMS_PLANT2_AUTOSAVE are being applied
//	 * to ui elements and process and device variables
//	 * (settigs set to the previous ones)
//	 *
//	 */
//
//	LCD_PWM.fill= 100;//PARAMS_DEVICE_AUTOSAVE.screenBrigntnLvl;
//
//
//}


void ctrl_initialize(void)
{

//	dma_initialize();
	//adc_initialize();
	//adc_start_conv();

//	i2c_initialize(I2C1);
//	ctrl_load_saved_prev_settings();
//	ctrl_initialize_device_parameters();

	ctrl_autosave_init(&AUTOSAVE_CTRL);
}



