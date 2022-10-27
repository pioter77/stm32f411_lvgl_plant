/*
 * ctrl_measure.h
 *
 *  Created on: 18 paź 2022
 *      Author: x300
 */

#ifndef INC_CTRL_MEASURE_H_
#define INC_CTRL_MEASURE_H_

#include "main.h"
#include "adc.h"


#define ADC_NO_CONV 4
#define ADC_NO_CONV_END (ADC_NO_CONV-1)

typedef struct CTRL_MEAS_T{

}CTRL_MEAS_t;


typedef struct ADC_T{
	ADC_TypeDef *adc;
	uint16_t channel_end;
	volatile uint16_t channel_cnt;
	volatile uint16_t adc_buff[ADC_NO_CONV];	//in % 0-100%
}ADC_t;

extern ADC_t ADC_MEAS;

void adc_init(void);
void ctrl_measure_init(void);
void ctrl_measure(void);

#endif /* INC_CTRL_MEASURE_H_ */
