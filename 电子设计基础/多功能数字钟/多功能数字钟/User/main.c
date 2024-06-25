#include "smg.h"
#include "public.h"
#include "beep.h"
#include "key.h"
#include "time.h"

u8 mode = 0;                            //保存当前模式
u8 press_number = 0;                    //保存按键按下的次数

void time_0_set(){                      //定时器0设置
    EA = 1;
    ET0 = 1;
    TMOD |= 0x01;
    TH0 = 0xFC;
    TL0 = 0x66;
}

u8 not_zero(){
    u8 i;
    u8 bool = 0;
    for(i=0;i<8;i++){
        if(times[i] != 0) bool = 1;
    }
    return bool;
}

void main(){
    time_0_set();
    while(1){
        key();
        smg(times);
    }
}

void key(){
    u8 key_value = key_scan();               //按键键值
    if(key_value == 1){
        if(press_number == 0){
            TF0 = 0;
            TR0 = 1;
            press_number++;
        }
        else if(press_number == 1){
            TF0 = 0;
            TR0 = 0;
            press_number++;
        }
        else if(press_number == 2){
            u8 j;
            for(j=0;j<8;j++){
                times[j] = 0;
                TF0 = 0;
            }
            press_number = 0;
        }
    }
    else if(key_value == 2) mode = !mode;
    else if(key_value == 3){
        u8 i = 0;
        u8 value;
        LED0 = !LED0;
        while(i<8){
            value = key_scan();
            if(value == 3) i++;
            if(value == 4){
                times[i]++;
                if(i==2 || i==4){
                    if(times[i] == 6) times[i] = 0;
                }
                else{
                    if(times[i] == 10) times[i] = 0;
                }
            }
            smg(times);
        }
    }
}

void time() interrupt 1{
    static u16 j = 0;   
    TH0 = 0xFC;
    TL0 = 0x66;
    j++;
    if(j == 10){
        if(mode == 0) time_change_mode0();
        else if(mode == 1) time_change_mode1(7);
        j = 0;
    }
    if(!not_zero() && mode==1){
        u8 k;
        for(k=0;k<3;k++){
            beep(5000);
            delay_ms(200);
            beep(5000);
            delay_ms(500);
        }
        TF0 = 0;
        TR0 = 0;
        press_number = 0;
    }
}