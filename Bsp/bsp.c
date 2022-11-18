#include "./User/includes.h"

code u32 bote[]={0,115200,38400,19200,9600,4800,2400};
//========================================================================
// ����: void BSP_Init(void)
// ����: �������Ӳ����ʼ���������ܣ�����Ҫ��ʼ����Ӳ��ȫ���ڴ˴���ʼ�������ձ�main����������
// �汾: V1.0, 2022-10-17
//========================================================================
void BSP_Init(void)
{
	
	BSP_GPIO_Init();//GPIO��ʼ��
	
	BSP_Usart_Init(DEBUG_USART,DEBUG_BAUDRATE); //��ʼ����������λ�����ӵĴ���
	
#if  CONSOLE_USART	
	BSP_Usart_Init(CONSOLE_USART, CONSOLE_BAUDRATE); 		//��ʼ��printf��ӡ����Ĵ���
#endif	
		
	
#ifdef  STC15W4K48S4	

	BSP_Usart_Init(NETWORK_USART,NETWORK_BAUDRATE);//��ʼ������
	
	if(GPS_USART != DISABLE)//flash����������������GPS���ӵĴ���
	{
			if(GPS_BAUDRATE < (sizeof(bote)/sizeof(bote[0])))//У�鲨�����Ƿ�Խ��
			{
				BSP_Usart_Init(GPS_USART,bote[GPS_BAUDRATE]); //��ʼ��������GPS���ӵĴ���
				
				USART_CloseInterrupt(GPS_USART);//�ȹر��жϣ�ʹ��ʱ�ڴ򿪣���ֹ���ջ������
			}
			
	}	

	if(BUMP_HS_USART != DISABLE)//flash�����������������ɭ���˴�����֮�����ӵĴ���
	{
			if(BUMP_HS_BAUDRATE < (sizeof(bote)/sizeof(bote[0])))//У�鲨�����Ƿ�Խ��
			{
				BSP_Usart_Init(BUMP_HS_USART,bote[BUMP_HS_BAUDRATE]); //��ʼ���������ɭ���˴�����֮�����ӵĴ���
				
				USART_CloseInterrupt(BUMP_HS_USART);//�ȹر��жϣ�ʹ��ʱ�ڴ򿪣���ֹ���ջ������
			}
	}		

	if(BUMP_24G_USART != DISABLE)//flash����������������2.4G���˴�����֮�����ӵĴ���
	{
			if(BUMP_24G_BAUDRATE < (sizeof(bote)/sizeof(bote[0])))//У�鲨�����Ƿ�Խ��
			{
				BSP_Usart_Init(BUMP_24G_USART,bote[BUMP_24G_BAUDRATE]); //��ʼ������2.4G���˴�����֮�����ӵĴ���
				
				USART_CloseInterrupt(BUMP_24G_BAUDRATE);//�ȹر��жϣ�ʹ��ʱ�ڴ򿪣���ֹ���ջ������
			}
				
	}	
	
	if(TILT_ALL_USART != DISABLE)//flash���������ˣ����ܺ���Ǵ��������������ӵĴ���
	{
			if(TILT_ALL_BAUDRATE < (sizeof(bote)/sizeof(bote[0])))//У�鲨�����Ƿ�Խ��
			{
				BSP_Usart_Init(TILT_ALL_USART,bote[TILT_ALL_BAUDRATE]); //��ʼ�������ܺ���Ǵ��������������ӵĴ���
				
				USART_CloseInterrupt(TILT_ALL_USART);//�ȹر��жϣ�ʹ��ʱ�ڴ򿪣���ֹ���ջ������
			}
	}	
	
	if(TILT_Q_USART != DISABLE)//flash���������˳�ǰ����Ǵ��������������ӵĴ���
	{
		 if(TILT_Q_BAUDRATE < (sizeof(bote)/sizeof(bote[0])))//У�鲨�����Ƿ�Խ��
		 {
				BSP_Usart_Init(TILT_Q_USART,bote[TILT_Q_BAUDRATE]); //��ʼ����ǰ����Ǵ��������������ӵĴ���
			 
				USART_CloseInterrupt(TILT_Q_USART);//�ȹر��жϣ�ʹ��ʱ�ڴ򿪣���ֹ���ջ������
		 }
	}	
	
	if(TILT_H_USART != DISABLE)//flash���������˳�������Ǵ��������������ӵĴ���
	{
		 if(TILT_H_BAUDRATE < (sizeof(bote)/sizeof(bote[0])))//У�鲨�����Ƿ�Խ��
		 {
				BSP_Usart_Init(TILT_H_USART,bote[TILT_H_BAUDRATE]); //��ʼ����������Ǵ��������������ӵĴ���
			 
			  USART_CloseInterrupt(TILT_H_USART);//�ȹر��жϣ�ʹ��ʱ�ڴ򿪣���ֹ���ջ������
		 }
	}	
	
	if(TILT_G_USART != DISABLE)//flash���������˳�������Ǵ��������������ӵĴ���
	{
		 if(TILT_G_BAUDRATE < (sizeof(bote)/sizeof(bote[0])))//У�鲨�����Ƿ�Խ��
		 {
				BSP_Usart_Init(TILT_G_USART,bote[TILT_G_BAUDRATE]); //��ʼ����������Ǵ��������������ӵĴ���
			 
			  USART_CloseInterrupt(TILT_G_USART);//�ȹر��жϣ�ʹ��ʱ�ڴ򿪣���ֹ���ջ������
		 }
	}	
	
	if(TILT_MTC_USART != DISABLE)//flash���������˶���Ħ�г���Ǵ��������������ӵĴ���
	{
		 if(TILT_MT_BAUDRATE < (sizeof(bote)/sizeof(bote[0])))//У�鲨�����Ƿ�Խ��
		 {
				BSP_Usart_Init(TILT_MTC_USART,bote[TILT_MT_BAUDRATE]); //��ʼ������Ħ�г���Ǵ��������������ӵĴ���
			 
			  USART_CloseInterrupt(TILT_MTC_USART);//�ȹر��жϣ�ʹ��ʱ�ڴ򿪣���ֹ���ջ������
		 }
	}	

#endif
	
	if(UPLOAD_USART != DISABLE)//flash����������������GPS���ӵĴ���
	{
			if(UPLOAD_BAUDRATE < (sizeof(bote)/sizeof(bote[0])))//У�鲨�����Ƿ�Խ��
			{
				BSP_Usart_Init(UPLOAD_USART,bote[UPLOAD_BAUDRATE]); //��ʼ��������GPS���ӵĴ���
				
				USART_OpenInterrupt(UPLOAD_USART);//����λ��ͨѶ���ڣ��жϱ��뿪����
			}
				
	}
		
	BSP_ZhuansuCount_Init();//ת�����������ʼ����ʹ�ö�ʱ������0
	
	
	TOTAL_IT = TURE;//�������ж�
	
	
}

