// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.2.0
// PROJECT: lvgl_plant

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
void MenuBring1_Animation(lv_obj_t * TargetObject, int delay);
void MenuHide1_Animation(lv_obj_t * TargetObject, int delay);
lv_obj_t * ui_Screen1;
void ui_event_NextScButton(lv_event_t * e);
lv_obj_t * ui_NextScButton;
lv_obj_t * ui_MainScreenInfoLabel;
void ui_event_Out1Arc(lv_event_t * e);
lv_obj_t * ui_Out1Arc;
lv_obj_t * ui_Screen1_Label2;
lv_obj_t * ui_Out1Label;
void ui_event_Out2Arc(lv_event_t * e);
lv_obj_t * ui_Out2Arc;
lv_obj_t * ui_Screen1_Label1;
lv_obj_t * ui_Out2Label;
lv_obj_t * ui_Screen1_Label4;
lv_obj_t * ui_Out1Switch;
lv_obj_t * ui_Out2Switch;
lv_obj_t * ui_MainScreenParamLabel;
lv_obj_t * ui_Screen2;
lv_obj_t * ui_Chart1;
void ui_event_PrevScButton(lv_event_t * e);
lv_obj_t * ui_PrevScButton;
lv_obj_t * ui_PlotScreenInfoLabel;
lv_obj_t * ui_PlotButton1;
lv_obj_t * ui_PlotButton2;
lv_obj_t * ui_PlotButton3;
lv_obj_t * ui_PlotLegendLabel;
void ui_event_SettingsButton(lv_event_t * e);
lv_obj_t * ui_SettingsButton;
lv_obj_t * ui_Screen3;
void ui_event_ConfigBackButton(lv_event_t * e);
lv_obj_t * ui_ConfigBackButton;
lv_obj_t * ui_ConfigBackButtonLbl;
lv_obj_t * ui_TimeWindowLabel;
lv_obj_t * ui_OutputThrshldLabel;
lv_obj_t * ui_ConfigScreenInfoLabel;
lv_obj_t * ui_OutputThrshldSlider;
lv_obj_t * ui_TimeWindowSlider;
lv_obj_t * ui_OutputPowerLabel;
lv_obj_t * ui_OutputPowerSlider;
lv_obj_t * ui_OutputTimeSlider;
lv_obj_t * ui_OutputTimeLabel;
lv_obj_t * ui_OutputLifeLabel;
lv_obj_t * ui_OutputLifeLabelVal;
lv_obj_t * ui_Screen4;
void ui_event_SettingsBackButton(lv_event_t * e);
lv_obj_t * ui_SettingsBackButton;
lv_obj_t * ui_SettingsBackButtonLbl;
lv_obj_t * ui_DateSetLabel;
lv_obj_t * ui_TimeSetLabel;
lv_obj_t * ui_SettingScreenInfoLabel;
lv_obj_t * ui_ScreenBrigtLabel;
lv_obj_t * ui_ScreenBrigtSlider;
lv_obj_t * ui_ScreenTimeLabel;
lv_obj_t * ui_ScreenTimeSlider;
lv_obj_t * ui_DaySetLabel;
lv_obj_t * ui_YearSetLabel;
lv_obj_t * ui_MonthSetLabel;
lv_obj_t * ui_HourSetLabel;
lv_obj_t * ui_MinsSetLabel;
lv_obj_t * ui_TimeDateSaveButton;
lv_obj_t * ui_TimeDateSaveBtnLabel;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////
void MenuBring1_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 1500);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_0, 250, 0);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}
void MenuHide1_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 150);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_0, 0, 250);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}

