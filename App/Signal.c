#include	"./User/includes.h"
#include	"./User/config.h"
#include	<stdio.h>
#include	<string.h>

xdata SignalLineTypeDef SignalLine; 

#ifdef  STC15W4K48S4	

xdata PengganTypeDef 				pilepole = {0};//׮��
xdata TiltSensorTypeDef     Tilt[4]={0};//��Ǵ�����
xdata TiltAdjustTypeDef     mtc = {0};

#endif


//========================================================================
// ����: u8 zuozhuanxiangdeng(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ��ת����ź�,�翪��˫��������FLASE
// ������pSignalLine
// ����: ������ת����TURE���ر���ת����FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 zuozhuanxiangdeng(SignalLineTypeDef *pSignalLine)  //��ת��� D1
{
	xdata u8 zz_pin = BSP_ReadInputDataBit(&pSignalLine->zz);//��ȡ����״̬
	xdata u8 yz_pin = BSP_ReadInputDataBit(&pSignalLine->yz);//��ȡ����״̬
	
	if(zz_pin == TURE && yz_pin == FALSE)
			return TURE;
	else 
			return FALSE;
}
//========================================================================
// ����: u8 youzhuanxiangdeng(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ��ת����ź�,�翪��˫��������FLASE
// ������pSignalLine
// ����: ������ת����TURE���ر���ת����FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 youzhuanxiangdeng(SignalLineTypeDef *pSignalLine)  //��ת��� D2
{
	
	xdata u8 zz_pin = BSP_ReadInputDataBit(&pSignalLine->zz);//��ȡ����״̬
	xdata u8 yz_pin = BSP_ReadInputDataBit(&pSignalLine->yz);//��ȡ����״̬
	
	if(zz_pin == FALSE && yz_pin == TURE)
			return TURE;
	else 
			return FALSE;
	
}
//========================================================================
// ����: u8 xihuo(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ����Ϩ��״̬,���������źţ��ų�֮ǰ������������źš�
//  		 ��ʹ�ÿ��������򷢶���ת������Ϩ��     
// ������pSignalLine
// ����: �����ų�����TURE������Ϩ�𷵻�FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 xihuo(SignalLineTypeDef *pSignalLine)  //Ϩ�� D3
{
	static u8 qidong_flag = FALSE;
	static u8 zhaoche_flag = FALSE;
	xdata u8 qd_pin		=	BSP_ReadInputDataBit(&pSignalLine->qd);//��ȡ����״̬
	xdata u8 xh_pin 	= BSP_ReadInputDataBit(&pSignalLine->xh);//��ȡ����״̬
	xdata u8 xh_type	=	pSignalLine->xh.type;
	
	if(qd_pin == TURE)
			qidong_flag = TURE;//���������ź�

		switch(xh_type)	
		{
			case SWITCHING://����������ģʽ(���������ź�)
											if((xh_pin == TURE) && (qidong_flag == TURE)) 
											{
												qidong_flag	=	FALSE;//��������źű�־Ϊ
												zhaoche_flag = TURE;//�����Ѿ��ų���
												return TURE;        //
											}
											else if((xh_pin == TURE) && (zhaoche_flag == TURE))
											{	
												return TURE;
											}
											else 
											{
												zhaoche_flag = FALSE;
												return FALSE;
											}
			case SPEED://ת������ģʽ
											return FALSE;
			case SWITCHING_AND_SPEED://��������ת������
											return FALSE;
			case SWITCHING_OR_SPEED://��������ת������
											return FALSE;
			default:
											return FALSE;	
		}
}
//========================================================================
// ����: u8 shousha(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ��ɲ�ź�
// ������pSignalLine��
// ����: ����ɲ����TURE������ɲ����FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 shousha(SignalLineTypeDef *pSignalLine)  //��ɲD4
{
	
	u8 ss_pin = BSP_ReadInputDataBit(&pSignalLine->ss);//��ȡ����״̬
	
	return ss_pin;	
	
}
//========================================================================
// ����: u8 anquandai(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ��ȫ���ź�
// ������pSignalLine��
// ����: ϵ�ϰ�ȫ������TURE���ɿ���ȫ������FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 anquandai(SignalLineTypeDef *pSignalLine)  //��ȫ��D5
{
	
	u8 aqd_pin = BSP_ReadInputDataBit(&pSignalLine->aqd);//��ȡ����״̬
	#ifdef DEBUG1
				printf("aqd_pin = %b02d\r\n",aqd_pin);
	#endif	
	
	return aqd_pin;	
	
}
//========================================================================
// ����: u8 chenmen_zq(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ�����ź�,��ǰ����ǰ������Һ��ĸ��ţ�
// ������pSignalLine��
// ����: �򿪳��ŷ���FLASE���رճ��ŷ���0xF0,����Ϊ����λ
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 chemen(SignalLineTypeDef *pSignalLine)  		//����D6
{
	
	u8 cm_pin = BSP_ReadInputDataBit(&pSignalLine->cm);//��ȡ����״̬
	
	if(cm_pin == TURE)
		return 0xF0;	//����Ϊ����λ
	else 
		return FALSE;
	
}
//========================================================================
// ����: u8 daochedeng(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ�������ź�
// ������pSignalLine��
// ����: �ҵ�������TURE�����ڵ�������FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 daochedeng(SignalLineTypeDef *pSignalLine)  //������ D7
{
	
	u8 dcd_pin = BSP_ReadInputDataBit(&pSignalLine->dcd);//��ȡ����״̬
	
	return dcd_pin;	
	
}
//========================================================================
// ����: u8 laba(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ�����ź�
// ������pSignalLine��
// ����: �����ȷ���TURE���ɿ����ȷ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 laba(SignalLineTypeDef *pSignalLine)  //����  D8
{
	
	u8 lb_pin = BSP_ReadInputDataBit(&pSignalLine->lb);//��ȡ����״̬
	
	return lb_pin;	
	
}
//========================================================================
// ����: u8 raoche1(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ�Ƴ�����1�ź�
// ������pSignalLine��
// ����: �����ط���PRESS���ɿ����ط���NOPRESS
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 raoche1(SignalLineTypeDef *pSignalLine)  //�Ƴ�1   D9
{

	u8 rc_pin1 = BSP_ReadMultipleDataBit(&pSignalLine->rc,RCPIN1);//��ȡ����״̬
	
	(rc_pin1 == TURE)? (rc_pin1 = PRESS):(rc_pin1 = NOPRESS);//����Э�鸳ֵ
	
	return rc_pin1;	
	
}
//========================================================================
// ����: u8 raoche1(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ�Ƴ�����2�ź�
// ������pSignalLine��
// ����: �����ط���PRESS���ɿ����ط���NOPRESS
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 raoche2(SignalLineTypeDef *pSignalLine)  //�Ƴ�2   D10
{
	
	u8 rc_pin2 = BSP_ReadMultipleDataBit(&pSignalLine->rc,RCPIN2);//��ȡ����״̬
	
	(rc_pin2 == TURE)? (rc_pin2 = PRESS):(rc_pin2 = NOPRESS);//����Э�鸳ֵ
	
	return rc_pin2;	
	
}
//========================================================================
// ����: u8 wudeng(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ��ƿ���2�ź�
// ������pSignalLine��
// ����: ����Ʒ���TURE���ر���Ʒ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 wudeng(SignalLineTypeDef *pSignalLine)  //��� D11
{
	
	u8 wd_pin = BSP_ReadInputDataBit(&pSignalLine->wd);//��ȡ����״̬
	
	return wd_pin;	
	
}
//========================================================================
// ����: u8 yuanguang(SignalLineTypeDef *pSignalLine)
// ����: ��ȡԶ�⿪���ź�
// ������pSignalLine��
// ����: ��Զ��Ʒ���TURE���ر�Զ��Ʒ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 yuanguang(SignalLineTypeDef *pSignalLine)  //Զ�� D12
{
	
	u8 yg_pin = BSP_ReadInputDataBit(&pSignalLine->yg);//��ȡ����״̬
	
	return yg_pin;	
	
}
//========================================================================
// ����: u8 jinguang(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ���⿪���ź�
// ������pSignalLine��
// ����: ������Ʒ���TURE���رս���Ʒ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 jinguang(SignalLineTypeDef *pSignalLine)  //���� D13
{
	
	u8 jg_pin = BSP_ReadInputDataBit(&pSignalLine->jg);//��ȡ����״̬
	
	return jg_pin;	
	
}
//========================================================================
// ����: u8 xiaodeng(SignalLineTypeDef *pSignalLine)
// ����: ��ȡС�ƿ����ź�
// ������pSignalLine��
// ����: ��С�Ʒ���TURE���ر�С�Ʒ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 xiaodeng(SignalLineTypeDef *pSignalLine)  //С�� D14
{
	
	u8 xd_pin = BSP_ReadInputDataBit(&pSignalLine->xd);//��ȡ����״̬
	
	return xd_pin;	
	
}
//========================================================================
// ����: u8 jiaosha(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ��ɲ�ź�
// ������pSignalLine��
// ����: �Ƚ�ɲ����TURE���ɿ���ɲ����FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 jiaosha(SignalLineTypeDef *pSignalLine)  //��ɲ D15
{
	
	u8 js_pin = BSP_ReadInputDataBit(&pSignalLine->js);//��ȡ����״̬
	
	return js_pin;	
	
}
//========================================================================
// ����: u8 yushua(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ��ˢ���ź�
// ������pSignalLine��
// ����: ����ˢ������TURE���ر���ˢ������FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 yushua(SignalLineTypeDef *pSignalLine)  //��ˢ D16
{
	
	u8 ys_pin = BSP_ReadInputDataBit(&pSignalLine->ys);//��ȡ����״̬
	
	return ys_pin;	
	
}
//========================================================================
// ����: u8 zuohoushi(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ��������Ӿ��ź�
// ������pSignalLine��
// ����: ��������Ӿ�����TURE��δ���ڷ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 zuohoushi(SignalLineTypeDef *pSignalLine)  //����� D17
{
	
	u8 zhs_pin = BSP_ReadInputDataBit(&pSignalLine->zhs);//��ȡ����״̬
	
	return zhs_pin;	
	
}
//========================================================================
// ����: u8 qidong(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ���������ź�
// ������pSignalLine��
// ����: �������ʱ����TURE���ɿ�����Կ�׷���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 qidong(SignalLineTypeDef *pSignalLine)  //�������� D18
{
	
	u8 qd_pin = BSP_ReadInputDataBit(&pSignalLine->qd);//��ȡ����״̬
	
	return qd_pin;	
	
}
//========================================================================
// ����: u8 neihoushi(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ�����ں��Ӿ��ź�
// ������pSignalLine��
// ����: �����ں��Ӿ�����TURE��δ���ڷ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 neihoushi(SignalLineTypeDef *pSignalLine)  //�ں��� D19
{
	
	xdata u8 nhs_pin = BSP_ReadInputDataBit(&pSignalLine->nhs);//��ȡ����״̬
	
	return nhs_pin;	
	
}
//========================================================================
// ����: u8 zuoyitiaojie(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ���������ź�
// ������pSignalLine��
// ����: �������η���TURE��δ���ڷ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 zuoyitiaojie(SignalLineTypeDef *pSignalLine)  //���ε��ڿ��� D20
{
	
	u8 zytj_pin = BSP_ReadInputDataBit(&pSignalLine->zytj);//��ȡ����״̬
	
	return zytj_pin;	
	
}
//========================================================================
// ����: u8 dangwei(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ��λ�źţ������������дŸк�����������͡�
// ������pSignalLine��
// ����: 	GEAR1		 1��
//				GEAR2    2��
//				GEAR3    3��
//				GEAR4    4��
//				GEAR5    5��
//				GEARR    R��
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 dangwei(SignalLineTypeDef *pSignalLine)  //��λD21--D24
{
	xdata u8 temp = 0;
	xdata u8 dw_pin1 = BSP_ReadMultipleDataBit(&pSignalLine->dw,DWPIN1);//��ȡ����״̬D21
	xdata u8 dw_pin2 = BSP_ReadMultipleDataBit(&pSignalLine->dw,DWPIN2);//��ȡ����״̬D22
	xdata u8 dw_pin3 = BSP_ReadMultipleDataBit(&pSignalLine->dw,DWPIN3);//��ȡ����״̬D23
	xdata u8 dw_pin4 = BSP_ReadMultipleDataBit(&pSignalLine->dw,DWPIN4);//��ȡ����״̬D24
	xdata u8 dw_type = pSignalLine->dw.type;//��ȡ����������
	
	switch(dw_type)
	{
		case	MAGNETIC://�Ŵ�����
										temp = (dw_pin1<<0 | dw_pin2<<1 |	dw_pin3<<2 | dw_pin4<<3);
										if(temp == 0x01)
											return	GEAR1;
										else if(temp == 0x02)
											return	GEAR2;
										else if(temp == 0x04)
											return	GEAR3;
										else if(temp == 0x08)
											return	GEAR4;
										else if(temp == 0x05)
											return	GEAR5;
										else if(temp == 0x0F)
											return	GEARR;
										else 
											return	FALSE;
		case	ANGLE://�Ŵ�����
										temp = (dw_pin1<<0 | dw_pin2<<1 |	dw_pin3<<2);
										if(temp == 0x06)
											return	GEAR1;
										else if(temp ==  0x05)
											return	GEAR2;
										else if(temp ==  0x04)
											return	GEAR3;
										else if(temp ==  0x03)
											return	GEAR4;
										else if(temp ==  0x02)
											return	GEAR5;
										else if(temp ==  0x01)
											return	GEARR;
										else 
											return	FALSE;
		default:
			
					return	FALSE;				
	}

	
}
//========================================================================
// ����: u8 zuoyiyali(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ���Σ�ѹ�����ź�
// ������pSignalLine��
// ����: ������ѹ������TURE��û��ѹ������FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 zuoyiyali(SignalLineTypeDef *pSignalLine)  ///���Σ�ѹ���� D25
{
	
	xdata u8 zyyl_pin = BSP_ReadInputDataBit(&pSignalLine->zyyl);//��ȡ����״̬
	
	return zyyl_pin;	
	
}
//========================================================================
// ����: u8 lihe(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ������ź�
// ������pSignalLine��
// ����: �������������TURE��̧�����������FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 lihe(SignalLineTypeDef *pSignalLine)   //��� D26
{
	
	u8 lh_pin = BSP_ReadInputDataBit(&pSignalLine->lh);//��ȡ����״̬
	
	return lh_pin;	
	
}
//========================================================================
// ����: u8 yaoshimen(SignalLineTypeDef *pSignalLine)
// ����: ��ȡԿ�����ź�
// ������pSignalLine��
// ����: ��Կ���ſ��ط���TURE���ر�Կ���ſ��ط���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 yaoshimen(SignalLineTypeDef *pSignalLine)   //Կ���ſ��� D28
{
	
	u8 ysm_pin = BSP_ReadInputDataBit(&pSignalLine->ysm);//��ȡ����״̬
	
	return ysm_pin;	
	
}
//========================================================================
// ����: u8 fushache(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ��ɲ�ź�
// ������pSignalLine��
// ����: ���¸�ɲ������TURE��̧��ɲ������FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 fushache(SignalLineTypeDef *pSignalLine)   //��ɲ�� D29
{
	
	u8 fsc_pin = BSP_ReadInputDataBit(&pSignalLine->fsc);//��ȡ����״̬
	
	return fsc_pin;	
	
}
//========================================================================
// ����: u8 chuangdong(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ��ʱ�����ź�
// ������pSignalLine��
// ����: ���ߴ�������TURE��ƽ�ȷ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 chuangdong(SignalLineTypeDef *pSignalLine)   //���������� D30
{
	
	u8 cd_pin = BSP_ReadInputDataBit(&pSignalLine->cd);//��ȡ����״̬
	
	return cd_pin;	
	
}
//========================================================================
// ����: u8 raoche3(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ�Ƴ�3�ź�
// ������pSignalLine��
// ����: ���·���TURE��δ����FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 raoche3(SignalLineTypeDef *pSignalLine)   //�Ƴ�3  D31
{
	
	u8 rc_pin3 = BSP_ReadMultipleDataBit(&pSignalLine->rc,RCPIN3);//��ȡ����״̬
	
	(rc_pin3 == TURE)? (rc_pin3 = PRESS):(rc_pin3 = NOPRESS);//����Э�鸳ֵ
	
	return rc_pin3;	
	
}
//========================================================================
// ����: u8 shijing(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ˫���ź�
// ������pSignalLine��
// ����: ��˫������TURE���ر�˫������FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 shijing(SignalLineTypeDef *pSignalLine)   //ʾ������
{
	
	u8 zz_pin = BSP_ReadInputDataBit(&pSignalLine->zz);//��ȡ����״̬
	u8 yz_pin = BSP_ReadInputDataBit(&pSignalLine->yz);//��ȡ����״̬
	
	if(zz_pin == TURE && yz_pin == TURE)
			return TURE;
	else 
			return FALSE;
	
}
//========================================================================
// ����: u8 kongdang(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ�յ��ź�
// ������pSignalLine��
// ����: �յ�����TURE���ǿյ�����FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 kongdang(SignalLineTypeDef *pSignalLine)   //�յ�
{
	
	if(dangwei(pSignalLine) != FALSE)
			return TURE;
	else 
			return FALSE;
	
}
//========================================================================
// ����: u8 guanchayibiao(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ�۲��Ǳ����ź�
// ������pSignalLine��
// ����: �۲췵��TURE��û�й۲췵��FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 guanchayibiao(SignalLineTypeDef *pSignalLine)   //�۲��Ǳ���
{
	
	u8 gcybp_pin = BSP_ReadInputDataBit(&pSignalLine->gcybp);//��ȡ����״̬
	
	return gcybp_pin;	
	
}
//========================================================================
// ����: u8 DBQ_LeftFront(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ�����Ŵ�������ǰ���ź�
// ������pSignalLine��
// ����: �����Ϸ���TURE�������Ϸ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 DBQ_LeftFront(SignalLineTypeDef *pSignalLine)    //��������ǰ��״̬
{
  u8 dbq_pin1 = BSP_ReadMultipleDataBit(&pSignalLine->dbq,LEFT_FRONT_WHEEL);//��ȡ����״̬
	
	return dbq_pin1;

}
//========================================================================
// ����: u8 DBQ_LeftRear(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ�����Ŵ�����������ź�
// ������pSignalLine��
// ����: �����Ϸ���TURE�������Ϸ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 DBQ_LeftRear(SignalLineTypeDef *pSignalLine)    //�����������״̬
{
  u8 dbq_pin2 = BSP_ReadMultipleDataBit(&pSignalLine->dbq,LEFT_REAR_WHEEL);//��ȡ����״̬
	
	return dbq_pin2;

}
//========================================================================
// ����: u8 DBQ_LeftRear(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ�����Ŵ�������ǰ���ź�
// ������pSignalLine��
// ����: �����Ϸ���TURE�������Ϸ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 DBQ_RightFront(SignalLineTypeDef *pSignalLine)    //��������ǰ��״̬
{
  u8 dbq_pin3 = BSP_ReadMultipleDataBit(&pSignalLine->dbq,RIGHT_FRONT_WHEEL);//��ȡ����״̬
	
	return dbq_pin3;

}
//========================================================================
// ����: u8 DBQ_RightRear(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ�����Ŵ������Һ����ź�
// ������pSignalLine��
// ����: �����Ϸ���TURE�������Ϸ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 DBQ_RightRear(SignalLineTypeDef *pSignalLine)    //�������Һ���״̬
{
  u8 dbq_pin4 = BSP_ReadMultipleDataBit(&pSignalLine->dbq,RIGHT_REAR_WHEEL);//��ȡ����״̬
	
	return dbq_pin4;

}
//========================================================================
// ����: u8 DBQ_LeftMiddle(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ�����Ŵ�������ҳ����ź�
// ������pSignalLine��
// ����: �����Ϸ���TURE�������Ϸ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 DBQ_LeftMiddle(SignalLineTypeDef *pSignalLine)    //��������ҳ���״̬
{
  u8 dbq_pin5 = BSP_ReadMultipleDataBit(&pSignalLine->dbq,LEFT_MIDDLE_WHEEL);//��ȡ����״̬
	
	return dbq_pin5;

}
//========================================================================
// ����: u8 DBQ_RightMiddle(SignalLineTypeDef *pSignalLine)
// ����: ��ȡ�����Ŵ������ҹҳ����ź�
// ������pSignalLine��
// ����: �����Ϸ���TURE�������Ϸ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 DBQ_RightMiddle(SignalLineTypeDef *pSignalLine)    //�������ҹҳ���״̬
{
  u8 dbq_pin6 = BSP_ReadMultipleDataBit(&pSignalLine->dbq,RIGHT_MIDDLE_WHEEL);//��ȡ����״̬
	
	return dbq_pin6;

}
//========================================================================
// ����: u8 zhuansucount(SignalLineTypeDef *pSignalLine)
// ����: ��ȡת�ٵ��������ֵ
// ������pSignalLine��
// ����: �����Ϸ���TURE�������Ϸ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u16 zhuansucount(SignalLineTypeDef *pSignalLine)    //�������
{
	static u8 times = 0;//�����ȴ�������ʱ�䣩
	static u16 count = 0;//��ȡת�ٳ�ֵ
	
	if(times == pSignalLine->zs.sampling_time)//�������ʱ��
	{
		times = 0;
		count = TH0;
		count = count<<8;	
		count = count + TL0;		
		TH0 = 0;//����
		TL0 = 0;//����	
		if ((count == 0) && (pSignalLine->zs.init_value == 1))
		{
			count = 800;	//��������Ҫ��
		}
	}
	else
	{
		times++;
	}
	return count;

}
#ifdef  STC15W4K48S4