//========================================================================
// ����: void Cmd_Start_Callback(void)
// ����: �����յ�55 aa 00 00 11 11 �����ô˺���
// �汾: V1.0, 2022-10-17
//========================================================================
void Cmd_Start_Callback(void)
{

	USART_ClearMsgQueueRxBuffer(UPLOAD_USART);
	
	GetFlashConfig();//��ȡ���µ������ļ�
	
	BSP_Init();			//�������µ�Ӳ�����ó�ʼ��Ӳ����Ϣ
	

	
#ifdef  STC15W4K48S4
		//���Ѿ��Ѿ���ʼ��������ж�
	if(GPS_USART != DISABLE)//flash����������������GPS���ӵĴ���
	{		
		USART_OpenInterrupt(GPS_USART);//���������жϣ�
	}
	
	if(BUMP_HS_USART != DISABLE)//flash�����������������ɭ���˴�����֮�����ӵĴ���	
	{		
		USART_OpenInterrupt(BUMP_HS_USART);//���������жϣ�
	}
	
	if(BUMP_24G_USART != DISABLE)//flash����������������2.4G���˴�����֮�����ӵĴ���
	{	
		USART_OpenInterrupt(BUMP_24G_USART);//���������жϣ�
	}
		
	if(TILT_ALL_USART != DISABLE)//flash���������ˣ����ܺ���Ǵ��������������ӵĴ���
	{
		USART_OpenInterrupt(TILT_ALL_USART);//���������жϣ�
	}
	
	if(TILT_Q_USART != DISABLE)//flash���������˳�ǰ����Ǵ��������������ӵĴ���
	{
		USART_OpenInterrupt(TILT_Q_USART);//���������жϣ�
	}	
	
	if(TILT_H_USART != DISABLE)//flash���������˳�������Ǵ��������������ӵĴ���
	{	
		USART_OpenInterrupt(TILT_H_USART);//���������жϣ�
	}
	
	if(TILT_G_USART != DISABLE)//flash���������˳�������Ǵ��������������ӵĴ���
	{	
		USART_OpenInterrupt(TILT_G_USART);//���������жϣ�
	}
	
	if(TILT_MTC_USART != DISABLE)//flash���������˶���Ħ�г���Ǵ��������������ӵĴ���
	{	
				USART_OpenInterrupt(TILT_MTC_USART);//���������жϣ�
	}
	
	if(GPS_USART == USART1)//gps�������õ���USART1
	{
			S1_USE_P16P17();//�л�����1��GPS����
	}	
	
	GetTilt_Adjust_vaule();//��ȡ������Ħ�г��������Ļ�׼ֵ
	
#endif
}

