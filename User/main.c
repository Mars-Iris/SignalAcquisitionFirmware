#include	"./User/includes.h"
#include	"./User/config.h"
#include	<stdio.h>
#include	<string.h>


void main(void)
{
	
	GetFlashConfig();  //Ĭ�����ó�ʼ��
	
	BSP_Init();//����Ӳ����ʼ��,	
	
	Check_Serial_Id();	//У�鵥Ƭ�����к�
	
  while(1)	
	{ 
		
		#ifdef  STC15W4K48S4	
		SerialHandle(NETWORK_USART); //����ͨѶ�������
		#endif
		SerialHandle(DEBUG_USART);		//����ͨѶ�������	
		
		SerialDataUpload(UPLOAD_USART);//����λ���ϴ�����
		
		#ifdef  STC12C5A60S2	
			delay_ms(100);
		#endif
		//delay_ms(1000);
	}	
}