//========================================================================
// ����: u8 toukui(SignalLineTypeDef *pSignalLine)
// ����: ��ȡĦ�г�ͷ��״̬
// ������pSignalLine��
// ����: ���Ϸ���TURE��ȡ�·���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 toukui(SignalLineTypeDef *pSignalLine)    //Ħ�г�ͷ��
{
  u8 tk_pin = BSP_ReadInputDataBit(&pSignalLine->tk);//��ȡ����״̬
	
	return tk_pin;

}
//========================================================================
// ����: u8 zuobashou(SignalLineTypeDef *pSignalLine)
// ����: ��ȡĦ�г������״̬
// ������pSignalLine��
// ����: ��ס����TURE���뿪����FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 zuobashou(SignalLineTypeDef *pSignalLine)    //Ħ�г������
{
  u8 zbs_pin = BSP_ReadInputDataBit(&pSignalLine->zbs);//��ȡ����״̬
	
	return zbs_pin;

}
//========================================================================
// ����: u8 youbashou(SignalLineTypeDef *pSignalLine)
// ����: ��ȡĦ�г��Ұ���״̬
// ������pSignalLine��
// ����: ��ס����TURE���뿪����FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 youbashou(SignalLineTypeDef *pSignalLine)    //Ħ�г��Ұ���
{
  u8 ybs_pin = BSP_ReadInputDataBit(&pSignalLine->ybs);//��ȡ����״̬
	
	return ybs_pin;

}
//========================================================================
// ����: u8 zuojiaotaban(SignalLineTypeDef *pSignalLine)
// ����: ��ȡĦ�г��Ұ���״̬
// ������pSignalLine��
// ����: ��ס����TURE���뿪����FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 zuojiaotaban(SignalLineTypeDef *pSignalLine)    //Ħ�г����̤��
{
  u8 zjtb_pin = BSP_ReadInputDataBit(&pSignalLine->zjtb);//��ȡ����״̬
	
	return zjtb_pin;

}
//========================================================================
// ����: u8 youtaban(SignalLineTypeDef *pSignalLine)
// ����: ��ȡĦ�г��Ұ���״̬
// ������pSignalLine��
// ����: ��ס����TURE���뿪����FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 youjiaotaban(SignalLineTypeDef *pSignalLine)    //Ħ�г��ҽ�̤��
{
  u8 yjtb_pin = BSP_ReadInputDataBit(&pSignalLine->yjtb);//��ȡ����״̬
	
	return yjtb_pin;

}

