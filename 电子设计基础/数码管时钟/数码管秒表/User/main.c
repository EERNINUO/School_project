#include "smg.h"
#include "public.h"

u8 times[8] = {0,0,0,0,0,0,0,0};        //用于存储时间的值
static key_value = 0;                   //保存按键按下的次数

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

void time_change(){                      //时间进位
    u8 i;
    for(i=7;i>0;i--){
        if(i==2 || i==4 ){
            if(times[i] == 6){
                times[i-1]++;
                times[i] = 0;
            }
        }
        else{
            if(times[i] == 10){
                times[i-1]++;
                times[i] = 0;
            }
        }
    }
}

void main(){
    init_set();
    time_0_set();
    while(1){
        smg(times);
    }
}

void time() interrupt 1{
    static u16 i = 0;   
    TH0 = 0xFC;
    TL0 = 0x66;
    i++;
    if(i == 10){
        times[7]++;
        time_change();
        i = 0;
    }
    TF0 = 0;
    TR0 = 1;
}

void key() interrupt 0{
    delay_10us(1000);
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
            for(j=0;j<8;j++){
                times[j] = 0;
                TF0 = 0;
            }
            key_value = 0;
            IE0 = 0;
        }
    }
}