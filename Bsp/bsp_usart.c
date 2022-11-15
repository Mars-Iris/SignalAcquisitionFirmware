#include "./User/includes.h"
#include <stdio.h>
#include <string.h>


	
#ifdef  STC12C5A60S2	
	xdata UsartRxTypeDef Rx[2];	
	xdata u8 Rx1_Buffer[COM_Rx_LENTH];
	xdata u8 Rx2_Buffer[COM_Rx_LENTH];
#endif


#ifdef  STC15W4K48S4	
	xdata UsartRxTypeDef Rx[4];	
//Ϊ��Լ�ڴ棬��Ԥ���봦������GPS�Ĵ��ڻ������512�ֽڣ�����Ϊ128���ֽ�
  #if (GPS_USART == USART1)
	xdata u8 Rx1_Buffer[GPS_Rx_LENTH];
	xdata u8 Rx2_Buffer[COM_Rx_LENTH];
	xdata u8 Rx3_Buffer[COM_Rx_LENTH];
	xdata u8 Rx4_Buffer[COM_Rx_LENTH];
		
  #elif (GPS_USART == USART2)
	xdata u8 Rx1_Buffer[COM_Rx_LENTH];
	xdata u8 Rx2_Buffer[GPS_Rx_LENTH];
	xdata u8 Rx3_Buffer[COM_Rx_LENTH];
	xdata u8 Rx4_Buffer[COM_Rx_LENTH];
		
	#elif (GPS_USART == USART3)
	xdata u8 Rx1_Buffer[COM_Rx_LENTH];
	xdata u8 Rx2_Buffer[COM_Rx_LENTH];
	xdata u8 Rx3_Buffer[GPS_Rx_LENTH];
	xdata u8 Rx4_Buffer[COM_Rx_LENTH];
		
	#elif (GPS_USART == USART4)
	xdata u8 Rx1_Buffer[COM_Rx_LENTH];
	xdata u8 Rx2_Buffer[COM_Rx_LENTH];
	xdata u8 Rx3_Buffer[COM_Rx_LENTH];
	xdata u8 Rx4_Buffer[GPS_Rx_LENTH];
	#else	
	xdata u8 Rx1_Buffer[COM_Rx_LENTH];
	xdata u8 Rx2_Buffer[COM_Rx_LENTH];
	xdata u8 Rx3_Buffer[COM_Rx_LENTH];
	xdata u8 Rx4_Buffer[COM_Rx_LENTH];
	#endif
