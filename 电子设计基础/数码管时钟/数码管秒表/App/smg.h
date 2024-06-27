#ifndef _smg_H
#define _smg_H

#include "public.h"

#define SMG_A_DP_PORT	P0

//数码管位选控制
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

void smg(u8 dat[]);

#endif