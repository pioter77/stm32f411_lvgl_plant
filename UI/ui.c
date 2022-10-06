// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: lvgl_plant

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Screen1;
void ui_event_Button2(lv_event_t * e);
lv_obj_t * ui_Button2;
void ui_event_Button4(lv_event_t * e);
lv_obj_t * ui_Button4;
lv_obj_t * ui_Label1;
lv_obj_t * ui_Label2;
lv_obj_t * ui_Label3;
lv_obj_t * ui_Slider1;
lv_obj_t * ui_Slider2;
lv_obj_t * ui_Bar1;
lv_obj_t * ui_Slider3;
lv_obj_t * ui_Label15;
lv_obj_t * ui_Label6;
lv_obj_t * ui_Label4;
lv_obj_t * ui_Label10;
lv_obj_t * ui_Switch1;
lv_obj_t * ui_Label19;
lv_obj_t * ui_Label21;
lv_obj_t * ui_Button12;
lv_obj_t * ui_Label11;
lv_obj_t * ui_Label22;
lv_obj_t * ui_Label23;
lv_obj_t * ui_Screen2;
void ui_event_Button5(lv_event_t * e);
lv_obj_t * ui_Button5;
lv_obj_t * ui_Label7;
lv_obj_t * ui_Label9;
lv_obj_t * ui_Label16;
lv_obj_t * ui_Label8;
void ui_event_Button7(lv_event_t * e);
lv_obj_t * ui_Button7;
lv_obj_t * ui_Label12;
lv_obj_t * ui_Label13;
lv_obj_t * ui_Label14;
lv_obj_t * ui_Label17;
lv_obj_t * ui_Label20;
lv_obj_t * ui_Label24;
lv_obj_t * ui_Label26;
lv_obj_t * ui_Label27;
lv_obj_t * ui_Screen3;
lv_obj_t * ui_Chart1;
void ui_event_Button9(lv_event_t * e);
lv_obj_t * ui_Button9;
void ui_event_Button10(lv_event_t * e);
lv_obj_t * ui_Button10;
lv_obj_t * ui_Label18;
lv_obj_t * ui_Label5;
lv_obj_t * ui_Button3;
lv_obj_t * ui_Button6;
lv_obj_t * ui_Button8;
lv_obj_t * ui_Button11;
lv_obj_t * ui_Button1;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_Button2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen2, LV_SCR_LOAD_ANIM_MOVE_LEFT, 150, 0);
    }
}
void ui_event_Button4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen3, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 150, 0);
    }
}
void ui_event_Button5(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen1, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 150, 0);
    }
}
void ui_event_Button7(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen3, LV_SCR_LOAD_ANIM_MOVE_LEFT, 150, 0);
    }
}
void ui_event_Button9(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen2, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 150, 0);
    }
}
void ui_event_Button10(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen1, LV_SCR_LOAD_ANIM_MOVE_LEFT, 150, 0);
    }
}

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Button2 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Button2, 50);
    lv_obj_set_height(ui_Button2, 50);
    lv_obj_set_align(ui_Button2, LV_ALIGN_TOP_RIGHT);
    lv_obj_add_flag(ui_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Button4 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Button4, 50);
    lv_obj_set_height(ui_Button4, 50);
    lv_obj_add_flag(ui_Button4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label1 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label1, -1);
    lv_obj_set_y(ui_Label1, 36);
    lv_obj_set_align(ui_Label1, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Label1, "Humidity threshold");

    ui_Label2 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label2, 0);
    lv_obj_set_y(ui_Label2, -17);
    lv_obj_set_align(ui_Label2, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Label2, "Water flow speed");

    ui_Label3 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label3, 0);
    lv_obj_set_y(ui_Label3, 11);
    lv_obj_set_align(ui_Label3, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Label3, "Pump ON time");

    ui_Slider1 = lv_slider_create(ui_Screen1);
    lv_obj_set_width(ui_Slider1, 121);
    lv_obj_set_height(ui_Slider1, 10);
    lv_obj_set_x(ui_Slider1, -3);
    lv_obj_set_y(ui_Slider1, 8);
    lv_obj_set_align(ui_Slider1, LV_ALIGN_RIGHT_MID);

    ui_Slider2 = lv_slider_create(ui_Screen1);
    lv_obj_set_width(ui_Slider2, 126);
    lv_obj_set_height(ui_Slider2, 10);
    lv_obj_set_x(ui_Slider2, -1);
    lv_obj_set_y(ui_Slider2, 35);
    lv_obj_set_align(ui_Slider2, LV_ALIGN_RIGHT_MID);

    ui_Bar1 = lv_bar_create(ui_Screen1);
    lv_bar_set_value(ui_Bar1, 25, LV_ANIM_OFF);
    lv_obj_set_width(ui_Bar1, 121);
    lv_obj_set_height(ui_Bar1, 15);
    lv_obj_set_x(ui_Bar1, 0);
    lv_obj_set_y(ui_Bar1, -50);
    lv_obj_set_align(ui_Bar1, LV_ALIGN_RIGHT_MID);

    ui_Slider3 = lv_slider_create(ui_Screen1);
    lv_obj_set_width(ui_Slider3, 124);
    lv_obj_set_height(ui_Slider3, 10);
    lv_obj_set_x(ui_Slider3, 0);
    lv_obj_set_y(ui_Slider3, -21);
    lv_obj_set_align(ui_Slider3, LV_ALIGN_RIGHT_MID);

    ui_Label15 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label15, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label15, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label15, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_Label15, "1");

    ui_Label6 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label6, 1);
    lv_obj_set_y(ui_Label6, -48);
    lv_obj_set_align(ui_Label6, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Label6, "Humidity LEVEL");

    ui_Label4 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label4, 7);
    lv_obj_set_y(ui_Label4, 32);
    lv_obj_set_align(ui_Label4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label4, "24%");
    lv_obj_set_style_bg_color(ui_Label4, lv_color_hex(0x1E2A28), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Label4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label10 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label10, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label10, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label10, -108);
    lv_obj_set_y(ui_Label10, 67);
    lv_obj_set_align(ui_Label10, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label10, "Manual mode");

    ui_Switch1 = lv_switch_create(ui_Screen1);
    lv_obj_set_width(ui_Switch1, 50);
    lv_obj_set_height(ui_Switch1, 25);
    lv_obj_set_x(ui_Switch1, 23);
    lv_obj_set_y(ui_Switch1, 65);
    lv_obj_set_align(ui_Switch1, LV_ALIGN_CENTER);

    ui_Label19 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label19, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label19, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label19, 4);
    lv_obj_set_y(ui_Label19, -79);
    lv_obj_set_align(ui_Label19, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label19, "Status & Pump");

    ui_Label21 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label21, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label21, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label21, -95);
    lv_obj_set_y(ui_Label21, 103);
    lv_obj_set_align(ui_Label21, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label21, "Manual pump ON");

    ui_Button12 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Button12, 50);
    lv_obj_set_height(ui_Button12, 30);
    lv_obj_set_x(ui_Button12, 133);
    lv_obj_set_y(ui_Button12, 101);
    lv_obj_set_align(ui_Button12, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button12, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button12, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_Button12, lv_color_hex(0x31B99E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Button12, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Button12, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label11 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label11, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label11, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label11, 6);
    lv_obj_set_y(ui_Label11, 6);
    lv_obj_set_align(ui_Label11, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label11, "24%");
    lv_obj_set_style_bg_color(ui_Label11, lv_color_hex(0x1E2A28), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Label11, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label22 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label22, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label22, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label22, 7);
    lv_obj_set_y(ui_Label22, -22);
    lv_obj_set_align(ui_Label22, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label22, "24%");
    lv_obj_set_style_bg_color(ui_Label22, lv_color_hex(0x1E2A28), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Label22, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label23 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label23, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label23, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label23, 7);
    lv_obj_set_y(ui_Label23, -47);
    lv_obj_set_align(ui_Label23, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label23, "24%");
    lv_obj_set_style_bg_color(ui_Label23, lv_color_hex(0x1E2A28), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Label23, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Button2, ui_event_Button2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button4, ui_event_Button4, LV_EVENT_ALL, NULL);

}
void ui_Screen2_screen_init(void)
{
    ui_Screen2 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Button5 = lv_btn_create(ui_Screen2);
    lv_obj_set_width(ui_Button5, 50);
    lv_obj_set_height(ui_Button5, 50);
    lv_obj_add_flag(ui_Button5, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label7 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label7, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label7, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label7, 114);
    lv_obj_set_y(ui_Label7, 22);
    lv_obj_set_align(ui_Label7, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label7, "1:30 h");
    lv_obj_set_style_bg_color(ui_Label7, lv_color_hex(0x1E2A28), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Label7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label9 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label9, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label9, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label9, 5);
    lv_obj_set_y(ui_Label9, 21);
    lv_obj_set_align(ui_Label9, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Label9, "Time to next watering");

    ui_Label16 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label16, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label16, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label16, 114);
    lv_obj_set_y(ui_Label16, 79);
    lv_obj_set_align(ui_Label16, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label16, "12 h");
    lv_obj_set_style_bg_color(ui_Label16, lv_color_hex(0x1E2A28), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Label16, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label8 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label8, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label8, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label8, 1);
    lv_obj_set_y(ui_Label8, -8);
    lv_obj_set_align(ui_Label8, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Label8, "Watering cycles a day");

    ui_Button7 = lv_btn_create(ui_Screen2);
    lv_obj_set_width(ui_Button7, 50);
    lv_obj_set_height(ui_Button7, 50);
    lv_obj_set_align(ui_Button7, LV_ALIGN_TOP_RIGHT);
    lv_obj_add_flag(ui_Button7, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label12 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label12, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label12, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label12, -113);
    lv_obj_set_y(ui_Label12, -34);
    lv_obj_set_align(ui_Label12, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label12, "Date & TIme");

    ui_Label13 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label13, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label13, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label13, 98);
    lv_obj_set_y(ui_Label13, -35);
    lv_obj_set_align(ui_Label13, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label13, "12.06.2022   19:36");

    ui_Label14 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label14, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label14, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label14, -59);
    lv_obj_set_y(ui_Label14, 77);
    lv_obj_set_align(ui_Label14, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label14, "Time between cycles in day");

    ui_Label17 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label17, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label17, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label17, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_Label17, "2");

    ui_Label20 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label20, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label20, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label20, -2);
    lv_obj_set_y(ui_Label20, -82);
    lv_obj_set_align(ui_Label20, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label20, "Scheduling ");

    ui_Label24 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label24, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label24, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label24, 129);
    lv_obj_set_y(ui_Label24, -5);
    lv_obj_set_align(ui_Label24, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label24, "3");
    lv_obj_set_style_bg_color(ui_Label24, lv_color_hex(0x1E2A28), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Label24, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label26 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label26, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label26, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label26, 1);
    lv_obj_set_y(ui_Label26, 51);
    lv_obj_set_align(ui_Label26, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Label26, "Watering cycles start hour");

    ui_Label27 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label27, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label27, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label27, 114);
    lv_obj_set_y(ui_Label27, 49);
    lv_obj_set_align(ui_Label27, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label27, "8:00 h");
    lv_obj_set_style_bg_color(ui_Label27, lv_color_hex(0x1E2A28), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Label27, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Button5, ui_event_Button5, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button7, ui_event_Button7, LV_EVENT_ALL, NULL);

}
void ui_Screen3_screen_init(void)
{
    ui_Screen3 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Chart1 = lv_chart_create(ui_Screen3);
    lv_obj_set_width(ui_Chart1, 320);
    lv_obj_set_height(ui_Chart1, 145);
    lv_obj_set_x(ui_Chart1, 0);
    lv_obj_set_y(ui_Chart1, -42);
    lv_obj_set_align(ui_Chart1, LV_ALIGN_BOTTOM_LEFT);

    ui_Button9 = lv_btn_create(ui_Screen3);
    lv_obj_set_width(ui_Button9, 50);
    lv_obj_set_height(ui_Button9, 50);
    lv_obj_add_flag(ui_Button9, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button9, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Button10 = lv_btn_create(ui_Screen3);
    lv_obj_set_width(ui_Button10, 50);
    lv_obj_set_height(ui_Button10, 50);
    lv_obj_set_align(ui_Button10, LV_ALIGN_TOP_RIGHT);
    lv_obj_add_flag(ui_Button10, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button10, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label18 = lv_label_create(ui_Screen3);
    lv_obj_set_width(ui_Label18, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label18, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label18, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_Label18, "3");

    ui_Label5 = lv_label_create(ui_Screen3);
    lv_obj_set_width(ui_Label5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label5, -4);
    lv_obj_set_y(ui_Label5, -85);
    lv_obj_set_align(ui_Label5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label5, "Temperature plot");

    ui_Button3 = lv_btn_create(ui_Screen3);
    lv_obj_set_width(ui_Button3, 60);
    lv_obj_set_height(ui_Button3, 40);
    lv_obj_set_align(ui_Button3, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_add_flag(ui_Button3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button3, lv_color_hex(0x52A48A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button6 = lv_btn_create(ui_Screen3);
    lv_obj_set_width(ui_Button6, 60);
    lv_obj_set_height(ui_Button6, 40);
    lv_obj_set_x(ui_Button6, 65);
    lv_obj_set_y(ui_Button6, 0);
    lv_obj_set_align(ui_Button6, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_add_flag(ui_Button6, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button6, lv_color_hex(0x52A48A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button8 = lv_btn_create(ui_Screen3);
    lv_obj_set_width(ui_Button8, 60);
    lv_obj_set_height(ui_Button8, 40);
    lv_obj_set_x(ui_Button8, 130);
    lv_obj_set_y(ui_Button8, 0);
    lv_obj_set_align(ui_Button8, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_add_flag(ui_Button8, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button8, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button8, lv_color_hex(0x52A48A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button11 = lv_btn_create(ui_Screen3);
    lv_obj_set_width(ui_Button11, 60);
    lv_obj_set_height(ui_Button11, 40);
    lv_obj_set_x(ui_Button11, 195);
    lv_obj_set_y(ui_Button11, 0);
    lv_obj_set_align(ui_Button11, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_add_flag(ui_Button11, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button11, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button11, lv_color_hex(0x52A48A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button11, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button1 = lv_btn_create(ui_Screen3);
    lv_obj_set_width(ui_Button1, 60);
    lv_obj_set_height(ui_Button1, 40);
    lv_obj_set_x(ui_Button1, 260);
    lv_obj_set_y(ui_Button1, 0);
    lv_obj_set_align(ui_Button1, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_add_flag(ui_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button1, lv_color_hex(0x52A48A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Button9, ui_event_Button9, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button10, ui_event_Button10, LV_EVENT_ALL, NULL);

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
    lv_disp_load_scr(ui_Screen1);
}
