#include "beep.h"

void beep(u8 time){
    while (time--){
        BEEP = ~BEEP;
        delay_10us(50);
    }
}