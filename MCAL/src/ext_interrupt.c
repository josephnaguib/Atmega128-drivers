/*
 * CFile1.c
 *
 * Created: 6/1/2020 2:38:24 PM
 *  Author: mnaguib
 */ 
#include "ext_interrrupt.h"


void (*callList[4])(void);
	
void EXT_Enable(INT_NUM intNum, INT_SENSE intSenseCtrl){		switch (intSenseCtrl)		{			/* 0b10 */			case INT_SENSE_FALLING:			clearBit(EICRA,(intNum*2));			break;			/* 0b11 */			case INT_SENSE_RISING:			setBit(EICRA,(intNum*2));			break;		}		setBit(EICRA,(intNum*2 + 1));		setBit(EIMSK,intNum);	}	void EXT_Disable(INT_NUM intNum){		clearBit(EIMSK,intNum);	}	void EXT_CallSetup(INT_NUM intNum, void (*ptrFun)(void)){		callList[intNum] = ptrFun;	}

ISR(INT0_vect){	callList[INT_0]();}ISR(INT1_vect){	callList[INT_1]();}ISR(INT2_vect){	callList[INT_2]();}ISR(INT3_vect){	callList[INT_3]();}



