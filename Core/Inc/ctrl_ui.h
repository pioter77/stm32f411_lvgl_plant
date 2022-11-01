/*
 * fcnUi_chart.h
 *
 *  Created on: Oct 6, 2022
 *      Author: x280
 */

#ifndef INC_CTRL_UI_H_
#define INC_CTRL_UI_H_

#include "../UI/ui.h"
#include "../UI/ui_helpers.h"

#include "ctrl_device.h"
#include "ctrl_rtc.h"
#include "ctrl_measure.h"
#include "ctrl_process.h"
#include "ctrl_timers.h"

typedef enum {OUT1_CONF=1,
			  OUT2_CONF=2
						} outConfig_t;

typedef struct UI_CTRL_T{
	outConfig_t outConfigNo;					//depending on this variable config screen values are switch accordingly to which output was clicked
}UI_CTRL_t;

extern UI_CTRL_t UI_CTRL;

void cui_chart_init(void);
void cui_chart_update(void);
void cui_init(void);


void cui_Out1_clicked(lv_event_t * event);
void cui_Out2_clicked(lv_event_t * event);
void cui_Out1Switch_toggled(lv_event_t * event);
void cui_Out2Switch_toggled(lv_event_t * event);
void cui_OutputThrshld_changed(lv_event_t * event);
void cui_OutTimeWindow_changed(lv_event_t * event);
void cui_PumpPower_changed(lv_event_t * event);
void cui_PumpTime_changed(lv_event_t * event);
void cui_ScreenTime_changed(lv_event_t * event);
void cui_ScreenBrightness_changed(lv_event_t * event);
void cui_SaveClockDate_clicked(lv_event_t * event);

#endif /* INC_CTRL_UI_H_ */
