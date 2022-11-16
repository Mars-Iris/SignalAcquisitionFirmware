#include <stdio.h>
#include <string.h>
#include	"./User/config.h"
#include 	"./User/includes.h"

#ifdef  STC12C5A60S2	
	#define	BUF_LENTH	32
#endif

#ifdef  STC15W4K48S4	
	
	#define	BUF_LENTH	512
	
	//#define	BUF_LENTH	512
	
	#define OBD_LENTH  (BASEBOARD_SIZE * 2 + 2)  //ĩβ����/n��2���ַ�
		
	code  u8 OBDHandbuffer[]="$ZBSJ,";
	
  xdata u8 OBDstrbuffer[OBD_LENTH];
	
	
#endif

code  u8 Handbuffer[]={0x55,0xaa,0xfe,0x7c};

xdata u8 BaseBoardBuffer[BASEBOARD_SIZE];//�������崫�����λ��������

xdata volatile u8 start = FALSE;//��ʼָ��


xdata	u8 Buffer[BUF_LENTH];	//���ջ���

u8 code CMD_start[]	=	{0x55,0xaa,0x00,0x00,0x11,0x11};//��ʼ�ɼ�ָ��
u8 code CMD_stop[]	=	{0x55,0xaa,0x00,0x00,0x00,0x00};//ֹͣ�ɼ�ָ��
u8 code CMD_writeflash[]	=	{0x55,0xaa,0x49,0x4f,0x58,0x47};//дflash
u8 code CMD_readflash[]		=	{0x55,0xaa,0x49,0x4f,0x44,0x51};//��flash
u8 code CMD_wflash_Ack[]	=	{0x58,0x47,0x43,0x47};					//дflashӦ��
u8 code CMD_rflash_Ack[]	=	{0x44,0x51,0x43,0x47};					//��flashӦ��

#ifdef  STC15W4K48S4
u8 code CMD_conf_gpssmobile[]	=	{0x55,0xAA,0x49,0x4F,0xff,0xff};			//����gps�ƶ�վ
u8 code CMD_conf_gpsbase[]		=	{0x55,0xAA,0x49,0x4F,0xff,0xfe};			//����GPS��׼վ
u8 code CMD_get_gpsbasepos[]	=	{0x55,0xAA,0x49,0x4F,0xff,0xfc};			//��ȡGPS��׼վ����
#endif

