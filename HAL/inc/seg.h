/*
* seg.h
*
* Created: 5/21/2020 10:56:26 AM
*  Author: mnaguib
*/
#include "board.h"

#ifndef SEG_H_
#define SEG_H_

#define SEG_DATA_PORT PORTC
#define SEG_DATA_DDR  DDRC

#define SEG_DIGIT_PORT PORTA
#define SEG_DIGIT_DDR  DDRA
#define SEG_DIGIT_MSK  0x0F
/*7 SEG Enable*/
#define SEG_EN_PORT		PORTF
#define SEG_EN_DDR		PORTF
#define SEG_EN_PIN		PF2

#define NUM_0          0xC0
#define NUM_1          0xF9
#define NUM_2          0xA4
#define NUM_3          0xB0
#define NUM_4          0x99
#define NUM_5          0x92
#define NUM_6          0x82
#define NUM_7          0xF8
#define NUM_8          0x80
#define NUM_9          0x90
#define NUM_DOT        0x7F

void Seg_Init(void);
void Seg_display(INT8U u8Digit, INT8U u8Value);
void Seg_displayInt(INT32U u32IntValue);
void seg_DisplayFloat(FP32 u32FloatValue);

#endif /* SEG_H_ */