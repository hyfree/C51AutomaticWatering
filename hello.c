#include<reg51.h>


sbit sensor = P0^0;//传感器
sbit pump = P0^1;//水泵
sbit led = P0^2;//led灯




void JiaoShui(short second);
void DelayAnySecond(short second);
void Delay1000ms();



void main(){   
 
    
	short jiaoshuiTime=30; 
	short dengDaiTime=3600;
	
	//进行初始化
	//sensor=0;
    pump = 0;
	led=0;
	Delay1000ms();
    while (1){
		
		if(sensor==1){
			
			JiaoShui(jiaoshuiTime);
			
			DelayAnySecond(dengDaiTime);
		}
    }
}
//浇水
void JiaoShui(short second){
		pump=1;
		DelayAnySecond(second);
		pump=0;
}

//延迟若干秒
//second 
void DelayAnySecond(short second){
	unsigned char i;
	for (i=0; i<second; i++){
		 Delay1000ms();
		led=~led;
	}
}
//延迟1000毫秒
void Delay1000ms()		//@11.0592MHz
{
	unsigned char i, j, k;
	i = 8;
	j = 1;
	k = 243;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

