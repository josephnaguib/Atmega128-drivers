/*
 * CFile1.c
 *
 * Created: 6/1/2020 2:38:24 PM
 *  Author: mnaguib
 */ 
#include "ext_interrrupt.h"


void (*callList[4])(void);
	
void EXT_Enable(INT_NUM intNum, INT_SENSE intSenseCtrl){

ISR(INT0_vect){


