#include "time.h"
#include "key.h"
#include "smg.h"

u8 times[8] = {0,0,0,0,0,0,0,0};               //用于存储时间的值

void time_change_mode0(){                      //时间进位
    u8 i;
    times[7]++;
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

void time_change_mode1(u8 i) reentrant{
    if(times[i] == 0){
        time_change_mode1(i-1);
        if(i==2 || i==4){
            times[i] = 5;
        }
        else times[i] = 9;
    }
    else{
        times[i]--;
    }
}
