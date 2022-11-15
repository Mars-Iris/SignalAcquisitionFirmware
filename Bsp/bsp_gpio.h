#ifndef __BSP_GPIO_H
#define __BSP_GPIO_H	 
#include	"./User/config.h"




//���������ź�����ڱ��
#define D1 1   //��ת
#define D2 2   //��ת
#define D3 3   //�����
#define D4 4   //��ɲ
#define D5 5   //��ȫ��
#define D6 6   //����
#define D7 7   //������
#define D8 8   //����
#define D9 9   //�Ƴ�1
#define D10 10  //�Ƴ�2
#define D11 11  //���
#define D12 12  //Զ��
#define D13 13  //����
#define D14 14  //ʾ��
#define D15 15  //ɲ��
#define D16 16  //��ˢ
#define D17 17  //����Ӿ�
#define D18 18  //���
#define D19 19  //�ں��Ӿ�
#define D20 20  //����(ѹ��)
#define D21 21  //��λ_1
#define D22 22  //��λ_2
#define D23 23  //��λ_3
#define D24 24  //��λ_4
#define D25 25  //������
#define D26 26  //���
#define D27 27  //ת��
#define D28 28  //Կ�׿���
#define D29 29  //��ɲ��
#define D30 30  //�𶯴�����
#define D31 31  //����//��д����ʱ���á���λ������IO�ڡ�
#define D32 32  //�Ƴ�3��Ƭ����λ��
#define D33 33  //��ת���Ӳ�������ź�
#define D34 34  //��ת���Ӳ�������ź�
#define D35 35  //�۲��Ǳ���

typedef struct
{ 
	u8 pin;								//����ܽ�λ�� 
	u8 modle; 						//����ģʽ
	u8 rising_ed; 				//����������ʱ��
	u8 falling_ed; 				//�½�������ʱ��
	u8 type;              //����������������
	u8 times;      				//������������,��������flash��
	u8 stateflag;      		//���ڱ����ź������־,��������flash��
}SignalTypeDef;



typedef struct 
{ 
	u8 pin;								//����ܽ�λ�� 
	u8 min;               //������С�������
	u8 bs;                //��������Ŵ���
  u8 sampling_time;     //�������ʱ��
	u8 init_value;        //��ʼת�� 0=Ĭ��0��1=Ĭ��800
}PulseTypeDef;//����

typedef struct 
{ 
	u8 pin1;            	  //�ź�����ܽ�λ��
	u8 pin2;             		//�ź�����ܽ�λ��
	u8 pin3;             		//�ź�����ܽ�λ��
	u8 pin4;             		//�ź�����ܽ�λ��
	u8 pin5;             		//�ź�����ܽ�λ��
	u8 pin6;             		//�ź�����ܽ�λ��
	u8 modle; 							//����ģʽ
	u8 rising_ed; 					//����������ʱ��
	u8 falling_ed; 					//�½�������ʱ��
	u8 type;              	//����������
	u8 counts[6];      			//������������,��������flash��
	u8 times;      					//������������,��������flash��
	u8 stateflag;      			//���ڱ����ź������־,��������flash��,��bit
}MultSignalTypeDef;   		//ͬ���źţ��������//�磺�����ſ���


#ifdef  STC15W4K48S4

typedef struct
{ 
	u8 times[16];      		  //������������,��������flash��
	u16 stateflag;      		//���ڱ����ź������־,��������flash��
	
}PengGanSignalTypeDef;

typedef struct 
{ 
	u8 name;  		//����
	u8 number;  	//���
	u8 count;  		//����Ŀ��Ӧ�ĸ�����
	u8 type;  		//����Ŀ��Ӧ�ĸ�����
	u16 value;  	//״̬,����λ�ã�����

}PengganTypeDef;   //�𶯴�����




#endif

