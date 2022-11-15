
#include	"./User/includes.h"
#include	<stdio.h>
#include	<string.h>

#ifdef  STC15W4K48S4	
xdata PengGanSignalTypeDef	pgxd[4];//��������
#endif
//========================================================================
// ����: void BSP_GPIO_Init(void)
// ����: ��ʼ������IO��.ȫ����ʼ��Ϊ������׼˫���
// �汾: V1.0, 2022-10-17
//========================================================================
void BSP_GPIO_Init(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;				//�ṹ����
	
	GPIO_InitStructure.Pin  = GPIO_Pin_All;			//ָ��Ҫ��ʼ����IO, GPIO_Pin_0 ~ GPIO_Pin_7, �����
	GPIO_InitStructure.Mode = GPIO_PullUp;			//ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	
	GPIO_Inilize(GPIO_P0,&GPIO_InitStructure);	//��ʼ��GPIO_P0
	GPIO_Inilize(GPIO_P1,&GPIO_InitStructure);	//��ʼ��GPIO_P1
	GPIO_Inilize(GPIO_P2,&GPIO_InitStructure);	//��ʼ��GPIO_P2
	GPIO_Inilize(GPIO_P3,&GPIO_InitStructure);	//��ʼ��GPIO_P3
	GPIO_Inilize(GPIO_P4,&GPIO_InitStructure);	//��ʼ��GPIO_P4
	
}
//========================================================================
// ����: void BSP_Zhuansu_Init(void)
// ����: ��ʼ����ʱ��0Ϊ����ģʽ����ת���������
// �汾: V1.0, 2022-10-17
//========================================================================
void BSP_ZhuansuCount_Init(void)
{
	  TMOD |= 0x05;	//���ö�ʱ��0Ϊ������ģʽ//��ת���������
	  TH0=0; 				//����������
	  TL0=0;				//����������
    TR0=1; 				//������0��ʼ����
}
//========================================================================
// ����: u8 BSP_GetGpioStatus(u8 pin)
// ����: ��ȡ����ܽŵ�ƽֵ.�˺�����Ӳ����·�����
// ����: ��������ڱ�ţ�ȡֵD1--D32.
// ����: ����ڵ�ƽֵ.0����1
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 BSP_GetGpioStatus(u8 pin)//��ѯ��Ӧ��IO��״̬
{
	switch(pin)
	{
#ifdef  STC12C5A60S2	
		case D1:		return(P00);
		case D2:   	return(P01);
		case D3:   	return(P02);
		case D4:   	return(P03);
		case D5:   	return(P04);
		case D6:   	return(P05);
		case D7:   	return(P06);
		case D8:   	return(P07);
		case D9:   	return(P27);
		case D10:  	return(P26);
		case D11:  	return(P25);
		case D12:  	return(P24);
		case D13:  	return(P23);
		case D14:  	return(P22);
		case D15:  	return(P21);
		case D16:  	return(P20);
		case D17:  	return(P10);
		case D18:  	return(P11);
		case D19:  	return(P12);
		case D20:  	return(P13);
		case D21:  	return(P14);
		case D22:  	return(P15);
		case D23:  	return(P16);
		case D24:  	return(P17);
		case D25:  	return(P32);
		case D26:  	return(P33);
		case D27:  	return(P34);
		case D28:  	return(P35);
		case D29:  	return(P36);
		case D30:  	return(P37); 
		case D31:  	return(P47);
		case D32:  	return(P46);
		case D33:  	return(P45);
		case D34:  	return(P44); 
		case D35:  	return(P44);
#endif
#ifdef  STC15W4K48S4	
		case D1:		return(P45);
		case D2:   	return(P27);
		case D3:   	return(P02);
		case D4:   	return(P26);
		case D5:   	return(P03);
		case D6:   	return(P25);
		case D7:   	return(P04);
		case D8:   	return(P24);
		case D9:   	return(P05);
		case D10:  	return(P23);
		case D11:  	return(P06);
		case D12:  	return(P22);
		case D13:  	return(P07);
		case D14:  	return(P21);
		case D15:  	return(P20);
		case D16:  	return(P44);
		case D17:  	return(P12);
		case D18:  	return(P42);
		case D19:  	return(P13);
		case D20:  	return(P41);
		case D21:  	return(P14);
		case D22:  	return(P37);
		case D23:  	return(P15);
		case D24:  	return(P36);
		case D25:  	return(P35);
		case D26:  	return(P34);
		case D27:  	return(P33);
		case D28:  	return(P32);
		case D29:  	return(P54);
		case D30:  	return(P55); 
		case D31:  	return(P55);
#endif
		
		default: 
								return(0);
	}
}
//========================================================================
// ����: u8 BSP_ReadInputDataBit(SignalTypeDef *pSignal)
// ����: ��ȡ����ܽŵ�ƽֵ.
// ����: SignalTypeDefΪָ���źŽṹ���ָ��.
// ����: ����TURE����FALSE.
// �汾: V1.0, 2022-10-17
//========================================================================
u8 BSP_ReadInputDataBit(SignalTypeDef *pSignal)
{
  xdata u8 status = 0;
	xdata u8 signalstatus = BSP_GetGpioStatus(pSignal->pin);//��ȡ��Ƭ���Ĺܽ�����״̬
	if(pSignal->falling_ed == 255)  pSignal->falling_ed = 0;//�˴���Ϊ�����ϰ汾�ĳ���δ���Ӹò��������

	if(pSignal->stateflag == 0)
	{
		if (signalstatus == pSignal->modle)//�ж��ź��Ƿ���
		{
			pSignal->times = 0;
			status = TURE;	
		}
		else if(pSignal->times < pSignal->rising_ed) //�źŶ�������ʱ����
		{
			(pSignal->times)++;
			status = TURE;	
		}	
		else 
		{
			pSignal->stateflag = 1;
			status = FALSE; 
		}
  }
	else 
	{
		if (signalstatus != pSignal->modle)//��ȡ��Ӧ��״̬
		{
			pSignal->times = 0;
			status = FALSE;
		}
		else if(pSignal->times < pSignal->falling_ed) //�źŶ�������ʱ����
		{
			(pSignal->times)++;
			status = FALSE;
		}	
		else 
		{
			pSignal->stateflag = 0;
			status = TURE; 
		}		
	}
	#ifdef DEBUG1
	if(pSignal->pin ==12)
	{
					printf("pin = %b02u  modle  = %b02u  times = %b02u rising_ed = %b02u falling_ed = %b02u\r\n"\
								,pSignal->pin,pSignal->modle,pSignal->times,pSignal->rising_ed,pSignal->falling_ed);
					printf("gpiovalue = %b02d.  ",signalstatus);
					printf("output = %b02d.\r\n",status);
	}
	#endif	
	return(status);
}
//========================================================================
// ����:BSP_ReadMultipleDataBit(MultSignalTypeDef *pSignal,u8 pin)
// ����: ��ȡһ������������ź���
// ����: MultSignalTypeDefָ���ַ��pin��������һ���ź���.
// ����: ����TURE����FALSE.
// �汾: V1.0, 2022-10-17
//========================================================================
u8 BSP_ReadMultipleDataBit(MultSignalTypeDef *pSignal,u8 offset)
{
	xdata u8 pin = *(u8 *)((u8 *)pSignal + offset  - 1);
  xdata u8 status = 0;
	xdata u8 signalstatus = BSP_GetGpioStatus(pin);//��ȡ��Ƭ���Ĺܽ�����״̬
	xdata u8 flag = 0;//�źŷ�ת��־
	
	flag = (((pSignal->stateflag) >> (offset-1)) & (0x01));//�õ���־״̬
	
	pSignal->times = pSignal->counts[offset-1];//��ȡ��ʱ��������ֵ
	
	if(pSignal->falling_ed == 255)  pSignal->falling_ed = 0;//�˴���Ϊ�����ϰ汾�ĳ���δ���Ӹò��������
		
	if(flag == 0)
	{
		if (signalstatus == pSignal->modle)//�ж��ź��Ƿ���
		{
			pSignal->times = 0;
			status = TURE;
		}
		else if(pSignal->times < pSignal->rising_ed) //�źŶ�������ʱ����
		{
			pSignal->times++;
			status = TURE;
		}	
		else 
		{
			flag = 1;
			status = FALSE; 
		}
  }
	else 
	{
		if (signalstatus != pSignal->modle)//��ȡ��Ӧ��״̬
		{
			pSignal->times = 0;
			status = FALSE;
		}
		else if(pSignal->times < pSignal->falling_ed) //�źŶ�������ʱ����
		{
			pSignal->times++;
			status = FALSE;
		}	
		else 
		{
			flag = 0;
			status = TURE; 
		}		
	}
	#ifdef DEBUG1
		if(pin == 13)
		{
		printf("pin = %b02u  modle  = %b02u  times = %b02u rising_ed = %b02u falling_ed = %b02u\r\n"\
								,pin,pSignal->modle,pSignal->times,pSignal->rising_ed,pSignal->falling_ed);
		printf("gpiovalue = %b02d.  ",signalstatus);
		printf("output = %b02d.\r\n",status);
		}
	
	#endif	
  pSignal->counts[offset-1]=pSignal->times;//���汾����ʱ��������ֵ
	
  pSignal->stateflag |= (flag << offset-1);
		
	return(status);
}
#ifdef  STC15W4K48S4	
//========================================================================
// ����:BSP_ReadBumpDataBit(SignalTypeDef *pSignal,u8 group,u8 valuebit,u8 offset)
// ����: ���˴���������
// ����: MultSignalTypeDefָ���ַ��u8 ����״̬��valueֵ offset��������һ���ź��ߣ���0��ʼ��.
// ����: ����TURE����FALSE.
// �汾: V1.0, 2022-10-17
//========================================================================
u8 BSP_ReadBumpDataBit(SignalTypeDef *pSignal,u8 group,u8 valuebit,u8 offset)
{
  xdata u8 status = 0;
	xdata u8 signalstatus = valuebit;//��ȡ����״̬
	
	xdata u8 flag = 0;//�źŷ�ת��־
	
	flag = (((pgxd[group].stateflag) >> offset) & (0x01));//�õ���־״̬
	
	pSignal->times = pgxd[group].times[offset];//��ȡ��ʱ��������ֵ
	
	if(pSignal->falling_ed == 255)  pSignal->falling_ed = 0;//�˴���Ϊ�����ϰ汾�ĳ���δ���Ӹò��������
		
	if(flag == 0)
	{
		if (signalstatus == TURE)//�ж��ź��Ƿ���
		{
			pSignal->times = 0;
			status = TURE;
		}
		else if(pSignal->times < pSignal->rising_ed) //�źŶ�������ʱ����
		{
			pSignal->times++;
			status = TURE;
		}	
		else 
		{
			flag = 1;
			status = FALSE; 
		}
  }
	else 
	{
		if (signalstatus != TURE)//��ȡ��Ӧ��״̬
		{
			pSignal->times = 0;
			status = FALSE;
		}
		else if(pSignal->times < pSignal->falling_ed) //�źŶ�������ʱ����
		{
			pSignal->times++;
			status = FALSE;
		}	
		else 
		{
			flag = 0;
			status = TURE; 
		}		
	}
	#ifdef DEBUG1
		if(pin == 13)
		{
		printf("pin = %b02u  modle  = %b02u  times = %b02u rising_ed = %b02u falling_ed = %b02u\r\n"\
								,pin,pSignal->modle,pSignal->times,pSignal->rising_ed,pSignal->falling_ed);
		printf("gpiovalue = %b02d.  ",signalstatus);
		printf("output = %b02d.\r\n",status);
		}
	
	#endif	
		
  pgxd[group].times[offset] = pSignal->times;//���汾����ʱ��������ֵ
	
	if( flag == 0 )
	{
		pgxd[group].stateflag &= ~(u16)(1<< offset);//��������������
	}
	else 
		pgxd[group].stateflag |= (u16)(1<< offset);//��������������
	
	return(status);
}
#endif