#endif
//========================================================================
// ����:char putchar(char ch) printf�ض�����
// ����:printf�ض���usart1
// ������
// �汾: 
//========================================================================
char putchar(char ch)  //����Ĭ�ϵģ���ʹ��printf����ʱ�Զ�����
{
	USART_SendData(CONSOLE_USART,(char)ch);
	return ch;
}
//========================================================================
// ����:BSP_Usart_Init(unsigned char USARTx,unsigned long bote)
// ����: ��ʼ������
// ������USARTx�˿ںţ�bote������
// �汾: V1.0, 2022-10-17
//========================================================================
void BSP_Usart_Init(unsigned char USARTx,unsigned long bote)
{
	COMx_InitDefine		COMx_InitStructure;					        //�ṹ����
	
	if(USARTx == USART1)
	{	
		Rx[USARTx-1].pStart = Rx1_Buffer;
		Rx[USARTx-1].pEnd	 = Rx1_Buffer + sizeof(Rx1_Buffer) -1;
		Rx[USARTx-1].pIn 	 = Rx[USARTx-1].pStart;
		Rx[USARTx-1].overflow_flag = 0;
		memset(Rx1_Buffer,0,sizeof(Rx1_Buffer));
		
		COMx_InitStructure.UART_BRT_Use   = BRT_Timer1;			  //ʹ�ò����ʷ�����,   BRT_Timer1, BRT_Timer2 
	}
	else if(USARTx == USART2)
	{
		Rx[USARTx-1].pStart = Rx2_Buffer;
		Rx[USARTx-1].pEnd	 = Rx2_Buffer + sizeof(Rx2_Buffer) -1;
		Rx[USARTx-1].pIn 	 = Rx[USARTx-1].pStart;
		Rx[USARTx-1].overflow_flag = 0;
		memset(Rx2_Buffer,0,sizeof(Rx2_Buffer));
		
		COMx_InitStructure.UART_BRT_Use   = BRT_Timer2;			  //ʹ�ò����ʷ�����,   BRT_Timer2 (ע��: ����2�̶�ʹ��BRT_Timer2)
	}
#ifdef  STC15W4K48S4	
	else if(USARTx == USART3)
	{
		Rx[USARTx-1].pStart = Rx3_Buffer;
		Rx[USARTx-1].pEnd	 = Rx3_Buffer + sizeof(Rx3_Buffer) -1;
		Rx[USARTx-1].pIn 	 = Rx[USARTx-1].pStart;
		Rx[USARTx-1].overflow_flag = 0;
		memset(Rx3_Buffer,0,sizeof(Rx3_Buffer));
		
		COMx_InitStructure.UART_BRT_Use   = BRT_Timer3;			  //ʹ�ò����ʷ�����,   BRT_Timer2, BRT_Timer3 
	}
	else if(USARTx == USART4)
	{
		Rx[USARTx-1].pStart = Rx4_Buffer;
		Rx[USARTx-1].pEnd	 = Rx4_Buffer + sizeof(Rx4_Buffer) -1;
		Rx[USARTx-1].pIn 	 = Rx[USARTx-1].pStart;
		Rx[USARTx-1].overflow_flag = 0;
		memset(Rx4_Buffer,0,sizeof(Rx4_Buffer));
		
		COMx_InitStructure.UART_BRT_Use   = BRT_Timer4;			  //ʹ�ò����ʷ�����,   BRT_Timer2, BRT_Timer4 
	}
#endif
	else 
	{
		return;
	}
	COMx_InitStructure.UART_BaudRate  = bote;		   	      //������, һ�� 110 ~ 115200
	COMx_InitStructure.UART_Interrupt = ENABLE;				    //�ж�����,   ENABLE��DISABLE
	USART_Configuration(USARTx, &COMx_InitStructure);		  //��ʼ������1 USART1,USART2
}
//========================================================================
// ����:u16 BSP_GetUsartRxBuffer(u8 USARTx,u8 *RxBuffer,u16 *lenth)
// ����: ��ȡ���ڻ����е����ݣ���д����Э��ƥ��ɹ���lenth���������
// ������u8 USARTxΪ�˿ںţ�RxBuffer������ָ��,�������ĳ���
// ���أ���ȡ�����ݳ���
// �汾: V1.0, 2022-10-17
//========================================================================
u16 BSP_GetUsartRxBuffer(u8 USARTx,u8 *pRxBuffer,u16 Rxlenth)
{
	xdata u16 remaindlen = 0;		//����ʣ��ռ��С���������ʱʹ��
	xdata u16 lenth = 0;				//����ȥ���ݳ���
	xdata u16 i = 0;
	
	
	if(USARTx == DISABLE) //Ӳ������δ��ʼ��
	{	
		return 0;//����0
	}
	
	remaindlen = (u16)(Rx[USARTx-1].pEnd - Rx[USARTx-1].pIn) + 1;//����ʣ��ռ��С
	
	lenth = USART_ReadRxBuffer(USARTx,Rx[USARTx-1].pIn,remaindlen);//��ȡ���ڽ��յĻ�������
	
	Rx[USARTx-1].pIn = (u8 *)(Rx[USARTx-1].pIn + lenth);//��ָ���ƶ�����һ����Ҫд�����ݵ�λ��
	
	lenth = (u16)(Rx[USARTx-1].pIn - Rx[USARTx-1].pStart); //���ݳ��Ƚ���
	
	if(Rx[USARTx-1].pIn >= Rx[USARTx-1].pEnd) //��������Ƿ�Խ��
	{
	
		BSP_ClearUsartRxBuffer(USARTx);//����Զ���ջ�������

		printf("BSP_GetUsartRxBuffer:Index overflow!!!  USARTx = %b02d\r\n",USARTx);
		
		#ifdef DEBUG
		printf("BSP_GetUsartRxBuffer:Index overflow!!!  USARTx = %b02d\r\n",USARTx);	
		#endif	
		
		lenth = 0;//����Զ���ջ�������
	}

	if(lenth >= Rxlenth)//�������ݳ�������Ҫд�Ļ���ռ���
	{
		lenth = Rxlenth;	//�ض�����
		
		printf("Rxlenth:Index overflow!!!  USARTx = %b02d\r\n",USARTx);
		
		for (i = 0;i < Rxlenth; i++) //���ݿ���
		{
			*pRxBuffer++ = *(Rx[USARTx-1].pStart+i);	
		}
		BSP_ClearUsartRxBuffer(USARTx);//����Զ���ջ�������
	}
	else
	{
		for (i = 0;i < lenth; i++) //���ݿ���
		{
			*pRxBuffer++ = *(Rx[USARTx-1].pStart+i);	
		}
		
	}
	
	*pRxBuffer = '\0';				 //�����ں����ַ�������ʱ��Ϊ��������ʹ��
	
	return lenth;
	
}
//========================================================================
// ����:u16 BSP_GetFormatRxBuffer(u8 USARTx,u8 *RxBuffer,u16 *lenth,u8 *cutstr)
// ����: ��ȡ���ڻ����е����ݣ��������һ��'\n'�����и��ȡ.
// ������u8 USARTxΪ�˿ںţ�RxBuffer������ָ��,Rxlenth�������ĳ���,u8 ��*cutstr��Ϊ�и��ַ��� cutlenth,���и��ַ��ĳ���
// ���أ���ȡ�����ݳ���
// �汾: V1.0, 2022-10-17
//========================================================================
u16 BSP_GetFormatRxBuffer(u8 USARTx,u8 *pRxBuffer,u16 Rxlenth,u8 *cutstr,u8 cutlenth)
{
	xdata u16 lenth = 0;					//�������ݳ���
	xdata u8  *pTemp     = NULL;
	xdata u8  *pStart    = NULL;
	xdata u8  *pcutstr    = NULL;
	xdata u8  i  = 0;

	
	if(USARTx == DISABLE) //Ӳ������δ��ʼ��
	{	
		return 0;//����0
	}
	
	lenth = BSP_GetUsartRxBuffer(USARTx,pRxBuffer,Rxlenth);//��ȡ��������
	
	pcutstr = ByteArrayCompar_r(pRxBuffer,lenth,cutstr,cutlenth);//�ҵ��и��ַ�����λ�ã��Ӻ���ǰ�ҡ�
	
	if(pcutstr == NULL)//δ��ѯ���и��ַ�
	{
		memset(pRxBuffer,0,Rxlenth);//��ջ�������
		
		//printf("BSP_GetFormatRxBuffer lenth = %h04d\r\n",lenth);
		
		lenth = 0;//��ȡ����Ϊ0
		
		
		return lenth;//����0
	}
	//��������pRxBuffer������
	if(*(cutstr+cutlenth-1) == '\n')//����л��з�������ĩβ�з�
	{
		//printf("BSP_GetFormatRxBuffer lenth = %h04d\r\n",lenth);
		
		pcutstr = (u8 *)(pcutstr +1);//�����и��ַ�
		
	}
  lenth = (u16)(pcutstr - pRxBuffer);//���ݳ��ȣ����ظ�������
	
	memset(pcutstr,0,(u16)(Rxlenth - lenth));//�����������ݣ����ظ�������
	
	//��������Rx������
	pStart = Rx[USARTx-1].pStart;
	
	pTemp = (u8 *)(pStart + lenth);
	
	while (pTemp  < Rx[USARTx-1].pIn)
	{
			*pStart++ = *pTemp++;    //��ʣ�µ������Ƶ����������׵�ַ	
	}
	memset(pStart,0,(u16)(Rx[USARTx-1].pEnd - pStart +1));//�����������
	
	Rx[USARTx-1].pIn = pStart;
	
	return lenth;
}
//========================================================================
// ����:void BSP_ClearUsartRxBuffer(u8 USARTx)
// ����: �����ڻ�������
// ������u8 USARTxΪ�˿ں�
// �汾: V1.0, 2022-10-17
//========================================================================
void BSP_ClearUsartRxBuffer(u8 USARTx)
{
	xdata u16 lenth = 0;

	if(USARTx == DISABLE) return;//Ӳ������δ����
	
	lenth = (u16)(Rx[USARTx-1].pEnd - Rx[USARTx-1].pStart + 1);//���㻺�������ܳ���
	
  memset(Rx[USARTx-1].pStart, 0,lenth);//����������
	
	Rx[USARTx-1].pIn = Rx[USARTx-1].pStart;		//ָ�򻺴����׵�ַ
	
	 #ifdef DEBUG
		printf("Rx[%b02d]Clear,OK!\r\n",(USARTx-1));
	 #endif
}
//========================================================================
// ����:WaitForTISignal(u8 USARTx)
// ����: �ȴ��������ݷ�����ɣ�����ģʽ
// ������u8 USARTx���ں�
// �汾: V1.0, 2022-10-17
//========================================================================
static void WaitForTISignal(u8 USARTx)
{
	if(USARTx == USART1)
	{
		while(TI == 0); 
		TI = 0;
	}
	else if(USARTx == USART2)
	{
		while((S2CON & 2) == 0); 
		S2CON &= ~2;
	}
	#ifdef  STC15W4K48S4
	else if(USARTx == USART3)
	{
		while(TI3 ==0);
		CLR_TI3();
	}
	else if(USARTx == USART4)
	{
		while(TI4==0);
		CLR_TI4();   
	}
	#endif
	else 
	{
		return;
	}
}
//========================================================================
// ����:void USART_SendData(u8 USARTx,u8 ch)
// ����: �������ݷ���ģʽ����ѯ��ʽ
// ������u8 USARTx���ں�,u8 ch��Ҫ���͵�����
// �汾: V1.0, 2022-10-17
//========================================================================
void USART_SendData(u8 USARTx,u8 ch)
{
	
	if(USARTx == DISABLE) //Ӳ������δ��ʼ��
	{	
		return ;//ֱ�ӷ���
	}
	switch(USARTx)
	{
		case USART1:
								SBUF = ch;
								break;
		case USART2:
								S2BUF = ch;
								break;
#ifdef  STC15W4K48S4
		case USART3:
								S3BUF = ch;
								break;		
		case USART4:
								S4BUF = ch;
								break;	
#endif
		default:
								break;
		
	}
	WaitForTISignal(USARTx);//�ȴ����ݴ������
}
//========================================================================
// ����:void USART_Sendbuffer(u8 USARTx,const u8 *ch, u16 lenth)
// ����: �������ݷ���ģʽ����ѯ��ʽ
// ������u8 USARTx���ں�,u8 ch��Ҫ���͵�����,lenth�������ĳ���
// �汾: V1.0, 2022-10-17
//========================================================================
void USART_Sendbuffer(u8 USARTx,const u8 *ch, u8 lenth)
{
	unsigned char i = 0;
	//printf("USART_Sendbuffer\r\n");
	for (i=0;i<lenth;i++)
	{
		USART_SendData(USARTx,*ch++);
	}
	
}

