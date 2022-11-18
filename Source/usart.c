#include "./User/includes.h"
#include <stdio.h>
#include <string.h>

#ifdef  STC12C5A60S2	
xdata MessageQueue  Msg_RX[2];
xdata u8 Msg_Rx1Buffer[Q_BUF_LENTH];			//������
xdata u8 Msg_Rx2Buffer[Q_BUF_LENTH];			//������
#endif

#ifdef  STC15W4K48S4	
xdata volatile MessageQueue  Msg_RX[4];
//Ϊ��Լ�ڴ棬��Ԥ���봦������GPS�Ĵ��ڻ������512�ֽڣ�����Ϊ128���ֽ�
xdata u8 Msg_Rx1Buffer[Q_GPS_BUF_LENTH];	//������
xdata u8 Msg_Rx2Buffer[Q_BUF_LENTH];			//������
xdata u8 Msg_Rx3Buffer[Q_BUF_LENTH];			//������
xdata u8 Msg_Rx4Buffer[Q_BUF_LENTH];			//������	
#endif

//========================================================================
// ����: u8	USART_Configuration(unsigned char UARTx, COMx_InitDefine *COMx)
// ����: ��ʼ��MCU��UART��.
// ����: COMx_InitDefine: �ṹ����,��ο�uart.h��Ķ���.
// ����: ��
// �汾: V1.0, 2022-10-17
//========================================================================
void USART_Configuration(unsigned char UARTx, COMx_InitDefine *COMx)
{
	unsigned char	i=0;
	if(UARTx == USART1)
	{
		Msg_RX[UARTx-1].pStart 	= 	Msg_Rx1Buffer;																//��������ʼ��ַ
		Msg_RX[UARTx-1].pEnd		= 	Msg_Rx1Buffer + sizeof(Msg_Rx1Buffer) - 1;		//������������ַ
		Msg_RX[UARTx-1].pOut		= 	Msg_RX[UARTx-1].pStart;												//���ݳ���ָ��
		Msg_RX[UARTx-1].pIn			= 	Msg_RX[UARTx-1].pStart;	//�������ָ��	
		Msg_RX[UARTx-1].overflow_flag = 0;//���������־
		memset(Msg_Rx1Buffer,0,sizeof(Msg_Rx1Buffer));
		if(COMx->UART_BRT_Use == BRT_Timer1)
			{
					PCON &= 0x7F;		//�����ʲ�����
					SCON = 0x50;		//8λ����,�ɱ䲨����
					AUXR |= 0x40;		//��ʱ��1ʱ��ΪFosc,��1T
					AUXR &= 0xFE;		//����1ѡ��ʱ��1Ϊ�����ʷ�����
					TMOD &= 0x0F;		//�����ʱ��1ģʽλ
					TMOD |= 0x20;		//�趨��ʱ��1Ϊ8λ�Զ���װ��ʽ
					TL1 = 256-(MAIN_Fosc / 32) / COMx->UART_BaudRate;		//�趨��ʱ��ֵ
					TH1 = 256-(MAIN_Fosc / 32) / COMx->UART_BaudRate;		//�趨��ʱ����װֵ
					ET1 = 0;		//��ֹ��ʱ��1�ж�
					TR1 = 1;		//������ʱ��1
				  ES=COMx->UART_Interrupt;//�ж�����
			}
		else if(COMx->UART_BRT_Use == BRT_Timer2)
			{
				#ifdef  STC15W4K48S4	
					SCON = 0x50;		//8λ����,�ɱ䲨����
					AUXR |= 0x01;		//����1ѡ��ʱ��2Ϊ�����ʷ�����
					AUXR |= 0x04;		//��ʱ��2ʱ��ΪFosc,��1T
					T2L = (u8)(65535UL - ((MAIN_Fosc / 4) / COMx->UART_BaudRate));
					T2H = (u8)((65535UL - ((MAIN_Fosc / 4) / COMx->UART_BaudRate))>>8);		//�趨��ʱ��ֵ
					AUXR |= 0x10;		//������ʱ��2
					ES=COMx->UART_Interrupt;//�ж�����
				#endif
				
				#ifdef  STC12C5A60S2		
					PCON &= 0x7F;		//�����ʲ�����
					SCON = 0x50;		//8λ����,�ɱ䲨����
					AUXR |= 0x04;		//���������ʷ�����ʱ��ΪFosc,��1T
					BRT = 256-(MAIN_Fosc / 32) / COMx->UART_BaudRate;		//�趨���������ʷ�������װֵ
					AUXR |= 0x01;		//����1ѡ����������ʷ�����Ϊ�����ʷ�����
					AUXR |= 0x10;		//�������������ʷ�����
				  ES=COMx->UART_Interrupt;//�ж�����
				#endif
			}

  }
	if(UARTx == USART2)
	{
		Msg_RX[UARTx-1].pStart 	= 	Msg_Rx2Buffer;																//��������ʼ��ַ
		Msg_RX[UARTx-1].pEnd		= 	Msg_Rx2Buffer + sizeof(Msg_Rx2Buffer) - 1;	//������������ַ
		Msg_RX[UARTx-1].pOut		= 	Msg_RX[UARTx-1].pStart;																//���ݳ���ָ��
		Msg_RX[UARTx-1].pIn			= 	Msg_RX[UARTx-1].pStart;	//�������ָ��	
		Msg_RX[UARTx-1].overflow_flag = 0;//���������־
		memset(Msg_Rx2Buffer,0,sizeof(Msg_Rx2Buffer));														//�������ָ��		

		#ifdef  STC15W4K48S4	
			S2CON = 0x50;		//8λ����,�ɱ䲨����
			AUXR |= 0x04;		//��ʱ��2ʱ��ΪFosc,��1T
			T2L = (u8)(65535UL - ((MAIN_Fosc / 4) / COMx->UART_BaudRate));
			T2H = (u8)((65535UL - ((MAIN_Fosc / 4) / COMx->UART_BaudRate))>>8);		//�趨��ʱ��ֵ
			AUXR |= 0x10;		//������ʱ��2	
			IE2 |=COMx->UART_Interrupt;	//������2�ж�  ES2=1=COMx->UART_Interrupt;//�ж�����
		#endif
		
		#ifdef  STC12C5A60S2		
			AUXR &= 0xF7;		//�����ʲ�����
			S2CON = 0x50;		//8λ����,�ɱ䲨����
			AUXR |= 0x04;		//���������ʷ�����ʱ��ΪFosc,��1T
			BRT = 256-(MAIN_Fosc / 32) / COMx->UART_BaudRate;	//�趨���������ʷ�������װֵ
			AUXR |= 0x10;		//�������������ʷ�����
			IE2 |=COMx->UART_Interrupt;	//������2�ж�  ES2=1=COMx->UART_Interrupt;//�ж�����
		#endif
	}
	#ifdef  STC15W4K48S4	
	if(UARTx == USART3)
	{
		Msg_RX[UARTx-1].pStart 	= 	Msg_Rx3Buffer;																//��������ʼ��ַ
		Msg_RX[UARTx-1].pEnd		= 	Msg_Rx3Buffer + sizeof(Msg_Rx3Buffer) - 1;	//������������ַ
		Msg_RX[UARTx-1].pOut		= 	Msg_RX[UARTx-1].pStart;																//���ݳ���ָ��
		Msg_RX[UARTx-1].pIn			= 	Msg_RX[UARTx-1].pStart;	//�������ָ��	
		Msg_RX[UARTx-1].overflow_flag = 0;//���������־
		memset(Msg_Rx3Buffer,0,sizeof(Msg_Rx3Buffer));														//�������ָ��	
		if(COMx->UART_BRT_Use == BRT_Timer2)
		{
			S3CON = 0x10;		//8λ����,�ɱ䲨����
			S3CON &= 0xBF;		//����3ѡ��ʱ��2Ϊ�����ʷ�����
			AUXR |= 0x04;		//��ʱ��2ʱ��ΪFosc,��1T
			T2L = (u8)(65535UL - ((MAIN_Fosc / 4) / COMx->UART_BaudRate));
			T2H = (u8)((65535UL - ((MAIN_Fosc / 4) / COMx->UART_BaudRate))>>8);		//�趨��ʱ��ֵ
			AUXR |= 0x10;		//������ʱ��2
			IE2 |= (COMx->UART_Interrupt << 3);//�ж�����
		}
		else if(COMx->UART_BRT_Use == BRT_Timer3)
		{
			S3CON = 0x10;		//8λ����,�ɱ䲨����
			S3CON |= 0x40;		//����3ѡ��ʱ��3Ϊ�����ʷ�����
			T4T3M |= 0x02;		//��ʱ��3ʱ��ΪFosc,��1T
			T3L = (u8)(65535UL - ((MAIN_Fosc / 4) / COMx->UART_BaudRate));
			T3H = (u8)((65535UL - ((MAIN_Fosc / 4) / COMx->UART_BaudRate))>>8);		//�趨��ʱ��ֵ
			T4T3M |= 0x08;		//������ʱ��3	
			IE2 |= (COMx->UART_Interrupt << 3);//�ж�����			
		}
	
	}
	if(UARTx == USART4)
	{
		Msg_RX[UARTx-1].pStart 	= 	Msg_Rx4Buffer;																//��������ʼ��ַ
		Msg_RX[UARTx-1].pEnd		= 	Msg_Rx4Buffer + sizeof(Msg_Rx4Buffer) - 1;		//������������ַ
		Msg_RX[UARTx-1].pOut		= 	Msg_RX[UARTx-1].pStart;												//���ݳ���ָ��
		Msg_RX[UARTx-1].pIn			= 	Msg_RX[UARTx-1].pStart;												//�������ָ��	
		Msg_RX[UARTx-1].overflow_flag = 0;																				//���������־
		memset(Msg_Rx4Buffer,0,sizeof(Msg_Rx4Buffer));														//�������ָ��	
		if(COMx->UART_BRT_Use == BRT_Timer2)
		{
			S4CON = 0x10;		//8λ����,�ɱ䲨����
			S4CON &= 0xBF;		//����4ѡ��ʱ��2Ϊ�����ʷ�����
			AUXR |= 0x04;		//��ʱ��2ʱ��ΪFosc,��1T
			T2L = (u8)(65535UL - ((MAIN_Fosc / 4) / COMx->UART_BaudRate));
			T2H = (u8)((65535UL - ((MAIN_Fosc / 4) / COMx->UART_BaudRate))>>8);		//�趨��ʱ��ֵ
			AUXR |= 0x10;		//������ʱ��2
			IE2 |= (COMx->UART_Interrupt << 4);//�ж�����	
		}
		else if(COMx->UART_BRT_Use == BRT_Timer4)
		{
			S4CON = 0x10;		//8λ����,�ɱ䲨����
			S4CON |= 0x40;		//����4ѡ��ʱ��4Ϊ�����ʷ�����
			T4T3M |= 0x20;		//��ʱ��4ʱ��ΪFosc,��1T
			T4L = (u8)(65535UL - ((MAIN_Fosc / 4) / COMx->UART_BaudRate));
			T4H = (u8)((65535UL - ((MAIN_Fosc / 4) / COMx->UART_BaudRate))>>8);		//�趨��ʱ��ֵ	
			T4T3M |= 0x80;		//������ʱ��4	
			IE2 |= (COMx->UART_Interrupt << 4);//�ж�����		
		}	
	}
	#endif
	
}
/*******************************************************************************/
void int_4(void) interrupt 4 //����1�ж�
{
	if(RI==1)
	{ 
		RI=0;
	  if((Msg_RX[0].pIn >= Msg_RX[0].pOut) && (Msg_RX[0].overflow_flag == 1))
		{

			Msg_RX[0].pIn = Msg_RX[0].pStart;
			Msg_RX[0].pOut = Msg_RX[0].pStart;
			Msg_RX[0].overflow_flag = 0;	
		}
		if(Msg_RX[0].pIn == Msg_RX[0].pEnd)		//����߽�
		{
			*Msg_RX[0].pIn 	= SBUF;						//�������	
			Msg_RX[0].pIn 	= Msg_RX[0].pStart;	//ѭ������ʼλ��
			Msg_RX[0].overflow_flag = 1;			//�Ѿ������߽�
		}
		else 
		{
			*Msg_RX[0].pIn++ = SBUF;
		}

	}
}
/*****************************************************************************/
void int_8(void) interrupt 8 //����2�ж�
{
	if(S2CON&0x01)  //S2RI=1
	{
		S2CON&=0xfe; 
	  if((Msg_RX[1].pIn == Msg_RX[1].pOut) && (Msg_RX[1].overflow_flag == 1))//�������
		{
			Msg_RX[1].pIn = Msg_RX[1].pStart;
			Msg_RX[1].pOut = Msg_RX[1].pStart;
			Msg_RX[1].overflow_flag = 0;	
		}
    if(Msg_RX[1].pIn == Msg_RX[1].pEnd)		//����߽�
		{
			*Msg_RX[1].pIn 	= S2BUF;						//�������	
			Msg_RX[1].pIn 	= Msg_RX[1].pStart;	//ѭ������ʼλ��
			Msg_RX[1].overflow_flag = 1;			//�Ѿ������߽�
		}
		else 
		{
			*Msg_RX[1].pIn++ = S2BUF;	
		}
	}
	
}

