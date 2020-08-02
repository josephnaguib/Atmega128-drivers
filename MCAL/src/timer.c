/*
* timer.c
*
* Created: 6/2/2020 11:27:46 AM
*  Author: mnaguib
*/
/*
	clearBit(TCCR0,CS00);
	clearBit(TCCR0,CS01);
	clearBit(TCCR0,CS02);
	/*clearBits(TCCR0,((1<<CS00)|(1<<CS01)|(1<<CS02)));*/
	
}
void Timer0_ResetCounters(void){
	TCNT0=0;
	overflows=0;
}


void Timer0_DelayMS(INT32U delayMS){
	Timer0_ResetCounters();
	Timer0_Start();
	while((delayMS*1000UL)>(TCNT0+overflows*256+1));
}
void Timer0_DelayUS(INT32U delayUS){
	Timer0_ResetCounters();
	Timer0_Start();
	while((delayUS)>(TCNT0+overflows*256+1));
	
}
void Timer0_SetDuty(INT8U duty){
	OCR0=(duty*255)/100;
}
void Timer0_IncDuty(INT8U Incduty){
	if((OCR0+(Incduty*255)/100)<=255){
		OCR0+=(Incduty*255)/100;
	}
	else{
		OCR0=255;
	}
}
void Time0_DecDuty(INT8U decduty){
	if(OCR0>=(decduty*255UL)/100){
		OCR0-=(decduty*255UL)/100;
	}
	else{
		OCR0=0;
	}
}
//Timer delay in ms
void Timer0_SetNotification(void(*ptrFun)(void), INT32U notifyDelay){
	notifier=ptrFun;
	notifyDelay=notifyDelay;
	Timer0_ResetCounters();
	//Calculate counters
	TCNT0=256-((notifyDelay*1000)%256-1);
	calcoverflows=(notifyDelay*1000)/256+1;
	Timer0_Start();
}
