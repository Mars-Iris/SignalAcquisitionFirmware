#include	"./User/includes.h"
#include	"./User/config.h"
#include	<stdio.h>
#include	<string.h>


u8 i = 0;
void main(void)
{
	
	BSP_Init();//����Ӳ����ʼ��,
	
	Check_Serial_Id();	//У�鵥Ƭ�����к�
	
	SignalLine_Init();  //�ź����ó�ʼ��

	
  while(1)	
	{ 
//		#ifdef  STC15W4K48S4
//		SerialHandle(GPS_USART);		//����ͨѶ�������	
//		#endif
		
		SerialHandle(UPLOAD_USART);	//����ͨѶ�������	
		
		SerialDataUpload(UPLOAD_USART);//����λ���ϴ�����
		
		#ifdef  STC12C5A60S2	
			delay_ms(100);
		#endif
		//delay_ms(10);
	}	
}




