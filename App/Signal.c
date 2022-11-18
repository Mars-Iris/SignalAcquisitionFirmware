#include	"./User/includes.h"
#include	"./User/config.h"
#include	<stdio.h>
#include	<string.h>

#ifdef  STC15W4K48S4	

xdata PengganTypeDef 				pilepole = {0};//׮��
xdata TiltSensorTypeDef     Tilt[4]={0};//��Ǵ�����
xdata TiltAdjustTypeDef     mtc = {0};

#endif


//========================================================================
// ����: u8 zuozhuanxiangdeng(FlashParameterTypeDef *pFlash)
// ����: ��ȡ��ת����ź�,�翪��˫��������FLASE
// ������pFlash
// ����: ������ת����TURE���ر���ת����FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 zuozhuanxiangdeng(void)  //��ת��� D1
{
	xdata u8 zz_pin = BSP_ReadInputDataBit(&pFlash->zz);//��ȡ����״̬
	xdata u8 yz_pin = BSP_ReadInputDataBit(&pFlash->yz);//��ȡ����״̬
	
	if(zz_pin == TURE && yz_pin == FALSE)
			return TURE;
	else 
			return FALSE;
}
//========================================================================
// ����: u8 youzhuanxiangdeng(void)
// ����: ��ȡ��ת����ź�,�翪��˫��������FLASE
// ������pFlash
// ����: ������ת����TURE���ر���ת����FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 youzhuanxiangdeng(void)  //��ת��� D2
{
	
	xdata u8 zz_pin = BSP_ReadInputDataBit(&pFlash->zz);//��ȡ����״̬
	xdata u8 yz_pin = BSP_ReadInputDataBit(&pFlash->yz);//��ȡ����״̬
	
	if(zz_pin == FALSE && yz_pin == TURE)
			return TURE;
	else 
			return FALSE;
	
}
//========================================================================
// ����: u8 xihuo(void)
// ����: ��ȡ����Ϩ��״̬,���������źţ��ų�֮ǰ������������źš�
//  		 ��ʹ�ÿ��������򷢶���ת������Ϩ��     
// ������pFlash
// ����: �����ų�����TURE������Ϩ�𷵻�FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 xihuo(void)  //Ϩ�� D3
{
	static u8 qidong_flag = FALSE;
	static u8 zhaoche_flag = FALSE;
	xdata u8 qd_pin		=	BSP_ReadInputDataBit(&pFlash->qd);//��ȡ����״̬
	xdata u8 xh_pin 	= BSP_ReadInputDataBit(&pFlash->xh);//��ȡ����״̬
	xdata u8 xh_type	=	pFlash->xh.type;
	
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
// ����: u8 shousha(void)
// ����: ��ȡ��ɲ�ź�
// ������pFlash��
// ����: ����ɲ����TURE������ɲ����FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 shousha(void)  //��ɲD4
{
	
	u8 ss_pin = BSP_ReadInputDataBit(&pFlash->ss);//��ȡ����״̬
	
	return ss_pin;	
	
}
//========================================================================
// ����: u8 anquandai(FlashParameterTypeDef *pFlash)
// ����: ��ȡ��ȫ���ź�
// ������pFlash��
// ����: ϵ�ϰ�ȫ������TURE���ɿ���ȫ������FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 anquandai(void)  //��ȫ��D5
{
	
	u8 aqd_pin = BSP_ReadInputDataBit(&pFlash->aqd);//��ȡ����״̬
	#ifdef DEBUG1
				printf("aqd_pin = %b02d\r\n",aqd_pin);
	#endif	
	
	return aqd_pin;	
	
}
//========================================================================
// ����: u8 chenmen_zq(void)
// ����: ��ȡ�����ź�,��ǰ����ǰ������Һ��ĸ��ţ�
// ������pFlash��
// ����: �򿪳��ŷ���FLASE���رճ��ŷ���0xF0,����Ϊ����λ
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 chemen(void)  		//����D6
{
	
	u8 cm_pin = BSP_ReadInputDataBit(&pFlash->cm);//��ȡ����״̬
	
	if(cm_pin == TURE)
		return 0xF0;	//����Ϊ����λ
	else 
		return FALSE;
	
}
//========================================================================
// ����: u8 daochedeng(void)
// ����: ��ȡ�������ź�
// ������pFlash��
// ����: �ҵ�������TURE�����ڵ�������FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 daochedeng(void)  //������ D7
{
	
	u8 dcd_pin = BSP_ReadInputDataBit(&pFlash->dcd);//��ȡ����״̬
	
	return dcd_pin;	
	
}
//========================================================================
// ����: u8 laba(void)
// ����: ��ȡ�����ź�
// ������pFlash��
// ����: �����ȷ���TURE���ɿ����ȷ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 laba(void)  //����  D8
{
	
	u8 lb_pin = BSP_ReadInputDataBit(&pFlash->lb);//��ȡ����״̬
	
	return lb_pin;	
	
}
//========================================================================
// ����: u8 raoche1(void)
// ����: ��ȡ�Ƴ�����1�ź�
// ������pFlash��
// ����: �����ط���PRESS���ɿ����ط���NOPRESS
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 raoche1(void)  //�Ƴ�1   D9
{

	u8 rc_pin1 = BSP_ReadMultipleDataBit(&pFlash->rc,RCPIN1);//��ȡ����״̬
	
	(rc_pin1 == TURE)? (rc_pin1 = PRESS):(rc_pin1 = NOPRESS);//����Э�鸳ֵ
	
	return rc_pin1;	
	
}
//========================================================================
// ����: u8 raoche1(FlashParameterTypeDef *pFlash)
// ����: ��ȡ�Ƴ�����2�ź�
// ������pFlash��
// ����: �����ط���PRESS���ɿ����ط���NOPRESS
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 raoche2(void)  //�Ƴ�2   D10
{
	
	u8 rc_pin2 = BSP_ReadMultipleDataBit(&pFlash->rc,RCPIN2);//��ȡ����״̬
	
	(rc_pin2 == TURE)? (rc_pin2 = PRESS):(rc_pin2 = NOPRESS);//����Э�鸳ֵ
	
	return rc_pin2;	
	
}
//========================================================================
// ����: u8 wudeng(void)
// ����: ��ȡ��ƿ���2�ź�
// ������pFlash��
// ����: ����Ʒ���TURE���ر���Ʒ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 wudeng(void)  //��� D11
{
	
	u8 wd_pin = BSP_ReadInputDataBit(&pFlash->wd);//��ȡ����״̬
	
	return wd_pin;	
	
}
//========================================================================
// ����: u8 yuanguang(void)
// ����: ��ȡԶ�⿪���ź�
// ������pFlash��
// ����: ��Զ��Ʒ���TURE���ر�Զ��Ʒ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 yuanguang(void)  //Զ�� D12
{
	
	u8 yg_pin = BSP_ReadInputDataBit(&pFlash->yg);//��ȡ����״̬
	
	return yg_pin;	
	
}
//========================================================================
// ����: u8 jinguang(void)
// ����: ��ȡ���⿪���ź�
// ������pFlash��
// ����: ������Ʒ���TURE���رս���Ʒ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 jinguang(void)  //���� D13
{
	
	u8 jg_pin = BSP_ReadInputDataBit(&pFlash->jg);//��ȡ����״̬
	
	return jg_pin;	
	
}
//========================================================================
// ����: u8 xiaodeng(void)
// ����: ��ȡС�ƿ����ź�
// ������pFlash��
// ����: ��С�Ʒ���TURE���ر�С�Ʒ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 xiaodeng(void)  //С�� D14
{
	
	u8 xd_pin = BSP_ReadInputDataBit(&pFlash->xd);//��ȡ����״̬
	
	return xd_pin;	
	
}
//========================================================================
// ����: u8 jiaosha(void)
// ����: ��ȡ��ɲ�ź�
// ������pFlash��
// ����: �Ƚ�ɲ����TURE���ɿ���ɲ����FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 jiaosha(void)  //��ɲ D15
{
	
	u8 js_pin = BSP_ReadInputDataBit(&pFlash->js);//��ȡ����״̬
	
	return js_pin;	
	
}
//========================================================================
// ����: u8 yushua(void)
// ����: ��ȡ��ˢ���ź�
// ������pFlash��
// ����: ����ˢ������TURE���ر���ˢ������FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 yushua(void)  //��ˢ D16
{
	
	u8 ys_pin = BSP_ReadInputDataBit(&pFlash->ys);//��ȡ����״̬
	
	return ys_pin;	
	
}
//========================================================================
// ����: u8 zuohoushi(void)
// ����: ��ȡ��������Ӿ��ź�
// ������pFlash��
// ����: ��������Ӿ�����TURE��δ���ڷ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 zuohoushi(void)  //����� D17
{
	
	u8 zhs_pin = BSP_ReadInputDataBit(&pFlash->zhs);//��ȡ����״̬
	
	return zhs_pin;	
	
}
//========================================================================
// ����: u8 qidong(void)
// ����: ��ȡ���������ź�
// ������pFlash��
// ����: �������ʱ����TURE���ɿ�����Կ�׷���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 qidong(void)  //�������� D18
{
	
	u8 qd_pin = BSP_ReadInputDataBit(&pFlash->qd);//��ȡ����״̬
	
	return qd_pin;	
	
}
//========================================================================
// ����: u8 neihoushi(void)
// ����: ��ȡ�����ں��Ӿ��ź�
// ������pFlash��
// ����: �����ں��Ӿ�����TURE��δ���ڷ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 neihoushi(void)  //�ں��� D19
{
	
	xdata u8 nhs_pin = BSP_ReadInputDataBit(&pFlash->nhs);//��ȡ����״̬
	
	return nhs_pin;	
	
}
//========================================================================
// ����: u8 zuoyitiaojie(void)
// ����: ��ȡ���������ź�
// ������pFlash��
// ����: �������η���TURE��δ���ڷ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 zuoyitiaojie(void)  //���ε��ڿ��� D20
{
	
	u8 zytj_pin = BSP_ReadInputDataBit(&pFlash->zytj);//��ȡ����״̬
	
	return zytj_pin;	
	
}
//========================================================================
// ����: u8 dangwei(void)
// ����: ��ȡ��λ�źţ������������дŸк�����������͡�
// ������pFlash��
// ����: 	GEAR1		 1��
//				GEAR2    2��
//				GEAR3    3��
//				GEAR4    4��
//				GEAR5    5��
//				GEARR    R��
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 dangwei(void)  //��λD21--D24
{
	xdata u8 temp = 0;
	xdata u8 dw_pin1 = BSP_ReadMultipleDataBit(&pFlash->dw,DWPIN1);//��ȡ����״̬D21
	xdata u8 dw_pin2 = BSP_ReadMultipleDataBit(&pFlash->dw,DWPIN2);//��ȡ����״̬D22
	xdata u8 dw_pin3 = BSP_ReadMultipleDataBit(&pFlash->dw,DWPIN3);//��ȡ����״̬D23
	xdata u8 dw_pin4 = BSP_ReadMultipleDataBit(&pFlash->dw,DWPIN4);//��ȡ����״̬D24
	xdata u8 dw_type = pFlash->dw.type;//��ȡ����������
	
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
// ����: u8 zuoyiyali(void)
// ����: ��ȡ���Σ�ѹ�����ź�
// ������pFlash��
// ����: ������ѹ������TURE��û��ѹ������FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 zuoyiyali(void)  ///���Σ�ѹ���� D25
{
	
	xdata u8 zyyl_pin = BSP_ReadInputDataBit(&pFlash->zyyl);//��ȡ����״̬
	
	return zyyl_pin;	
	
}
//========================================================================
// ����: u8 lihe(FlashParameterTypeDef *pFlash)
// ����: ��ȡ������ź�
// ������pFlash��
// ����: �������������TURE��̧�����������FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 lihe(void)   //��� D26
{
	
	u8 lh_pin = BSP_ReadInputDataBit(&pFlash->lh);//��ȡ����״̬
	
	return lh_pin;	
	
}
//========================================================================
// ����: u8 yaoshimen(void)
// ����: ��ȡԿ�����ź�
// ������pFlash��
// ����: ��Կ���ſ��ط���TURE���ر�Կ���ſ��ط���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 yaoshimen(void)   //Կ���ſ��� D28
{
	
	u8 ysm_pin = BSP_ReadInputDataBit(&pFlash->ysm);//��ȡ����״̬
	
	return ysm_pin;	
	
}
//========================================================================
// ����: u8 fushache(void)
// ����: ��ȡ��ɲ�ź�
// ������pFlash��
// ����: ���¸�ɲ������TURE��̧��ɲ������FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 fushache(void)   //��ɲ�� D29
{
	
	u8 fsc_pin = BSP_ReadInputDataBit(&pFlash->fsc);//��ȡ����״̬
	
	return fsc_pin;	
	
}
//========================================================================
// ����: u8 chuangdong(void)
// ����: ��ȡ��ʱ�����ź�
// ������pFlash��
// ����: ���ߴ�������TURE��ƽ�ȷ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 chuangdong(void)   //���������� D30
{
	
	u8 cd_pin = BSP_ReadInputDataBit(&pFlash->cd);//��ȡ����״̬
	
	return cd_pin;	
	
}
//========================================================================
// ����: u8 raoche3(void)
// ����: ��ȡ�Ƴ�3�ź�
// ������pFlash��
// ����: ���·���TURE��δ����FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 raoche3(void)   //�Ƴ�3  D31
{
	
	u8 rc_pin3 = BSP_ReadMultipleDataBit(&pFlash->rc,RCPIN3);//��ȡ����״̬
	
	(rc_pin3 == TURE)? (rc_pin3 = PRESS):(rc_pin3 = NOPRESS);//����Э�鸳ֵ
	
	return rc_pin3;	
	
}
//========================================================================
// ����: u8 shijing(void)
// ����: ��ȡ˫���ź�
// ������pFlash��
// ����: ��˫������TURE���ر�˫������FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 shijing(void)   //ʾ������
{
	
	u8 zz_pin = BSP_ReadInputDataBit(&pFlash->zz);//��ȡ����״̬
	u8 yz_pin = BSP_ReadInputDataBit(&pFlash->yz);//��ȡ����״̬
	
	if(zz_pin == TURE && yz_pin == TURE)
			return TURE;
	else 
			return FALSE;
	
}
//========================================================================
// ����: u8 kongdang(void)
// ����: ��ȡ�յ��ź�
// ������pFlash��
// ����: �յ�����TURE���ǿյ�����FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 kongdang(void)   //�յ�
{
	
	if(dangwei() != FALSE)
			return TURE;
	else 
			return FALSE;
	
}
//========================================================================
// ����: u8 guanchayibiao(void)
// ����: ��ȡ�۲��Ǳ����ź�
// ������pFlash��
// ����: �۲췵��TURE��û�й۲췵��FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 guanchayibiao(void)   //�۲��Ǳ���
{
	
	u8 gcybp_pin = BSP_ReadInputDataBit(&pFlash->gcybp);//��ȡ����״̬
	
	return gcybp_pin;	
	
}
//========================================================================
// ����: u8 DBQ_LeftFront(void)
// ����: ��ȡ�����Ŵ�������ǰ���ź�
// ������pFlash��
// ����: �����Ϸ���TURE�������Ϸ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 DBQ_LeftFront(void)    //��������ǰ��״̬
{
  u8 dbq_pin1 = BSP_ReadMultipleDataBit(&pFlash->dbq,LEFT_FRONT_WHEEL);//��ȡ����״̬
	
	return dbq_pin1;

}
//========================================================================
// ����: u8 DBQ_LeftRear(void)
// ����: ��ȡ�����Ŵ�����������ź�
// ������pFlash��
// ����: �����Ϸ���TURE�������Ϸ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 DBQ_LeftRear(void)    //�����������״̬
{
  u8 dbq_pin2 = BSP_ReadMultipleDataBit(&pFlash->dbq,LEFT_REAR_WHEEL);//��ȡ����״̬
	
	return dbq_pin2;

}
//========================================================================
// ����: u8 DBQ_LeftRear(void)
// ����: ��ȡ�����Ŵ�������ǰ���ź�
// ������pFlash��
// ����: �����Ϸ���TURE�������Ϸ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 DBQ_RightFront(void)    //��������ǰ��״̬
{
  u8 dbq_pin3 = BSP_ReadMultipleDataBit(&pFlash->dbq,RIGHT_FRONT_WHEEL);//��ȡ����״̬
	
	return dbq_pin3;

}
//========================================================================
// ����: u8 DBQ_RightRear(void)
// ����: ��ȡ�����Ŵ������Һ����ź�
// ������pFlash��
// ����: �����Ϸ���TURE�������Ϸ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 DBQ_RightRear(void)    //�������Һ���״̬
{
  u8 dbq_pin4 = BSP_ReadMultipleDataBit(&pFlash->dbq,RIGHT_REAR_WHEEL);//��ȡ����״̬
	
	return dbq_pin4;

}
//========================================================================
// ����: u8 DBQ_LeftMiddle(void)
// ����: ��ȡ�����Ŵ�������ҳ����ź�
// ������pFlash��
// ����: �����Ϸ���TURE�������Ϸ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 DBQ_LeftMiddle(void)    //��������ҳ���״̬
{
  u8 dbq_pin5 = BSP_ReadMultipleDataBit(&pFlash->dbq,LEFT_MIDDLE_WHEEL);//��ȡ����״̬
	
	return dbq_pin5;

}
//========================================================================
// ����: u8 DBQ_RightMiddle(void)
// ����: ��ȡ�����Ŵ������ҹҳ����ź�
// ������pFlash��
// ����: �����Ϸ���TURE�������Ϸ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 DBQ_RightMiddle(void)    //�������ҹҳ���״̬
{
  u8 dbq_pin6 = BSP_ReadMultipleDataBit(&pFlash->dbq,RIGHT_MIDDLE_WHEEL);//��ȡ����״̬
	
	return dbq_pin6;

}
//========================================================================
// ����: u8 zhuansucount(void)
// ����: ��ȡת�ٵ��������ֵ
// ������pFlash��
// ����: �����Ϸ���TURE�������Ϸ���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u16 zhuansucount(void)    //�������
{
	static u8 times = 0;//�����ȴ�������ʱ�䣩
	static u16 count = 0;//��ȡת�ٳ�ֵ
	
	if(times == pFlash->zs.sampling_time)//�������ʱ��
	{
		times = 0;
		count = TH0;
		count = count<<8;	
		count = count + TL0;		
		TH0 = 0;//����
		TL0 = 0;//����	
		if ((count == 0) && (pFlash->zs.init_value == 1))
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
// ����: u8 toukui(void)
// ����: ��ȡĦ�г�ͷ��״̬
// ������pFlash��
// ����: ���Ϸ���TURE��ȡ�·���FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 toukui(void)    //Ħ�г�ͷ��
{
  u8 tk_pin = BSP_ReadInputDataBit(&pFlash->tk);//��ȡ����״̬
	
	return tk_pin;

}
//========================================================================
// ����: u8 zuobashou(void)
// ����: ��ȡĦ�г������״̬
// ������pFlash��
// ����: ��ס����TURE���뿪����FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 zuobashou(void)    //Ħ�г������
{
  u8 zbs_pin = BSP_ReadInputDataBit(&pFlash->zbs);//��ȡ����״̬
	
	return zbs_pin;

}
//========================================================================
// ����: u8 youbashou(void)
// ����: ��ȡĦ�г��Ұ���״̬
// ������pFlash��
// ����: ��ס����TURE���뿪����FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 youbashou(void)    //Ħ�г��Ұ���
{
  u8 ybs_pin = BSP_ReadInputDataBit(&pFlash->ybs);//��ȡ����״̬
	
	return ybs_pin;

}
//========================================================================
// ����: u8 zuojiaotaban(void)
// ����: ��ȡĦ�г��Ұ���״̬
// ������pFlash��
// ����: ��ס����TURE���뿪����FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 zuojiaotaban(void)    //Ħ�г����̤��
{
  u8 zjtb_pin = BSP_ReadInputDataBit(&pFlash->zjtb);//��ȡ����״̬
	
	return zjtb_pin;

}
//========================================================================
// ����: u8 youtaban(void)
// ����: ��ȡĦ�г��Ұ���״̬
// ������pFlash��
// ����: ��ס����TURE���뿪����FLASE
// �汾: V1.0, 2022-10-17
//========================================================================
static u8 youjiaotaban(void)    //Ħ�г��ҽ�̤��
{
  u8 yjtb_pin = BSP_ReadInputDataBit(&pFlash->yjtb);//��ȡ����״̬
	
	return yjtb_pin;

}

//========================================================================
// ����: u8 GetHSShockSensor_value(u8 bump_usart)
// ����: �ɼ���ɭ���˴�����������
// ������bump_usart������������֮��Ĵ��ںţ�FlashParameterTypeDef���ݽṹ
// ����: 
// �汾: V1.0, 2022-10-17
//========================================================================
static void GetHSShockSensor_value(u8 bump_usart)    //�õ���ɭ���˴�������ֵ
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
	
	if (Serial_HighSensorShock_Analy(bump_usart) == TURE)//��ȡ����������
	{
	
				for (group_i = 0; group_i < sizeof(pFlash->bump)/sizeof(pFlash->bump[0]);group_i++)
				{
					
					if(pFlash->bump[group_i].name == 0) 
					{
						break;//flash����δ�������˽�����Ŀ
					}
					value  =	 pFlash->bump[group_i].value;//ȡ����״̬
					
					//printf("value = %h04X\r\n",value);
					
					for (i = 0 ; i< pFlash->bump[group_i].count;i++)
					{		
						valuebit  = (u16)(value >> i) & (0x0001);//ȡ������λ
						
						temp = BSP_ReadBumpDataBit(&pFlash->pgjs,group_i,valuebit,i);//��������
						
						if( temp == 0 )
						{
						  pFlash->bump[group_i].value &= ~(1<< i);//��������������
						}
						else 
						  pFlash->bump[group_i].value |= (1<< i);//��������������
					}
					//printf("pole->bump[group_i].value = %h04X\r\n",pole->bump[group_i].value);
					
					
				}
				//������Ҫ��ѯ����״̬��������Ҫ�ڶ��α�����������Ҫ��¼������λ��
				for ( ;gor_i < sizeof(pFlash->bump)/sizeof(pFlash->bump[0]);gor_i++)
				{
					
					if(pFlash->bump[gor_i].name == 0) 
					{
						gor_i = 0;
						
						break;//flash����δ�������˽�����Ŀ
					}
					
					value  =	pFlash->bump[gor_i].value;//ȡ����״̬
					
					//printf("penggan.value = %h04X\r\n",value);
					
					for (;pos_i< pFlash->bump[gor_i].count;pos_i++)
					{
						
						valuebit = (u8)(value >> pos_i) & (0x0001);//ȡ������λ
						
						if(valuebit == 1)//���������ź�
						{
								pilepole.name   = pFlash->bump[gor_i].name;			//�ϴ�����״̬	
								pilepole.number = pFlash->bump[gor_i].number;	  //�ϴ�����״̬			
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

	if (TILT_ALL_USART != DISABLE)//ȫ����ȡ
	{
			Serial_TiltSensor_Analy(Tilt_usart,pTilt);
	
//		 printf("------------------------------------------\r\n");
//		 printf("Tilt[PLACE_Q_AXLE].Roll = %h04d\r\n",	  Tilt[PLACE_Q_AXLE].Roll);
//		 printf("Tilt[PLACE_Q_AXLE].Pitch = %h04d\r\n",		Tilt[PLACE_Q_AXLE].Pitch);
//		 printf("Tilt[PLACE_Q_AXLE].Yaw = %h04d\r\n",			Tilt[PLACE_Q_AXLE].Yaw);
//		 printf("------------------------------------------\r\n");
	}
	else
	{
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
	}
}

//========================================================================
// ����: void GetTilt_Adjust_vaule(void) //��ȡĦ�г���Ǵ�����У׼ֵ
// ����: ��ȡ����Ħ�г���Ǵ�����У׼��׼ֵ
// ������
// ����: 
// �汾: V1.0, 2022-10-17
//========================================================================
void GetTilt_Adjust_vaule(void) //��ȡ����Ħ�г���Ǵ�����У׼ֵ
{
	if(TILT_MTC_USART != DISABLE)
	{
		USART_ClearMsgQueueRxBuffer(TILT_MTC_USART);//�����ڻ���
	
	  BSP_ClearUsartRxBuffer(TILT_MTC_USART);//
	
	  delay_ms(200);//��ʱ300�����ȡ��׼ֵ
		
		GetTiltSensor_value(TILT_MTC_USART,&Tilt[PLACE_MTC_AXLE]);//��ȡ��׼ֵ
		mtc.Adjust_XL = Tilt[PLACE_MTC_AXLE].RollL;					//X��Ƕȵ��ֽ�	
		mtc.Adjust_XH = Tilt[PLACE_MTC_AXLE].RollH;  				//X��Ƕȸ��ֽ�
		mtc.Adjust_YL = Tilt[PLACE_MTC_AXLE].PitchL;					//Y��Ƕȵ��ֽ�
		mtc.Adjust_YH = Tilt[PLACE_MTC_AXLE].PitchH;  				//Y��Ƕȸ��ֽ�	
		
//		printf("mtc.Adjust_XL = %b02d\r\n",	mtc.Adjust_XL);
//		printf("mtc.Adjust_XH = %b02d\r\n",	mtc.Adjust_XH);
//		printf("mtc.Adjust_YL = %b02d\r\n",mtc.Adjust_YL);
//		printf("mtc.Adjust_YH = %b02d\r\n",mtc.Adjust_YH);	
	}
}
#endif
//========================================================================
// ����: void DefaultConfig_Init(void)
// ����: ��ʼ��Ĭ������
// ��������
// �汾: V1.0, 2022-10-17
//========================================================================
void GetFlashConfig(void)
{
	
	  BSP_GetFlashConfig();	//��ȡ���ò���
	
	  if(pFlash->zz.pin == 0)				pFlash->zz.pin 		= D1;		//��ת,Ĭ�϶˿�ΪD1
		if(pFlash->yz.pin == 0)				pFlash->yz.pin 		= D2;		//��ת,Ĭ�϶˿�ΪD2
		if(pFlash->xh.pin == 0)				pFlash->xh.pin 		= D3;		//�����,Ĭ�϶˿�ΪD3
		if(pFlash->ss.pin == 0)				pFlash->ss.pin 		= D4;		//��ɲ,Ĭ�϶˿�ΪD4
		if(pFlash->aqd.pin == 0)			pFlash->aqd.pin 	= D5;	  //��ȫ��,Ĭ�϶˿�ΪD5	
		if(pFlash->cm.pin == 0)				pFlash->cm.pin 		= D6;		//����,Ĭ�϶˿�ΪD6
		if(pFlash->dcd.pin == 0)			pFlash->dcd.pin 	= D7;	  //������,Ĭ�϶˿�ΪD7
		if(pFlash->lb.pin == 0)				pFlash->lb.pin 		= D8;		//����,Ĭ�϶˿�ΪD8
	
		if(pFlash->rc.pin1 == 0)			pFlash->rc.pin1 	= D9;	//�Ƴ�1,Ĭ�϶˿�ΪD9
		if(pFlash->rc.pin2 == 0)			pFlash->rc.pin2 	= D10;//�Ƴ�2,Ĭ�϶˿�ΪD10
		if(pFlash->wd.pin == 0)				pFlash->wd.pin 		= D11;	//���,Ĭ�϶˿�ΪD11
		if(pFlash->yg.pin == 0)				pFlash->yg.pin 		= D12;	//Զ��,Ĭ�϶˿�ΪD12
		if(pFlash->jg.pin == 0)				pFlash->jg.pin 		= D13;	//����,Ĭ�϶˿�ΪD13	
		if(pFlash->xd.pin == 0)				pFlash->xd.pin 		= D14;	//С��,Ĭ�϶˿�ΪD14
		if(pFlash->js.pin == 0)				pFlash->js.pin 		= D15;	//��ɲ,Ĭ�϶˿�ΪD15
		if(pFlash->ys.pin == 0)				pFlash->ys.pin 		= D16;	//��ˢ,Ĭ�϶˿�ΪD16
	
		if(pFlash->zhs.pin == 0)			pFlash->zhs.pin 	= D17;//����Ӿ�,Ĭ�϶˿�ΪD17
		if(pFlash->qd.pin == 0)				pFlash->qd.pin 		= D18;	//����,Ĭ�϶˿�ΪD18
		if(pFlash->nhs.pin == 0)			pFlash->nhs.pin 	= D19;//�ں��Ӿ�,Ĭ�϶˿�ΪD19
		if(pFlash->zytj.pin == 0)			pFlash->zytj.pin 	= D20;	//Զ����(ѹ��,Ĭ�϶˿�ΪD20
		if(pFlash->dw.pin1 == 0)			pFlash->dw.pin1 	= D21;//��λ1,Ĭ�϶˿�ΪD21	
		if(pFlash->dw.pin2 == 0)			pFlash->dw.pin2		= D22;	//��λ2,Ĭ�϶˿�ΪD22
		if(pFlash->dw.pin3 == 0)			pFlash->dw.pin3 	= D23;//��λ3,Ĭ�϶˿�ΪD23
		if(pFlash->dw.pin4 == 0)			pFlash->dw.pin4 	= D24;//��λ4,Ĭ�϶˿�ΪD24
		
		if(pFlash->zyyl.pin == 0)			pFlash->zyyl.pin 	= D25;	//������,Ĭ�϶˿�ΪD25
		if(pFlash->lh.pin == 0)				pFlash->lh.pin 		= D26;	//���,Ĭ�϶˿�ΪD26
		if(pFlash->zs.pin == 0)				pFlash->zs.pin 		= D27;	//ת��,Ĭ�϶˿�ΪD27
		if(pFlash->ysm.pin == 0)			pFlash->ysm.pin 	= D28;//Կ�׿���,Ĭ�϶˿�ΪD28
		if(pFlash->fsc.pin == 0)			pFlash->fsc.pin 	= D29;//��ɲ��,Ĭ�϶˿�ΪD29	
		if(pFlash->cd.pin == 0)				pFlash->cd.pin		= D30;//����������,Ĭ�϶˿�ΪD30
		//if(pFlash->dw3.pin == 0)		pFlash->dw3.pin 	= D31;//����,Ĭ�϶˿�ΪD31
		if(pFlash->rc.pin3 == 0)			pFlash->rc.pin3 	= D32;//�Ƴ�3,Ĭ�϶˿�ΪD32
#ifdef  STC15W4K48S4			
	
		if(pFlash->tk.pin == 0)				pFlash->tk.pin 	= D5;		//��ȫ��,Ĭ�϶˿�ΪD5			//Ħ�г�ͷ��
		if(pFlash->zbs.pin == 0)			pFlash->zbs.pin 	= D17;//����Ӿ�,Ĭ�϶˿�ΪD17		//Ħ�г������
		if(pFlash->ybs.pin == 0)			pFlash->ybs.pin	= D19;	//�ں��Ӿ�,Ĭ�϶˿�ΪD19		//Ħ�г��Ұ���
		if(pFlash->zjtb.pin == 0)			pFlash->zjtb.pin = D6;	//����,Ĭ�϶˿�ΪD6				//Ħ�г����̤��
		if(pFlash->yjtb.pin == 0)			pFlash->yjtb.pin = D16;	//��ˢ,Ĭ�϶˿�ΪD16				//Ħ�г��ҽ�̤��
		
		if(pFlash-> upload.com > 4)		pFlash-> upload.com 	= DISABLE;//���ںų�����Χ
		if(pFlash-> gps.com > 4)			pFlash-> upload.com 	= DISABLE;//���ںų�����Χ
		if(pFlash-> bump_hs.com > 4)	pFlash-> upload.com 	= DISABLE;//���ںų�����Χ
		if(pFlash-> bump_24g.com > 4)	pFlash-> upload.com 	= DISABLE;//���ںų�����Χ
		if(pFlash-> titl_all.com > 4)	pFlash-> upload.com 	= DISABLE;//���ںų�����Χ
		
		if(pFlash-> titl_q.com > 4)		pFlash-> upload.com 	= DISABLE;//���ںų�����Χ
		if(pFlash-> titl_h.com > 4)		pFlash-> upload.com 	= DISABLE;//���ںų�����Χ
		if(pFlash-> titl_g.com > 4)		pFlash-> upload.com 	= DISABLE;//���ںų�����Χ
		if(pFlash-> titl_mtc.com > 4)	pFlash-> upload.com 	= DISABLE;//���ںų�����Χ
#endif

#ifdef  STC12C5A60S2
		if(pFlash-> upload.com > 2)		pFlash-> upload.com 	= DISABLE;//���ںų�����Χ
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
	
	    GetHSShockSensor_value(BUMP_HS_USART);//������������
	    Get24GShockSensor_value(BUMP_24G_USART);//������������
			GetTiltSensor_value(TILT_Q_USART,&Tilt[PLACE_Q_AXLE]);//�ɼ�ǰ������
			GetTiltSensor_value(TILT_H_USART,&Tilt[PLACE_H_AXLE]);//�ɼ���������
			GetTiltSensor_value(TILT_G_USART,&Tilt[PLACE_G_AXLE]);//�ɼ���������
		  GetTiltSensor_value(TILT_MTC_USART,&Tilt[PLACE_MTC_AXLE]);	//�ɼ�����Ħ�г��������
		  GetTiltSensor_value(TILT_ALL_USART,Tilt);	//�ɼ����ܺ���������

#endif
	
			pDatabuf[0] |= (jiaosha() << 0);		 					//��ɱ
			pDatabuf[0]	|=	(lihe() << 1); 							//�����				
			pDatabuf[0]	|=	(jinguang() << 2);						//�����
			pDatabuf[0]	|=	(yuanguang() << 3);					//Զ���	
			pDatabuf[0]	|=	(youzhuanxiangdeng() << 4);	//��ת��			
			pDatabuf[0]	|=	(zuozhuanxiangdeng() << 5);	//��ת��
    	pDatabuf[0]	|=	(shousha()<<6);							//��ɲ
      pDatabuf[0]	|=	(zuoyitiaojie()<<7);					//����
			
			pDatabuf[1]	|=	(laba() << 0);				//����
			pDatabuf[1]	|=	(daochedeng() << 2);	//�����ƿ���		
			pDatabuf[1]	|=	(xiaodeng() << 3);		//С��
			pDatabuf[1]	|=	(shijing() << 4);		//˫��
			pDatabuf[1]	|=	(anquandai() << 5);	//��ȫ������    
			pDatabuf[1]	|=	(qidong() << 6);			//��������
			pDatabuf[1]	|=	(xihuo() << 7);			//������ת��
	
			pDatabuf[2]	|=	chemen();		//����
			pDatabuf[2]	|=	dangwei();		//��λ

			pDatabuf[3]	=	0;			//����
			pDatabuf[4]	|=	(u8)zhuansucount();			//������ת�ٵͰ�λ   
			pDatabuf[5]	|=	(u8)zhuansucount()>>8;		//������ת�ٸ߰�λ
			
			pDatabuf[6] |=	(kongdang() << 0);		//�յ�
			pDatabuf[6]	|=	(zuoyiyali() << 3);	//���ο���
			
			pDatabuf[7]	|=	(yushua() << 0);			//��ˢ
			pDatabuf[7]	|=	(wudeng() << 1);			//���
			pDatabuf[7]	|=	(neihoushi() << 2);	//�ں���
			pDatabuf[7]	|=	(zuohoushi() << 3);	//������
			pDatabuf[7]	|=	(jinguang() << 4);		//���
			pDatabuf[7]	|=	(yuanguang() << 4);	//���
			pDatabuf[7]	|=	(fushache() << 5);		//��ɲ
			pDatabuf[7]	|=	(qidong() << 6);			//����
			//pDatabuf[8]=0;			//���̵�״̬
			//pDatabuf[9]=0;			//�쳣״̬

			pDatabuf[10]	=	raoche1();	//��ǰ�Ƴ�
			pDatabuf[11]	=	raoche2();	//����Ƴ�
			pDatabuf[12]	=	raoche1();	//��ǰ�Ƴ�
			pDatabuf[13]	=	raoche3();	//�Һ��Ƴ�

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
			
			pDatabuf[31]		|=	(yaoshimen() << 0); 			//Կ�׿���
			pDatabuf[31]		|=	(chuangdong() << 1);			//��������
			
#ifdef  STC15W4K48S4	
			pDatabuf[31]		|=	(toukui() << 2); 			//ͷ����1=���ϣ�//Ħ�г�
			pDatabuf[31]		|=	(zuobashou() << 3);		//����֣�1=���ϣ�//Ħ�г�
			pDatabuf[31]		|=	(youbashou() << 4);		//�Ұ��֣�1=���ϣ�//Ħ�г�
			pDatabuf[31]		|=	(zuojiaotaban() << 5);			//��̤�壨1=���ϣ�//Ħ�г�
			pDatabuf[31]		|=	(youjiaotaban() << 6);			//��̤�壨1=���ϣ�//Ħ�г�
#endif
			//*pDatabuf[31]		|=	(youmentaban() << 7);	//1=����̤�� 
			
			
			pDatabuf[32]		=	FIRMWARE_NUM;			//���ص�Ƭ���̼���
			//*pDatabuf[33]		=	0;							//������ת��

			pDatabuf[34]		|=	(DBQ_LeftFront()<<7);    //��������ǰ���ź�    ��1=�������ϣ�0=�����ϣ�
			pDatabuf[34]		|=	(DBQ_LeftRear()<<6);     //������������ź�    ��1=�������ϣ�0=�����ϣ�
			pDatabuf[34]		|=	(DBQ_RightFront()<<5);   //��������ǰ���ź�    ��1=�������ϣ�0=�����ϣ�
			pDatabuf[34]		|=	(DBQ_RightRear()<<4);    //�������Һ����ź�    ��1=�������ϣ�0=�����ϣ�
			pDatabuf[34]		|=	(DBQ_LeftMiddle()<<3);   //��������ҳ����ź�  ��1=�������ϣ�0=�����ϣ�
			pDatabuf[34]		|=	(DBQ_RightMiddle()<<2);  //�������ҹҳ����ź�  ��1=�������ϣ�0=�����ϣ�
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

			pDatabuf[55]		|=	(guanchayibiao() << 0);//�۲��Ǳ���
			
			pDatabuf[lenth-2]		=	count++;    //���ݱ�ǩΪ���ݳ��ȵĵ����ڶ�λ,ÿ������1	
			
			Checksum(pDatabuf,lenth);//����У���			
}	





