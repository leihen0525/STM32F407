/*
 * Ethernet.PHY.LAN8742A.h
 *
 *  Created on: 2019Äê5ÔÂ24ÈÕ
 *      Author: Master.HE
 */

#ifndef ETHERNET_PHY_LAN8742A_H_
#define ETHERNET_PHY_LAN8742A_H_

int Ethernet_PHY_LAN8742A_IO_Reset(int Handle);
int Ethernet_PHY_LAN8742A_Register_Reset(int Handle);
int Ethernet_PHY_LAN8742A_SET_AutoNego(int Handle);

int Ethernet_PHY_LAN8742A_GET_AutoNego_Complete(int Handle);
int Ethernet_PHY_LAN8742A_GET_Linked_Status(int Handle);

#endif /* ETHERNET_PHY_LAN8742A_H_ */
