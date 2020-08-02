/*
 * eeprom.c
 *
 * Created: 6/7/2020 2:00:41 PM
 *  Author: mnaguib
 */ 
#include "spi_eeprom.h"

static void SPI_EEPROM_WriteEnable(void);


void SPI_EEPROM_Init(void){
	SPI_Init(MODE_MASTER);
}
static void SPI_EEPROM_WriteEnable(void){
	clearBit(SPI_PORT,SPI_SS);
	SPI_Tranceive(Ins_WREN);
	setBit(SPI_PORT,SPI_SS);
	_delay_ms(10);
}
INT8U SPI_EEPROM_ReadByte(INT16U u16RomAddr){
		INT8U result=0;
		clearBit(SPI_PORT,SPI_SS);
		/*Send Read instruction*/
		SPI_Tranceive(Ins_READ|((u16RomAddr>>5)&0x08)); //Set the A8 in the instruction Reg
		/*Send ROM Address*/
		SPI_Tranceive((INT8U)u16RomAddr);
		/*Receive and read data from EEPROM*/
		result=SPI_Tranceive(0x00);
		
		setBit(SPI_PORT,SPI_SS);
		_delay_ms(10);
		return result;
		
}
void SPI_EEPROM_WriteByte(INT16U u16RomAddr,INT8U u8Data){
	SPI_EEPROM_WriteEnable();
	clearBit(SPI_PORT,SPI_SS);
	
	SPI_Tranceive(Ins_WRITE|((u16RomAddr>>5)&0x08)); //Set the A8 in the instruction Reg
	SPI_Tranceive((INT8U)u16RomAddr);
	SPI_Tranceive(u8Data);
	
	setBit(SPI_PORT,SPI_SS);
	_delay_ms(10);
}