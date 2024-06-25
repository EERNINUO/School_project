#include "key.h"
#include "beep.h"

u8 key_scan(){
	u8 key;
	if(KEY1==0||KEY2==0||KEY3==0||KEY4==0){//任意按键按下
		delay_10us(100);//消抖
		if(KEY1==0||KEY2==0||KEY3==0||KEY4==0){
			if(KEY1==0)
				key = KEY1_PRESS;
			else if(KEY2==0)
				key = KEY2_PRESS;
			else if(KEY3==0)
				key = KEY3_PRESS;
			else if(KEY4==0)
				key = KEY4_PRESS;
			beep(200);
		}
		while(KEY1==0||KEY2==0||KEY3==0||KEY4==0);
	}
	else if(KEY1==1&&KEY2==1&&KEY3==1&&KEY4==1)	
		key = KEY_UNPRESS;//无按键按下
	return key;
}