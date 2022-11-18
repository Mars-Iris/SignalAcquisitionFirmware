#ifndef		__CONFIG_H
#define		__CONFIG_H

//-------------------------------配置单片机型号-----------------------------------//

//#define		STC12C5A60S2     

#define		STC15W4K48S4   

//----------------------------------系统配置-------------------------------------//

//配置板号，详细定义见check.h
#define BOARD_NO   195 //贵州省黔南州长顺驾校科目二考场	195 

//单片机固件号（软件上会显示）
#define FIRMWARE_NUM 20 


//配置系统时钟频率。
#define MAIN_Fosc		11059200L	

//校验单片机序列号,未定义不校验
#define CHECKID 

//配置主板通讯数据长度
#define BASEBOARD_SIZE	65


//主板与上位机连接的串口 
#define UPLOAD_USART 				(pFlash->upload.com) 
#define UPLOAD_BAUDRATE			(pFlash->upload.bote)

//主板与上位机连接的串口 
#define DEBUG_USART 				USART1
#define DEBUG_BAUDRATE  		115200L

//控制台printf打印输出的串口号,仅输出
#define CONSOLE_USART				USART1			//可选USART1，USART2，USART3，USART4 DISABLE
#define CONSOLE_BAUDRATE		115200L			//可选2400L,4800L,9600L,19200L,38400L,115200L	
																				//如果串口被初始化别的功能，波特率可能会被覆盖



//使用调试模式时打开下面宏定义
//#define DEBUG	

//-----------------------------STC15W4K48S4编译配置-------------------------------//
#ifdef  STC15W4K48S4

//加载对应的启动文件
#include "./STC/stc15w4k48s4.h"

//网口
#define NETWORK_USART 			USART2
#define NETWORK_BAUDRATE  	115200L
#define NETWORK_STATE 			(pFlash->network.com)

//主板与GPS板卡连接的串口 
#define GPS_USART 					(pFlash->gps.com)
#define GPS_BAUDRATE      	(pFlash->upload.bote)

//主板与高森碰杆传感器之间连接的串口
#define BUMP_HS_USART 			(pFlash->bump_hs.com)
#define BUMP_HS_BAUDRATE 		(pFlash->bump_hs.bote)

//主板与2.4G接收模块（碰杆传感器）之间连接的串口
#define BUMP_24G_USART 			(pFlash->bump_24g.com)
#define BUMP_24G_BAUDRATE 	(pFlash->bump_24g.bote)

//主板与（汇总后）连接的串口号
#define TILT_ALL_USART 		  (pFlash->titl_all.com)
#define TILT_ALL_BAUDRATE 	(pFlash->titl_all.bote)

//主板与车前轴连接的串口
#define TILT_Q_USART 				(pFlash->titl_q.com)
#define TILT_Q_BAUDRATE 		(pFlash->titl_q.bote)

//主板与车后轴连接的串口号
#define TILT_H_USART 				(pFlash->titl_h.com)
#define TILT_H_BAUDRATE 		(pFlash->titl_h.bote)

//主板与车挂轴连接的串口号
#define TILT_G_USART 				(pFlash->titl_g.com)
#define TILT_G_BAUDRATE			(pFlash->titl_g.bote)

//主板二轮摩托车与连接的串口
#define TILT_MTC_USART 			(pFlash->titl_mtc.com)
#define TILT_MT_BAUDRATE 		(pFlash->titl_mtc.bote)

#endif

//-----------------------------STC12C5A60S2编译配置-------------------------------//
#ifdef  STC12C5A60S2

//加载对应的启动文件
#include "./STC/stc12c5a60s2.h"
	
#endif




#endif