//========================================================================
// ����:printf_buffer(const char *name,const u8 *pbuffer,u16 lenth)
// ����: ��ʽ����Ӧ��������
// ������nameΪ��ӡ��������������,pbufferΪ�������ƣ�lenthΪ��ӡ����ǰ���ٸ�Ԫ��
// �汾: V1.0, 2022-10-17
//========================================================================
#ifdef DEBUG1
void printf_buffer(const char *name,const u8 *pbuffer,u16 lenth)
{
	int i = 0;
	printf("%s:",name);
	for (i = 0; i < lenth; i++)
	{
		printf("%b02X",*pbuffer++);	
		printf(" ");			
	}
	printf("\r\n");
}
#endif
//========================================================================
// ����:HextoStr(const u8 *pbuffer,char *pStr,u16 lenth)
// ����: ���ַ�����ת�����ַ�����
// ������pbufferΪ�ֽ��������ƣ�pStr��Ҫ�����ַ����ĵ�ַ��lenthΪ�ֽ�����ĳ���
// �汾: V1.0, 2022-10-17
//========================================================================
#ifdef  STC15W4K48S4	
void HextoStr(const u8 *pbuffer,u8 *pStr,u16 lenth)
{
	u16 i = 0;
	char temp[3] = "";
	for (i = 0; i < lenth; i++)
	{
		sprintf(temp,"%b02X",*pbuffer++);
		strcat(pStr,temp);
	}
	strcat(pStr,"\n");
}
#endif




