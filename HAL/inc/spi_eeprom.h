/*
 * eeprom.h
 *
 * Created: 6/7/2020 2:00:29 PM
 *  Author: mnaguib
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "spi.h"

#define Ins_WREN	0x06
#define Ins_READ	0x03
#define Ins_WRITE	0x02

void SPI_EEPROM_Init(void);
INT8U SPI_EEPROM_ReadByte(INT16U u16RomAddr);
void SPI_EEPROM_WriteByte(INT16U u16RomAddr,INT8U u8Data);
#endif /* EEPROM_H_ */