//========================================================================
// ����: u8 GetHSShockSensor_value(u8 bump_usart,SignalLineTypeDef *pole)
// ����: �ɼ���ɭ���˴�����������
// ������bump_usart������������֮��Ĵ��ںţ�SignalLineTypeDef���ݽṹ
// ����: 
// �汾: V1.0, 2022-10-17
//========================================================================
static void GetHSShockSensor_value(u8 bump_usart,SignalLineTypeDef *pole)    //�õ���ɭ���˴�������ֵ
{
  xdata u8 group_i = 0;//
	xdata u8 temp = 0;//
	xdata u16 value = 0;//
	xdata u8 valuebit = 0;//
	xdata u8 i = 0;
	static u8 gor_i = 0;
	static u8 pos_i = 0;
	
	if(bump_usart == DISABLE) //Ӳ������δ��ʼ��
	{
		return;
	}
	
	pilepole.name   = 0;	//�ϴ�����״̬	����
	pilepole.number = 0;	//�ϴ�����״̬	����		
	pilepole.value  = 0;	//�ϴ�����λ��	����
	
	if (Serial_HighSensorShock_Analy(bump_usart,pole) == TURE)//��ȡ����������
	{
	
				for (group_i = 0; group_i < sizeof(pole->bump)/sizeof(pole->bump[0]);group_i++)
				{
					
					if(pole->bump[group_i].name == 0) 
					{
						break;//flash����δ�������˽�����Ŀ
					}
					value  =	 pole->bump[group_i].value;//ȡ����״̬
					
					//printf("value = %h04X\r\n",value);
					
					for (i = 0 ; i< pole->bump[group_i].count;i++)
					{		
						valuebit  = (u16)(value >> i) & (0x0001);//ȡ������λ
						
						temp = BSP_ReadBumpDataBit(&pole->pgjs,group_i,valuebit,i);//��������
						
						if( temp == 0 )
						{
						  pole->bump[group_i].value &= ~(1<< i);//��������������
						}
						else 
						  pole->bump[group_i].value |= (1<< i);//��������������
					}
					//printf("pole->bump[group_i].value = %h04X\r\n",pole->bump[group_i].value);
					
					
				}
				//������Ҫ��ѯ����״̬��������Ҫ�ڶ��α�����������Ҫ��¼������λ��
				for ( ;gor_i < sizeof(pole->bump)/sizeof(pole->bump[0]);gor_i++)
				{
					
					if(pole->bump[gor_i].name == 0) 
					{
						gor_i = 0;
						
						break;//flash����δ�������˽�����Ŀ
					}
					
					value  =	pole->bump[gor_i].value;//ȡ����״̬
					
					//printf("penggan.value = %h04X\r\n",value);
					
					for (;pos_i< pole->bump[gor_i].count;pos_i++)
					{
						
						valuebit = (u8)(value >> pos_i) & (0x0001);//ȡ������λ
						
						if(valuebit == 1)//���������ź�
						{
								pilepole.name   = pole->bump[gor_i].name;			//�ϴ�����״̬	
								pilepole.number = pole->bump[gor_i].number;	  //�ϴ�����״̬			
								pilepole.value  = pos_i+1;	//�ϴ�����λ��
								pos_i++;//����ѭ������
							 
							 //printf("penggan.value = %h04X\r\n",value);
							 //printf("pilepole.name = %b02d\r\n",pilepole.name);
							 //printf("pilepole.number = %b02d\r\n",pilepole.number);
							 //printf("pilepole.value = %h04d\r\n",pilepole.value);
							 //printf("\r\n");
							
								return;
						}
					}
					pos_i = 0;
					
				}
				gor_i = 0;
	}	
}

