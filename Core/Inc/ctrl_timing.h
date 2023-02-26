/*
 * ctrl_timers.h
 *
 *  Created on: 18 paź 2022
 *      Author: x300
 */

#ifndef INC_CTRL_TIMING_H_
#define INC_CTRL_TIMING_H_

#include "main.h"
#include "tim.h"

typedef struct tims_T{
	_Bool isOn;
	_Bool isUp;
	volatile uint32_t count;
	volatile uint32_t count_max;
}tims_t;

typedef struct timing_T{
	TIM_TypeDef *tim_instance;
	uint16_t arr;
	uint16_t psc;

	tims_t tims_1000ms1;
	tims_t tims_1000ms2;
	tims_t tims_1000ms3;

	tims_t tims_plant1Check;
	tims_t tims_plant1Water;
	tims_t tims_plant1Life;
	tims_t tims_plant2Check;
	tims_t tims_plant2Water;
	tims_t tims_plant2Life;
}timing_t;

extern timing_t TIMING;

void co_timing_init(timing_t *ctrl_t);
void co_timing_ISR(timing_t *ctrl_t);

_Bool timingIsUp(tims_t *tims);
_Bool timingIsOn(tims_t *tims);
void timingSetLength(tims_t *tims, uint32_t length);
void timingRestart(tims_t *tims);
void timingStart(tims_t *tims);
void timingStop(tims_t *tims);
void timingCount(tims_t *tims);




#endif /* INC_CTRL_TIMING_H_ */
