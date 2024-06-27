#include "reg52.h"
#define LED P2

typedef unsigned char u8;
typedef unsigned int u16;

void delay(u16 time){
	while(time--);
}

u8 i = 0;	

void main(){
	while(1){
		for(i=0;i<8;i++){
			LED = ~(0x01<<i);
			delay(50000);
		}
	}
}
