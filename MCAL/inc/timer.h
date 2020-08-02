/*
* timer.h
*
* Created: 6/2/2020 11:27:23 AM
*  Author: mnaguib
*/


#ifndef TIMER_H_
#define TIMER_H_

#define  F_CPU 8000000UL
#include "avr/io.h"
#include "data_types.h"
#include "bit_math.h"
#include "util/delay.h"
#include "ext_interrrupt.h"


#define MODE_NORMAL		 0
#define MODE_CTC		 1
#define MODE_FAST_PWM	 2
#define MODE_PHASE_PWM	 3

/*typedef enum{
	MODE_NORMAL,MODE_CTC,MODE_FAST_PWM, MODE_PHASE_PWM
}Mode;*/

void Timer0_Init(INT8U Mode);
void Timer0_Start(void);
void Timer0_Stop(void);
void Timer0_ResetCounters(void);

void Timer0_DelayMS(INT32U delayMS);
void Timer0_DelayUS(INT32U delayUS);
// duty from 0-100 %
void Timer0_SetDuty(INT8U duty);
void Timer0_IncDuty(INT8U duty);
void Time0_DecDuty(INT8U duty);
//Timer delay in ms
void Timer0_SetNotification(void(*ptrFun)(void), INT32U notifyDelay);


#endif /* TIMER_H_ */