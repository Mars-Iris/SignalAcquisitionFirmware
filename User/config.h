#ifndef		__CONFIG_H
#define		__CONFIG_H

//-------------------------------配置单片机型号-----------------------------------//

//#define		STC12C5A60S2     

#define		STC15W4K48S4   

//----------------------------------系统配置-------------------------------------//

//配置板号，详细定义见check.h
#define BOARD_NO   GZ_QNZ_CS_KM2 //贵州省黔南州长顺驾校科目二考场			195 

//单片机固件号（软件上会显示）
#define FIRMWARE_NUM 20 

//配置系统时钟频率。
#define MAIN_Fosc		11059200L	

//校验单片机序列号,未定义不校验
#define CHECKID 

//配置主板通讯数据长度
#define BASEBOARD_SIZE	65

//配置主板与上位机连接的串号
#define UPLOAD_USART				USART1			//可选USART1，USART2，USART3，USART4	

#define UPLOAD_BAUDRATE			115200L			//可选2400L,4800L,9600L,19200L,38400L,115200L

//控制台printf打印输出的串口号
#define CONSOLE_USART				DISABLE			//可选USART1，USART2，USART3，USART4 DISABLE

#define CONSOLE_BAUDRATE		115200L			//可选2400L,4800L,9600L,19200L,38400L,115200L	
																				//如果串口被初始化别的功能，波特率可能会被覆盖

//使用调试模式时打开下面宏定义
//#define DEBUG	

//-----------------------------STC15W4K48S4编译配置-------------------------------//
#ifdef  STC15W4K48S4

//加载对应的启动文件
#include "./STC/stc15w4k48s4.h"
	
//配置GPS板卡与主板连接的串口号
#define GPS_USART						DISABLE			//可选USART1，USART2，USART3，USART4,DISABLE	

#define GPS_BAUDRATE				DISABLE			//可选2400L,4800L,9600L,19200L,38400L,115200L，该值最后被软件自动配置为38400

//配置高森碰杆传感器与主板之间连接的串口号
#define HS_BUMP_USART				DISABLE			//可选USART1，USART2，USART3，USART4,DISABLE

#define HS_BUMP_BAUDRATE		115200L			//可选2400L,4800L,9600L,19200L,38400L,115200L

//配置2.4G接收模块（碰杆传感器）与主板之间连接的串口
#define BUMP_24G_USART			DISABLE			//可选USART1，USART2，USART3，USART4,DISABLE

#define BUMP_24G_BAUDRATE		115200L			//可选2400L,4800L,9600L,19200L,38400L,115200L

 //配置倾角传感器与主板之间连接的串口号
#define TILT_Q_USART				DISABLE			//可选USART1，USART2，USART3，USART4,DISABLE,车前轴与主板连接的串口号	
#define TILT_H_USART				DISABLE			//可选USART1，USART2，USART3，USART4,DISABLE,车后轴与主板连接的串口号
#define TILT_G_USART				DISABLE			//可选USART1，USART2，USART3，USART4,DISABLE,车挂轴与主板连接的串口号
#define TILT_MTC_USART			DISABLE			//可选USART1，USART2，USART3，USART4,DISABLE,二轮摩托车与主板连接的串口号
#define TILT_ALL_USART			DISABLE			//可选USART1，USART2，USART3，USART4,DISABLE,（汇总后）与主板连接的串口号

#define TILT_BAUDRATE				115200L			//可选2400L,4800L,9600L,19200L,38400L,115200L

	
#endif

//-----------------------------STC12C5A60S2编译配置-------------------------------//
#ifdef  STC12C5A60S2

//加载对应的启动文件
#include "./STC/stc12c5a60s2.h"
	

	
#endif

























#endif
