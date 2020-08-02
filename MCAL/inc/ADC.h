/*
* ADC.h
*
* Created: 5/31/2020 2:55:19 PM
*  Author: mnaguib
*/


#ifndef ADC_H_
#define ADC_H_

#define  F_CPU 8000000UL
#include "avr/io.h"
#include "data_types.h"
#include "bit_math.h"
#include "util/delay.h"

/*

typedef struct{
	INT8U MUX     :5;
	INT8U ADLAR_B :1;
	INT8U REFS    :2;
}ADCMUX_BFD;

typedef struct{
	INT8U ADPS     :3;
	INT8U ADIE_B   :1;
	INT8U ADIF_B   :1;
	INT8U ADFR_B   :1;
	INT8U ADSC_B   :1;
	INT8U ADEN_B   :1;
}ADCSRA_BFD;

typedef struct{
	INT16U ADC_Data;
	ADCSRA_BFD ADCSRA_BF;
	ADCMUX_BFD	ADCMUX_BF; 
	}ADC_Struct;
	
#define ADC_Struct ((volatile ADC_Struct*)(0x24))
/*
#define	ADC_Data_LR	(((volatile INT8U*)(0x24)))

*/

void ADC_Init(void);
INT16U ADC_Read(INT8U u8Channel);



#endif /* ADC_H_ */