//========================================================================
// ����: void Cmd_Stop_Callback(void)
// ����: �����յ�55 aa 00 00 00 00 �����ô˺���
// �汾: V1.0, 2022-10-17
//========================================================================
void Cmd_Stop_Callback(void)
{
	
#ifdef  STC15W4K48S4
	
	//�ر��Ѿ��Ѿ���ʼ��������жϣ���ֹ���ڻ������
	
	if(GPS_USART != DISABLE)//flash����������������GPS���ӵĴ���
	{		
		USART_CloseInterrupt(GPS_USART);//�رմ����жϣ�
	}
	
	if(BUMP_HS_USART != DISABLE)//flash�����������������ɭ���˴�����֮�����ӵĴ���	
	{		
		USART_CloseInterrupt(BUMP_HS_USART);//�رմ����жϣ�
	}
	
	if(BUMP_24G_USART != DISABLE)//flash����������������2.4G���˴�����֮�����ӵĴ���
	{	
		USART_CloseInterrupt(BUMP_24G_USART);//�رմ����жϣ�
	}
		
	if(TILT_ALL_USART != DISABLE)//flash���������ˣ����ܺ���Ǵ��������������ӵĴ���
	{
		USART_CloseInterrupt(TILT_ALL_USART);//�رմ����жϣ�
	}
	
	if(TILT_Q_USART != DISABLE)//flash���������˳�ǰ����Ǵ��������������ӵĴ���
	{
		USART_CloseInterrupt(TILT_Q_USART);//�رմ����жϣ�
	}	
	
	if(TILT_H_USART != DISABLE)//flash���������˳�������Ǵ��������������ӵĴ���
	{	
		USART_CloseInterrupt(TILT_H_USART);//�رմ����жϣ�
	}
	
	if(TILT_G_USART != DISABLE)//flash���������˳�������Ǵ��������������ӵĴ���
	{	
		USART_CloseInterrupt(TILT_G_USART);//�رմ����жϣ�
	}
	
	if(TILT_MTC_USART != DISABLE)//flash���������˶���Ħ�г���Ǵ��������������ӵĴ���
	{	
		USART_CloseInterrupt(TILT_MTC_USART);//�رմ����жϣ�
	}		
	
#endif
}




