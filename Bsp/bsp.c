#include "./User/includes.h"


//========================================================================
// 函数: void BSP_Init(void)
// 描述: 板载相关硬件初始化函数汇总，将需要初始化的硬件全部在此处初始化，最终被main函数所调用
// 版本: V1.0, 2022-10-17
//========================================================================
void BSP_Init(void)
{
	
	BSP_GPIO_Init();		//GPIO初始化
	
	
	BSP_Usart_Init(UPLOAD_USART,UPLOAD_BAUDRATE); 			//初始化主板与上位机连接的串口
	
#if  CONSOLE_USART	
	BSP_Usart_Init(CONSOLE_USART, CONSOLE_BAUDRATE); 		//初始化printf打印输出的串口
#endif	
	
	
#ifdef  STC15W4K48S4		
	#if  GPS_USART	
		BSP_Usart_Init(GPS_USART,GPS_BAUDRATE); 						//初始化GPS板卡与主板连接的串口
	#endif
	
	#if  HS_BUMP_USART	
		BSP_Usart_Init(HS_BUMP_USART,HS_BUMP_BAUDRATE); 		//初始化高森碰杆传感器与主板之间连接的串口
	#endif
	
	#if  TILT_Q_USART	
		BSP_Usart_Init(TILT_Q_USART,TILT_BAUDRATE);					//初始化车前轴倾角传感器与主板连接的串口
	#endif
	
	#if  TILT_H_USART	
		BSP_Usart_Init(TILT_H_USART,TILT_BAUDRATE);					//初始化车后轴倾角传感器与主板连接的串口
	#endif
	
	#if  TILT_G_USART	
		BSP_Usart_Init(TILT_G_USART,TILT_BAUDRATE);					//初始化车挂轴倾角传感器与主板连接的串口
	#endif
	
	#if  TILT_MTC_USART	
		BSP_Usart_Init(TILT_MTC_USART,TILT_BAUDRATE);				//初始化二轮摩托车倾角传感器与主板连接的串口
	#endif
	
	#if  TILT_ALL_USART	
		BSP_Usart_Init(TILT_ALL_USART,TILT_BAUDRATE);				//初始化（汇总后）倾角传感器与主板连接的串口
	#endif
	
	#if  BUMP_24G_USART
		BSP_Usart_Init(BUMP_24G_USART,BUMP_24G_BAUDRATE);		//初2.4G接收模块（碰杆传感器）与主板之间连接的串口
	#endif
	

#endif
		
	BSP_ZhuansuCount_Init();//转速脉冲计数初始化，使用定时计数器0
	
	
	TOTAL_IT = TURE;//开启总中断
	
	
}