//========================================================================
// ����: u8 Get24GShockSensor_value(u8 Tilt_usart)
// ����: ��ȡ2.4���˴�������ֵ
// ������u8 bump_usart��2.4Gģ��������֮�����ӵĴ��ں�
// ����: 
// �汾: V1.0, 2022-10-17
//========================================================================
static void Get24GShockSensor_value(u8 bump_usart)    //�õ�2.4G�������˴�������ֵ
{

	if(bump_usart != DISABLE)
	{
				//memset(&Tilt,0,sizeof(Tilt));//�������
				pilepole.name   = 0;	//�ϴ�����״̬	����
				pilepole.number = 0;	//�ϴ�����״̬	����		
				pilepole.value  = 0;	//�ϴ�����λ��	����
				Serial_Sensor24GShock_Analy(bump_usart,&pilepole);
	}
}

//========================================================================
// ����: u8 GetTiltSensor_value(u8 Tilt_usart,TiltSensorTypeDef *pTilt)
// ����: ��ȡ��Ǵ�������ֵ
// ������u8 Tilt_usart��������������֮�����ӵĴ��ںţ� pTiltָ�����ݱ����ָ��
// ����: 
// �汾: V1.0, 2022-10-17
//========================================================================
static void GetTiltSensor_value(u8 Tilt_usart,TiltSensorTypeDef *pTilt)    //��Ǵ�������ֵ
{

	#if TILT_ALL_USART //ȫ����ȡ
			Serial_TiltSensor_Analy(Tilt_usart,pTilt);
	
//		 printf("------------------------------------------\r\n");
//		 printf("Tilt[PLACE_Q_AXLE].Roll = %h04d\r\n",	  Tilt[PLACE_Q_AXLE].Roll);
//		 printf("Tilt[PLACE_Q_AXLE].Pitch = %h04d\r\n",		Tilt[PLACE_Q_AXLE].Pitch);
//		 printf("Tilt[PLACE_Q_AXLE].Yaw = %h04d\r\n",			Tilt[PLACE_Q_AXLE].Yaw);
//		 printf("------------------------------------------\r\n");
	#else
	if(Tilt_usart != DISABLE)//������ȡ
	{
		 //memset(pTilt,0,sizeof(Tilt[0]));//����
		 if (Serial_TiltSensor_Analy(Tilt_usart,pTilt) == TURE)//������ȡ
		 {
			 if(Tilt_usart == TILT_MTC_USART) //����Ƕ���Ħ�г�
			 {
	 
					(char)pTilt->RollL -= mtc.Adjust_XL;  	//�õ�X���ֵ���ֽ�	
					(char)pTilt->RollH -= mtc.Adjust_XH;  	//�õ�X���ֵ���ֽ�	
					(char)pTilt->PitchL -= mtc.Adjust_YL;  //�õ�Y���ֵ���ֽ�		
					(char)pTilt->PitchH -= mtc.Adjust_YH;  //�õ�Y���ֵ���ֽ�	
				 
//					printf("pTilt->RollL = %b02d\r\n",	pTilt->RollL);
//					printf("pTilt->RollH = %b02d\r\n",	pTilt->RollH);
//					printf("pTilt->PitchL = %b02d\r\n",	pTilt->PitchL);
//					printf("pTilt->PitchH = %b02d\r\n",	pTilt->PitchH);	
//					printf("\r\n");				 
			 }
		 }		 
	}
	#endif
}

