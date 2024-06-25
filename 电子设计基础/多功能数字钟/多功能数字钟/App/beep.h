#ifndef _BEEP_H
#define _BEEP_H

#include "public.h"

sbit BEEP = P2^5;

void beep(u8 time);

#endif