/*
 * Ethernet.PHY.LAN8742A.Enum.h
 *
 *  Created on: 2019Äê5ÔÂ24ÈÕ
 *      Author: Master.HE
 */

#ifndef ETHERNET_PHY_LAN8742A_ENUM_H_
#define ETHERNET_PHY_LAN8742A_ENUM_H_

typedef enum
{
	PHY_LAN8742A_Register_BasicControl							=0,
	PHY_LAN8742A_Register_BasicStatus							=1,
	PHY_LAN8742A_Register_Identifier1							=2,
	PHY_LAN8742A_Register_Identifier2							=3,
	PHY_LAN8742A_Register_AutoNegotiationAdvertisement			=4,
	PHY_LAN8742A_Register_AutoNegotiationLinkPartnerAbility		=5,
	PHY_LAN8742A_Register_AutoNegotiationExpansion				=6,
	PHY_LAN8742A_Register_ModeControl_Status					=17,
	PHY_LAN8742A_Register_SpecialModes							=18,
	PHY_LAN8742A_Register_SymbolErrorCounter					=26,
	PHY_LAN8742A_Register_Control_StatusIndication				=27,
	PHY_LAN8742A_Register_InterruptSource						=29,
	PHY_LAN8742A_Register_InterruptMask							=30,
	PHY_LAN8742A_Register_SpecialControl_Status					=31,

}PHY_LAN8742A_Register_Type;

#endif /* ETHERNET_PHY_LAN8742A_ENUM_H_ */
