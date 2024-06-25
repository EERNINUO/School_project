#include "smg.h"

//共阴极数码管段码
u8 gsmg_code[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
				0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

u8 gsmg_code_dot[10] = {0xbf,0x86,0xdb,0xcf,0xe6,0xed,0xfd,0x87,
				0xff,0xef};

void smg(u8 dat[])
{
	u8 i;
	for(i=0;i<8;i++)
	{
		switch(i)//位选
		{
			case 0: LSC=1;LSB=1;LSA=1;break;
			case 1: LSC=1;LSB=1;LSA=0;break;
			case 2: LSC=1;LSB=0;LSA=1;break;
			case 3: LSC=1;LSB=0;LSA=0;break;
			case 4: LSC=0;LSB=1;LSA=1;break;
			case 5: LSC=0;LSB=1;LSA=0;break;
			case 6: LSC=0;LSB=0;LSA=1;break;
			case 7: LSC=0;LSB=0;LSA=0;break;
		}
		if(i==0){
			SMG_A_DP_PORT=gsmg_code_dot[dat[i]];//传送段选数据
		}
		else if(i==1){
			SMG_A_DP_PORT=gsmg_code[dat[i]];//传送段选数据
		}
		else{
			SMG_A_DP_PORT=0x00;
		}
		delay_10us(100);//延时一段时间，等待显示稳定
		SMG_A_DP_PORT=0x00;//消音
	}
}