//========================================================================
// ����: void GetTilt_Adjust_vaule(u8 Tilt_usart,u8 *TiltSensorTypeDef pTilt) //��ȡĦ�г���Ǵ�����У׼ֵ
// ����: ��ȡ��Ǵ������Ļ�׼ֵ
// ������u8 Tilt_usart��������������֮�����ӵĴ��ںţ�pTiltָ�����ݱ����ָ��
// ����: 
// �汾: V1.0, 2022-10-17
//========================================================================
static void  GetTilt_Adjust_vaule(u8 Tilt_usart,TiltSensorTypeDef *pTilt) //��ȡĦ�г���Ǵ�����У׼ֵ
{
	if(Tilt_usart != DISABLE)
	{
		GetTiltSensor_value(Tilt_usart,pTilt);//��ȡ��׼ֵ
		mtc.Adjust_XL = pTilt->RollL;					//X��Ƕȵ��ֽ�	
		mtc.Adjust_XH = pTilt->RollH;  				//X��Ƕȸ��ֽ�
		mtc.Adjust_YL = pTilt->PitchL;					//Y��Ƕȵ��ֽ�
		mtc.Adjust_YH = pTilt->PitchH;  				//Y��Ƕȸ��ֽ�	
		
//		printf("mtc.Adjust_XL = %b02d\r\n",	mtc.Adjust_XL);
//		printf("mtc.Adjust_XH = %b02d\r\n",	mtc.Adjust_XH);
//		printf("mtc.Adjust_YL = %b02d\r\n",mtc.Adjust_YL);
//		printf("mtc.Adjust_YH = %b02d\r\n",mtc.Adjust_YH);	
	}
}
#endif
//========================================================================
// ����: void Cmd_Start_Callback(void)
// ����: �����յ�55 aa 00 00 11 11 �����ô˺���
// �汾: V1.0, 2022-10-17
//========================================================================
void Cmd_Start_Callback(void)
{
	USART_ClearMsgQueueRxBuffer(UPLOAD_USART);
	
	BSP_ClearUsartRxBuffer(UPLOAD_USART);//
	
	SignalLine_Init();//��ȡ���µ������ļ�
	
#ifdef  STC15W4K48S4
	USART_ClearMsgQueueRxBuffer(TILT_MTC_USART);//�����ڻ���
	
	BSP_ClearUsartRxBuffer(TILT_MTC_USART);//
	
	delay_ms(200);//��ʱ300�����ȡ��׼ֵ
	
	GetTilt_Adjust_vaule(TILT_MTC_USART,&Tilt[PLACE_MTC_AXLE]);//��ȡ������Ħ�г��������Ļ�׼ֵ
	
#endif
}

