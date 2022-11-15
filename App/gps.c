#include <stdio.h>
#include <string.h>
#include	"./User/config.h"
#include 	"./User/includes.h"




#ifdef  STC15W4K48S4

#if GPS_USART

xdata	u8 GpsRxBuffer[128]="";	//���ջ���

u8 code CMD_GpsConfFail[]	=	{0x53,0x5A,0x43,0x47};//Gps����ʧ��ָ��
u8 code CMD_GpsConfSucc[]	=	{0x44,0x51,0x43,0x47,0x00};//Gps���óɹ�ָ��


char code  CMD_GpsAckSucc[]	=	"OK";//Gps���óɹ�ָ��

char code  CMD_BY_BaseAuto[] =	"fix auto\r\n";//�Զ���ȡ��׼վ����
char code  CMD_BY_GetBasePos[] =	"log refstationa\r\n";//��ȡ��׼վ����

char code  CMD_HX_BaseAuto[] =	"fix auto\r\n";//�Զ���ȡ��׼վ����
char code  CMD_HX_GetBasePos[] =	"log bestposa\r\n";//��ȡ��׼վ����


char code  CMD_ConfigEnd[] = "Configuration complete\r\n";//���ý���ָ����ڳ����ѭ���Ƿ��������GPS�����޹أ������У���
char code  CMD_BY_BaseStation[][CMD_GPS_LENTH] =         //����GPS��׼վָ��
{
	"interfacemode com3 bynav bynav\r\n",//�����ö˿ڵ���������Ϊbynav��
	"interfacemode com2 rtcm rtcm\r\n",//�����ö˿��������Ϊrtcm��
	"rtktype base\r\n",// //����Ϊ��׼վ
	"fix auto\r\n",////�Զ���ȡ��׼վ����
	"serialconfig com1 38400\r\n",//
	"serialconfig com2 38400\r\n",//
	"serialconfig com3 38400\r\n",//
	"log com2 rtcm1074 ontime 1\r\n",//
	"log com2 rtcm1084 ontime 1\r\n",//
	"log com2 rtcm1114 ontime 1\r\n",//
	"log com2 rtcm1124 ontime 1\r\n",//
	"log com2 rtcm1006 ontime 5\r\n",//
	"log com2 rtcm1033 ontime 10\r\n",//
	"unlogall com3\r\n",//
	"log com3 gpgga ontime 1\r\n",//
	"saveconfig\r\n",							//
	"reboot\r\n",									// //����		
	"Configuration complete\r\n"	//���ý���ָ����ڳ����ѭ���Ƿ��������GPS�����޹أ������У���	
};

char code  CMD_BY_MobileStation[][CMD_GPS_LENTH] =         //����GPS�ƶ�վ����ָ��
{
	"interfacemode com3 bynav bynav\r\n",//
	"unlogall\r\n",
	"interfacemode com2 rtcm rtcm\r\n",
	"rtktypertk rover\r\n",
	"interfacemode com3 bynav bynav\r\n",
	"serialconfig com2 38400\r\n",
	"serialconfig com3 38400\r\n",
	"serialconfig com1 38400\r\n",
	"log com3 ptnlpjk ontime 0.1\r\n",
	"log com3 gpvtg ontime 0.1\r\n",
	"log com3 ptnlavr ontime 0.1\r\n",
	"saveconfig\r\n",		
	"Configuration complete\r\n",	//���ý���ָ����ڳ����ѭ���Ƿ��������GPS�����޹أ������У���
};

char code  CMD_HX_BaseStation[][CMD_GPS_LENTH] =         //��оGPS��׼վָ��
{
	"lmode base time 60 1.5 2.5\r\n",				//��GPS����Ϊ��׼վ
	"fix auto\r\n",											//�Զ���ȡ��׼վ����
	"unlog com3\r\n",								
	"log com2 rtcm1033 ontime 10\r\n",									
	"log com2 rtcm1006 ontime 10\r\n",//
	"log com2 rtcm1074 ontime 1\r\n",//
	"log com2 rtcm1084 ontime 1\r\n",//
	"log com2 rtcm1124 ontime 1\r\n",//
	"log com2 rtcm1094 ontime 1\r\n",//
	"config com2 38400\r\n",//
	"config com3 38400\r\n",//
	"saveconfig\r\n",//		
	"Configuration complete\r\n"	//���ý���ָ����ڳ����ѭ���Ƿ��������GPS�����޹أ������У���
};


