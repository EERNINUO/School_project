#include "smg.h"
#include "public.h"
#include "beep.h"

static key_value = 0;                   //保存按键按下的次数
u8 times[2] = {0,0};        //用于存储时间的值

void time_0_set(){                      //定时器0设置
    EA = 1;
    ET0 = 1;
    TMOD |= 0x01;
    TH0 = 0xFC;
    TL0 = 0x66;
}

void init_set(){                        //外部中断0设置
    EX0 = 1;
    EX1 = 1;
    IT0 = 1;
    IT1 = 1;
}

void main(){
    time_0_set();
	init_set();
    while(1){
        smg(times);
    }
}

void key() interrupt 0{
    delay_10us(1000);
	beep(200);
    if(P3^2 == 0){
        if(key_value == 0){
            TF0 = 0;
            TR0 = 1;
            key_value++;
            IE0 = 0;
        }
        else if (key_value == 1)
        {
            TF0 = 0;
            TR0 = 0;
            key_value++;
            IE0 = 0;
        }
        else if(key_value == 2){
            u8 j;
            for(j=0;j<2;j++){
                times[j] = 0;
                TF0 = 0;
            }
            key_value = 0;
            IE0 = 0;
        }
    }
}

void time() interrupt 1{
    static u16 i = 0;   
    TH0 = 0xFC;
    TL0 = 0x66;
    i++;
    if(i == 100){
        times[1]++;
        if(times[1] == 10){
            times[0]++;
            times[1] = 0;
            if(times[0] == 10){
                times[0] = 0;
            }
        }
        i = 0;
    }
    TF0 = 0;
    TR0 = 1;
}