#ifdef  STC15W4K48S4
//========================================================================
// ����:void InsertBaseboardDstaUpload(u8 gps_usart,u8 upload_usart)
// ����: ������������(vtg���֮ǰ)���ϴ������ȡ����GPS���ݣ��Զ��ϴ�����������
// ������u8 gps_usartΪgps������Ĵ���,u8 upload_usart��λ��������Ĵ���
// �汾: V1.0, 2022-10-17
//========================================================================
static void InsertBaseboardData(u8 gps_usart,u8 upload_usart)
{
	 static u8 timeout = 0;//����5�ζ�ȡ����VTG���ݣ��Զ��ϴ�����������
	 static u8 vtg_flag = 0;//����5�ζ�ȡ����VTG���ݣ��Զ��ϴ�����������
	 xdata u8 *pvtg = NULL;
	 xdata u8 *pOut = (u8 *)Buffer;//ָ�����ݵĳ���
	 xdata u16 lenth = 0;
	 xdata u8 cutstr[] ="\n";
	 xdata u8 i = 0;
	
	
		if(vtg_flag == 0)//����vtgһ��������1��
		{
			  vtg_flag = 1;
			
				memset(BaseBoardBuffer,0,sizeof(BaseBoardBuffer));	//����������ݻ���
			  GetBaseBoardDataPack(BaseBoardBuffer,sizeof(BaseBoardBuffer));//��ȡ��������

				memset(OBDstrbuffer,0,sizeof(OBDstrbuffer));	//����������ݻ���
				HextoStr(BaseBoardBuffer,OBDstrbuffer,sizeof(BaseBoardBuffer));//����ת��	
		}

		memset(Buffer,0,sizeof(Buffer));	//��մ��ڽ��ջ���
		lenth = BSP_GetFormatRxBuffer(gps_usart,Buffer,sizeof(Buffer),cutstr,strlen(cutstr));//��ȡ�Ļ�������

		
		if (lenth > 0)  //���治Ϊ��
		{ 
			timeout = 0;//OBDģʽ
				
			pvtg = strstr((char *)pOut,"VTG");//�����ַ���
			
			while(pvtg != NULL)
			{
				pvtg = (u8 *)(pvtg - 3);//$GPVTG���ҵ�VTG����ǰ�ƶ�3���ַ���ָ��$����
		
				USART_Sendbuffer(upload_usart,(u8 *)pOut,(u16)(pvtg - pOut));//��VTGǰ��������ȷ�����
				
				vtg_flag = 0;//���������
				
				USART_Sendbuffer(upload_usart,OBDHandbuffer,sizeof(OBDHandbuffer)-1);//����������ͷ����
				
				USART_Sendbuffer(upload_usart,OBDstrbuffer,OBD_LENTH-1);//������������	
				
				pOut = pvtg;
				
				pvtg = pvtg + 6;//����vtg������һ��
				
				pvtg = strstr((char *)pvtg,"VTG");//�����ַ���//������һ������
		  }
			
			USART_Sendbuffer(upload_usart,(u8 *)pOut,(lenth-(u16)(pOut-Buffer)));//�ϴ�ʣ������

		}
		else
		{
			if(timeout >= 10)
			{
						
				 vtg_flag = 0;//���������
				
				//USART_Sendbuffer(upload_usart,Handbuffer,sizeof(Handbuffer));//���������ݶ����Ƹ�ʽ
				
				//USART_Sendbuffer(upload_usart,BaseBoardBuffer,sizeof(BaseBoardBuffer));//���������ݶ����Ƹ�ʽ
				
			  USART_Sendbuffer(upload_usart,OBDHandbuffer,sizeof(OBDHandbuffer)-1);//�����������ַ�����ʽ
				
				
				USART_Sendbuffer(upload_usart,OBDstrbuffer,OBD_LENTH-1);//�����������ַ�����ʽ
				
				
				delay_ms(100);//���100����
			}
			else
			{
				timeout++;
				delay_ms(100);//���100����
			}
			
		} 
}
#endif
//========================================================================
// ����:void SerialDataUpload(u8 upload_usart)
// ����: �ϴ���������
// ������u8 upload_usartΪ��������λ���Ĵ���
// �汾: V1.0, 2022-10-17
//========================================================================
void SerialDataUpload(u8 upload_usart)
{

	if(start == TURE)
	//if(start != TURE)
	{
		  
			#ifdef  STC12C5A60S2		
			memset(BaseBoardBuffer,0,sizeof(BaseBoardBuffer));	//����������ݻ���
			
			GetBaseBoardDataPack(BaseBoardBuffer,sizeof(BaseBoardBuffer));//��ȡ��������	
				
			USART_Sendbuffer(upload_usart,Handbuffer,sizeof(Handbuffer));//�ϴ�����������
						
			USART_Sendbuffer(upload_usart,BaseBoardBuffer,sizeof(BaseBoardBuffer));//�ϴ�����������
			#endif
		
			#ifdef  STC15W4K48S4		
			InsertBaseboardData(GPS_USART,upload_usart);//�������������ϴ�				
			#endif
		 
	}
}
#ifdef  STC15W4K48S4	


