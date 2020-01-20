/*
 * Ethernet.PHY.LAN8742A.c
 *
 *  Created on: 2019Äê5ÔÂ24ÈÕ
 *      Author: Master.HE
 */
#include "Ethernet.PHY.LAN8742A.Define.h"
#include "Ethernet.PHY.LAN8742A.Enum.h"
#include "Drivers.STM32F4xx.Ether.Enum.h"
#include "API.h"
#include "Ethernet.PHY.LAN8742A.h"
#include "Ethernet\Ethernet.h"



int Ethernet_PHY_LAN8742A_IO_Reset(int Handle)
{
	return Device_Control(Handle,Ether_Control_PHY_IO_Reset);
}
int Ethernet_PHY_LAN8742A_Register_Reset(int Handle)
{
	int Err=Ethernet_PHY_Register_Write(
			Handle,
			Layer_Config_Physical_PHY_Address,
			PHY_LAN8742A_Register_BasicControl,
			PHY_Reset);

	if(Err!=Error_OK)
	{
		return Err;
	}

	Scheduling_Sleep_Task(50);

	return Error_OK;
}
int Ethernet_PHY_LAN8742A_SET_AutoNego(int Handle)
{
	int Err=Ethernet_PHY_Register_Write(
			Handle,
			Layer_Config_Physical_PHY_Address,
			PHY_LAN8742A_Register_BasicControl,
			PHY_AutoNegotiation);

	if(Err!=Error_OK)
	{
		return Err;
	}

	//Scheduling_Sleep_Task(50);

	return Error_OK;
}

int Ethernet_PHY_LAN8742A_GET_AutoNego_Complete(int Handle)
{
	uint16_t DATA=0;
	int Err=Ethernet_PHY_Register_Read(
			Handle,
			Layer_Config_Physical_PHY_Address,
			PHY_LAN8742A_Register_BasicStatus,
			&DATA);

	if(Err!=Error_OK)
	{
		return Err;
	}
	if((DATA&PHY_AutoNego_Complete)==0)
	{
		return false;
	}
	else
	{
		return true;
	}

}
int Ethernet_PHY_LAN8742A_GET_Linked_Status(int Handle)
{
	uint16_t DATA=0;


	int Err=Ethernet_PHY_Register_Read(
			Handle,
			Layer_Config_Physical_PHY_Address,
			PHY_LAN8742A_Register_BasicStatus,
			&DATA);

	if(Err!=Error_OK)
	{
		return Err;
	}

	Err=Ethernet_PHY_Register_Read(
				Handle,
				Layer_Config_Physical_PHY_Address,
				PHY_LAN8742A_Register_BasicStatus,
				&DATA);

	if(Err!=Error_OK)
	{
		return Err;
	}

	if((DATA&PHY_Linked_Status)==0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
