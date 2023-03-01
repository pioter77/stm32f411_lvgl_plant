// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.0
// LVGL VERSION: 8.2.0
// PROJECT: lvgl_plant

#ifndef _LVGL_PLANT_UI_H
#define _LVGL_PLANT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../lvgl/lvgl.h"

void MenuBring1_Animation(lv_obj_t * TargetObject, int delay);
void MenuHide1_Animation(lv_obj_t * TargetObject, int delay);
extern lv_obj_t * ui_Screen1;
void ui_event_NextScButton(lv_event_t * e);
extern lv_obj_t * ui_NextScButton;
extern lv_obj_t * ui_MainScreenInfoLabel;
void ui_event_Out1Arc(lv_event_t * e);
extern lv_obj_t * ui_Out1Arc;
extern lv_obj_t * ui_Screen1_Label2;
extern lv_obj_t * ui_Out1Label;
extern lv_obj_t * ui_Out1LabelState;
void ui_event_Out2Arc(lv_event_t * e);
extern lv_obj_t * ui_Out2Arc;
extern lv_obj_t * ui_Screen1_Label1;
extern lv_obj_t * ui_Out2Label;
extern lv_obj_t * ui_Out2LabelState;
extern lv_obj_t * ui_Screen1_Label4;
extern lv_obj_t * ui_Out1Switch;
extern lv_obj_t * ui_Out2Switch;
extern lv_obj_t * ui_MainScreenParamLabel;
extern lv_obj_t * ui_Screen2;
extern lv_obj_t * ui_Chart1;
void ui_event_PrevScButton(lv_event_t * e);
extern lv_obj_t * ui_PrevScButton;
extern lv_obj_t * ui_PlotScreenInfoLabel;
extern lv_obj_t * ui_PlotButton1;
extern lv_obj_t * ui_LabelPlotButon1;
extern lv_obj_t * ui_PlotButton2;
extern lv_obj_t * ui_LabelPlotButon2;
extern lv_obj_t * ui_PlotButton3;
extern lv_obj_t * ui_LabelPlotButon3;
extern lv_obj_t * ui_PlotLegendLabel;
extern lv_obj_t * ui_LabelPlotLegend;
void ui_event_SettingsButton(lv_event_t * e);
extern lv_obj_t * ui_SettingsButton;
extern lv_obj_t * ui_Screen3;
void ui_event_ConfigBackButton(lv_event_t * e);
extern lv_obj_t * ui_ConfigBackButton;
extern lv_obj_t * ui_ConfigBackButtonLbl;
extern lv_obj_t * ui_TimeWindowLabel;
extern lv_obj_t * ui_OutputThrshldLabel;
extern lv_obj_t * ui_ConfigScreenInfoLabel;
extern lv_obj_t * ui_OutputThrshldSlider;
extern lv_obj_t * ui_TimeWindowSlider;
extern lv_obj_t * ui_OutputPowerLabel;
extern lv_obj_t * ui_OutputPowerSlider;
extern lv_obj_t * ui_OutputTimeSlider;
extern lv_obj_t * ui_OutputTimeLabel;
extern lv_obj_t * ui_OutputLifeLabel;
extern lv_obj_t * ui_OutputLifeLabelVal;
extern lv_obj_t * ui_LabelPmenuOutThrshld;
extern lv_obj_t * ui_LabelPmenuTwindow;
extern lv_obj_t * ui_LabelPmenuOutPower;
extern lv_obj_t * ui_LabelPmenuOutTime;
extern lv_obj_t * ui_Screen4;
void ui_event_SettingsBackButton(lv_event_t * e);
extern lv_obj_t * ui_SettingsBackButton;
extern lv_obj_t * ui_SettingsBackButtonLbl;
extern lv_obj_t * ui_DateSetLabel;
extern lv_obj_t * ui_TimeSetLabel;
extern lv_obj_t * ui_SettingScreenInfoLabel;
extern lv_obj_t * ui_ScreenBrigtLabel;
extern lv_obj_t * ui_ScreenBrigtSlider;
extern lv_obj_t * ui_ScreenTimeLabel;
extern lv_obj_t * ui_ScreenTimeSlider;
extern lv_obj_t * ui_DaySetLabel;
extern lv_obj_t * ui_YearSetLabel;
extern lv_obj_t * ui_MonthSetLabel;
extern lv_obj_t * ui_HourSetLabel;
extern lv_obj_t * ui_MinsSetLabel;
extern lv_obj_t * ui_TimeDateSaveButton;
extern lv_obj_t * ui_TimeDateSaveBtnLabel;
extern lv_obj_t * ui_ScreenBrigtSliderLblVal;
extern lv_obj_t * ui_ScreenTimeSliderLblVal;
extern lv_obj_t * ui_ScreenBrigtCheckbox;
extern lv_obj_t * ui_ScreenTimeCheckbox;






void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
