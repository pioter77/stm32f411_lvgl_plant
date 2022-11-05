/*
 * fcnUi_chart.c
 *
 *  Created on: Oct 6, 2022
 *      Author: x280
 */
#include "ctrl_ui.h"
#include "debug.h"

UI_CTRL_t UI_CTRL={
		.outConfigNo= OUT1_CONF
};


void cui_chart_init(void)
{
	lv_chart_set_type(ui_Chart1, LV_CHART_TYPE_LINE);

	lv_chart_series_t * ser1 = lv_chart_add_series(ui_Chart1, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);	//adc readout 1
	lv_chart_series_t * ser2 = lv_chart_add_series(ui_Chart1, lv_palette_main(LV_PALETTE_GREEN), LV_CHART_AXIS_SECONDARY_Y);		//adc readout 2

    lv_chart_set_next_value(ui_Chart1, ser1, 10);
    lv_chart_set_next_value(ui_Chart1, ser1, 10);
    lv_chart_set_next_value(ui_Chart1, ser1, 10);
    lv_chart_set_next_value(ui_Chart1, ser1, 10);
    lv_chart_set_next_value(ui_Chart1, ser1, 10);
    lv_chart_set_next_value(ui_Chart1, ser1, 10);
    lv_chart_set_next_value(ui_Chart1, ser1, 10);
    lv_chart_set_next_value(ui_Chart1, ser1, 30);
    lv_chart_set_next_value(ui_Chart1, ser1, 70);
    lv_chart_set_next_value(ui_Chart1, ser1, 90);



    ser2->y_points[0] = 90;
    ser2->y_points[1] = 70;
    ser2->y_points[2] = 65;
    ser2->y_points[3] = 65;
    ser2->y_points[4] = 65;
    ser2->y_points[5] = 65;
    ser2->y_points[6] = 65;
    ser2->y_points[7] = 65;
    ser2->y_points[8] = 65;
    ser2->y_points[9] = 65;
}

void cui_chart_update(void)
{
	lv_chart_refresh(ui_Chart1);
}



static void cui_events_assign(void)
{
	lv_obj_add_event_cb(ui_Out1Arc, 			cui_Out1_clicked, 				LV_EVENT_RELEASED, 			NULL);
	lv_obj_add_event_cb(ui_Out2Arc, 			cui_Out2_clicked, 				LV_EVENT_RELEASED, 			NULL);
	lv_obj_add_event_cb(ui_Out1Switch, 			cui_Out1Switch_toggled, 		LV_EVENT_RELEASED, 			NULL);
	lv_obj_add_event_cb(ui_Out2Switch, 			cui_Out2Switch_toggled, 		LV_EVENT_RELEASED, 			NULL);
	lv_obj_add_event_cb(ui_OutputThrshldSlider, cui_OutputThrshld_changed, 		LV_EVENT_VALUE_CHANGED, 	NULL);
	lv_obj_add_event_cb(ui_TimeWindowSlider, 	cui_OutTimeWindow_changed, 		LV_EVENT_VALUE_CHANGED, 	NULL);
	lv_obj_add_event_cb(ui_OutputPowerSlider, 	cui_PumpPower_changed, 			LV_EVENT_VALUE_CHANGED, 	NULL);
	lv_obj_add_event_cb(ui_OutputTimeSlider, 	cui_PumpTime_changed, 			LV_EVENT_VALUE_CHANGED,	 	NULL);
	lv_obj_add_event_cb(ui_ScreenTimeSlider, 	cui_ScreenTime_changed, 		LV_EVENT_VALUE_CHANGED, 	NULL);
	lv_obj_add_event_cb(ui_ScreenBrigtSlider, 	cui_ScreenBrightness_changed, 	LV_EVENT_VALUE_CHANGED, 	NULL);
	lv_obj_add_event_cb(ui_TimeDateSaveButton, 	cui_SaveClockDate_clicked, 		LV_EVENT_RELEASED, 			NULL);

}

void cui_init(void)
{
	cui_events_assign();
	cui_chart_init();
	cui_chart_update();
}
//***************************************************UI elements EVENTS:***************************************
void cui_Out1_clicked(lv_event_t * event)
{
#if DEBUG_DEVICE
	printf("\n i entered out1 event callback! ");
#endif
	UI_CTRL.outConfigNo= OUT1_CONF;
	lv_label_set_text(ui_ConfigScreenInfoLabel, "Plant 1 config");
	lv_slider_set_value(ui_OutputThrshldSlider, 	PLANT1.moisture_threshold, 		LV_ANIM_OFF);
	lv_slider_set_left_value(ui_TimeWindowSlider, 	PLANT1.time_window_start, 		LV_ANIM_OFF);
	lv_slider_set_value(ui_TimeWindowSlider, 		PLANT1.time_window_end, 		LV_ANIM_OFF);
	lv_slider_set_value(ui_OutputPowerSlider, 		PLANT1.pump_power, 				LV_ANIM_OFF);
	lv_slider_set_value(ui_OutputTimeSlider, 		PLANT1.pump_duration, 			LV_ANIM_OFF);
	char buff[]="00000 min";
	sprintf((char *)buff, "%.5d min", PLANT1.pump_life);
	lv_label_set_text(ui_OutputLifeLabelVal, buff);
}

