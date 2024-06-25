#ifndef _time_H
#define __time_H

#include "public.h"

extern u8 times[8];                   //用于存储时间的值

void time_change_mode0(void);                      //时间进位
void time_change_mode1(u8 i) reentrant;
void key(void);

#endif