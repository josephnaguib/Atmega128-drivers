/*
 * RTC.c
 *
 * Created: 6/8/2020 3:25:55 PM
 *  Author: mnaguib
 */ 
#include "RTC.h"

static RTC_Struct RTC;

void RTC_Init(void){
	TWI_Init();
}
RTC_Struct* RTC_Update(void){
	INT8U ind = 0;