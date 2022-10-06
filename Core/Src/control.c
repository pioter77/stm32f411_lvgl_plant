/*
 * control.c
 *
 *  Created on: Oct 3, 2022
 *      Author: x280
 */


#include "control.h"


void pump_ctrl(void)
{
	tim1Ch1_fill = (uint16_t)(999 * (float)lv_slider_get_value(ui_Slider1) /100.0);
	tim1Ch2_fill = (uint16_t)(999 * (float)lv_slider_get_value(ui_Slider3) /100.0);
}
