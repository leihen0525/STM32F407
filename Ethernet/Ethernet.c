/*
 * Ethernet.c
 *
 *  Created on: 2019Äê7ÔÂ15ÈÕ
 *      Author: Master.HE
 */
#include "API.h"
#include "Module\Module.h"
#include "Error.h"
#include "Net.Core.Device.h"
#include "Net.Device.Struct.h"
#include "Drivers.STM32F4xx.Ether.Enum.h"
#include "Drivers.STM32F4xx.Ether.Struct.h"

#include "Ethernet.PHY.LAN8742A\Ethernet.PHY.LAN8742A.h"
#include "Ethernet.h"

Ethernet_DATA_Type Ethernet_DATA;

const Net_Device_OPS_Type Ethernet_OPS=
{
	.Device_Name="eth0",
	.Info="MCU:STM32F4xx Module:eth0 Version:0.0.1 "__DATE__" "__TIME__,

	.HEADER=14,
	.MTU=1500,
	.MAC_Address={0x10,0x22,0x33,0x44,0x55,0x66},

	.Init=Ethernet_Init,
	.SET_MAC_Address=Ethernet_SET_MAC_Address,
	.GET_Linked_Status=Ethernet_GET_Linked_Status,
	.Open=Ethernet_Open,
	.Close=Ethernet_Close,
	.Read=Ethernet_Read,
	.Write=Ethernet_Write,
};
const Net_Device_IP_Config Ethernet_IP_Config=
{
	.IPv4=
	{
		.IP_Address={192,168,50,125},
		.SubNet_Mask={255,255,255,0},
		.Default_Gateway={192,168,50,1},
	},
};
int Ethernet_Eetup(void)
{
	Ethernet_DATA.Handle=-1;

	Net_Core_Device_Register(Net_Device_Ethernet,false,(Net_Device_IP_Config *)&Ethernet_IP_Config,&Ethernet_OPS);

	return Error_OK;
}
int Ethernet_Init(int Flag)
{
	int Err;

	if((Err=Ethernet_DATA.Handle=Device_Open("Ether",0))<Error_OK)
	{
		return Err;
	}
	Ethernet_DATA.Handle=Err;

	if((Err=Ethernet_PHY_LAN8742A_IO_Reset(Ethernet_DATA.Handle))!=Error_OK)
	{
		return Err;
	}
	if((Err=Ethernet_PHY_LAN8742A_Register_Reset(Ethernet_DATA.Handle))!=Error_OK)
	{
		return Err;
	}

	if((Err=Ethernet_PHY_LAN8742A_SET_AutoNego(Ethernet_DATA.Handle))!=Error_OK)
	{
		return Err;
	}

	return Error_OK;
}
int Ethernet_SET_MAC_Address(uint8_t *MAC_Address)
{
	return Device_Control(Ethernet_DATA.Handle,Ether_Control_SET_MAC_Address,MAC_Address);
}
int Ethernet_GET_Linked_Status(void)
{
	return Ethernet_PHY_LAN8742A_GET_Linked_Status(Ethernet_DATA.Handle);
}
int Ethernet_Open(void)
{
	return Device_Control(Ethernet_DATA.Handle,Ether_Control_SET_MAC_Start);
}
int Ethernet_Close(void)
{
	return Device_Control(Ethernet_DATA.Handle,Ether_Control_SET_MAC_Stop);
}

int Ethernet_Read(void *Buffer, unsigned long Size,int TimeOut)
{
	return Device_Read(Ethernet_DATA.Handle,0,Buffer,Size,TimeOut);
}
int Ethernet_Write(long OffSet_Pos,const void *Buffer, unsigned long Size,int TimeOut)
{
	return Device_Write(Ethernet_DATA.Handle,OffSet_Pos,Buffer,Size,TimeOut);
}



















int Ethernet_PHY_Register_Write(int Handle,uint8_t PHYAddress, uint8_t PHYReg, uint16_t PHYValue)
{
	Ether_Control_PHY_DATA_Type PHY_DATA;

	PHY_DATA.PHY_Address=PHYAddress;
	PHY_DATA.MII_Register=PHYReg;
	PHY_DATA.DATA=PHYValue;

	return Device_Control(Handle,Ether_Control_PHY_Register_Write,&PHY_DATA);
}

int Ethernet_PHY_Register_Read(int Handle,uint8_t PHYAddress, uint8_t PHYReg,uint16_t *PHYValue)
{
	if(PHYValue==Null)
	{
		return Error_Invalid_Parameter;
	}
	*PHYValue=0;

	Ether_Control_PHY_DATA_Type PHY_DATA;

	PHY_DATA.PHY_Address=PHYAddress;
	PHY_DATA.MII_Register=PHYReg;
	PHY_DATA.DATA=0;

	int Err=Device_Control(Handle,Ether_Control_PHY_Register_Read,&PHY_DATA);

	if(Err!=Error_OK)
	{
		return Err;
	}
	*PHYValue=PHY_DATA.DATA;
	return Error_OK;

}


Com_Module_Init_Export(Ethernet_Eetup);
