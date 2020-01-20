/*
 * Ethernet.h
 *
 *  Created on: 2019Äê7ÔÂ15ÈÕ
 *      Author: Master.HE
 */

#ifndef ETHERNET_H_
#define ETHERNET_H_

#include "Master.Stdint.h"

#include "Ethernet.Struct.h"

int Ethernet_Eetup(void);
int Ethernet_Init(int Flag);
int Ethernet_SET_MAC_Address(uint8_t *MAC_Address);
int Ethernet_GET_Linked_Status(void);
int Ethernet_Open(void);
int Ethernet_Close(void);
int Ethernet_Read(void *Buffer, unsigned long Size,int TimeOut);
int Ethernet_Write(long OffSet_Pos,const void *Buffer, unsigned long Size,int TimeOut);

int Ethernet_PHY_Register_Write(int Handle,uint8_t PHYAddress, uint8_t PHYReg, uint16_t PHYValue);
int Ethernet_PHY_Register_Read(int Handle,uint8_t PHYAddress, uint8_t PHYReg,uint16_t *PHYValue);



extern Ethernet_DATA_Type Ethernet_DATA;


#endif /* ETHERNET_H_ */
