#ifndef __USART_H
#define __USART_H	 


#ifdef  STC15W4K48S4
	#define	Q_BUF_LENTH					128 //��Ϣ���еĻ���ռ��С
	#define	Q_GPS_BUF_LENTH			500
#endif

#ifdef  STC12C5A60S2
	#define	Q_BUF_LENTH	32 //��Ϣ���еĻ���ռ��С
#endif

	


#define	USART1	1
#define	USART2	2

#ifdef  STC15W4K48S4
	#define	USART3	3
	#define	USART4	4
#endif



#define	UART_ShiftRight	0				//ͬ����λ���
#define	UART_8bit_BRTx	(1<<6)	//8λ����,�ɱ䲨����
#define	UART_9bit				(2<<6)	//9λ����,�̶�������
#define	UART_9bit_BRTx	(3<<6)	//9λ����,�ɱ䲨����

#define	BRT_Timer1	1
#define	BRT_Timer2	2

#ifdef  STC15W4K48S4
	#define	BRT_Timer3	3
	#define	BRT_Timer4	4
#endif


	
typedef struct
{ 	
	unsigned char	*pStart;								//��������ʼ��ַ
	unsigned char	*pEnd;									//������������ַ
	unsigned char *pOut;									//���ݳ���ָ��
	unsigned char	*pIn;										//�������ָ��
	unsigned char	overflow_flag;  				//�����־
	//unsigned char	buffer[Q_BUFFER_LENTH];	//������
}MessageQueue; 


typedef struct
{ 
	unsigned char	UART_Mode;			//ģʽ,            UART_ShiftRight,UART_8bit_BRTx,UART_9bit,UART_9bit_BRTx
	unsigned char	UART_BRT_Use;		//ʹ�ò����ʷ����� BRT_Timer1,BRT_Timer2
	unsigned long UART_BaudRate;		//������,        ENABLE,DISABLE
	unsigned char	UART_RxEnable;		//�������,      ENABLE,DISABLE
	unsigned char	BaudRateDouble;		//�����ʼӱ�,    ENABLE,DISABLE
	unsigned char	UART_Interrupt;		//�жϿ���,      ENABLE,DISABLE
	unsigned char	UART_Polity;		  //���ȼ�,        PolityLow,PolityHigh
}COMx_InitDefine; 


	

	
void USART_Configuration(unsigned char UARTx, COMx_InitDefine *COMx);
u16 USART_ReadRxBuffer(u8 UARTx, u8 *pbuffer, u16 Buflenth);
void USART_ClearMsgQueueRxBuffer(u8 UARTx);
void USART_CloseInterrupt(u8 UARTx);
void USART_OpenInterrupt(u8 UARTx);
	
	
#endif

