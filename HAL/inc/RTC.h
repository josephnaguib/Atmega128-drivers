/*
 * RTC.h
 *
 * Created: 6/8/2020 3:25:46 PM
 *  Author: mnaguib
 */ 


#ifndef RTC_H_
#define RTC_H_
#define  F_CPU 8000000UL
#include "avr/io.h"
#include "data_types.h"
#include "bit_math.h"
#include "util/delay.h"
#include "ext_interrrupt.h"
#include "TWI.h"

#define RTC_SLA_W		0b11010000
#define RTC_SLA_R		0b11010001

typedef struct{
	INT8U RTC_RegisterValues[7];
	INT8U RTC_Time[9];//10:20:23
	INT8U RTC_Date[11];//10/11/22
	}RTC_Struct;
	
void RTC_Init(void);
RTC_Struct* RTC_Update(void);

#endif /* RTC_H_ */