#include "smg.h"
#include "public.h"
#include "beep.h"
#include "key.h"
#include "time.h"

u8 mode = 0;                        //保存当前模式
u8 press_number = 0;                        //保存按键按下的次数

void time_0_set(){                      //定时器0设置
    EA = 1;
    ET0 = 1;
    TMOD |= 0x01;
    TH0 = 0xFC;
    TL0 = 0x66;
}

void main(){
    time_0_set();
    while(1){
        key();
        smg(times);
    }
}

void time() /*interrupt 1*/{
    static u16 j = 0;   
    TH0 = 0xFC;
    TL0 = 0x66;
    j++;
    if(j == 10){
        if(mode == 0) time_change_mode0();
        else if(mode == 1) time_change_mode1();
        j = 0;
    }
    TF0 = 0;
    TR0 = 1;
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
        for(u8 i=0;i<8;i++){
            while(key_scan != 3){
                if(key_scan() == 4){
                    times[i]++;
                    if(i==2 || i==4){
                        if(times[i] == 6) times[i] = 0;
                    }
                    else{
                        if(times[i] == 10) times[i] = 0;
                    }
                }
            }
        }
    }
}