typedef struct 
{ 
	
	SignalTypeDef 			zytj;	  //���ο��أ����ڣ�
	SignalTypeDef 			ss;	  	//��ɲ����
	SignalTypeDef 			zz;	    //��ת����
	SignalTypeDef 			yz;	  	//��ת����
	SignalTypeDef 			yg;	  	//Զ�⿪��
	SignalTypeDef 			jg;	  	//���⿪��
	SignalTypeDef 			lh;	    //��Ͽ���
	SignalTypeDef 			js;	  	//��ɲ����
	
	SignalTypeDef 			xh;	  	//Ϩ�𿪹�
	SignalTypeDef 			qd;	    //��������
	SignalTypeDef 			aqd;	  //��ȫ������
	SignalTypeDef 			xd;	  	//С�ƿ���
	SignalTypeDef 			lb;	  	//���ȿ���
	SignalTypeDef 			cm;	    //���ſ���
//	SignalTypeDef 			dw1;	  //��λ1����
//	SignalTypeDef 			dw2;	  //��λ2����
//	
//	SignalTypeDef 			dw3;	  //��λ3����
//	SignalTypeDef 			dw4;	  //��λ4����
	SignalTypeDef 			zhs;	  //����ӿ���
	SignalTypeDef 			nhs;	  //�ں��ӿ���
	SignalTypeDef 			fsc;	  //��ɲ����
	SignalTypeDef 			wd;	    //��ƿ���
	SignalTypeDef 			ys;	  	//��ˢ����
	SignalTypeDef 			dcd;	  //�����ƿ���
	
	SignalTypeDef 			ysm;	  //Կ���ſ���
//	SignalTypeDef 			rc1;	  //�Ƴ�����1
//	SignalTypeDef 			rc2;	  //�Ƴ�����2
//	SignalTypeDef 			rc3;	  //�Ƴ�����3
	SignalTypeDef 			cd;	  	//��������
	SignalTypeDef 			zyyl;	  //���ο��أ�ѹ����
	PulseTypeDef				zs;	  	//ת��
	SignalTypeDef 			lc;	  	//���
	
	//SignalTypeDef 			zzxd_yj;//��ת���Ӳ������
	//SignalTypeDef 			yzxd_yj;//��ת���Ӳ������
	
	SignalTypeDef 			gcybp;		//�۲��Ǳ���
	
	MultSignalTypeDef		dw;				//��λ
	MultSignalTypeDef		rc;				//�Ƴ�
	
	MultSignalTypeDef		dbq;			//�������ź���
	
#ifdef  STC15W4K48S4
	SignalTypeDef 			tk;	  	//Ħ�г�ͷ��
	SignalTypeDef 			zbs;	  //Ħ�г������
	SignalTypeDef 			ybs;	  //Ħ�г��Ұ���
	SignalTypeDef 			zjtb;	  //Ħ�г����̤��
	SignalTypeDef 			yjtb;	  //Ħ�г��ҽ�̤��
	SignalTypeDef 			pgjs;	  //���˽���
	
	PengganTypeDef     	bump[4];   //������Ŀ

#endif

	


	
}SignalLineTypeDef;//�������е��ź���




//Ϩ���ź����еķ�ʽ
#define SWITCHING 0  //����������ģʽ
#define SPEED 1      //ת������ģʽ
#define SWITCHING_AND_SPEED 2  //��������ת������
#define SWITCHING_OR_SPEED 3  //��������ת������

//�Ƴ�����

#define RCPIN1 1			//�Ƴ������ź���1
#define RCPIN2 2			//�Ƴ������ź���2
#define RCPIN3 3			//�Ƴ������ź���3

#define PRESS 70  		 //���¿���
#define NOPRESS 20     //û�а���

//��λ������

#define DWPIN1 1  		//��λ�ź���1
#define DWPIN2 2      //��λ�ź���2
#define DWPIN3 3  		//��λ�ź���3
#define DWPIN4 4      //��λ�ź���4

#define GEAR1 1  			//1��
#define GEAR2 2       //2��
#define GEAR3 3  			//3��
#define GEAR4 4       //4��
#define GEAR5 5  			//5��
#define GEARR 8       //R��

//��λ����������
#define MAGNETIC	0  	//�Ŵ�����
#define ANGLE 		1   //��Ǵ�����

//�����Ŵ�����
#define LEFT_FRONT_WHEEL		1  //��ǰ�ִ�����
#define LEFT_REAR_WHEEL			2	 //����ִ�����
#define RIGHT_FRONT_WHEEL 	3	 //��ǰ�ִ�����
#define RIGHT_REAR_WHEEL 		4  //�Һ��ִ�����
#define LEFT_MIDDLE_WHEEL 	5  //��ҳ�������
#define RIGHT_MIDDLE_WHEEL 	6	 //�ҹҳ�������

void BSP_GPIO_Init(void);
void BSP_ZhuansuCount_Init(void);
u8 BSP_ReadInputDataBit(SignalTypeDef *pSignal);
u8 BSP_ReadMultipleDataBit(MultSignalTypeDef *pSignal,u8 pin);

#ifdef  STC15W4K48S4
u8 BSP_ReadBumpDataBit(SignalTypeDef *pSignal,u8 group,u8 value,u8 offset);
#endif

#endif