void cui_Out2_clicked(lv_event_t * event)
{
#if DEBUG_DEVICE
	printf("\n i entered out2 event callback! ");
#endif
	UI_CTRL.outConfigNo= OUT2_CONF;
	lv_label_set_text(ui_ConfigScreenInfoLabel, "Plant 2 config");
	lv_slider_set_value(ui_OutputThrshldSlider,     PLANT2.moisture_threshold, 		LV_ANIM_OFF);
	lv_slider_set_left_value(ui_TimeWindowSlider, 	PLANT2.time_window_start, 		LV_ANIM_OFF);
	lv_slider_set_value(ui_TimeWindowSlider, 		PLANT2.time_window_end, 		LV_ANIM_OFF);
	lv_slider_set_value(ui_OutputPowerSlider, 		PLANT2.pump_power, 				LV_ANIM_OFF);
	lv_slider_set_value(ui_OutputTimeSlider, 		PLANT2.pump_duration, 			LV_ANIM_OFF);
	char buff[]="00000 min";
	sprintf((char *)buff, "%.5d min", PLANT2.pump_life);
	lv_label_set_text(ui_OutputLifeLabelVal, buff);
}

void cui_Out1Switch_toggled(lv_event_t * event)
{
	if( lv_obj_has_state(ui_Out1Switch, LV_STATE_CHECKED))
	{
		plant_switch_on(&PLANT1);
	}else{
		plant_switch_off(&PLANT1);
	}
}

void cui_Out2Switch_toggled(lv_event_t * event)
{
	if( lv_obj_has_state(ui_Out2Switch, LV_STATE_CHECKED))
	{
		plant_switch_on(&PLANT2);
	}else{
		plant_switch_off(&PLANT2);
	}
}

void cui_OutputThrshld_changed(lv_event_t * event)
{
#if DEBUG_DEVICE
	printf("\n i entered output threshold event callback! ");
#endif

	if(UI_CTRL.outConfigNo == OUT1_CONF) PLANT1.moisture_threshold= lv_slider_get_value(ui_OutputThrshldSlider);
	else if(UI_CTRL.outConfigNo == OUT2_CONF) PLANT2.moisture_threshold= lv_slider_get_value(ui_OutputThrshldSlider);
}

void cui_OutTimeWindow_changed(lv_event_t * event)
{
	if(UI_CTRL.outConfigNo == OUT1_CONF) {
		PLANT1.time_window_start= lv_slider_get_left_value(ui_TimeWindowSlider);
		PLANT1.time_window_end=   lv_slider_get_value(ui_TimeWindowSlider);

	}else if(UI_CTRL.outConfigNo == OUT2_CONF) {
		PLANT2.time_window_start= lv_slider_get_left_value(ui_TimeWindowSlider);
		PLANT2.time_window_end=   lv_slider_get_value(ui_TimeWindowSlider);
	}
}

void cui_PumpPower_changed(lv_event_t * event)
{
	if(UI_CTRL.outConfigNo == OUT1_CONF) PLANT1.pump_power= lv_slider_get_value(ui_OutputPowerSlider);
	else if(UI_CTRL.outConfigNo == OUT2_CONF) PLANT2.pump_power= lv_slider_get_value(ui_OutputPowerSlider);
}

void cui_PumpTime_changed(lv_event_t * event)
{
	if(UI_CTRL.outConfigNo == OUT1_CONF) PLANT1.pump_duration= lv_slider_get_value(ui_OutputTimeSlider);
	else if(UI_CTRL.outConfigNo == OUT2_CONF) PLANT2.pump_duration= lv_slider_get_value(ui_OutputTimeSlider);
}

void cui_ScreenTime_changed(lv_event_t * event)
{
//	if(UI_CTRL.outConfigNo == OUT1_CONF) D= lv_slider_get_value(ui_ScreenTimeSlider);
//	else if(UI_CTRL.outConfigNo == OUT2_CONF) PLANT2.pump_power= lv_slider_get_value(ui_ScreenTimeSlider);
}

void cui_ScreenBrightness_changed(lv_event_t * event)
{
	ctrl_device_lcdbrightness();
}

void cui_SaveClockDate_clicked(lv_event_t * event)
{

	char buff4[]="0000";
	char buff2[]="00";
	lv_dropdown_get_selected_str(ui_DaySetLabel, buff2, sizeof(buff2));
	RTC_CTRL.day_s=  	 (uint8_t)strtoul(buff2, NULL, 10);
	lv_dropdown_get_selected_str(ui_MonthSetLabel, buff2, sizeof(buff2));
	RTC_CTRL.month_s=    (uint8_t)strtoul(buff2, NULL, 10);
	lv_dropdown_get_selected_str(ui_YearSetLabel, buff4, sizeof(buff4));
	RTC_CTRL.year_s=  	 (uint8_t)(strtoul(buff4, NULL, 10)-2000);

	lv_dropdown_get_selected_str(ui_HourSetLabel, buff2, sizeof(buff2));
	RTC_CTRL.hour_s=  	 (uint8_t)strtoul(buff2, NULL, 10);
	lv_dropdown_get_selected_str(ui_MinsSetLabel, buff2, sizeof(buff2));
	RTC_CTRL.minutes_s=  (uint8_t)strtoul(buff2, NULL, 10);
	RTC_CTRL.seconds_s=  0;


	rtc_allow_set();
	rtc_set();
}
//*************************************************************************************************************
