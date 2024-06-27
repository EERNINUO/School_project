#include "reg52.h"
#include "intrins.h"
#define LED P2

typedef unsigned char u8;
typedef unsigned int u16;

void delay(u16 i){
	while(i--);
}

u8 i = 0;	

void main(){
	LED = 0xfc;
	while(1){
		LED = _crol_(LED,1);
		delay(20000);
	}
}


