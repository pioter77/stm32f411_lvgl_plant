/*
 * ctrl_timers.c
 *
 *  Created on: 18 paź 2022
 *      Author: x300
 */


#include "ctrl_timing.h"


//void hardware_initialize(void)
//{
	/*
	//enable led timers
		  LL_TIM_EnableIT_UPDATE(TIM3);
		  LL_TIM_CC_EnableChannel(TIM3, LL_TIM_CHANNEL_CH1);
		  LL_TIM_CC_EnableChannel(TIM3, LL_TIM_CHANNEL_CH2);
		  LL_TIM_CC_EnableChannel(TIM3, LL_TIM_CHANNEL_CH3);
		  LL_TIM_CC_EnableChannel(TIM3, LL_TIM_CHANNEL_CH4);
		  LL_TIM_OC_SetCompareCH1(TIM3, 0);
		  LL_TIM_OC_SetCompareCH2(TIM3, 0);
		  LL_TIM_OC_SetCompareCH3(TIM3, 0);
		  LL_TIM_OC_SetCompareCH4(TIM3, 0);
		  LL_TIM_EnableCounter(TIM3);
	//enable encoder timer:
		  //for advanced timers type only:
		  LL_TIM_EnableAutomaticOutput(TIM1);
		  //encoder:
		  LL_TIM_EnableCounter(TIM1);
		  TIM1->ARR=179;
		  TIM1->CNT=0;
		  */
//}

timing_t TIMING={

		.tims_1000ms1= {0,0,0,0},
		.tims_1000ms2= {0,0,0,0},
		.tims_1000ms3= {0,0,0,0},
		.tims_plant1Check= {0,0,0,0},
		.tims_plant2Check= {0,0,0,0},
		.tims_plant1Water= {0,0,0,0},
		.tims_plant2Water= {0,0,0,0},

};

void co_timing_init(timing_t *ctrl_t)
{
	ctrl_t->tim_instance= TIM5;
	ctrl_t->psc= 100-1;
	ctrl_t->arr= 1000-1;		//those params will give ims tick update

	LL_TIM_DisableCounter(ctrl_t->tim_instance);
	LL_TIM_ClearFlag_UPDATE(ctrl_t->tim_instance);
	LL_TIM_EnableIT_UPDATE(ctrl_t->tim_instance);
	LL_TIM_SetAutoReload(ctrl_t->tim_instance, ctrl_t->arr);
	LL_TIM_SetPrescaler(ctrl_t->tim_instance, ctrl_t->psc);
	LL_TIM_EnableCounter(ctrl_t->tim_instance);

	timingSetLength(&ctrl_t->tims_1000ms1, 300);
	timingSetLength(&ctrl_t->tims_1000ms2, 1000);
	timingSetLength(&ctrl_t->tims_1000ms3, 1000);

	timingStart(&ctrl_t->tims_1000ms1);
	timingStart(&ctrl_t->tims_1000ms2);
	timingStart(&ctrl_t->tims_1000ms3);



}

void co_timing_ISR(timing_t *ctrl_t)
{
	if(LL_TIM_IsActiveFlag_UPDATE(ctrl_t->tim_instance))
	{
		LL_TIM_ClearFlag_UPDATE(ctrl_t->tim_instance);

		timingCount(&ctrl_t->tims_1000ms1);
		timingCount(&ctrl_t->tims_1000ms2);
		timingCount(&ctrl_t->tims_1000ms3);


		//timing for plants:
		timingCount(&ctrl_t->tims_plant1Check);
		timingCount(&ctrl_t->tims_plant2Check);
		timingCount(&ctrl_t->tims_plant1Water);
		timingCount(&ctrl_t->tims_plant2Water);

		//htu21d timing:
		timingCount(&ctrl_t->tims_htu21d);


	}
}

_Bool timingIsUp(tims_t *tims)
{
	if(tims->isOn)
	{
		if(tims->isUp) return 1;
		else return 0;
	}else{
		return 0;
	}
}

_Bool timingIsOn(tims_t *tims)
{

	return (_Bool)(tims->isOn);
}

void timingSetLength(tims_t *tims, uint32_t length)
{
	tims->count_max= length;
}

void timingRestart(tims_t *tims)
{
	tims->isOn= 0;
	tims->count= 0;
	tims->isUp= 0;
	tims->isOn= 1;
}

void timingStart(tims_t *tims)
{
	tims->isOn=1;
}

void timingStop(tims_t *tims)
{
	tims->isOn= 0;
	tims->count= 0;
	tims->isUp= 0;
}

//called in isr:
void timingCount(tims_t *tims)
{
	if(tims->isOn)
	{
		if(tims->count < tims->count_max) tims->count++;
		else {
			tims->isUp=1;
		}
	}else return;
}