//========================================================================
// ����:void Serial_TiltSensor_Analy(u8 Tilt_usart,TiltSensorTypeDef *Tilt)
// ����: ������Ǵ���������
// ������u8 Tilt_usartΪ��Ǵ�����������֮��Ľӿ� TiltSensorTypeDef *Tilt���������ݱ�����ڴ��ַ
// ���أ����������ݷ���TURE�����򷵻�FALSE
// �汾: V1.0, 2022-10-17
//========================================================================
u8 Serial_TiltSensor_Analy(u8 Tilt_usart,TiltSensorTypeDef *Tilt)
{
   
	 xdata u8 *pOut =  NULL;//ָ�����ݵĳ���
	 xdata u16 lenth = 0;
	 xdata u8 cutstr[] ={0x55,0x53};
	 xdata u8 ret = FALSE;
	 xdata u8 i = 0;
	 xdata u8 j = 0;
		
	 memset(Buffer,0,sizeof(Buffer));	//��մ��ڽ��ջ���
	 
	 lenth = BSP_GetFormatRxBuffer(Tilt_usart,Buffer,sizeof(Buffer),cutstr,sizeof(cutstr));//��ȡ�Ļ�������	 

	 if(lenth > 0)
	 {
		pOut = ByteArrayCompar(Buffer,lenth,cutstr,sizeof(cutstr));//��ȡ��ͷ��λ��		
	 
		while(pOut != NULL)
		{
				//55 53 00 00 01 01 00 00 02 02 00 00 03 03 00 00 00 00 00 00 00 
				#if TILT_ALL_USART//���еĴ��������ܺ�ͳһ���������  
				{
					
					i= 0;
					j = 0;
					while(j<20)
					{
							Tilt->RollL = *(pOut + (i+2));			//X��Ƕȵ��ֽ�
						  Tilt->RollH = *(pOut + (i+3));			//X��Ƕȸ��ֽ�
							Tilt->PitchL = *(pOut + (i+4));			//Y��Ƕȵ��ֽ�
							Tilt->PitchH = *(pOut + (i+5));			//Y��Ƕȸ��ֽ�
						  Tilt->YawL = *(pOut + (j+14));				//Z��Ƕȵ��ֽ�
						  Tilt->YawH = *(pOut + (j+15));				//Z��Ƕȸ��ֽ�					
							Tilt->Roll	= (int)((Tilt->RollH << 8) 	| Tilt->RollL	)	/32768.0*1800;			//X��Ƕ�
							Tilt->Pitch = (int)((Tilt->PitchH << 8) | Tilt->PitchL)	/32768.0*1800;			//Y��Ƕ�
							Tilt->Yaw		= (int)((Tilt->YawH << 8) 	| Tilt->YawL)		/32768.0*1800;			//Z��Ƕ�

							if(Tilt->Roll>127) //�߽紦��
							{
								Tilt->Roll = 127;
							}
							else if(Tilt->Roll < -127) 
							{
								Tilt->Roll = -127;
							}
							if(Tilt->Pitch>127) //�߽紦��
							{
								Tilt->Pitch = 127;
							}
							else if(Tilt->Pitch < -127) 
							{
								Tilt->Pitch = -127;
							}		
							if(Tilt->Yaw>127) //�߽紦��
							{
								Tilt->Yaw = 127;
							}
							else if(Tilt->Yaw < -127) 
							{
							Tilt->Yaw = -127;
							}
						
							i = i+4;//��Э���ƶ�
							j = j+2;
							Tilt++;//�Ƶ���һ������
							
					}	
					ret = TURE;
				}
				#else   //55 53 01 02 02 02 01 01 00 00 00  
				{
						Tilt->RollL = *(pOut + 2);			//X��Ƕȵ��ֽ�
						Tilt->RollH = *(pOut + 3);			//X��Ƕȸ��ֽ�
						Tilt->PitchL = *(pOut + 4);			//Y��Ƕȵ��ֽ�
						Tilt->PitchH = *(pOut + 5);			//Y��Ƕȸ��ֽ�	
						Tilt->YawL = *(pOut + 6);				//Z��Ƕȵ��ֽ�
						Tilt->YawH = *(pOut + 7);				//Z��Ƕȸ��ֽ�
					
//					  printf("------------------------------------\r\n");
//						printf("Tilt->RollL = %b02d\r\n",	Tilt->RollL);
//						printf("Tilt->RollH = %b02d\r\n",	Tilt->RollH);
//						printf("Tilt->PitchL = %b02d\r\n",Tilt->PitchL);
//						printf("Tilt->PitchH = %b02d\r\n",Tilt->PitchH);
//						printf("Tilt->YawL = %b02d\r\n",	Tilt->YawL);
//						printf("Tilt->YawH = %b02d\r\n",	Tilt->YawH);
//					  printf("------------------------------------\r\n");
								
						Tilt->Roll	= (int)((Tilt->RollH << 8) 	| Tilt->RollL	)	/32768.0*1800;			//X��Ƕ�
						Tilt->Pitch = (int)((Tilt->PitchH << 8) | Tilt->PitchL)	/32768.0*1800;			//Y��Ƕ�
						Tilt->Yaw		= (int)((Tilt->YawH << 8) 	| Tilt->YawL)		/32768.0*1800;			//Z��Ƕ�
					
//						printf("Tilt->Roll = %h04d\r\n",	Tilt->Roll);
//						printf("Tilt->Pitch = %h04d\r\n",	Tilt->Pitch);
//						printf("Tilt->Yaw = %h04d\r\n",		Tilt->Yaw);
							
						if(Tilt->Roll > 127) //�߽紦��
						{
							Tilt->Roll = 127;
						}
						else if(Tilt->Roll < -127) 
						{
							Tilt->Roll = -127;
						}

						if(Tilt->Pitch > 127) //�߽紦��
						{
							Tilt->Pitch = 127;
						}
						else if(Tilt->Pitch < -127) 
						{
							Tilt->Pitch = -127;
						}		
						if(Tilt->Yaw > 127) //�߽紦��
						{
							Tilt->Yaw = 127;
						}
						else if(Tilt->Yaw < -127) 
						{
							Tilt->Yaw = -127;
						}	
						
					 ret = TURE;							
				
				}
				#endif
			 pOut = pOut +1;//ָ����ƣ�ȡ��һ������
						 
			 pOut = ByteArrayCompar(pOut,lenth,cutstr,sizeof(cutstr));//��ȡ��ͷ��λ��
						 
		}	
	}		
	 
	return ret; 
}

