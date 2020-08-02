/*
 * seg.c
 *
 * Created: 5/21/2020 10:56:42 AM
 *  Author: mnaguib
 */ 
#include"seg.h"
static const int Numbers[]={NUM_0,NUM_1,NUM_2,NUM_3,
	NUM_4,NUM_5,NUM_6,NUM_7,NUM_8,NUM_9,NUM_DOT};
void Seg_Init(void){
	/*7SEG EN(Active low)*/
	setBit(SEG_EN_DDR,SEG_EN_PIN);
	clearBit(SEG_EN_PORT,LEDS_EN_PIN);
	
	setALLBits(SEG_DATA_DDR);//All Output
	setBits(SEG_DIGIT_DDR,SEG_DIGIT_MSK);//0x0f
	/* DEFAULT*/
	setALLBits(SEG_DATA_PORT);
	clearBits(SEG_DIGIT_PORT, SEG_DIGIT_MSK);
}
void Seg_display(INT8U u8Digit, INT8U u8Value){
	/*Select digit*/
	setBit(SEG_DIGIT_PORT, (u8Digit-1));
	/* apply data value*/
	if(u8Value==NUM_DOT)
	SEG_DATA_PORT=Numbers[10];
	else
	SEG_DATA_PORT=Numbers[u8Value];
	_delay_ms(1);
	clearBit(SEG_DIGIT_PORT, (u8Digit-1));
}