#ifdef  STC15W4K48S4	
//========================================================================
//����: ����3�ж�
//========================================================================
void UART3_int (void) interrupt UART3_VECTOR //�����ж�3
{
	if(RI3) 
	{
		CLR_RI3(); 
	  if((Msg_RX[2].pIn == Msg_RX[2].pOut) && (Msg_RX[2].overflow_flag == 1))//�������
		{
			Msg_RX[2].pIn = Msg_RX[2].pStart;
			Msg_RX[2].pOut = Msg_RX[2].pStart;
			Msg_RX[2].overflow_flag = 0;	
		}
    if(Msg_RX[2].pIn == Msg_RX[2].pEnd)		//����߽�
		{
			*Msg_RX[2].pIn 	= S3BUF;						//�������	
			Msg_RX[2].pIn 	= Msg_RX[2].pStart;	//ѭ������ʼλ��
			Msg_RX[2].overflow_flag = 1;			//�Ѿ������߽�
		}
		else 
		{
			*Msg_RX[2].pIn++ = S3BUF;	
		}
	}
	
}
#endif
#ifdef  STC15W4K48S4	
//========================================================================
//����: ����4�ж�
//========================================================================
void UART4_int (void) interrupt UART4_VECTOR //�����ж�4
{
	if(RI4) 
	{		
		CLR_RI4();
	  if((Msg_RX[3].pIn == Msg_RX[3].pOut) && (Msg_RX[3].overflow_flag == 1))//�������
		{
			Msg_RX[3].pIn = Msg_RX[3].pStart;
			Msg_RX[3].pOut = Msg_RX[3].pStart;
			Msg_RX[3].overflow_flag = 0;	
		}
    if(Msg_RX[3].pIn == Msg_RX[3].pEnd)		//����߽�
		{
			*Msg_RX[3].pIn 	= S4BUF;						//�������	
			Msg_RX[3].pIn 	= Msg_RX[3].pStart;	//ѭ������ʼλ��
			Msg_RX[3].overflow_flag = 1;			//�Ѿ������߽�
		}
		else 
		{
			*Msg_RX[3].pIn++ = S4BUF;	
		}
	}
	
}
#endif
//========================================================================
// ����: u8	USART_ReadRxBuffer(u8 UARTx��u8 *pbuffer,u16 *lenth)
// ����: ��ȡ���ڵĻ������ݵ�ָ�����ڴ��
// ����: u8 UARTx��Ҫ���Ķ˿ںţ�u8 *pbuffer�ڴ��ĵ�ַ��u16 BuflenthΪ�������Ĵ�С.
// ����: ���ض�ȡ���ݵĳ���
// �汾: V1.0, 2022-10-17
//========================================================================
u16 USART_ReadRxBuffer(u8 UARTx, u8 *pbuffer, u16 Buflenth)
{
	u8 *pIn 	= 	Msg_RX[UARTx-1].pIn;
	u8 *pOut 	= 	Msg_RX[UARTx-1].pOut;
	xdata u16 lenth = 0;
	xdata u8 *ptemp = pbuffer;

	while(pOut != pIn)        	//1�ζ�ȡ���еĻ���
	{
		lenth++;	//��¼���������ݳ���	
		if (lenth < Buflenth)						//�ж������Ƿ�Խ��
		{	   
				if(pOut == Msg_RX[UARTx-1].pEnd)	//����߽�
				{
						*pbuffer++ = *pOut;		//���ݳ���				
							pOut		 = Msg_RX[UARTx-1].pStart;//ѭ������ʼλ��
						Msg_RX[UARTx-1].overflow_flag = 0;		//�����־��0
				}
				else 
				{			  
						*pbuffer++ = *pOut++;	//���ݳ��� 
				}
			#ifdef DEBUG
				printf("RxBuffer[%bd] = %b02x",(u8)(lenth-1),*(pbuffer-1));	
				printf("\r\n");
			#endif
		}
		else					//��������Խ��
		{
			#ifdef DEBUG
			printf("USART_ReadRxBuffer:Index overflow!!!\r\n");	
			#endif		
			break;//�˳������ٿ���
		}
	}
	Msg_RX[UARTx-1].pOut = pIn; //�����ݳ���λ���Ƶ����λ�ã�׼��������һ�ֶ�ȡ
	return lenth;
		
}


