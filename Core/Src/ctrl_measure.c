/*
 * ctrl_measure.c
 *
 *  Created on: 18 paź 2022
 *      Author: x300
 */


#include "ctrl_measure.h"


ADC_t ADC_MEAS={
	.adc=ADC1,
	.dma= DMA2,
	.dma_channel= LL_DMA_STREAM_0,
	.adc_conv_max= ADC_NO_CONV,
	.isConvFinished= ADC_CONV_NOT_FINISHED,
	.adc_buff[0 ... ADC_NO_CONV_END]=0,

};



#if ADC_NO_CONV > 1
	 volatile uint16_t adc_median_buff1[ADC_FILTER_LEN];
#endif
#if ADC_NO_CONV > 1
	 volatile uint16_t adc_median_buff2[ADC_FILTER_LEN];
#endif
#if ADC_NO_CONV > 2
	 volatile uint16_t adc_median_buff3[ADC_FILTER_LEN];
#endif
#if ADC_NO_CONV > 3
	 volatile uint16_t adc_median_buff4[ADC_FILTER_LEN];
#endif




void adc_init(void)
{
	  //Dma Adc enable
	  LL_ADC_Disable(ADC_MEAS.adc);
	  LL_DMA_DisableStream(ADC_MEAS.dma, ADC_MEAS.dma_channel);
	  LL_DMA_ConfigAddresses(ADC_MEAS.dma,
			  	  	  	  	  ADC_MEAS.dma_channel,
							  LL_ADC_DMA_GetRegAddr(ADC_MEAS.adc, LL_ADC_DMA_REG_REGULAR_DATA),
							  (uint32_t)&ADC_MEAS.adc_buff,
							  LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
	  LL_DMA_SetDataLength(ADC_MEAS.dma, ADC_MEAS.dma_channel, ADC_MEAS.adc_conv_max);
	  LL_DMA_EnableIT_TC(ADC_MEAS.dma, ADC_MEAS.dma_channel);
	  LL_DMA_EnableIT_TE(ADC_MEAS.dma, ADC_MEAS.dma_channel);
	  LL_DMA_EnableStream(ADC_MEAS.dma, ADC_MEAS.dma_channel);

	  //init adc
	  LL_ADC_EnableIT_EOCS(ADC_MEAS.adc);
	  LL_ADC_EnableIT_OVR(ADC_MEAS.adc);
	  LL_ADC_Enable(ADC_MEAS.adc);

		//start adc meas
	  LL_ADC_REG_StartConversionSWStart(ADC_MEAS.adc);
}

void adc_dma_isr_handler(void)
{
	if(LL_DMA_IsActiveFlag_TC0(ADC_MEAS.dma))
	{
		LL_DMA_ClearFlag_TC0(ADC_MEAS.dma);
	}
	if(LL_DMA_IsActiveFlag_TE0(ADC_MEAS.dma))
	{
		LL_DMA_ClearFlag_TE0(ADC_MEAS.dma);
	}
}

void ctrl_measure_init(void)
{
	adc_init();
}

void ctrl_measure(void)
{
//	PLANT1.moisture_level_raw= ADC_MEAS.adc_buff[0];
//	PLANT2.moisture_level_raw= ADC_MEAS.adc_buff[1];
	PLANT1.moisture_level_raw= adc_median_filter(ADC_MEAS.adc_buff[0], (uint16_t *)adc_median_buff1);
	PLANT2.moisture_level_raw= adc_median_filter(ADC_MEAS.adc_buff[1], (uint16_t *)adc_median_buff2);

	PLANT1.moisture_level= (uint16_t)((PLANT1.moisture_level_raw/4095.0)*100.0);
	PLANT2.moisture_level= (uint16_t)((PLANT2.moisture_level_raw/4095.0)*100.0);
//	ADC_MEAS.adc_buff[2];
//	ADC_MEAS.adc_buff[3];
}

uint16_t adc_median_filter(uint16_t input_val, uint16_t *buff)
{
	uint16_t buff_med[ADC_FILTER_LEN];
	memcpy(buff_med, (buff+1), ADC_FILTER_LEN-1);
	buff_med[ADC_FILTER_LEN-1]= input_val;
	qsort(buff_med, ADC_FILTER_LEN, sizeof(uint16_t), compare_fcn);
	volatile uint16_t ret_val= (buff_med[ADC_FILTER_LEN/2-1]+buff_med[ADC_FILTER_LEN/2])/2;

	for(uint8_t i=0; i<ADC_FILTER_LEN-1; i++) buff[i]= buff[i+1];
	buff[ADC_FILTER_LEN-1]= input_val;
	return ret_val;
}

int compare_fcn(const void *a, const void *b)
{
	const uint16_t a_bak= *(const uint16_t *)a;
	const uint16_t b_bak= *(const uint16_t *)b;

	if(a_bak < b_bak) return -1;
	else if(a_bak > b_bak) return 1;
	else return 0;


}
