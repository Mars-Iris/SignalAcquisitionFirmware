#include <stdio.h>
#include "./User/includes.h"
#include <string.h>

#define ID_ADDR_RAM 0xF1                //STCϵ��ID�ŵĴ����RAM���ĵ�ַ
//#define ID_ADDR_ROM 0x3ff9            //STCϵ��ID�ŵĴ����ROM���ĵ�ַ
//========================================================================
// ����: BSP_GetlocalId(char *strid)
// ����: ��ȡMCUоƬ�����к�
// ������*strid[]ָ�򴮺ű�����ڴ棬�����ʽΪ�ַ���
//			 lenth  ��ȡ�Ĵ��ų��ȣ�STC12ϵ��/STC12ϵ��,����Ϊ7
// ����: ��
// �汾: V1.0, 2022-10-17
//========================================================================
void BSP_GetlocalId(u8 *id)				//��ȡ��Ƭ��ID��Ϣ
{
		unsigned char idata *iptr;
    //unsigned char code *cptr;
    unsigned char i=0;
			
    iptr = ID_ADDR_RAM;                 //��RAM����ȡID��
    for (i=0; i<7; i++)             		//��7���ֽ�
    {
			*id++ = *iptr++;			
    }
		
//    cptr = ID_ADDR_ROM;              	//�ӳ�������ȡID��
//    for (i=0; i<7; i++)              	//��7���ֽ�
//    {
//        FID[i]=(*cptr++);             //����ID������
//    }			
}
/***********************************************************************/