//========================================================================
// ����: void SignalLine_Init(void)
// ����: ��ʼ���źŵ����ã�����˿�δ���ã���Ĭ�϶˿ڽ���
// ��������
// �汾: V1.0, 2022-10-17
//========================================================================
void SignalLine_Init(void)
{
	  xdata SignalLineTypeDef *pSignalLine = &SignalLine;
	
	  BSP_GetFlashConfig(pSignalLine);	//��ȡ���ò���
	
	  if(pSignalLine->zz.pin == 0)			pSignalLine->zz.pin 	= D1;		//��ת,Ĭ�϶˿�ΪD1
		if(pSignalLine->yz.pin == 0)			pSignalLine->yz.pin 	= D2;		//��ת,Ĭ�϶˿�ΪD2
		if(pSignalLine->xh.pin == 0)			pSignalLine->xh.pin 	= D3;		//�����,Ĭ�϶˿�ΪD3
		if(pSignalLine->ss.pin == 0)			pSignalLine->ss.pin 	= D4;		//��ɲ,Ĭ�϶˿�ΪD4
		if(pSignalLine->aqd.pin == 0)			pSignalLine->aqd.pin 	= D5;		//��ȫ��,Ĭ�϶˿�ΪD5	
		if(pSignalLine->cm.pin == 0)			pSignalLine->cm.pin 	= D6;		//����,Ĭ�϶˿�ΪD6
		if(pSignalLine->dcd.pin == 0)			pSignalLine->dcd.pin 	= D7;		//������,Ĭ�϶˿�ΪD7
		if(pSignalLine->lb.pin == 0)			pSignalLine->lb.pin 	= D8;		//����,Ĭ�϶˿�ΪD8
	
		if(pSignalLine->rc.pin1 == 0)			pSignalLine->rc.pin1 	= D9;		//�Ƴ�1,Ĭ�϶˿�ΪD9
		if(pSignalLine->rc.pin2 == 0)			pSignalLine->rc.pin2 	= D10;	//�Ƴ�2,Ĭ�϶˿�ΪD10
		if(pSignalLine->wd.pin == 0)			pSignalLine->wd.pin 	= D11;	//���,Ĭ�϶˿�ΪD11
		if(pSignalLine->yg.pin == 0)			pSignalLine->yg.pin 	= D12;	//Զ��,Ĭ�϶˿�ΪD12
		if(pSignalLine->jg.pin == 0)			pSignalLine->jg.pin 	= D13;	//����,Ĭ�϶˿�ΪD13	
		if(pSignalLine->xd.pin == 0)			pSignalLine->xd.pin 	= D14;	//С��,Ĭ�϶˿�ΪD14
		if(pSignalLine->js.pin == 0)			pSignalLine->js.pin 	= D15;	//��ɲ,Ĭ�϶˿�ΪD15
		if(pSignalLine->ys.pin == 0)			pSignalLine->ys.pin 	= D16;	//��ˢ,Ĭ�϶˿�ΪD16
	
		if(pSignalLine->zhs.pin == 0)			pSignalLine->zhs.pin 	= D17;	//����Ӿ�,Ĭ�϶˿�ΪD17
		if(pSignalLine->qd.pin == 0)			pSignalLine->qd.pin 	= D18;	//����,Ĭ�϶˿�ΪD18
		if(pSignalLine->nhs.pin == 0)			pSignalLine->nhs.pin 	= D19;	//�ں��Ӿ�,Ĭ�϶˿�ΪD19
		if(pSignalLine->zyyl.pin == 0)		pSignalLine->zyyl.pin = D20;	//Զ����(ѹ��,Ĭ�϶˿�ΪD20
		if(pSignalLine->dw.pin1 == 0)			pSignalLine->dw.pin1 	= D21;	//��λ1,Ĭ�϶˿�ΪD21	
		if(pSignalLine->dw.pin2 == 0)			pSignalLine->dw.pin2	= D22;	//��λ2,Ĭ�϶˿�ΪD22
		if(pSignalLine->dw.pin3 == 0)			pSignalLine->dw.pin3 	= D23;	//��λ3,Ĭ�϶˿�ΪD23
		if(pSignalLine->dw.pin4 == 0)			pSignalLine->dw.pin4 	= D24;	//��λ4,Ĭ�϶˿�ΪD24
		
		if(pSignalLine->zytj.pin == 0)		pSignalLine->zytj.pin = D25;	//������,Ĭ�϶˿�ΪD25
		if(pSignalLine->lh.pin == 0)			pSignalLine->lh.pin 	= D26;	//���,Ĭ�϶˿�ΪD26
		if(pSignalLine->zs.pin == 0)			pSignalLine->zs.pin 	= D27;	//ת��,Ĭ�϶˿�ΪD27
		if(pSignalLine->ysm.pin == 0)			pSignalLine->ysm.pin 	= D28;	//Կ�׿���,Ĭ�϶˿�ΪD28
		if(pSignalLine->fsc.pin == 0)			pSignalLine->fsc.pin 	= D29;	//��ɲ��,Ĭ�϶˿�ΪD29	
		if(pSignalLine->cd.pin == 0)			pSignalLine->cd.pin		= D30;	//����������,Ĭ�϶˿�ΪD30
		//if(pSignalLine->dw3.pin == 0)		pSignalLine->dw3.pin 	= D31;	//����,Ĭ�϶˿�ΪD31
		if(pSignalLine->rc.pin3 == 0)			pSignalLine->rc.pin3 	= D32;	//�Ƴ�3,Ĭ�϶˿�ΪD32
		
	#ifdef  STC15W4K48S4	
		if(pSignalLine->tk.pin == 0)			pSignalLine->tk.pin 	= D5;		//��ȫ��,Ĭ�϶˿�ΪD5			//Ħ�г�ͷ��
		if(pSignalLine->zbs.pin == 0)			pSignalLine->zbs.pin 	= D17;	//����Ӿ�,Ĭ�϶˿�ΪD17		//Ħ�г������
		if(pSignalLine->ybs.pin == 0)			pSignalLine->ybs.pin	= D19;	//�ں��Ӿ�,Ĭ�϶˿�ΪD19		//Ħ�г��Ұ���
		if(pSignalLine->zjtb.pin == 0)		pSignalLine->zjtb.pin = D6;		//����,Ĭ�϶˿�ΪD6				//Ħ�г����̤��
		if(pSignalLine->yjtb.pin == 0)		pSignalLine->yjtb.pin = D16;	//��ˢ,Ĭ�϶˿�ΪD16				//Ħ�г��ҽ�̤��
	#endif
		

		
}
//========================================================================
// ����: void GetDataPack(u8 *pData��u16 lenth)
// ����: ��ȡ����ͨѶЭ��Ĵ������.
// ����: pDataָ�򷢸����ڵ���������,lenth��Ҫ��ȡ�����ݳ���.
// ����: ��.
// �汾: V1.0, 2022-10-17
//========================================================================
void GetBaseBoardDataPack(u8 pDatabuf[], u16 lenth)
{
			
			static xdata u8 count=0;
	
#ifdef  STC15W4K48S4		
	
	    GetHSShockSensor_value(HS_BUMP_USART,&SignalLine);//������������
	    Get24GShockSensor_value(BUMP_24G_USART);//������������
			GetTiltSensor_value(TILT_Q_USART,&Tilt[PLACE_Q_AXLE]);//�ɼ�ǰ������
			GetTiltSensor_value(TILT_H_USART,&Tilt[PLACE_H_AXLE]);//�ɼ���������
			GetTiltSensor_value(TILT_G_USART,&Tilt[PLACE_G_AXLE]);//�ɼ���������
		  GetTiltSensor_value(TILT_MTC_USART,&Tilt[PLACE_MTC_AXLE]);	//�ɼ�����Ħ�г��������
		  GetTiltSensor_value(TILT_ALL_USART,Tilt);	//�ɼ����ܺ���������

#endif
	
			pDatabuf[0] |= (jiaosha(&SignalLine) << 0);		 					//��ɱ
			pDatabuf[0]	|=	(lihe(&SignalLine) << 1); 							//�����				
			pDatabuf[0]	|=	(jinguang(&SignalLine) << 2);						//�����
			pDatabuf[0]	|=	(yuanguang(&SignalLine) << 3);					//Զ���	
			pDatabuf[0]	|=	(youzhuanxiangdeng(&SignalLine) << 4);	//��ת��			
			pDatabuf[0]	|=	(zuozhuanxiangdeng(&SignalLine) << 5);	//��ת��
    	pDatabuf[0]	|=	(shousha(&SignalLine)<<6);							//��ɲ
      pDatabuf[0]	|=	(zuoyitiaojie(&SignalLine)<<7);					//����
			
			pDatabuf[1]	|=	(laba(&SignalLine) << 0);				//����
			pDatabuf[1]	|=	(daochedeng(&SignalLine) << 2);	//�����ƿ���		
			pDatabuf[1]	|=	(xiaodeng(&SignalLine) << 3);		//С��
			pDatabuf[1]	|=	(shijing(&SignalLine) << 4);		//˫��
			pDatabuf[1]	|=	(anquandai(&SignalLine) << 5);	//��ȫ������    
			pDatabuf[1]	|=	(qidong(&SignalLine) << 6);			//��������
			pDatabuf[1]	|=	(xihuo(&SignalLine) << 7);			//������ת��
	
			pDatabuf[2]	|=	chemen(&SignalLine);		//����
			pDatabuf[2]	|=	dangwei(&SignalLine);		//��λ

			pDatabuf[3]	=	0;			//����
			pDatabuf[4]	|=	(u8)zhuansucount(&SignalLine);			//������ת�ٵͰ�λ   
			pDatabuf[5]	|=	(u8)zhuansucount(&SignalLine)>>8;		//������ת�ٸ߰�λ
			
			pDatabuf[6] |=	(kongdang(&SignalLine) << 0);		//�յ�
			pDatabuf[6]	|=	(zuoyiyali(&SignalLine) << 3);	//���ο���
			
			pDatabuf[7]	|=	(yushua(&SignalLine) << 0);			//��ˢ
			pDatabuf[7]	|=	(wudeng(&SignalLine) << 1);			//���
			pDatabuf[7]	|=	(neihoushi(&SignalLine) << 2);	//�ں���
			pDatabuf[7]	|=	(zuohoushi(&SignalLine) << 3);	//������
			pDatabuf[7]	|=	(jinguang(&SignalLine) << 4);		//���
			pDatabuf[7]	|=	(yuanguang(&SignalLine) << 4);	//���
			pDatabuf[7]	|=	(fushache(&SignalLine) << 5);		//��ɲ
			pDatabuf[7]	|=	(qidong(&SignalLine) << 6);			//����
			//pDatabuf[8]=0;			//���̵�״̬
			//pDatabuf[9]=0;			//�쳣״̬

			pDatabuf[10]	=	raoche1(&SignalLine);	//��ǰ�Ƴ�
			pDatabuf[11]	=	raoche2(&SignalLine);	//����Ƴ�
			pDatabuf[12]	=	raoche1(&SignalLine);	//��ǰ�Ƴ�
			pDatabuf[13]	=	raoche3(&SignalLine);	//�Һ��Ƴ�

			//pDatabuf[14]	=	0;			//��̼�����λ//������0
			//pDatabuf[15]	=	0;			//��̼�����λ//������0
			
			//*pDatabuf[16]	=	0;			//����
			pDatabuf[17]	=	(u8)BOARD_NO >> 8;	//��Ÿ�λ
			pDatabuf[18]	=	(u8)BOARD_NO;				//��ŵ�λ
			
			pDatabuf[19]	=	0;			//����ǰ����೬�����������Ե���ľ��루��λ���ף�
			pDatabuf[20]	=	0;			//����ǰ���Ҳ೬�����������Ե���ľ��루��λ���ף�
			pDatabuf[21]	=	0;			//����������೬�����������Ե���ľ��루��λ���ף�
			pDatabuf[22]	=	0;			//���������Ҳ೬�����������Ե���ľ��루��λ���ף�
			pDatabuf[23]	=	0;			//ǣ����������೬�����������Ե���ľ��루��λ���ף�
			pDatabuf[24]	=	0;			//ǣ���������Ҳ೬�����������Ե���ľ��루��λ���ף�
			
			pDatabuf[25]	=	0;				//ѵ��Ȧ��������λ
			pDatabuf[26]	=	0;				//ѵ��Ȧ��������λ
			
			pDatabuf[27]	=	0;				//���ٸ�λ
			pDatabuf[28]	=	0;				//���ٵ�λ
			pDatabuf[29]	=	0;				//���ADֵ
			pDatabuf[30]	=	0;				//����ADֵ
			
			pDatabuf[31]		|=	(yaoshimen(&SignalLine) << 0); 			//Կ�׿���
			pDatabuf[31]		|=	(chuangdong(&SignalLine) << 1);			//��������
			
#ifdef  STC15W4K48S4	
			pDatabuf[31]		|=	(toukui(&SignalLine) << 2); 			//ͷ����1=���ϣ�//Ħ�г�
			pDatabuf[31]		|=	(zuobashou(&SignalLine) << 3);		//����֣�1=���ϣ�//Ħ�г�
			pDatabuf[31]		|=	(youbashou(&SignalLine) << 4);		//�Ұ��֣�1=���ϣ�//Ħ�г�
			pDatabuf[31]		|=	(zuojiaotaban(&SignalLine) << 5);			//��̤�壨1=���ϣ�//Ħ�г�
			pDatabuf[31]		|=	(youjiaotaban(&SignalLine) << 6);			//��̤�壨1=���ϣ�//Ħ�г�
#endif
			//*pDatabuf[31]		|=	(youmentaban(&SignalLine) << 7);	//1=����̤�� 
			
			
			pDatabuf[32]		=	FIRMWARE_NUM;			//���ص�Ƭ���̼���
			//*pDatabuf[33]		=	0;							//������ת��

			pDatabuf[34]		|=	(DBQ_LeftFront(&SignalLine)<<7);    //��������ǰ���ź�    ��1=�������ϣ�0=�����ϣ�
			pDatabuf[34]		|=	(DBQ_LeftRear(&SignalLine)<<6);     //������������ź�    ��1=�������ϣ�0=�����ϣ�
			pDatabuf[34]		|=	(DBQ_RightFront(&SignalLine)<<5);   //��������ǰ���ź�    ��1=�������ϣ�0=�����ϣ�
			pDatabuf[34]		|=	(DBQ_RightRear(&SignalLine)<<4);    //�������Һ����ź�    ��1=�������ϣ�0=�����ϣ�
			pDatabuf[34]		|=	(DBQ_LeftMiddle(&SignalLine)<<3);   //��������ҳ����ź�  ��1=�������ϣ�0=�����ϣ�
			pDatabuf[34]		|=	(DBQ_RightMiddle(&SignalLine)<<2);  //�������ҹҳ����ź�  ��1=�������ϣ�0=�����ϣ�
			//*pDatabuf[34]		|=	((gaosujingshi()&0x01)<<1);  		//1=���پ�ʾ��־
			//*pDatabuf[34]		|=	((gaosuanquan()&0x01)<<0);  		//1=���ٰ�ȫ����//�������ʹ��
#ifdef  STC15W4K48S4	
			
			pDatabuf[35]			=		pilepole.name;				//��Ŀ����--01׮����02�޿��ţ�03ǣ����׮����04�����ϰ���05������
			pDatabuf[36]			=		pilepole.number;			//��Ŀ���01��02��03....
			pDatabuf[37]			=		(u8)pilepole.value;		//����λ��01��02��03��04��05��06...��00=�����ˣ�
	
			//*pDatabuf[38]		=	0;		//�ӽ�����
			//*pDatabuf[39]		=	0;		//�ƴ�Ѷ������״̬��41���ںϳɣ�4F�ϳ���ϣ�00����״̬	
			pDatabuf[40]			=	(char)Tilt[PLACE_Q_AXLE].Pitch;	//�����ų�ǰY�����ݣ�[�з���char]��ȡС�����һλ��*10���ϴ���
			pDatabuf[41]			=	(char)Tilt[PLACE_H_AXLE].Pitch;	//�����ų���Y�����ݣ�[�з���char]��ȡС�����һλ��*10���ϴ���
			pDatabuf[42]			=	(char)Tilt[PLACE_G_AXLE].Pitch;	//�����ų���Y�����ݣ�[�з���char]��ȡС�����һλ��*10���ϴ���
			pDatabuf[43]			=	(char)Tilt[PLACE_MTC_AXLE].RollL;		//������Ħ�У�����Y��ԭʼ����-��λ ������ǣ�����Ϊ�����ҵ���ߣ�������
			pDatabuf[44]			=	(char)Tilt[PLACE_MTC_AXLE].RollH;		//������Ħ�У�����Y��ԭʼ����-��λ
			pDatabuf[45]			=	(char)Tilt[PLACE_MTC_AXLE].PitchL;		// (����Ħ�У�����X��ԭʼ����-��λ �������ǣ���Ϊ����
			pDatabuf[46]			=	(char)Tilt[PLACE_MTC_AXLE].PitchH;		//������Ħ�У�����X��ԭʼ����-��λ
#endif			
			pDatabuf[47]			=		ID_LENTH;	//�������к��ֽ����������Ժ�����ϵ��������
			pDatabuf[48]		=		localid[0];
			pDatabuf[49]		=		localid[1];
			pDatabuf[50]		=		localid[2];
			pDatabuf[51]		=		localid[3];
			pDatabuf[52]		=		localid[4];
			pDatabuf[53]		=		localid[5];
			pDatabuf[54]		=		localid[6];

			pDatabuf[55]		|=	(guanchayibiao(&SignalLine) << 0);//�۲��Ǳ���
			
			pDatabuf[lenth-2]		=	count++;    //���ݱ�ǩΪ���ݳ��ȵĵ����ڶ�λ,ÿ������1	
			
			Checksum(pDatabuf,lenth);//����У���			
}	





