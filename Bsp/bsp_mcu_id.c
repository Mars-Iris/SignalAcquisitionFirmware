#include <stdio.h>
#include "./User/includes.h"
#include <string.h>

#define ID_ADDR_RAM 0xF1                //STC系列ID号的存放在RAM区的地址
//#define ID_ADDR_ROM 0x3ff9            //STC系列ID号的存放在ROM区的地址
//========================================================================
// 函数: BSP_GetlocalId(char *strid)
// 描述: 读取MCU芯片的序列号
// 参数：*strid[]指向串号保存的内存，保存格式为字符串
//			 lenth  读取的串号长度，STC12系列/STC12系列,长度为7
// 返回: 无
// 版本: V1.0, 2022-10-17
//========================================================================
void BSP_GetlocalId(u8 *id)				//读取单片机ID信息
{
		unsigned char idata *iptr;
    //unsigned char code *cptr;
    unsigned char i=0;
			
    iptr = ID_ADDR_RAM;                 //从RAM区读取ID号
    for (i=0; i<7; i++)             		//读7个字节
    {
			*id++ = *iptr++;			
    }
		
//    cptr = ID_ADDR_ROM;              	//从程序区读取ID号
//    for (i=0; i<7; i++)              	//读7个字节
//    {
//        FID[i]=(*cptr++);             //发送ID到串口
//    }			
}
/***********************************************************************/