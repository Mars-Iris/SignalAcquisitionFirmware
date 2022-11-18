#include "./User/includes.h"

code u32 bote[]={0,115200,38400,19200,9600,4800,2400};
//========================================================================
// 函数: void BSP_Init(void)
// 描述: 板载相关硬件初始化函数汇总，将需要初始化的硬件全部在此处初始化，最终被main函数所调用
// 版本: V1.0, 2022-10-17
//========================================================================
void BSP_Init(void)
{
	
	BSP_GPIO_Init();//GPIO初始化
	
	BSP_Usart_Init(DEBUG_USART,DEBUG_BAUDRATE); //初始化主板与上位机连接的串口
	
#if  CONSOLE_USART	
	BSP_Usart_Init(CONSOLE_USART, CONSOLE_BAUDRATE); 		//初始化printf打印输出的串口
#endif	
		
	
#ifdef  STC15W4K48S4	

	BSP_Usart_Init(NETWORK_USART,NETWORK_BAUDRATE);//初始化网口
	
	if(GPS_USART != DISABLE)//flash里面配置了主板与GPS连接的串口
	{
			if(GPS_BAUDRATE < (sizeof(bote)/sizeof(bote[0])))//校验波特率是否越界
			{
				BSP_Usart_Init(GPS_USART,bote[GPS_BAUDRATE]); //初始化主板与GPS连接的串口
				
				USART_CloseInterrupt(GPS_USART);//先关闭中断，使用时在打开，防止接收缓存溢出
			}
			
	}	

	if(BUMP_HS_USART != DISABLE)//flash里面配置了主板与高森碰杆传感器之间连接的串口
	{
			if(BUMP_HS_BAUDRATE < (sizeof(bote)/sizeof(bote[0])))//校验波特率是否越界
			{
				BSP_Usart_Init(BUMP_HS_USART,bote[BUMP_HS_BAUDRATE]); //初始化主板与高森碰杆传感器之间连接的串口
				
				USART_CloseInterrupt(BUMP_HS_USART);//先关闭中断，使用时在打开，防止接收缓存溢出
			}
	}		

	if(BUMP_24G_USART != DISABLE)//flash里面配置了主板与2.4G碰杆传感器之间连接的串口
	{
			if(BUMP_24G_BAUDRATE < (sizeof(bote)/sizeof(bote[0])))//校验波特率是否越界
			{
				BSP_Usart_Init(BUMP_24G_USART,bote[BUMP_24G_BAUDRATE]); //初始化主板2.4G碰杆传感器之间连接的串口
				
				USART_CloseInterrupt(BUMP_24G_BAUDRATE);//先关闭中断，使用时在打开，防止接收缓存溢出
			}
				
	}	
	
	if(TILT_ALL_USART != DISABLE)//flash里面配置了（汇总后）倾角传感器与主板连接的串口
	{
			if(TILT_ALL_BAUDRATE < (sizeof(bote)/sizeof(bote[0])))//校验波特率是否越界
			{
				BSP_Usart_Init(TILT_ALL_USART,bote[TILT_ALL_BAUDRATE]); //初始化（汇总后）倾角传感器与主板连接的串口
				
				USART_CloseInterrupt(TILT_ALL_USART);//先关闭中断，使用时在打开，防止接收缓存溢出
			}
	}	
	
	if(TILT_Q_USART != DISABLE)//flash里面配置了车前轴倾角传感器与主板连接的串口
	{
		 if(TILT_Q_BAUDRATE < (sizeof(bote)/sizeof(bote[0])))//校验波特率是否越界
		 {
				BSP_Usart_Init(TILT_Q_USART,bote[TILT_Q_BAUDRATE]); //初始化车前轴倾角传感器与主板连接的串口
			 
				USART_CloseInterrupt(TILT_Q_USART);//先关闭中断，使用时在打开，防止接收缓存溢出
		 }
	}	
	
	if(TILT_H_USART != DISABLE)//flash里面配置了车后轴倾角传感器与主板连接的串口
	{
		 if(TILT_H_BAUDRATE < (sizeof(bote)/sizeof(bote[0])))//校验波特率是否越界
		 {
				BSP_Usart_Init(TILT_H_USART,bote[TILT_H_BAUDRATE]); //初始化车后轴倾角传感器与主板连接的串口
			 
			  USART_CloseInterrupt(TILT_H_USART);//先关闭中断，使用时在打开，防止接收缓存溢出
		 }
	}	
	
	if(TILT_G_USART != DISABLE)//flash里面配置了车挂轴倾角传感器与主板连接的串口
	{
		 if(TILT_G_BAUDRATE < (sizeof(bote)/sizeof(bote[0])))//校验波特率是否越界
		 {
				BSP_Usart_Init(TILT_G_USART,bote[TILT_G_BAUDRATE]); //初始化车挂轴倾角传感器与主板连接的串口
			 
			  USART_CloseInterrupt(TILT_G_USART);//先关闭中断，使用时在打开，防止接收缓存溢出
		 }
	}	
	
	if(TILT_MTC_USART != DISABLE)//flash里面配置了二轮摩托车倾角传感器与主板连接的串口
	{
		 if(TILT_MT_BAUDRATE < (sizeof(bote)/sizeof(bote[0])))//校验波特率是否越界
		 {
				BSP_Usart_Init(TILT_MTC_USART,bote[TILT_MT_BAUDRATE]); //初始化二轮摩托车倾角传感器与主板连接的串口
			 
			  USART_CloseInterrupt(TILT_MTC_USART);//先关闭中断，使用时在打开，防止接收缓存溢出
		 }
	}	

#endif
	
	if(UPLOAD_USART != DISABLE)//flash里面配置了主板与GPS连接的串口
	{
			if(UPLOAD_BAUDRATE < (sizeof(bote)/sizeof(bote[0])))//校验波特率是否越界
			{
				BSP_Usart_Init(UPLOAD_USART,bote[UPLOAD_BAUDRATE]); //初始化主板与GPS连接的串口
				
				USART_OpenInterrupt(UPLOAD_USART);//和上位机通讯串口，中断必须开启！
			}
				
	}
		
	BSP_ZhuansuCount_Init();//转速脉冲计数初始化，使用定时计数器0
	
	
	TOTAL_IT = TURE;//开启总中断
	
	
}

