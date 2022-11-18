#ifndef		__CONFIG_H
#define		__CONFIG_H

//-------------------------------���õ�Ƭ���ͺ�-----------------------------------//

//#define		STC12C5A60S2     

#define		STC15W4K48S4   

//----------------------------------ϵͳ����-------------------------------------//

//���ð�ţ���ϸ�����check.h
#define BOARD_NO   195 //����ʡǭ���ݳ�˳��У��Ŀ������	195 

//��Ƭ���̼��ţ�����ϻ���ʾ��
#define FIRMWARE_NUM 20 


//����ϵͳʱ��Ƶ�ʡ�
#define MAIN_Fosc		11059200L	

//У�鵥Ƭ�����к�,δ���岻У��
#define CHECKID 

//��������ͨѶ���ݳ���
#define BASEBOARD_SIZE	65


//��������λ�����ӵĴ��� 
#define UPLOAD_USART 				(pFlash->upload.com) 
#define UPLOAD_BAUDRATE			(pFlash->upload.bote)

//��������λ�����ӵĴ��� 
#define DEBUG_USART 				USART1
#define DEBUG_BAUDRATE  		115200L

//����̨printf��ӡ����Ĵ��ں�,�����
#define CONSOLE_USART				USART1			//��ѡUSART1��USART2��USART3��USART4 DISABLE
#define CONSOLE_BAUDRATE		115200L			//��ѡ2400L,4800L,9600L,19200L,38400L,115200L	
																				//������ڱ���ʼ����Ĺ��ܣ������ʿ��ܻᱻ����



//ʹ�õ���ģʽʱ������궨��
//#define DEBUG	

//-----------------------------STC15W4K48S4��������-------------------------------//
#ifdef  STC15W4K48S4

//���ض�Ӧ�������ļ�
#include "./STC/stc15w4k48s4.h"

//����
#define NETWORK_USART 			USART2
#define NETWORK_BAUDRATE  	115200L
#define NETWORK_STATE 			(pFlash->network.com)

//������GPS�忨���ӵĴ��� 
#define GPS_USART 					(pFlash->gps.com)
#define GPS_BAUDRATE      	(pFlash->upload.bote)

//�������ɭ���˴�����֮�����ӵĴ���
#define BUMP_HS_USART 			(pFlash->bump_hs.com)
#define BUMP_HS_BAUDRATE 		(pFlash->bump_hs.bote)

//������2.4G����ģ�飨���˴�������֮�����ӵĴ���
#define BUMP_24G_USART 			(pFlash->bump_24g.com)
#define BUMP_24G_BAUDRATE 	(pFlash->bump_24g.bote)

//�����루���ܺ����ӵĴ��ں�
#define TILT_ALL_USART 		  (pFlash->titl_all.com)
#define TILT_ALL_BAUDRATE 	(pFlash->titl_all.bote)

//�����복ǰ�����ӵĴ���
#define TILT_Q_USART 				(pFlash->titl_q.com)
#define TILT_Q_BAUDRATE 		(pFlash->titl_q.bote)

//�����복�������ӵĴ��ں�
#define TILT_H_USART 				(pFlash->titl_h.com)
#define TILT_H_BAUDRATE 		(pFlash->titl_h.bote)

//�����복�������ӵĴ��ں�
#define TILT_G_USART 				(pFlash->titl_g.com)
#define TILT_G_BAUDRATE			(pFlash->titl_g.bote)

//�������Ħ�г������ӵĴ���
#define TILT_MTC_USART 			(pFlash->titl_mtc.com)
#define TILT_MT_BAUDRATE 		(pFlash->titl_mtc.bote)

#endif

//-----------------------------STC12C5A60S2��������-------------------------------//
#ifdef  STC12C5A60S2

//���ض�Ӧ�������ļ�
#include "./STC/stc12c5a60s2.h"
	
#endif




#endif
