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
#include "ctrl_process.h"

#define ADC_NO_CONV 4
#define ADC_NO_CONV_END (ADC_NO_CONV-1)

typedef struct CTRL_MEAS_T{

}CTRL_MEAS_t;

typedef enum {ADC_CONV_NOT_FINISHED=0, ADC_CONV_FISHED} isConvFinished_t;

typedef struct ADC_T{
	ADC_TypeDef *adc;
	DMA_TypeDef *dma;
	uint32_t dma_channel;
	uint16_t adc_conv_max;
	volatile isConvFinished_t isConvFinished;				//flag to 1 when string of channel conversion
	volatile uint16_t adc_buff[ADC_NO_CONV];	//in % 0-100%
}ADC_t;

extern ADC_t ADC_MEAS;

void ctrl_measure(void);				//in this function we interract with process that will get adc values

void adc_init(void);
//void adc_update(void);
void adc_dma_isr_handler(void);
void ctrl_measure_init(void);


#endif /* INC_CTRL_MEASURE_H_ */
