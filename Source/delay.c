#include	"delay.h"
#include	"GPIO.h"
#include  <string.h>
#include <stdio.h>
#include "intrins.h"
#include <ctype.h>
//========================================================================
// ����: void  delay_ms(unsigned char ms)
// ����: ��ʱ������
// ����: ms,Ҫ��ʱ��ms��, ����ֻ֧��1~255ms. �Զ���Ӧ��ʱ��.
// ����: none.
// �汾: VER1.0
// ����: 2013-4-1
// ��ע: 
//========================================================================
void  delay_ms(unsigned int ms)
{
     unsigned int i;
	 do{
	      i = MAIN_Fosc / 13000;
		  while(--i)	;   //14T per loop
     }while(--ms);
}
//========================================================================
//void Delay50ms()		//@11.0592MHz
//void Delay100ms()		//@11.0592MHz
//{
//	unsigned char i, j, k;

//	_nop_();
//	_nop_();
//	i = 3;
//	j = 26;
//	k = 223;
//	do
//	{
//		do
//		{
//			while (--k);
//		} while (--j);
//	} while (--i);
//}
//========================================================================
//void Delay500us()		//@11.0592MHz
void Delay100ms()		//@11.0592MHz
{
	unsigned char i, j;

	_nop_();
	_nop_();
	i = 7;
	j = 113;
	do
	{
		while ((--j)&&(jiaosha_ztbh()==0));
	} while ((--i)&&(jiaosha_ztbh()==0));
}
//========================================================================
void delay(unsigned int k)
{
while(k--);
}
//========================================================================
