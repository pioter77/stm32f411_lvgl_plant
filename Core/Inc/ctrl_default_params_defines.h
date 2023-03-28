/*
 * ctrl_default_params_defines.h
 *
 *  Created on: 19 mar 2023
 *      Author: X280
 */

#ifndef INC_CTRL_DEFAULT_PARAMS_DEFINES_H_
#define INC_CTRL_DEFAULT_PARAMS_DEFINES_H_

//*****************************************************************************************************************************************************************
#define DEF_DEV_PARAM_SCREEN_BRIGNTNESS_LVL						100						//screen brightness level 								1-100 		[%]
#define DEF_DEV_PARAM_SCREEN_BRIGHTNESS_AUTO_ON					0						//screen brightness level automatic flag				0, 1
#define DEF_DEV_PARAM_SCREEN_TIME_SET							0						//screen time after it goes dark						30-300		[s]
#define DEF_DEV_PARAM_SCREEN_TIME_ISON							0						//screen time black out enable flag						0, 1

//plant 1 settings:
#define DEF_DEV_PARAM_PLANT_1_IS_ON								0						//plant 1 toggle switch state 							0, 1
#define DEF_DEV_PARAM_PLANT_1_MOIST_THRSHLD						1						//plant 1 moisture threshold set						1-100 		[%]
#define DEF_DEV_PARAM_PLANT_1_TIME_WIND_START					6						//plant 1 watering time window start					6-23
#define DEF_DEV_PARAM_PLANT_1_TIME_WIND_END						23						//plant 1 watering time window end						6-23
#define DEF_DEV_PARAM_PLANT_1_PUMP_POWER						100						//plant 1 pump power set 								70-100 		[%]
#define DEF_DEV_PARAM_PLANT_1_PUMP_TIME							10						//plant 1 pump interval time set 						1-50		[s]
#define DEF_DEV_PARAM_PLANT_1_PUMP_LIFE							0						//plant pump life that passed							0-65535		[s]
#define DEF_DEV_PARAM_PLANT_1_LAST_DAY_WATER					0						//the last day that watering has taken place			1-31
#define DEF_DEV_PARAM_PLANT_1_LAST_DAY_CYCLE_CNT				0						//the cycle count on last day watering recorded 		0-3

//plant 1 settings:
#define DEF_DEV_PARAM_PLANT_2_IS_ON								0						//plant 2 toggle switch state 							0, 1
#define DEF_DEV_PARAM_PLANT_2_MOIST_THRSHLD						1						//plant 2 moisture threshold set						1-100 		[%]
#define DEF_DEV_PARAM_PLANT_2_TIME_WIND_START					6						//plant 2 watering time window start					6-23
#define DEF_DEV_PARAM_PLANT_2_TIME_WIND_END						23						//plant 2 watering time window end						6-23
#define DEF_DEV_PARAM_PLANT_2_PUMP_POWER						100						//plant 2 pump power set 								70-100 		[%]
#define DEF_DEV_PARAM_PLANT_2_PUMP_TIME							10						//plant 2 pump interval time set 						1-50		[s]
#define DEF_DEV_PARAM_PLANT_2_PUMP_LIFE							0						//plant pump life that passed							0-65535		[s]
#define DEF_DEV_PARAM_PLANT_2_LAST_DAY_WATER					0						//the last day that watering has taken place			1-31
#define DEF_DEV_PARAM_PLANT_2_LAST_DAY_CYCLE_CNT				0						//the cycle count on last day watering recorded 		0-3
//*****************************************************************************************************************************************************************

#endif /* INC_CTRL_DEFAULT_PARAMS_DEFINES_H_ */