//========================================================================
// ����:HighSensorShock_Analy(u8 bump_usart,SignalLineTypeDef *pole)
// ����: ����ͨѶЭ��������˴�����������������,�������õ����ݱ��浽poleָ����ڴ���
// ������USRATx����ͨѶ�Ķ˿ںţ�SignalLineTypeDef *pole���˵���������ָ��
// ���أ���ȡ���������ݷ���TURE�����߷���FALSE
// �汾: V1.0, 2022-10-17
//========================================================================
u8 Serial_HighSensorShock_Analy(u8 bump_usart,SignalLineTypeDef *pole) //��ɭ�𶯴��������ݽ���
{
	 //$HS-MOTION,15,0000000000.0000100000*03
	 xdata u8 *phand = NULL;//ָ�����ݵĳ���
	 xdata u8 *pOut = NULL;//ָ�����ݵĳ���
	 xdata u8 *pEnd = NULL;
	 xdata u16 lenth = 0;
	 xdata u8 group_i = 0;//
	 xdata u16 temp = 0;//
	 xdata u8 ret = FALSE;
	 xdata u8 i = 0;
	 xdata u8 cutstr[] ="\n";


	 memset(Buffer,0,sizeof(Buffer));	//��մ��ڽ��ջ���

	 lenth = BSP_GetFormatRxBuffer(bump_usart,Buffer,sizeof(Buffer),cutstr,strlen(cutstr));//��ȡ�Ļ�������	
	
	  if (lenth > 0)  //���治Ϊ��
		{ 	
			
			phand = strstr((char *)Buffer,"$HS-MOTION");//�����ַ���
			
			//printf("phand = %p\r\n",phand);
			
			pEnd = strstr((char *)Buffer,cutstr);//���ҽ�������
			
			//printf("pEnd = %p\r\n",pEnd);
			
			while((phand != NULL) && (pEnd != NULL))
			{
				ret =TURE;//�Ѿ�����������
				
				//printf("BSP_GetFormatRxBuffer lenth = %h04d\r\n",lenth);
				
				phand = strstr((char *)phand,",");//���Ҷ���
				phand ++ ;
				phand = strstr((char *)phand,",");//���ҵڶ�������
				
				pOut = (u8 *)(phand +1);	//ָ������
				
				//printf("pOut = %p\r\n",pOut);
				
				for (group_i = 0; group_i < sizeof(pole->bump)/sizeof(pole->bump[0]);group_i++)
				{
					 // printf("group_i = %b02d\r\n",group_i);
					
						if(pole->bump[group_i].name != 0)					//������Ŀ�Ѿ�����
						{
							
							if( (pOut + pole->bump[group_i].count) > pEnd)					//���ݳ��Ȳ��Ϸ����˳�
							{

								//printf("pOut + pole->bump[group_i].count) > pEnd\r\n");
								break;
							}		
							
							pole->bump[group_i].value = 0;//���㣬���ڸ�ֵ
							
							for (i = 0; i< pole->bump[group_i].count; i++)//ȡ���������״̬
							{
				
								temp = (*pOut - '0');					//ȡ����״̬
								
								if (*pOut == '.')							
								{
									pOut++;			  							//����С����
									temp = (*pOut - '0');				//ȡ����״̬	
								}	
								pOut++;		
										
								temp = temp << i;
											
								pole->bump[group_i].value |= temp;//����������״̬��˳��д�뷵��ֵ
								
							}
							//printf("value = %h04d\r\n",pole->bump[group_i].value);
						}
						else
							{
								  //printf("pole->bump[group_i].name == 0\r\n");
									break;//�������δ���û�û�а�˳�����øò��������أ����ڽ�����������
							}		
				 }
				
				
				 
				phand = strstr((char *)pOut,"$HS-MOTION");//�����ַ���
				 
				//printf("phand = %p\r\n",phand);
				 
				pEnd = pEnd + 1;	//�����и�Ľ�����
				pEnd = strstr((char *)pEnd,cutstr);//�ٴβ��ҽ�������	
				 
				//printf("pEnd = %p\r\n",pEnd); 		 
	     
		  }
		}
		return ret;
		
}

