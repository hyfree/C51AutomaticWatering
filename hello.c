#include<reg51.h>


sbit sensor = P0^0;//������
sbit pump = P0^1;//ˮ��
sbit led = P0^2;//led��




void JiaoShui(short second);
void DelayAnySecond(short second);
void Delay1000ms();



void main(){   
 
    
	short jiaoshuiTime=30; 
	short dengDaiTime=3600;
	
	//���г�ʼ��
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
//��ˮ
void JiaoShui(short second){
		pump=1;
		DelayAnySecond(second);
		pump=0;
}

//�ӳ�������
//second 
void DelayAnySecond(short second){
	unsigned char i;
	for (i=0; i<second; i++){
		 Delay1000ms();
		led=~led;
	}
}
//�ӳ�1000����
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