//========================================================================
// 函数: void Cmd_Start_Callback(void)
// 描述: 主板收到55 aa 00 00 11 11 后会调用此函数
// 版本: V1.0, 2022-10-17
//========================================================================
void Cmd_Start_Callback(void)
{

	USART_ClearMsgQueueRxBuffer(UPLOAD_USART);
	
	GetFlashConfig();//获取最新的配置文件
	
	BSP_Init();			//按照最新的硬件配置初始化硬件信息
	

	
#ifdef  STC15W4K48S4
		//打开已经已经初始化外设的中断
	if(GPS_USART != DISABLE)//flash里面配置了主板与GPS连接的串口
	{		
		USART_OpenInterrupt(GPS_USART);//开启串口中断！
	}
	
	if(BUMP_HS_USART != DISABLE)//flash里面配置了主板与高森碰杆传感器之间连接的串口	
	{		
		USART_OpenInterrupt(BUMP_HS_USART);//开启串口中断！
	}
	
	if(BUMP_24G_USART != DISABLE)//flash里面配置了主板与2.4G碰杆传感器之间连接的串口
	{	
		USART_OpenInterrupt(BUMP_24G_USART);//开启串口中断！
	}
		
	if(TILT_ALL_USART != DISABLE)//flash里面配置了（汇总后）倾角传感器与主板连接的串口
	{
		USART_OpenInterrupt(TILT_ALL_USART);//开启串口中断！
	}
	
	if(TILT_Q_USART != DISABLE)//flash里面配置了车前轴倾角传感器与主板连接的串口
	{
		USART_OpenInterrupt(TILT_Q_USART);//开启串口中断！
	}	
	
	if(TILT_H_USART != DISABLE)//flash里面配置了车后轴倾角传感器与主板连接的串口
	{	
		USART_OpenInterrupt(TILT_H_USART);//开启串口中断！
	}
	
	if(TILT_G_USART != DISABLE)//flash里面配置了车挂轴倾角传感器与主板连接的串口
	{	
		USART_OpenInterrupt(TILT_G_USART);//开启串口中断！
	}
	
	if(TILT_MTC_USART != DISABLE)//flash里面配置了二轮摩托车倾角传感器与主板连接的串口
	{	
				USART_OpenInterrupt(TILT_MTC_USART);//开启串口中断！
	}
	
	if(GPS_USART == USART1)//gps串口配置的是USART1
	{
			S1_USE_P16P17();//切换串口1到GPS串口
	}	
	
	GetTilt_Adjust_vaule();//获取传二轮摩托车传感器的基准值
	
#endif
}

//========================================================================
// 函数: void Cmd_Stop_Callback(void)
// 描述: 主板收到55 aa 00 00 00 00 后会调用此函数
// 版本: V1.0, 2022-10-17
//========================================================================
void Cmd_Stop_Callback(void)
{
	
#ifdef  STC15W4K48S4
	
	//关闭已经已经初始化外设的中断，防止串口缓存溢出
	
	if(GPS_USART != DISABLE)//flash里面配置了主板与GPS连接的串口
	{		
		USART_CloseInterrupt(GPS_USART);//关闭串口中断！
	}
	
	if(BUMP_HS_USART != DISABLE)//flash里面配置了主板与高森碰杆传感器之间连接的串口	
	{		
		USART_CloseInterrupt(BUMP_HS_USART);//关闭串口中断！
	}
	
	if(BUMP_24G_USART != DISABLE)//flash里面配置了主板与2.4G碰杆传感器之间连接的串口
	{	
		USART_CloseInterrupt(BUMP_24G_USART);//关闭串口中断！
	}
		
	if(TILT_ALL_USART != DISABLE)//flash里面配置了（汇总后）倾角传感器与主板连接的串口
	{
		USART_CloseInterrupt(TILT_ALL_USART);//关闭串口中断！
	}
	
	if(TILT_Q_USART != DISABLE)//flash里面配置了车前轴倾角传感器与主板连接的串口
	{
		USART_CloseInterrupt(TILT_Q_USART);//关闭串口中断！
	}	
	
	if(TILT_H_USART != DISABLE)//flash里面配置了车后轴倾角传感器与主板连接的串口
	{	
		USART_CloseInterrupt(TILT_H_USART);//关闭串口中断！
	}
	
	if(TILT_G_USART != DISABLE)//flash里面配置了车挂轴倾角传感器与主板连接的串口
	{	
		USART_CloseInterrupt(TILT_G_USART);//关闭串口中断！
	}
	
	if(TILT_MTC_USART != DISABLE)//flash里面配置了二轮摩托车倾角传感器与主板连接的串口
	{	
		USART_CloseInterrupt(TILT_MTC_USART);//关闭串口中断！
	}		
	
#endif
}




