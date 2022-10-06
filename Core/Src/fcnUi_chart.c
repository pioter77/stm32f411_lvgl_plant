/*
 * fcnUi_chart.c
 *
 *  Created on: Oct 6, 2022
 *      Author: x280
 */
#include "fcnUi_chart.h"

void fcnUi_chart_init(void)
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

void fcnUi_chart_update(void)
{
	lv_chart_refresh(ui_Chart1);
}
