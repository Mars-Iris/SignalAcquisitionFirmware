#ifndef		__CONFIG_H
#define		__CONFIG_H

//-------------------------------���õ�Ƭ���ͺ�-----------------------------------//

//#define		STC12C5A60S2     

#define		STC15W4K48S4   

//----------------------------------ϵͳ����-------------------------------------//

//���ð�ţ���ϸ�����check.h
#define BOARD_NO   GZ_QNZ_CS_KM2 //����ʡǭ���ݳ�˳��У��Ŀ������			195 

//��Ƭ���̼��ţ�����ϻ���ʾ��
#define FIRMWARE_NUM 20 

//����ϵͳʱ��Ƶ�ʡ�
#define MAIN_Fosc		11059200L	

//У�鵥Ƭ�����к�,δ���岻У��
#define CHECKID 

//��������ͨѶ���ݳ���
#define BASEBOARD_SIZE	65

//������������λ�����ӵĴ���
#define UPLOAD_USART				USART1			//��ѡUSART1��USART2��USART3��USART4	

#define UPLOAD_BAUDRATE			115200L			//��ѡ2400L,4800L,9600L,19200L,38400L,115200L

//����̨printf��ӡ����Ĵ��ں�
#define CONSOLE_USART				DISABLE			//��ѡUSART1��USART2��USART3��USART4 DISABLE

#define CONSOLE_BAUDRATE		115200L			//��ѡ2400L,4800L,9600L,19200L,38400L,115200L	
																				//������ڱ���ʼ����Ĺ��ܣ������ʿ��ܻᱻ����

//ʹ�õ���ģʽʱ������궨��
//#define DEBUG	

//-----------------------------STC15W4K48S4��������-------------------------------//
#ifdef  STC15W4K48S4

//���ض�Ӧ�������ļ�
#include "./STC/stc15w4k48s4.h"
	
//����GPS�忨���������ӵĴ��ں�
#define GPS_USART						DISABLE			//��ѡUSART1��USART2��USART3��USART4,DISABLE	

#define GPS_BAUDRATE				DISABLE			//��ѡ2400L,4800L,9600L,19200L,38400L,115200L����ֵ�������Զ�����Ϊ38400

//���ø�ɭ���˴�����������֮�����ӵĴ��ں�
#define HS_BUMP_USART				DISABLE			//��ѡUSART1��USART2��USART3��USART4,DISABLE

#define HS_BUMP_BAUDRATE		115200L			//��ѡ2400L,4800L,9600L,19200L,38400L,115200L

//����2.4G����ģ�飨���˴�������������֮�����ӵĴ���
#define BUMP_24G_USART			DISABLE			//��ѡUSART1��USART2��USART3��USART4,DISABLE

#define BUMP_24G_BAUDRATE		115200L			//��ѡ2400L,4800L,9600L,19200L,38400L,115200L

 //������Ǵ�����������֮�����ӵĴ��ں�
#define TILT_Q_USART				DISABLE			//��ѡUSART1��USART2��USART3��USART4,DISABLE,��ǰ�����������ӵĴ��ں�	
#define TILT_H_USART				DISABLE			//��ѡUSART1��USART2��USART3��USART4,DISABLE,���������������ӵĴ��ں�
#define TILT_G_USART				DISABLE			//��ѡUSART1��USART2��USART3��USART4,DISABLE,���������������ӵĴ��ں�
#define TILT_MTC_USART			DISABLE			//��ѡUSART1��USART2��USART3��USART4,DISABLE,����Ħ�г����������ӵĴ��ں�
#define TILT_ALL_USART			DISABLE			//��ѡUSART1��USART2��USART3��USART4,DISABLE,�����ܺ����������ӵĴ��ں�

#define TILT_BAUDRATE				115200L			//��ѡ2400L,4800L,9600L,19200L,38400L,115200L

	
#endif

//-----------------------------STC12C5A60S2��������-------------------------------//
#ifdef  STC12C5A60S2

//���ض�Ӧ�������ļ�
#include "./STC/stc12c5a60s2.h"
	

	
#endif

























#endif
