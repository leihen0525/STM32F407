/*
 * main.c
 *
 *  Created on: 2019Äê9ÔÂ18ÈÕ
 *      Author: Master.HE
 */
#include "Module\Module.h"
#include "Net.Socket.h"


int aaaa(void);
int aaaa(void)
{
	int hh=Net_Socket(Net_Socket_Domain_AF_INET,0,Net_Socket_Protocol_IPPROTO_UDP);
	
	Net_Bind(hh,Null);
	
	return 0;
}


Application_Module_Init_Export(aaaa);