//========================================================================
// ����: void USART_CloseInterrupt(u8 UARTx)
// ����: �رմ����ж�
// ����: u8 UARTx��Ҫ�رյĴ��ں�
// ����: 
// �汾: V1.0, 2022-10-17
//========================================================================
void USART_CloseInterrupt(u8 UARTx)
{
			switch(UARTx)
			{
				case USART1:
										ES = 0;//�ر��ж�
										break;
				case USART2:
										IE2 &= ~(1<< 0);//�ر��ж�
										break;
#ifdef  STC15W4K48S4	
				case USART3:
										IE2 &= ~(1<< 3);//�ر��ж�
										break;
				case USART4:
										IE2 &= ~(1<< 4);//�ر��ж�
										break;
#endif
				default:
										return;
			}	
}

//========================================================================
// ����: void USART_OpenInterrupt(u8 UARTx)
// ����: ���������ж�
// ����: u8 UARTx��Ҫ�����Ĵ��ں�
// ����: 
// �汾: V1.0, 2022-10-17
//========================================================================
void USART_OpenInterrupt(u8 UARTx)
{
			switch(UARTx)
			{
				case USART1:
										ES = 1;//�����ж�
										break;
				case USART2:
										IE2 |=(1<< 0);//�����ж�
										break;
#ifdef  STC15W4K48S4
				case USART3:
										IE2 |= (1<< 3);//�����ж�
										break;
				case USART4:
										IE2 |= (1<< 4);//�����ж�
										break;
				default:
										return;
#endif
			}
}
//========================================================================
// ����: void USART_ClearMsgQueueRxBuffer(u8 UARTx)
// ����: �����ڻ�������
// ����: u8 UARTx��Ҫ����Ĵ��ں�
// ����: 
// �汾: V1.0, 2022-10-17
//========================================================================
void USART_ClearMsgQueueRxBuffer(u8 UARTx)
{
			u16 Bufferlenth = 0;
	
	    if(UARTx != DISABLE)
			{
	
				USART_CloseInterrupt(UARTx);//�ر��ж�

				Bufferlenth = Msg_RX[UARTx-1].pEnd - Msg_RX[UARTx-1].pStart +1;//���㻺�����ĳ���
		
				memset(Msg_RX[UARTx-1].pStart,0,Bufferlenth);//������
		
				Msg_RX[UARTx-1].pIn = Msg_RX[UARTx-1].pStart;//��λ�������ָ��
		
				Msg_RX[UARTx-1].pOut = Msg_RX[UARTx-1].pStart;//��λ���ݳ���ָ��
		
				Msg_RX[UARTx-1].overflow_flag = 0;//�����־����
		
				USART_OpenInterrupt(UARTx);//�����ж�
			}
	
		
}