//========================================================================
// ����:Serial_Sensor24GShock_Analy(u8 bump_usart,PengganTypeDef *pole)
// ����: ����ͨѶЭ��������˴�����������������,�������õ����ݱ��浽poleָ����ڴ���
// ������USRATx����ͨѶ�Ķ˿ںţ�PengganTypeDef *pole���˵���������ָ��
// ���أ���ȡ���������ݷ���TURE�����߷���FALSE
// �汾: V1.0, 2022-10-17
//========================================================================
void Serial_Sensor24GShock_Analy(u8 bump24g_usart,PengganTypeDef *pole) //2.4G�𶯴��������ݽ���
{
	 xdata u8 *pOut =  NULL;//ָ�����ݵĳ���
	 xdata u16 lenth = 0;
	 xdata u8 cutstr[] ={0x53};

	 memset(Buffer,0,sizeof(Buffer));	//��մ��ڽ��ջ���

	 lenth = BSP_GetFormatRxBuffer(bump24g_usart,Buffer,sizeof(Buffer),cutstr,sizeof(cutstr));//��ȡ�Ļ�������	

	  if (lenth > 0)  //���治Ϊ��
		{ 	
			pOut = ByteArrayCompar(Buffer,lenth,cutstr,sizeof(cutstr));//��ȡ��ͷ��λ��	
			
			while(pOut != NULL)
		  {
			 pole->name = *(pOut +2);		//��Ŀ����
			 pole->number = *(pOut +3);	//��Ŀ���
			 pole->value = *(pOut +4);	//�˺�
				
			 pOut = pOut +1;//ָ����ƣ�ȡ��һ������
				
			 pOut = ByteArrayCompar(pOut,lenth,cutstr,sizeof(cutstr));//��ȡ��ͷ��λ��
			}	
		}
		
}