///////////////////// FUNCTIONS ////////////////////
void ui_event_NextScButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen2, LV_SCR_LOAD_ANIM_MOVE_LEFT, 150, 0);
    }
}
void ui_event_Out1Arc(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen3, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 150, 0);
    }
}
void ui_event_Out2Arc(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen3, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 150, 0);
    }
}
void ui_event_PrevScButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen1, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 150, 0);
    }
}
void ui_event_SettingsButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen4, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 150, 0);
    }
}
void ui_event_ConfigBackButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen1, LV_SCR_LOAD_ANIM_MOVE_TOP, 150, 0);
    }
}
void ui_event_SettingsBackButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen2, LV_SCR_LOAD_ANIM_MOVE_TOP, 150, 0);
    }
}

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_NextScButton = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_NextScButton, 50);
    lv_obj_set_height(ui_NextScButton, 50);
    lv_obj_set_align(ui_NextScButton, LV_ALIGN_TOP_RIGHT);
    lv_obj_add_flag(ui_NextScButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_NextScButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NextScButton, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NextScButton, lv_color_hex(0x4040FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NextScButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_NextScButton, lv_color_hex(0x787868), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_NextScButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NextScButton, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_NextScButton, LV_BORDER_SIDE_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_MainScreenInfoLabel = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_MainScreenInfoLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_MainScreenInfoLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_MainScreenInfoLabel, -2);
    lv_obj_set_y(ui_MainScreenInfoLabel, -77);
    lv_obj_set_align(ui_MainScreenInfoLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_MainScreenInfoLabel, "Soil Humidity");

    ui_Out1Arc = lv_arc_create(ui_Screen1);
    lv_obj_set_width(ui_Out1Arc, 145);
    lv_obj_set_height(ui_Out1Arc, 145);
    lv_obj_set_x(ui_Out1Arc, 10);
    lv_obj_set_y(ui_Out1Arc, -39);
    lv_obj_set_align(ui_Out1Arc, LV_ALIGN_BOTTOM_LEFT);
    lv_arc_set_value(ui_Out1Arc, 30);
    lv_obj_set_style_radius(ui_Out1Arc, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Out1Arc, lv_color_hex(0xAF81D4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Out1Arc, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Out1Arc, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Out1Arc, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Out1Arc, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Out1Arc, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Out1Arc, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Out1Arc, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Screen1_Label2 = lv_label_create(ui_Out1Arc);
    lv_obj_set_width(ui_Screen1_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Screen1_Label2, 37);
    lv_obj_set_y(ui_Screen1_Label2, -2);
    lv_obj_set_align(ui_Screen1_Label2, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(ui_Screen1_Label2, "Sensor 1");
    lv_obj_set_style_text_color(ui_Screen1_Label2, lv_color_hex(0x6E0A82), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen1_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Screen1_Label2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen1_Label2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Out1Label = lv_label_create(ui_Out1Arc);
    lv_obj_set_width(ui_Out1Label, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Out1Label, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Out1Label, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Out1Label, "39% / 17%");

    ui_Out2Arc = lv_arc_create(ui_Screen1);
    lv_obj_set_width(ui_Out2Arc, 145);
    lv_obj_set_height(ui_Out2Arc, 145);
    lv_obj_set_x(ui_Out2Arc, -10);
    lv_obj_set_y(ui_Out2Arc, -39);
    lv_obj_set_align(ui_Out2Arc, LV_ALIGN_BOTTOM_RIGHT);
    lv_arc_set_value(ui_Out2Arc, 22);
    lv_obj_set_style_radius(ui_Out2Arc, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Out2Arc, lv_color_hex(0x56AF71), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Out2Arc, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Out2Arc, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Out2Arc, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Out2Arc, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Out2Arc, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Out2Arc, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Out2Arc, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Screen1_Label1 = lv_label_create(ui_Out2Arc);
    lv_obj_set_width(ui_Screen1_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Screen1_Label1, 38);
    lv_obj_set_y(ui_Screen1_Label1, -2);
    lv_obj_set_align(ui_Screen1_Label1, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(ui_Screen1_Label1, "Sensor 2");
    lv_obj_set_style_text_color(ui_Screen1_Label1, lv_color_hex(0x6E0A82), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen1_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Screen1_Label1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen1_Label1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Out2Label = lv_label_create(ui_Out2Arc);
    lv_obj_set_width(ui_Out2Label, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Out2Label, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Out2Label, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Out2Label, "80% / 20%");

    ui_Screen1_Label4 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Screen1_Label4, 766);
    lv_obj_set_y(ui_Screen1_Label4, 92);
    lv_obj_set_align(ui_Screen1_Label4, LV_ALIGN_CENTER);

    ui_Out1Switch = lv_switch_create(ui_Screen1);
    lv_obj_set_width(ui_Out1Switch, 50);
    lv_obj_set_height(ui_Out1Switch, 25);
    lv_obj_set_x(ui_Out1Switch, 55);
    lv_obj_set_y(ui_Out1Switch, -5);
    lv_obj_set_align(ui_Out1Switch, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_set_style_bg_color(ui_Out1Switch, lv_color_hex(0x787868), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Out1Switch, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Out2Switch = lv_switch_create(ui_Screen1);
    lv_obj_set_width(ui_Out2Switch, 50);
    lv_obj_set_height(ui_Out2Switch, 25);
    lv_obj_set_x(ui_Out2Switch, -55);
    lv_obj_set_y(ui_Out2Switch, -5);
    lv_obj_set_align(ui_Out2Switch, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_set_style_bg_color(ui_Out2Switch, lv_color_hex(0x787868), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Out2Switch, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_MainScreenParamLabel = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_MainScreenParamLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_MainScreenParamLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_MainScreenParamLabel, 1);
    lv_obj_set_y(ui_MainScreenParamLabel, -107);
    lv_obj_set_align(ui_MainScreenParamLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_MainScreenParamLabel, "17:39:00 12.02.22  24*C/48%");

    lv_obj_add_event_cb(ui_NextScButton, ui_event_NextScButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Out1Arc, ui_event_Out1Arc, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Out2Arc, ui_event_Out2Arc, LV_EVENT_ALL, NULL);

}
void ui_Screen2_screen_init(void)
{
    ui_Screen2 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Chart1 = lv_chart_create(ui_Screen2);
    lv_obj_set_width(ui_Chart1, 320);
    lv_obj_set_height(ui_Chart1, 145);
    lv_obj_set_x(ui_Chart1, 0);
    lv_obj_set_y(ui_Chart1, -42);
    lv_obj_set_align(ui_Chart1, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_set_style_radius(ui_Chart1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PrevScButton = lv_btn_create(ui_Screen2);
    lv_obj_set_width(ui_PrevScButton, 50);
    lv_obj_set_height(ui_PrevScButton, 50);
    lv_obj_add_flag(ui_PrevScButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_PrevScButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PrevScButton, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PrevScButton, lv_color_hex(0x4040FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PrevScButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PrevScButton, lv_color_hex(0x787868), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PrevScButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PrevScButton, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PrevScButton, LV_BORDER_SIDE_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PlotScreenInfoLabel = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_PlotScreenInfoLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_PlotScreenInfoLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_PlotScreenInfoLabel, 31);
    lv_obj_set_y(ui_PlotScreenInfoLabel, -80);
    lv_obj_set_align(ui_PlotScreenInfoLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PlotScreenInfoLabel, "Parameters plot");

    ui_PlotButton1 = lv_btn_create(ui_Screen2);
    lv_obj_set_width(ui_PlotButton1, 60);
    lv_obj_set_height(ui_PlotButton1, 40);
    lv_obj_set_x(ui_PlotButton1, 10);
    lv_obj_set_y(ui_PlotButton1, 0);
    lv_obj_set_align(ui_PlotButton1, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_add_flag(ui_PlotButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_PlotButton1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PlotButton1, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PlotButton1, lv_color_hex(0x52A48A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PlotButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PlotButton2 = lv_btn_create(ui_Screen2);
    lv_obj_set_width(ui_PlotButton2, 60);
    lv_obj_set_height(ui_PlotButton2, 40);
    lv_obj_set_x(ui_PlotButton2, 75);
    lv_obj_set_y(ui_PlotButton2, 0);
    lv_obj_set_align(ui_PlotButton2, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_add_flag(ui_PlotButton2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_PlotButton2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PlotButton2, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PlotButton2, lv_color_hex(0x52A48A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PlotButton2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PlotButton3 = lv_btn_create(ui_Screen2);
    lv_obj_set_width(ui_PlotButton3, 60);
    lv_obj_set_height(ui_PlotButton3, 40);
    lv_obj_set_x(ui_PlotButton3, 140);
    lv_obj_set_y(ui_PlotButton3, 0);
    lv_obj_set_align(ui_PlotButton3, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_add_flag(ui_PlotButton3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_PlotButton3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PlotButton3, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PlotButton3, lv_color_hex(0x52A48A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PlotButton3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PlotLegendLabel = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_PlotLegendLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_PlotLegendLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_PlotLegendLabel, 102);
    lv_obj_set_y(ui_PlotLegendLabel, 100);
    lv_obj_set_align(ui_PlotLegendLabel, LV_ALIGN_CENTER);

    ui_SettingsButton = lv_btn_create(ui_Screen2);
    lv_obj_set_width(ui_SettingsButton, 50);
    lv_obj_set_height(ui_SettingsButton, 50);
    lv_obj_set_x(ui_SettingsButton, -214);
    lv_obj_set_y(ui_SettingsButton, 0);
    lv_obj_set_align(ui_SettingsButton, LV_ALIGN_TOP_RIGHT);
    lv_obj_add_flag(ui_SettingsButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_SettingsButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SettingsButton, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SettingsButton, lv_color_hex(0x4040FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SettingsButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_SettingsButton, lv_color_hex(0x787868), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_SettingsButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SettingsButton, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_SettingsButton, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_PrevScButton, ui_event_PrevScButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingsButton, ui_event_SettingsButton, LV_EVENT_ALL, NULL);

}
void ui_Screen3_screen_init(void)
{
    ui_Screen3 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ConfigBackButton = lv_btn_create(ui_Screen3);
    lv_obj_set_width(ui_ConfigBackButton, 50);
    lv_obj_set_height(ui_ConfigBackButton, 50);
    lv_obj_add_flag(ui_ConfigBackButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ConfigBackButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ConfigBackButton, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ConfigBackButton, lv_color_hex(0x4040FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ConfigBackButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ConfigBackButtonLbl = lv_label_create(ui_ConfigBackButton);
    lv_obj_set_width(ui_ConfigBackButtonLbl, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ConfigBackButtonLbl, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ConfigBackButtonLbl, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ConfigBackButtonLbl, "Back");

    ui_TimeWindowLabel = lv_label_create(ui_Screen3);
    lv_obj_set_width(ui_TimeWindowLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TimeWindowLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TimeWindowLabel, 0);
    lv_obj_set_y(ui_TimeWindowLabel, 100);
    lv_label_set_text(ui_TimeWindowLabel, "Time window");

    ui_OutputThrshldLabel = lv_label_create(ui_Screen3);
    lv_obj_set_width(ui_OutputThrshldLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_OutputThrshldLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_OutputThrshldLabel, 0);
    lv_obj_set_y(ui_OutputThrshldLabel, 55);
    lv_label_set_long_mode(ui_OutputThrshldLabel, LV_LABEL_LONG_SCROLL);
    lv_label_set_text(ui_OutputThrshldLabel, "Moisture \nThreshold");

    ui_ConfigScreenInfoLabel = lv_label_create(ui_Screen3);
    lv_obj_set_width(ui_ConfigScreenInfoLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ConfigScreenInfoLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ConfigScreenInfoLabel, -1);
    lv_obj_set_y(ui_ConfigScreenInfoLabel, -105);
    lv_obj_set_align(ui_ConfigScreenInfoLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ConfigScreenInfoLabel, "Plant X config");

    ui_OutputThrshldSlider = lv_slider_create(ui_Screen3);
    lv_obj_set_width(ui_OutputThrshldSlider, 180);
    lv_obj_set_height(ui_OutputThrshldSlider, 21);
    lv_obj_set_x(ui_OutputThrshldSlider, -5);
    lv_obj_set_y(ui_OutputThrshldSlider, 55);
    lv_obj_set_align(ui_OutputThrshldSlider, LV_ALIGN_TOP_RIGHT);

    lv_obj_set_style_bg_color(ui_OutputThrshldSlider, lv_color_hex(0x4040FF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_OutputThrshldSlider, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_TimeWindowSlider = lv_slider_create(ui_Screen3);
    lv_slider_set_mode(ui_TimeWindowSlider, LV_SLIDER_MODE_RANGE);
    lv_slider_set_value(ui_TimeWindowSlider, 60, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_TimeWindowSlider) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_TimeWindowSlider, 30,
                                                                                                     LV_ANIM_OFF);
    lv_obj_set_width(ui_TimeWindowSlider, 180);
    lv_obj_set_height(ui_TimeWindowSlider, 21);
    lv_obj_set_x(ui_TimeWindowSlider, -5);
    lv_obj_set_y(ui_TimeWindowSlider, 100);
    lv_obj_set_align(ui_TimeWindowSlider, LV_ALIGN_TOP_RIGHT);

    lv_obj_set_style_bg_color(ui_TimeWindowSlider, lv_color_hex(0x4040FF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TimeWindowSlider, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_OutputPowerLabel = lv_label_create(ui_Screen3);
    lv_obj_set_width(ui_OutputPowerLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_OutputPowerLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_OutputPowerLabel, 0);
    lv_obj_set_y(ui_OutputPowerLabel, 140);
    lv_label_set_text(ui_OutputPowerLabel, "Pump power");

    ui_OutputPowerSlider = lv_slider_create(ui_Screen3);
    lv_obj_set_width(ui_OutputPowerSlider, 180);
    lv_obj_set_height(ui_OutputPowerSlider, 21);
    lv_obj_set_x(ui_OutputPowerSlider, -5);
    lv_obj_set_y(ui_OutputPowerSlider, 140);
    lv_obj_set_align(ui_OutputPowerSlider, LV_ALIGN_TOP_RIGHT);

    lv_obj_set_style_bg_color(ui_OutputPowerSlider, lv_color_hex(0x4040FF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_OutputPowerSlider, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_OutputTimeSlider = lv_slider_create(ui_Screen3);
    lv_obj_set_width(ui_OutputTimeSlider, 180);
    lv_obj_set_height(ui_OutputTimeSlider, 21);
    lv_obj_set_x(ui_OutputTimeSlider, -5);
    lv_obj_set_y(ui_OutputTimeSlider, 180);
    lv_obj_set_align(ui_OutputTimeSlider, LV_ALIGN_TOP_RIGHT);

    lv_obj_set_style_bg_color(ui_OutputTimeSlider, lv_color_hex(0x4040FF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_OutputTimeSlider, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_OutputTimeLabel = lv_label_create(ui_Screen3);
    lv_obj_set_width(ui_OutputTimeLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_OutputTimeLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_OutputTimeLabel, 0);
    lv_obj_set_y(ui_OutputTimeLabel, 180);
    lv_label_set_text(ui_OutputTimeLabel, "Pump time");

    ui_OutputLifeLabel = lv_label_create(ui_Screen3);
    lv_obj_set_width(ui_OutputLifeLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_OutputLifeLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_OutputLifeLabel, 0);
    lv_obj_set_y(ui_OutputLifeLabel, 220);
    lv_label_set_text(ui_OutputLifeLabel, "Pump life:");

    ui_OutputLifeLabelVal = lv_label_create(ui_OutputLifeLabel);
    lv_obj_set_width(ui_OutputLifeLabelVal, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_OutputLifeLabelVal, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_OutputLifeLabelVal, 120);
    lv_obj_set_y(ui_OutputLifeLabelVal, 0);
    lv_obj_set_align(ui_OutputLifeLabelVal, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(ui_OutputLifeLabelVal, "15 min ");

    lv_obj_add_event_cb(ui_ConfigBackButton, ui_event_ConfigBackButton, LV_EVENT_ALL, NULL);

}
void ui_Screen4_screen_init(void)
{
    ui_Screen4 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_SettingsBackButton = lv_btn_create(ui_Screen4);
    lv_obj_set_width(ui_SettingsBackButton, 50);
    lv_obj_set_height(ui_SettingsBackButton, 50);
    lv_obj_add_flag(ui_SettingsBackButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_SettingsBackButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SettingsBackButton, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SettingsBackButton, lv_color_hex(0x4040FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SettingsBackButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingsBackButtonLbl = lv_label_create(ui_SettingsBackButton);
    lv_obj_set_width(ui_SettingsBackButtonLbl, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SettingsBackButtonLbl, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_SettingsBackButtonLbl, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SettingsBackButtonLbl, "Back");

    ui_DateSetLabel = lv_label_create(ui_Screen4);
    lv_obj_set_width(ui_DateSetLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_DateSetLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_DateSetLabel, -137);
    lv_obj_set_y(ui_DateSetLabel, -45);
    lv_obj_set_align(ui_DateSetLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_DateSetLabel, "Date");

    ui_TimeSetLabel = lv_label_create(ui_Screen4);
    lv_obj_set_width(ui_TimeSetLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TimeSetLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TimeSetLabel, -136);
    lv_obj_set_y(ui_TimeSetLabel, -2);
    lv_obj_set_align(ui_TimeSetLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_TimeSetLabel, "Time");

    ui_SettingScreenInfoLabel = lv_label_create(ui_Screen4);
    lv_obj_set_width(ui_SettingScreenInfoLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SettingScreenInfoLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_SettingScreenInfoLabel, 6);
    lv_obj_set_y(ui_SettingScreenInfoLabel, -105);
    lv_obj_set_align(ui_SettingScreenInfoLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SettingScreenInfoLabel, "Device Settings");

    ui_ScreenBrigtLabel = lv_label_create(ui_Screen4);
    lv_obj_set_width(ui_ScreenBrigtLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScreenBrigtLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScreenBrigtLabel, -113);
    lv_obj_set_y(ui_ScreenBrigtLabel, 48);
    lv_obj_set_align(ui_ScreenBrigtLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ScreenBrigtLabel, "Screen\nBrightness");

    ui_ScreenBrigtSlider = lv_slider_create(ui_Screen4);
    lv_slider_set_range(ui_ScreenBrigtSlider, 5, 100);
    lv_slider_set_value(ui_ScreenBrigtSlider, 50, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_ScreenBrigtSlider) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_ScreenBrigtSlider, 0,
                                                                                                      LV_ANIM_OFF);
    lv_obj_set_width(ui_ScreenBrigtSlider, 180);
    lv_obj_set_height(ui_ScreenBrigtSlider, 21);
    lv_obj_set_x(ui_ScreenBrigtSlider, 54);
    lv_obj_set_y(ui_ScreenBrigtSlider, 52);
    lv_obj_set_align(ui_ScreenBrigtSlider, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_ScreenBrigtSlider, lv_color_hex(0x4040FF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenBrigtSlider, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_ScreenTimeLabel = lv_label_create(ui_Screen4);
    lv_obj_set_width(ui_ScreenTimeLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScreenTimeLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScreenTimeLabel, -127);
    lv_obj_set_y(ui_ScreenTimeLabel, 97);
    lv_obj_set_align(ui_ScreenTimeLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ScreenTimeLabel, "Screen\nTime");

    ui_ScreenTimeSlider = lv_slider_create(ui_Screen4);
    lv_slider_set_range(ui_ScreenTimeSlider, 30, 300);
    lv_obj_set_width(ui_ScreenTimeSlider, 180);
    lv_obj_set_height(ui_ScreenTimeSlider, 21);
    lv_obj_set_x(ui_ScreenTimeSlider, 55);
    lv_obj_set_y(ui_ScreenTimeSlider, 96);
    lv_obj_set_align(ui_ScreenTimeSlider, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_ScreenTimeSlider, lv_color_hex(0x4040FF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenTimeSlider, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_DaySetLabel = lv_dropdown_create(ui_Screen4);
    lv_dropdown_set_options(ui_DaySetLabel,
                            "01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31");
    lv_obj_set_width(ui_DaySetLabel, 53);
    lv_obj_set_height(ui_DaySetLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_DaySetLabel, -26);
    lv_obj_set_y(ui_DaySetLabel, -53);
    lv_obj_set_align(ui_DaySetLabel, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_DaySetLabel, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags

    ui_YearSetLabel = lv_dropdown_create(ui_Screen4);
    lv_dropdown_set_options(ui_YearSetLabel, "2022\n2023\n2024\n2025\n2026\n2027\n2028\n2029\n2030");
    lv_obj_set_width(ui_YearSetLabel, 70);
    lv_obj_set_height(ui_YearSetLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_YearSetLabel, 108);
    lv_obj_set_y(ui_YearSetLabel, -54);
    lv_obj_set_align(ui_YearSetLabel, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_YearSetLabel, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags

    ui_MonthSetLabel = lv_dropdown_create(ui_Screen4);
    lv_dropdown_set_options(ui_MonthSetLabel, "01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12");
    lv_obj_set_width(ui_MonthSetLabel, 53);
    lv_obj_set_height(ui_MonthSetLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_MonthSetLabel, 34);
    lv_obj_set_y(ui_MonthSetLabel, -53);
    lv_obj_set_align(ui_MonthSetLabel, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_MonthSetLabel, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags

    ui_HourSetLabel = lv_dropdown_create(ui_Screen4);
    lv_dropdown_set_options(ui_HourSetLabel,
                            "01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23");
    lv_obj_set_width(ui_HourSetLabel, 53);
    lv_obj_set_height(ui_HourSetLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_HourSetLabel, -27);
    lv_obj_set_y(ui_HourSetLabel, 1);
    lv_obj_set_align(ui_HourSetLabel, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_HourSetLabel, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags

    ui_MinsSetLabel = lv_dropdown_create(ui_Screen4);
    lv_dropdown_set_options(ui_MinsSetLabel,
                            "01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31\n32\n33\n34\n35\n36\n37\n38\n39\n40\n41\n42\n43\n44\n45\n46\n47\n48\n49\n50\n51\n52\n53\n54\n55\n56\n57\n58\n59");
    lv_obj_set_width(ui_MinsSetLabel, 53);
    lv_obj_set_height(ui_MinsSetLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_MinsSetLabel, 33);
    lv_obj_set_y(ui_MinsSetLabel, 1);
    lv_obj_set_align(ui_MinsSetLabel, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_MinsSetLabel, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags

    ui_TimeDateSaveButton = lv_btn_create(ui_Screen4);
    lv_obj_set_width(ui_TimeDateSaveButton, 50);
    lv_obj_set_height(ui_TimeDateSaveButton, 50);
    lv_obj_set_x(ui_TimeDateSaveButton, 240);
    lv_obj_set_y(ui_TimeDateSaveButton, 90);
    lv_obj_add_flag(ui_TimeDateSaveButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_TimeDateSaveButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_TimeDateSaveButton, lv_color_hex(0x4040FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TimeDateSaveButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TimeDateSaveBtnLabel = lv_label_create(ui_TimeDateSaveButton);
    lv_obj_set_width(ui_TimeDateSaveBtnLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TimeDateSaveBtnLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_TimeDateSaveBtnLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_TimeDateSaveBtnLabel, " Save\nClock");

    lv_obj_add_event_cb(ui_SettingsBackButton, ui_event_SettingsBackButton, LV_EVENT_ALL, NULL);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    ui_Screen2_screen_init();
    ui_Screen3_screen_init();
    ui_Screen4_screen_init();
    lv_disp_load_scr(ui_Screen1);
}
