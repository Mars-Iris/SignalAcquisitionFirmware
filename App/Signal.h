#ifndef __SINGNAL_H
#define __SINGNAL_H	 


#define PLACE_Q_AXLE 0 			//ǰ��
#define PLACE_H_AXLE 1			//����
#define PLACE_G_AXLE 2 			//����
#define PLACE_MTC_AXLE 3		//Ħ�г�
#define PLACE_ALL_AXLE 4		//���е�


typedef struct 
{ 
	u8	RollL;					//X��Ƕȵ��ֽ�
	u8 	RollH;  				//X��Ƕȸ��ֽ�
	u8	PitchL;					//Y��Ƕȵ��ֽ�
	u8 	PitchH;  				//Y��Ƕȸ��ֽ�	
	u8	YawL;						//Z��Ƕȵ��ֽ�
	u8 	YawH;  					//Z��Ƕȸ��ֽ�	
	int Roll;						//��ת��
	int Pitch;  				//������
	int Yaw;  					//ƫ����
}TiltSensorTypeDef;   //��Ǵ�����



void GetFlashConfig(void);
void GetBaseBoardDataPack(u8 pDatabuf[], u16 lenth);
void GetTilt_Adjust_vaule(void); //��ȡ����Ħ�г���Ǵ�����У׼ֵ
#ifdef  STC15W4K48S4	



#endif


#endif