char code  CMD_HX10Hz_MobileStation[][CMD_GPS_LENTH] =         //��оGPS�ƶ�վָ��
{
	"log headinga ontime 1\r\n",				//��GPS����Ϊ��׼վ
	"com com2 38400\r\n",											//�Զ���ȡ��׼վ����
	"com com3 38400\r\n",								
	"Unlogall com2\r\n",									
	"Unlogall com3\r\n",//
	"log com3 gpntr ontime 0.1\r\n",//
	"log com3 gptra onchanged\r\n",//
	"log com3 gpvtg ontime 0.1\r\n",//
	"log com3 gprmc ontime 0.1\r\n",//
	"Headingmode variablelength \r\n",//
	"mode rover\r\n",//
	"saveconfig\r\n",//		
	"Configuration complete\r\n"	//���ý���ָ����ڳ����ѭ���Ƿ��������GPS�����޹أ������У���	
};

char code  CMD_HX5Hz_MobileStation[][CMD_GPS_LENTH] =         //��оGPS�ƶ�վָ��
{
	"log headinga ontime 1\r\n",				//��GPS����Ϊ��׼վ
	"com com2 38400\r\n",											//�Զ���ȡ��׼վ����
	"com com3 38400\r\n",								
	"Unlogall com2\r\n",									
	"Unlogall com3\r\n",//
	"log com3 gpntr ontime 0.2\r\n",//
	"log com3 gptra onchanged\r\n",//
	"log com3 gpvtg ontime 0.2\r\n",//
	"log com3 gprmc ontime 0.2\r\n",//
	"Headingmode variablelength \r\n",//
	"mode rover\r\n",//
	"saveconfig\r\n",//		
	"Configuration complete\r\n"	//���ý���ָ����ڳ����ѭ���Ƿ��������GPS�����޹أ������У���	
};
//========================================================================
// ����: u8 GPS_Configuration(u8 USARTx,char *dat)
// ����: ����gps����gps����ָ�ͬʱ�ɸ���ָ��ز��վ����
 //      ��������3�Σ����ɹ�������ʧ��
