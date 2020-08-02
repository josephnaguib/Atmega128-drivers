/*
 * TWI.c
 *
 * Created: 6/8/2020 1:16:01 PM
 *  Author: mnaguib
 */ 
#include "TWI.h"

/*100 KHz*/
void TWI_Init(void){
	TWBR=32; /*100KHz, TWPS:0*/
}
Bool TWI_Start(void){
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	TWI_Wait();
	return((TWSR&0xF8)==SC_Start);
}
Bool TWI_Restart(void){
		TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
		TWI_Wait();
		return((TWSR&0xF8) ==SC_Restart);
}
void TWI_Stop(void){
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}
Bool TWI_Wait(void){
	while (!(TWCR & (1<<TWINT))); /*Wait for TWINT==1*/
}

Bool TWI_WriteByte(INT8U u8Byte, INT8U u8StatusCode){
	TWDR = u8Byte;
	TWCR = (1<<TWINT) | (1<<TWEN);
	TWI_Wait();
	return((TWSR&0xF8) ==u8StatusCode);
}
Bool TWI_ReadByte(INT8U *pu8Byte, INT8U u8StatusCode){
	Bool result=FALSE;
	TWCR = (1<<TWINT) | (1<<TWEN);
	if(u8StatusCode== SC_MR_DATA_ACK){
		TWCR |= (1<<TWEA);
	}
	TWI_Wait();
	if((TWSR&0xF8) ==u8StatusCode){
		(*pu8Byte)=TWDR;
		result=TRUE;
	}
	return result;       
}
