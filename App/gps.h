#ifndef	__GPS_H
#define	__GPS_H






#ifdef  STC15W4K48S4
#if GPS_USART
	#define GPS_CONFIG_USART USART1 //����GPS�Ĵ��ں�
	
	
	#define BY_BASESTATION 		1   		//���ƻ�׼վ
	#define HX_BASESTATION 		2  			//��о��׼վ
	
	
	#define BY_MOBILESTATION 			6   //�����ƶ�վ
	#define HX10HZ_MOBILESTATION 	7   //��о10Hz�ƶ�վ
	#define HX5HZ_MOBILESTATION 	8   //��о5Hz�ƶ�վ

	#define CMD_GPS_LENTH 50 //GPSָ��ȶ���Ϊ50���ַ�

	#define BASESTATION 1		 	//��׼վ
	#define MOBILESTATION 2 	//�ƶ�վ





void GPS_EnterConfiguration(u8 mode);	
void GetBaseStationPos(void);
#endif
#endif


#endif
