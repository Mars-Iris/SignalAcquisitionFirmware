#include	"./User/includes.h"
#include	"./User/config.h"
#include	<stdio.h>
#include	<string.h>


u8 i = 0;
void main(void)
{
	
	BSP_Init();//板载硬件初始化,
	
	Check_Serial_Id();	//校验单片机序列号
	
	SignalLine_Init();  //信号配置初始化

	
  while(1)	
	{ 
//		#ifdef  STC15W4K48S4
//		SerialHandle(GPS_USART);		//串口通讯处理程序	
//		#endif
		
		SerialHandle(UPLOAD_USART);	//串口通讯处理程序	
		
		SerialDataUpload(UPLOAD_USART);//给上位机上传数据
		
		#ifdef  STC12C5A60S2	
			delay_ms(100);
		#endif
		//delay_ms(10);
	}	
}