// ������u8 USARTx,���ô��ڣ�char *cmd ָ��ָ��ĵ�ַ
// ����: ��
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 Configuration(u8 USARTx,char *cmd)	//����GPS�忨
{
	xdata u8 i=0;
	xdata u8 times=3;
	
	//printf("GPS_Configuration\r\n");
	
	while (times--)
	{
		
		if (strcmp(cmd,CMD_HX_BaseAuto) == 0)  //fix auto\r\n�뱱��ͨ��
		{
			delay_ms(3000); //��ʱ3��󣬻�ȡ���վ�Ķ�λ����
		}
		
		BSP_ClearUsartRxBuffer(USARTx);//�崮�ڻ���
		
		USART_Sendbuffer(USARTx,cmd,strlen(cmd));//��������ָ��
		
		delay_ms(300);//��ʱ350��ȡ�忨�ظ�
		
		memset(GpsRxBuffer, 0, sizeof(GpsRxBuffer));//�建������
		
		BSP_GetUsartRxBuffer(USARTx,GpsRxBuffer,sizeof(GpsRxBuffer));//��ȡ��������
					
		if(strstr((char *)GpsRxBuffer,CMD_GpsAckSucc) != NULL)  //Gps���óɹ�ָ��Ӧ��ɹ�OK
		{
			if (strstr(cmd,"com3 38400") != NULL)	//�ı䴮�ڲ�����ָ��serialconfig com3 38400\r\n
			{
				BSP_Usart_Init(USARTx,38400); //�����ʺ�GPS���ڲ�����ͬ��
				S1_USE_P16P17();//STC�л�����1��GPS����
			}
			return(1);//�յ�GPS��ȷ�Ļظ�
		}
	}
	return(0);//δ�յ�GPS��ȷ�Ļظ�
}
//========================================================================
// ����: void GPS_EnterConfig(u8 USARTx, char **pcmd)	//����GPS
// ����: ����ָ���pcmd��ָ������GPS�ƶ�վ��ָ��������һ��ָ�������CMD_ConfigEnd
// ������u8 USARTx,���ô���,char (*pcmd)[CMD_GPS_LENTH]ָ��ָ��ϵ�ָ��
// ����: ��
// �汾: V1.0, 2022-10-17
//========================================================================
static void EnterConfig(u8 USARTx, char (*pcmd)[CMD_GPS_LENTH])	
{
	xdata u8 Index = 0;//ָ�����
	xdata u8 temp = 0;//
		
	S1_Int_on();//������1�ж�
	
	BSP_Usart_Init(USARTx,115200);//���Բ�����
  S1_USE_P16P17();//STC�л�����1��GPS����
	
	if(Configuration(USARTx,pcmd[Index]) == 0)//����ʧ��
	{
		 BSP_Usart_Init(USARTx,38400);//���Բ�����
		 S1_USE_P16P17();//STC�л�����1��GPS����
	}
	if(Configuration(USARTx,pcmd[Index]) == 0)//����ʧ��
	{
		 BSP_Usart_Init(USARTx,19200);//���Բ�����
			S1_USE_P16P17();//STC�л�����1��GPS����
	}
	if(Configuration(USARTx,pcmd[Index]) == 1)//����������ɹ� 
	{
		while(strstr(pcmd[Index],CMD_ConfigEnd) == NULL)//��ѯ���������ָ�����ѭ�������ý���
		{
			
			//printf("Index = %b02d\r\n",Index);
			
			temp = Configuration(USARTx,pcmd[Index]);//��������ָ��
				
			if (temp == 0)//����ʧ��
			{
				USART_Sendbuffer(USARTx,CMD_GpsConfFail,sizeof(CMD_GpsConfFail));//��������ʧ��ָ��
				
				USART_SendData(USARTx,Index);//���ʹ�ָ������
				
				//printf("GpsConfFail :Index = %b02d\r\n",Index);
				
				return;//����ʧ��
			}
			
			Index ++;//�Ƶ���һ��ָ��
						
		}
	}
  USART_Sendbuffer(USARTx,CMD_GpsConfSucc,sizeof(CMD_GpsConfSucc));//Ӧ�����óɹ�
	
	//printf("GpsConfSucc\r\n",Index);			
}	
//========================================================================
// ����: void GetBaseStationPos(void)	
// ����: �õ�GPS��׼վ���꣬�ϴ�����λ��
// ��������
// ����: ��
// �汾: V1.0, 2022-10-17
//========================================================================
void GetBaseStationPos(void)	
{
	xdata u8 i = 0 ;	//
	xdata u8 type = 0 ;//��ȡ�����ļ����õ�gps����
	BSP_ClearUsartRxBuffer(GPS_USART);//�崮�ڻ���
	switch(type)
	{
		case BY_BASESTATION:
							USART_Sendbuffer(GPS_USART,CMD_BY_GetBasePos,strlen(CMD_BY_GetBasePos));//���ͻ�ȡ����gps��׼վ�����ָ��	
		case HX_BASESTATION:
							USART_Sendbuffer(GPS_USART,CMD_BY_GetBasePos,strlen(CMD_BY_GetBasePos));//���ͻ�ȡ��оgps��׼վ�����ָ��			
    default:
						break;
										
	}	
	delay_ms(300);
	
	memset(GpsRxBuffer, 0, sizeof(GpsRxBuffer));//�建������
		
	BSP_GetUsartRxBuffer(GPS_USART,GpsRxBuffer,sizeof(GpsRxBuffer));//��ȡ��������
		
	for(i=0;i<strlen((char *)GpsRxBuffer);i++)
	{		
		USART_SendData(UPLOAD_USART,GpsRxBuffer[i]);//�ظ���׼վ����
	}	 
	BSP_ClearUsartRxBuffer(GPS_USART);//�崮�ڻ���											
}



//========================================================================
// ����: void GPS_EnterConfiguration(void)	
// ����: ����GPS����ģʽ
// ������mode��ָ�����վ�����ƶ�վ������λ������
// ����: ��
// �汾: V1.0, 2022-10-17
//========================================================================
void GPS_EnterConfiguration(u8 mode)	
{
	
	xdata u8 gpsmodel = 0 ;//��ȡ�����ļ����õ�gps�ͺ�
	gpsmodel = HX10HZ_MOBILESTATION;////��ȡ�����ļ����õ�gps�ͺ�
	
	if	(mode ==BASESTATION )
	{
			switch(gpsmodel)
			{
				case BY_BASESTATION:
														EnterConfig(GPS_USART,CMD_BY_BaseStation);//���뱱��GPS��׼վ����
														break;
				case HX_BASESTATION:
														EnterConfig(GPS_USART,CMD_HX_BaseStation);//�����оGPS��׼վ����
														break;		
				default:
								break;
			}
										
	}	
	if	(mode == MOBILESTATION)
	{
			switch(gpsmodel)
			{
				case BY_MOBILESTATION:
														EnterConfig(GPS_USART,CMD_BY_MobileStation);			//���뱱��GPS�ƶ�վ����
														break;
				case HX10HZ_MOBILESTATION:
														EnterConfig(GPS_USART,CMD_HX10Hz_MobileStation);	//�����о10HzGPS�ƶ�վ����
														break;		
				case HX5HZ_MOBILESTATION:
														EnterConfig(GPS_USART,CMD_HX5Hz_MobileStation);		//�����о5HzGPS�ƶ�վ����
														break;	
				default:
								break;
			}		
	}
		
									
}
#endif

#endif