#endif
//========================================================================
// ����:u8 Serial_Analy(u8 *RxBuffer)
// ����: ����ͨѶЭ�������������
// ������USRATx����ͨѶ�Ķ˿ںţ�RxBuffer���ݻ�����ָ��,lenthΪ���ݳ���
// ���أ������ɹ�������TURE.ʧ�ܷ��� FALSE
// �汾: V1.0, 2022-10-17
//========================================================================
u8 Serial_CMD_Analy(u8 USRATx,u8 *RxBuffer,u16 lenth)
{
	u8 *pfirst = NULL;  
	xdata	u16 flash_addr = 0;
	xdata	u8 flash_value = 0;
	xdata	u16 validlen = 0;
	
	//����ʼ�ɼ�ָ�� 55 AA 00 00 11 11
	pfirst = ByteArrayCompar(RxBuffer,lenth,CMD_start,sizeof(CMD_start));//�Ƚ�ָ��
	if (NULL != pfirst) //�յ���ʼ�ɼ�ָ��
	{
		#ifdef DEBUG
		printf("received data:55 AA 00 00 11 11\r\n");
		#endif
		Cmd_Start_Callback();
		start = TURE;
		#ifdef  STC15W4K48S4
		S1_USE_P16P17();//�л�����1��GPS����
		#endif
		return	TURE;
	}

	//����ֹͣ�ɼ�ָ�� 55 AA 00 00 00 00  
	pfirst = ByteArrayCompar(RxBuffer,lenth,CMD_stop,sizeof(CMD_stop));//�Ƚ�ָ��
	if (NULL != pfirst) //�յ���ʼ�ɼ�ָ��
	{
		#ifdef DEBUG
		printf("received data: 55 AA 00 00 00 00\r\n");
		#endif
		start = FALSE;
		return	TURE;
	}

	//����дflashָ�� 0x55 0xaa 0x49 0x4f 0x58 0x47
	pfirst = ByteArrayCompar(RxBuffer,lenth,CMD_writeflash,sizeof(CMD_writeflash));//�Ƚ�ָ��
	
	if (NULL != pfirst) //�յ�дflashָ��
	{
		start = FALSE;	//ֹͣ�ɼ�
		validlen = lenth - (pfirst - RxBuffer);//��ͷУ��ɹ��󣬼�����Ч���ݵĳ��ȡ�
		if(validlen < 10) //дflashָ����10���ֽڣ�����10���ֽڼ�������
		{
			return FALSE;
		}
		flash_addr = *(pfirst + 6);
		flash_addr = flash_addr<<8;
		flash_addr = flash_addr + *(pfirst + 7);

		flash_value = *(pfirst + 9);
		
		BSP_FlashWriteByte(flash_addr,flash_value);//д��flash
		
		USART_Sendbuffer(USRATx,CMD_wflash_Ack,sizeof(CMD_wflash_Ack));//Ӧ��

		return TURE;
	}
	
	//�����flashָ�� 0x55,0xaa,0x49,0x4f,0x44,0x51 
	pfirst = ByteArrayCompar(RxBuffer,lenth,CMD_readflash,sizeof(CMD_readflash));//�Ƚ�ָ��
	
	if (NULL != pfirst) //�յ���flashָ��
	{
		start = FALSE;//ֹͣ�ɼ������ź�
		
		validlen = lenth - (pfirst - RxBuffer);//��ͷУ��ɹ��󣬼�����Ч���ݵĳ��ȡ�		
		
		if(validlen < 10) //дflashָ����10���ֽڣ�����10���ֽڼ�������
		{
			return FALSE;//�������մ�������
		}
			
		flash_addr = *(pfirst + 6);
		flash_addr = flash_addr<<8;
		flash_addr = flash_addr + *(pfirst + 7);
		
		flash_value = IapReadByte(flash_addr);//����flash	
		
		USART_Sendbuffer(USRATx,CMD_rflash_Ack,sizeof(CMD_rflash_Ack));//Ӧ��
		
		USART_SendData(USRATx,flash_value);//���Ͷ�������ֵ
		
		return TURE;
	}
	#ifdef  STC15W4K48S4
	#if GPS_USART
	//����GPS�ƶ�վ���� 0x55 0xAA 0x49 0x4F 0xff 0xff
	pfirst = ByteArrayCompar(RxBuffer,lenth,CMD_conf_gpssmobile,sizeof(CMD_conf_gpssmobile));//�Ƚ�ָ��
	
	if (NULL != pfirst) //�յ�GPS�ƶ�վ����ָ��
	{
		start = FALSE;//ֹͣ�ɼ������ź�
		
		GPS_EnterConfiguration(MOBILESTATION);//����GPS��׼վ����
			
		return TURE;
	}
	
	//����GPS��׼վ���� 0x55 0xAA 0x49 0x4F 0xff 0xfe
	pfirst = ByteArrayCompar(RxBuffer,lenth,CMD_conf_gpsbase,sizeof(CMD_conf_gpsbase));//�Ƚ�ָ��
	
	if (NULL != pfirst) //�յ�GPS�ƶ�վ����ָ��
	{
		start = FALSE;//ֹͣ�ɼ������ź�
		
		GPS_EnterConfiguration(BASESTATION);//����GPS��׼վ����

		return TURE;
	}	
	
  //��ȡGPS��׼վ����ָ��0x55 0xAA 0x49 0x4F 0xff 0xfc
	pfirst = ByteArrayCompar(RxBuffer,lenth,CMD_get_gpsbasepos,sizeof(CMD_get_gpsbasepos));//�Ƚ�ָ��
	
	if (NULL != pfirst) //�յ�GPS�ƶ�վ����ָ��
	{
		start = FALSE;//ֹͣ�ɼ������ź�
		
		GetBaseStationPos();//��ȡ��׼վ����
			
		return TURE;
	}		
	#endif
	#endif
	return FALSE;
		
}


//========================================================================
// ����:void SerialHandle(u8 USARTx)
// ����: ���ڴ������
// ������USARTx�˿ں�
// �汾: V1.0, 2022-10-17
//========================================================================
void SerialHandle(u8 USARTx)
{

	xdata u16 lenth = 0;        
	memset(Buffer,0,sizeof(Buffer));//��������
	
	if(USARTx == UPLOAD_USART)
	{			
			lenth = BSP_GetUsartRxBuffer(USARTx,Buffer,sizeof(Buffer));//��ȡ��������		
			if (lenth > 0)
			{
				if(Serial_CMD_Analy(USARTx,Buffer,lenth) == TURE)
				{
					 BSP_ClearUsartRxBuffer(USARTx);	//�����ɹ�����մ��ڻ�������
					
				}
				
			}	
	}
		

}


