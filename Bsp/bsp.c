#include "./User/includes.h"


//========================================================================
// ����: void BSP_Init(void)
// ����: �������Ӳ����ʼ���������ܣ�����Ҫ��ʼ����Ӳ��ȫ���ڴ˴���ʼ�������ձ�main����������
// �汾: V1.0, 2022-10-17
//========================================================================
void BSP_Init(void)
{
	
	BSP_GPIO_Init();		//GPIO��ʼ��
	
	
	BSP_Usart_Init(UPLOAD_USART,UPLOAD_BAUDRATE); 			//��ʼ����������λ�����ӵĴ���
	
#if  CONSOLE_USART	
	BSP_Usart_Init(CONSOLE_USART, CONSOLE_BAUDRATE); 		//��ʼ��printf��ӡ����Ĵ���
#endif	
	
	
#ifdef  STC15W4K48S4		
	#if  GPS_USART	
		BSP_Usart_Init(GPS_USART,GPS_BAUDRATE); 						//��ʼ��GPS�忨���������ӵĴ���
	#endif
	
	#if  HS_BUMP_USART	
		BSP_Usart_Init(HS_BUMP_USART,HS_BUMP_BAUDRATE); 		//��ʼ����ɭ���˴�����������֮�����ӵĴ���
	#endif
	
	#if  TILT_Q_USART	
		BSP_Usart_Init(TILT_Q_USART,TILT_BAUDRATE);					//��ʼ����ǰ����Ǵ��������������ӵĴ���
	#endif
	
	#if  TILT_H_USART	
		BSP_Usart_Init(TILT_H_USART,TILT_BAUDRATE);					//��ʼ����������Ǵ��������������ӵĴ���
	#endif
	
	#if  TILT_G_USART	
		BSP_Usart_Init(TILT_G_USART,TILT_BAUDRATE);					//��ʼ����������Ǵ��������������ӵĴ���
	#endif
	
	#if  TILT_MTC_USART	
		BSP_Usart_Init(TILT_MTC_USART,TILT_BAUDRATE);				//��ʼ������Ħ�г���Ǵ��������������ӵĴ���
	#endif
	
	#if  TILT_ALL_USART	
		BSP_Usart_Init(TILT_ALL_USART,TILT_BAUDRATE);				//��ʼ�������ܺ���Ǵ��������������ӵĴ���
	#endif
	
	#if  BUMP_24G_USART
		BSP_Usart_Init(BUMP_24G_USART,BUMP_24G_BAUDRATE);		//��2.4G����ģ�飨���˴�������������֮�����ӵĴ���
	#endif
	

#endif
		
	BSP_ZhuansuCount_Init();//ת�����������ʼ����ʹ�ö�ʱ������0
	
	
	TOTAL_IT = TURE;//�������ж�
	
	
}








