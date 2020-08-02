/*
 * ext_interrrupt.h
 *
 * Created: 6/1/2020 2:38:16 PM
 *  Author: mnaguib
 */ 


#ifndef EXT_INTERRRUPT_H_
#define EXT_INTERRRUPT_H_
#define  F_CPU 8000000UL
#include "avr/io.h"
#include "data_types.h"
#include "bit_math.h"
#include "util/delay.h"
#include "avr/interrupt.h"
#include "queue.h"


typedef enum{
	INT_0,INT_1,INT_2,INT_3
	}INT_NUM;
	
typedef enum{
	INT_SENSE_FALLING,INT_SENSE_RISING
}INT_SENSE;
void (*callList[4]) (void);
void EXT_Enable(INT_NUM intNum,INT_SENSE intsenseCtrl);
void EXT_disable(INT_NUM intNum);
void EXT_CallSetup(INT_NUM intNum, void (*ptrFun)(void));

#endif /* EXT_INTERRRUPT_H_ */