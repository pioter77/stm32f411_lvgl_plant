/*
 * ctrl_measure.c
 *
 *  Created on: 18 paź 2022
 *      Author: x300
 */


#include "ctrl_measure.h"


ADC_t ADC_MEAS={
/*	.adc=ADC1,
	.channel_max= ADC_NO_CONV_END,
	.channel_cnt=0
	*/
};


void adc_init(void)
{
/*
	  //Dma Adc enable
	  LL_ADC_Disable(ADC1);
	  LL_DMA_DisableStream(DMA2, LL_DMA_STREAM_0);
	  LL_DMA_ConfigAddresses(DMA2,
			  	  	  	  	  LL_DMA_STREAM_0,
							  LL_ADC_DMA_GetRegAddr(ADC1, LL_ADC_DMA_REG_REGULAR_DATA),
							  (uint32_t)&adc_readouts_bufer,
							  LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
	  LL_DMA_SetDataLength(DMA2, LL_DMA_STREAM_0, ADC_CONV_NUMBERS);
	  LL_DMA_EnableIT_TC(DMA2, LL_DMA_STREAM_0);
	  LL_DMA_EnableIT_TE(DMA2, LL_DMA_STREAM_0);
	  LL_DMA_EnableStream(DMA2, LL_DMA_STREAM_0);



	  //init adc
	  LL_ADC_EnableIT_EOCS(ADC1);
	  LL_ADC_EnableIT_OVR(ADC1);
	  LL_ADC_Enable(ADC1);


	//start adc meas
	  LL_ADC_REG_StartConversionSWStart(ADC1);
	  */
}

void ctrl_measure_init(void)
{
	adc_init();
}

void ctrl_measure(void)
{

}

