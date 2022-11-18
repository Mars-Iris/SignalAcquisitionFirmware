#ifndef __BSP_FLASH_H
#define __BSP_FLASH__H	

#include	"./User/config.h"
#include	"./User/includes.h"

//��һ����0x0000--0x1ff
//�ڶ�����0x0200--0x3ff

#define FLASH_ADDR_UPLOAD_COM     		0x0001      //��������λ�������Ӵ��ں�
#define FLASH_ADDR_UPLOAD_BOTE  			0x0002    	//��������λ�������Ӵ��ڲ�����
#define FLASH_ADDR_GPS_COM     				0x0003      //������GPS�����Ӵ��ں�
#define FLASH_ADDR_GPS_BOTE  					0x0004    	//������GPS�����Ӵ��ڲ�����

#define FLASH_ADDR_BUMP_HS_COM     		0x0005      //�������ɭ���˴��������Ӵ��ں�
#define FLASH_ADDR_BUMP_HS_BOTE  			0x0006    	//�������ɭ���˴��������Ӵ��ڲ�����
#define FLASH_ADDR_BUMP_24G_COM     	0x0007      //������2.4G���˴��������Ӵ��ں�
#define FLASH_ADDR_BUMP_24G_BOTE  		0x0008    	//������2.4G���˴��������Ӵ��ڲ�����


#define FLASH_ADDR_TILT_ALL_COM     	0x0009      //��������Ǵ����������Ӵ��ں�(���ݻ��ܺ�Խ�)
#define FLASH_ADDR_TILT_Q_COM     		0x000A      //������ǰ����Ǵ����������Ӵ��ںţ������������ӣ�
#define FLASH_ADDR_TILT_H_COM  				0x000B    	//�����������Ǵ����������Ӵ��ںţ������������ӣ�
#define FLASH_ADDR_TILT_G_COM     		0x000C      //�����������Ǵ����������Ӵ��ںţ������������ӣ�
#define FLASH_ADDR_TILT_MTC_COM  			0x000D    	//���������Ħ�г���Ǵ����������Ӵ��ںţ������������ӣ�
#define FLASH_ADDR_TILT_BOTE  				0x000E    	//��������Ǵ����������Ӵ��ڲ�����(��Ǵ�����������������ͬ)

#define FLASH_ADDR_NETWORK_COM  			0x000F    	//��������ģ�鹦���Ƿ�����



#define FLASH_ADDR_ZYTJ_PIN     			0x0020      //�����ź�����ܽ�λ��
#define FLASH_ADDR_ZYTJ_MODEL  				0x0021      //���ο��أ����ڣ�����ģʽ
#define FLASH_ADDR_ZYTJ_RISING_ED     0x0022      //���ο��أ����ڣ�����������
#define FLASH_ADDR_ZYTJ_FALLING_ED    0x0023      //���ο��أ����ڣ��½�������
#define FLASH_ADDR_ZYTJ_TYPE    			0x0024      //���ο��أ����ڣ���������

#define FLASH_ADDR_SS_PIN             0x0028      //��ɲ��������ܽ�λ��
#define FLASH_ADDR_SS_MODEL          	0x0029      //��ɲ��������ģʽ
#define FLASH_ADDR_SS_RISING_ED       0x002A      //��ɲ��������������
#define FLASH_ADDR_SS_FALLING_ED      0x002B      //��ɲ�����½�������
#define FLASH_ADDR_SS_TYPE        		0x002C      //��ɲ������������

#define FLASH_ADDR_ZZ_PIN             0x0030      //��ת��������ܽ�λ��
#define FLASH_ADDR_ZZ_MODEL          	0x0031      //��ת��������ģʽ
#define FLASH_ADDR_ZZ_RISING_ED       0x0032      //��ת��������������
#define FLASH_ADDR_ZZ_FALLING_ED      0x0033      //��ת�����½�������
#define FLASH_ADDR_ZZ_TYPE      			0x0034      //��ת������������

#define FLASH_ADDR_YZ_PIN             0x0038      //��ת��������ܽ�λ��
#define FLASH_ADDR_YZ_MODEL          	0x0039      //��ת��������ģʽ
#define FLASH_ADDR_YZ_RISING_ED       0x003A      //��ת��������������
#define FLASH_ADDR_YZ_FALLING_ED      0x003B      //��ת�����½�������
#define FLASH_ADDR_YZ_TYPE      			0x003C      //��ת������������

#define FLASH_ADDR_YG_PIN             0x0040      //Զ�⿪������ܽ�λ��
#define FLASH_ADDR_YG_MODEL          	0x0041      //Զ�⿪������ģʽ
#define FLASH_ADDR_YG_RISING_ED       0x0042      //Զ�⿪������������
#define FLASH_ADDR_YG_FALLING_ED      0x0043      //Զ�⿪���½�������
#define FLASH_ADDR_YG_TYPE      			0x0044      //Զ�⿪����������

#define FLASH_ADDR_JG_PIN             0x0048      //���⿪������ܽ�λ��
#define FLASH_ADDR_JG_MODEL          	0x0049      //���⿪������ģʽ
#define FLASH_ADDR_JG_RISING_ED       0x004A      //���⿪������������
#define FLASH_ADDR_JG_FALLING_ED      0x004B      //���⿪���½�������
#define FLASH_ADDR_JG_TYPE      			0x004C      //���⿪����������

#define FLASH_ADDR_LH_PIN             0x0050      //��Ͽ�������ܽ�λ��
#define FLASH_ADDR_LH_MODEL          	0x0051      //��Ͽ�������ģʽ
#define FLASH_ADDR_LH_RISING_ED       0x0052      //��Ͽ�������������
#define FLASH_ADDR_LH_FALLING_ED      0x0053      //��Ͽ����½�������
#define FLASH_ADDR_LH_TYPE      			0x0054      //��Ͽ�����������

#define FLASH_ADDR_JS_PIN             0x0058      //��ɲ��������ܽ�λ��
#define FLASH_ADDR_JS_MODEL          	0x0059      //��ɲ��������ģʽ
#define FLASH_ADDR_JS_RISING_ED       0x005A      //��ɲ��������������
#define FLASH_ADDR_JS_FALLING_ED      0x005B      //��ɲ�����½�������
#define FLASH_ADDR_JS_TYPE      			0x005C      //��ɲ������������

#define FLASH_ADDR_XH_PIN             0x0060      //Ϩ�𿪹�����ܽ�λ��
#define FLASH_ADDR_XH_MODEL          	0x0061      //Ϩ�𿪹�����ģʽ
#define FLASH_ADDR_XH_RISING_ED       0x0062      //Ϩ�𿪹�����������
#define FLASH_ADDR_XH_FALLING_ED      0x0063      //Ϩ�𿪹��½�������
#define FLASH_ADDR_XH_TYPE            0x0064      //����Ϩ��ʽ

#define FLASH_ADDR_QD_PIN             0x0068      //������������ܽ�λ��
#define FLASH_ADDR_QD_MODEL          	0x0069      //������������ģʽ
#define FLASH_ADDR_QD_RISING_ED       0x006A      //������������������
#define FLASH_ADDR_QD_FALLING_ED      0x006B      //���������½�������
#define FLASH_ADDR_QD_TYPE            0x006C      //������ʽ

#define FLASH_ADDR_AQD_PIN            0x0070      //��ȫ����������ܽ�λ��
#define FLASH_ADDR_AQD_MODEL          0x0071      //��ȫ����������ģʽ
#define FLASH_ADDR_AQD_RISING_ED      0x0072      //��ȫ����������������
#define FLASH_ADDR_AQD_FALLING_ED     0x0073      //��ȫ�������½�������
#define FLASH_ADDR_AQD_TYPE      			0x0074      //��ȫ��������������

#define FLASH_ADDR_SJ_PIN             0x0078      //ʾ����������ܽ�λ��
#define FLASH_ADDR_SJ_MODEL           0x0079      //ʾ����������ģʽ
#define FLASH_ADDR_SJ_RISING_ED       0x007A      //ʾ����������������
#define FLASH_ADDR_SJ_FALLING_ED      0x007B      //ʾ�������½�������
#define FLASH_ADDR_SJ_TYPE      			0x007C      //ʾ��������������

#define FLASH_ADDR_XD_PIN             0x0080      //С�ƿ�������ܽ�λ��
#define FLASH_ADDR_XD_MODEL          	0x0081      //С�ƿ�������ģʽ
#define FLASH_ADDR_XD_RISING_ED       0x0082      //С�ƿ�������������
#define FLASH_ADDR_XD_FALLING_ED      0x0083      //С�ƿ����½�������
#define FLASH_ADDR_XD_TYPE     				0x0084      //С�ƿ�����������

#define FLASH_ADDR_LB_PIN             0x0088      //���ȿ�������ܽ�λ��
#define FLASH_ADDR_LB_MODEL           0x0089      //���ȿ�������ģʽ
#define FLASH_ADDR_LB_RISING_ED       0x008A      //���ȿ���������������
#define FLASH_ADDR_LB_FALLING_ED      0x008B      //���ȿ����½�������
#define FLASH_ADDR_LB_TYPE     				0x008C      //���ȿ�����������

#define FLASH_ADDR_CM_PIN             0x0090      //���ſ�������ܽ�λ��
#define FLASH_ADDR_CM_MODEL           0x0091      //���ſ�������ģʽ
#define FLASH_ADDR_CM_RISING_ED       0x0092      //���ſ�������������
#define FLASH_ADDR_CM_FALLING_ED      0x0093      //���ſ����½�������
#define FLASH_ADDR_CM_TYPE     				0x0094      //���ſ�����������

#define FLASH_ADDR_DW_PIN1            0x0098      //��λ����1����ܽ�λ��
#define FLASH_ADDR_DW_MODEL         	0x0099      //��λ����1����ģʽ
#define FLASH_ADDR_DW_RISING_ED      	0x009A      //��λ����1����������
#define FLASH_ADDR_DW_FALLING_ED     	0x009B      //��λ����1�½�������
#define FLASH_ADDR_DW_TYPE          	0x009C      //��λ����

#define FLASH_ADDR_DW_PIN2            0x00A0      //��λ����2����ܽ�λ��
//#define FLASH_ADDR_DW2_MODEL         	0x00A1      //��λ����2����ģʽ
//#define FLASH_ADDR_DW2_RISING_ED      0x00A2      //��λ����2����������
//#define FLASH_ADDR_DW2_FALLING_ED     0x00A3      //��λ����2�½�������

#define FLASH_ADDR_DW_PIN3            0x00A8      //��λ����3����ܽ�λ��
//#define FLASH_ADDR_DW3_MODEL         	0x00A9      //��λ����3����ģʽ
//#define FLASH_ADDR_DW3_RISING_ED      0x00AA      //��λ����3����������
//#define FLASH_ADDR_DW3_FALLING_ED     0x00AB      //��λ����3�½�������

#define FLASH_ADDR_DW_PIN4           0x00B0      //��λ����4����ܽ�λ��
//#define FLASH_ADDR_DW4_MODEL         	0x00B1      //��λ����4����ģʽ
//#define FLASH_ADDR_DW4_RISING_ED      0x00B2      //��λ����4����������
//#define FLASH_ADDR_DW4_FALLING_ED     0x00B3      //��λ����4�½�������

#define FLASH_ADDR_ZHS_PIN            0x00B8      //����ӿ�������ܽ�λ��
#define FLASH_ADDR_ZHS_MODEL         	0x00B9      //����ӿ�������ģʽ
#define FLASH_ADDR_ZHS_RISING_ED      0x00BA      //����ӿ�������������
#define FLASH_ADDR_ZHS_FALLING_ED     0x00BB      //����ӿ����½�������
#define FLASH_ADDR_ZHS_TYPE          	0x00BC      //���������

#define FLASH_ADDR_NHS_PIN            0x00C0      //�ں��ӿ�������ܽ�λ��
#define FLASH_ADDR_NHS_MODEL         	0x00C1      //�ں��ӿ�������ģʽ
#define FLASH_ADDR_NHS_RISING_ED      0x00C2      //�ں��ӿ�������������
#define FLASH_ADDR_NHS_FALLING_ED     0x00C3      //�ں��ӿ����½�������
#define FLASH_ADDR_NHS_TYPE          	0x00C4      //�ں�������

#define FLASH_ADDR_FSC_PIN            0x00C8      //��ɲ��������ܽ�λ��
#define FLASH_ADDR_FSC_MODEL          0x00C9      //��ɲ��������ģʽ
#define FLASH_ADDR_FSC_RISING_ED      0x00CA      //��ɲ��������������
#define FLASH_ADDR_FSC_FALLING_ED     0x00CB      //��ɲ�����½�������
#define FLASH_ADDR_FSC_TYPE          	0x00CC      //��ɲ������

#define FLASH_ADDR_WD_PIN             0x00D0      //��ƿ�������ܽ�λ��
#define FLASH_ADDR_WD_MODEL          	0x00D1      //��ƿ�������ģʽ
#define FLASH_ADDR_WD_RISING_ED       0x00D2      //��ƿ�������������
#define FLASH_ADDR_WD_FALLING_ED      0x00D3      //��ƿ����½�������
#define FLASH_ADDR_WD_TYPE          	0x00D4      //����������ͺͷ�ʽ

 
#define FLASH_ADDR_YS_PIN             0x00D8      //��ˢ��������ܽ�λ��
#define FLASH_ADDR_YS_MODEL          	0x00D9      //��ˢ��������ģʽ
#define FLASH_ADDR_YS_RISING_ED       0x00DA      //��ˢ��������������
#define FLASH_ADDR_YS_FALLING_ED      0x00DB      //��ˢ�����½�������
#define FLASH_ADDR_YS_TYPE          	0x00DC      //��ˢ�������ͺͷ�ʽ

#define FLASH_ADDR_DCD_PIN            0x00E0      //�����ƿ�������ܽ�λ��
#define FLASH_ADDR_DCD_MODEL         	0x00E1      //�����ƿ�������ģʽ
#define FLASH_ADDR_DCD_RISING_ED      0x00E2      //�����ƿ�������������
#define FLASH_ADDR_DCD_FALLING_ED     0x00E3      //�����ƿ����½�������
#define FLASH_ADDR_DCD_TYPE          	0x00E4      //�������������ͺͷ�ʽ

#define FLASH_ADDR_YSM_PIN            0x00E8      //Կ���ſ�������ܽ�λ��
#define FLASH_ADDR_YSM_MODEL         	0x00E9      //Կ���ſ�������ģʽ
#define FLASH_ADDR_YSM_RISING_ED      0x00EA      //Կ���ſ�����������
#define FLASH_ADDR_YSM_FALLING_ED     0x00EB      //Կ���ſ����½�������
#define FLASH_ADDR_YSM_TYPE          	0x00EC      //Կ�����������ͺͷ�ʽ

#define FLASH_ADDR_RC_PIN1            0x00F0      //�Ƴ�����1����ܽ�λ��
#define FLASH_ADDR_RC_MODEL          	0x00F1      //�Ƴ�����1������ģʽ
#define FLASH_ADDR_RC_RISING_ED      	0x00F2      //�Ƴ�����1����������
#define FLASH_ADDR_RC_FALLING_ED     	0x00F3      //�Ƴ�����1�½�������
#define FLASH_ADDR_RC_TYPE           	0x00F4      //�Ƴ�ģʽ

#define FLASH_ADDR_RC_PIN2            0x00F8      //�Ƴ�����2����ܽ�λ��
//#define FLASH_ADDR_RC2_MODEL         	0x00F9      //�Ƴ�����2������ģʽ
//#define FLASH_ADDR_RC2_RISING_ED      0x00FA      //�Ƴ�����2����������
//#define FLASH_ADDR_RC2_FALLING_ED     0x00FB      //�Ƴ�����2�½�������

#define FLASH_ADDR_RC_PIN3            0x0100      //�Ƴ�����3����ܽ�λ��
//#define FLASH_ADDR_RC3_MODEL         	0x0101      //�Ƴ�����3������ģʽ
//#define FLASH_ADDR_RC3_RISING_ED      0x0102      //�Ƴ�����3����������
//#define FLASH_ADDR_RC3_FALLING_ED     0x0103      //�Ƴ�����3�½�������

#define FLASH_ADDR_CD_PIN             0x0108      //������������ܽ�λ��
#define FLASH_ADDR_CD_MODEL          	0x0109      //�������ع�����ģʽ
#define FLASH_ADDR_CD_RISING_ED      	0x010A      //������������������
#define FLASH_ADDR_CD_FALLING_ED     	0x010B      //���������½�������
#define FLASH_ADDR_CD_TYPE          	0x010C      //�����������ͺͷ�ʽ

#define FLASH_ADDR_ZYYL_PIN           0x0110      //���ο��أ�ѹ��������ܽ�λ��
#define FLASH_ADDR_ZYYL_MODEL        	0x0111      //���ο��أ�ѹ����������ģʽ
#define FLASH_ADDR_ZYYL_RISING_ED     0x0112      //���ο��أ�ѹ��������������
#define FLASH_ADDR_ZYYL_FALLING_ED    0x0113      //���ο��أ�ѹ�����½�������
#define FLASH_ADDR_ZYYL_TYPE          0x0114      //���ο��أ�ѹ�����������ͺͷ�ʽ

//#define FLASH_ADDR_ZSJS_PIN           0x0118      //ת�ټ�������ܽ�λ��
//#define FLASH_ADDR_ZSJS_MODEL         0x0119      //ת�ټ���������ģʽ
//#define FLASH_ADDR_ZSJS_RISING_ED     0x011A      //ת�ټ�������������
//#define FLASH_ADDR_ZSJS_FALLING_ED    0x011B      //ת�ټ����½�������

//#define FLASH_ADDR_LCJS_PIN           0x0120      //��̼�������ܽ�λ��
//#define FLASH_ADDR_LCJS_MODEL         0x0121      //��̼���������ģʽ
//#define FLASH_ADDR_LCJS_RISING_ED     0x0122      //��̼�������������
//#define FLASH_ADDR_LCJS_FALLING_ED    0x0123      //��̼����½�������

#define FLASH_ADDR_ZZXDYJ_PIN         0x0128      //��ת���Ӳ����������ܽ�λ��
#define FLASH_ADDR_ZZXDYJ_MODEL       0x0129      //��ת���Ӳ����������ģʽ
#define FLASH_ADDR_ZZXDYJ_RISING_ED   0x012A      //��ת���Ӳ����������������
#define FLASH_ADDR_ZZXDYJ_FALLING_ED  0x012B      //��ת���Ӳ�������½�������
#define FLASH_ADDR_ZZXDYJ_TYPE        0x012C     	//��ת���Ӳ�������������ͺͷ�ʽ

#define FLASH_ADDR_YZXDYJ_PIN         0x0130      //��ת���Ӳ����������ܽ�λ��
#define FLASH_ADDR_YZXDYJ_MODEL       0x0131      //��ת���Ӳ����������ģʽ
#define FLASH_ADDR_YZXDYJ_RISING_ED   0x0132      //��ת���Ӳ����������������
#define FLASH_ADDR_YZXDYJ_FALLING_ED  0x0133      //��ת���Ӳ�������½�������
#define FLASH_ADDR_YZXDYJ_TYPE        0x0134     	//��ת���Ӳ�������������ͺͷ�ʽ


#define FLASH_ADDR_DBQ_FALLING_ED     0x0136      //�����Ŵ������½�������
#define FLASH_ADDR_DBQ_TYPE           0x0137      //�����Ŵ���������

#define FLASH_ADDR_DBQ_PIN1      			0x0138      //��������ǰ�ֿ�������ܽ�λ��
#define FLASH_ADDR_DBQ_PIN2      			0x0139      //����������ֿ�������ܽ�λ��
#define FLASH_ADDR_DBQ_PIN3      			0x013A      //��������ǰ�ֿ�������ܽ�λ��
#define FLASH_ADDR_DBQ_PIN4      			0x013B      //�������Һ��ֿ�������ܽ�λ��
#define FLASH_ADDR_DBQ_PIN5      			0x013C      //����������ֿ�������ܽ�λ��
#define FLASH_ADDR_DBQ_PIN6      			0x013D      //�������ҹ��ֿ�������ܽ�λ��
#define FLASH_ADDR_DBQ_MODEL     			0x013E      //�����Ŵ�������������ģʽ
#define FLASH_ADDR_DBQ_RISING_ED   		0x013F      //�����Ŵ�������������������

#define FLASH_ADDR_GCYBP_PIN          0x0140      //�۲��Ǳ��̿�������ܽ�λ��
#define FLASH_ADDR_GCYBP_MODEL       	0x0141      //�۲��Ǳ��̿�������ģʽ
#define FLASH_ADDR_GCYBP_RISING_ED   	0x0142      //�۲��Ǳ��̿�������������
#define FLASH_ADDR_GCYBP_FALLING_ED  	0x0143      //�۲��Ǳ��̿����½�������
#define FLASH_ADDR_GCYBP_TYPE        	0x0144     	//�۲��Ǳ����������ͺͷ�ʽ

#define FLASH_ADDR_TK_PIN          		0x0148      //Ħ�г�ͷ����������ܽ�λ��
#define FLASH_ADDR_TK_MODEL       		0x0149      //Ħ�г�ͷ����������ģʽ
#define FLASH_ADDR_TK_RISING_ED   		0x014A      //Ħ�г�ͷ����������������
#define FLASH_ADDR_TK_FALLING_ED  		0x014B      //Ħ�г�ͷ�������½�������
#define FLASH_ADDR_TK_TYPE        		0x014C     	//Ħ�г�ͷ���������ͺͷ�ʽ

#define FLASH_ADDR_ZBS_PIN          	0x0150      //Ħ�г�����ֿ�������ܽ�λ��
#define FLASH_ADDR_ZBS_MODEL       		0x0151      //Ħ�г�����ֿ�������ģʽ
#define FLASH_ADDR_ZBS_RISING_ED   		0x0152      //Ħ�г�����ֿ�������������
#define FLASH_ADDR_ZBS_FALLING_ED  		0x0153      //Ħ�г�����ֿ����½�������
#define FLASH_ADDR_ZBS_TYPE        		0x0154     	//Ħ�г�������������ͺͷ�ʽ

#define FLASH_ADDR_YBS_PIN          	0x0158      //Ħ�г��Ұ��ֿ�������ܽ�λ��
#define FLASH_ADDR_YBS_MODEL       		0x0159      //Ħ�г��Ұ��ֿ�������ģʽ
#define FLASH_ADDR_YBS_RISING_ED   		0x015A      //Ħ�г��Ұ��ֿ�������������
#define FLASH_ADDR_YBS_FALLING_ED  		0x015B      //Ħ�г��Ұ��ֿ����½�������
#define FLASH_ADDR_YBS_TYPE        		0x015C     	//Ħ�г��Ұ����������ͺͷ�ʽ

#define FLASH_ADDR_ZJTB_PIN          	0x0160      //Ħ�г���̤�忪������ܽ�λ��
#define FLASH_ADDR_ZJTB_MODEL       	0x0161      //Ħ�г���̤�忪������ģʽ
#define FLASH_ADDR_ZJTB_RISING_ED   	0x0162      //Ħ�г���̤�忪������������
#define FLASH_ADDR_ZJTB_FALLING_ED  	0x0163      //Ħ�г���̤�忪���½�������
#define FLASH_ADDR_ZJTB_TYPE        	0x0164     	//Ħ�г���̤���������ͺͷ�ʽ

#define FLASH_ADDR_YJTB_PIN          	0x0168      //Ħ�г���̤�忪������ܽ�λ��
#define FLASH_ADDR_YJTB_MODEL       	0x0169      //Ħ�г���̤�忪������ģʽ
#define FLASH_ADDR_YJTB_RISING_ED   	0x016A      //Ħ�г���̤�忪������������
#define FLASH_ADDR_YJTB_FALLING_ED  	0x016B      //Ħ�г���̤�忪���½�������
#define FLASH_ADDR_YJTB_TYPE        	0x016C     	//Ħ�г���̤���������ͺͷ�ʽ

#define FLASH_ADDR_PGJS_PIN          	0x0170      //���˽��չܽ�λ��
#define FLASH_ADDR_PGJS_MODEL       	0x0171      //���˽�������ģʽ
#define FLASH_ADDR_PGJS_RISING_ED   	0x0172      //���˽�������������
#define FLASH_ADDR_PGJS_FALLING_ED  	0x0173      //���˽����½�������
#define FLASH_ADDR_PGJS_TYPE        	0x0174     	//���˽������ͺͷ�ʽ

//#define FLASH_ADDR_TILT_ADJUST_XL     0x0171      //��Ǵ�����У׼ֵXL
//#define FLASH_ADDR_TILT_ADJUST_XH     0x0172      //��Ǵ�����У׼ֵXH
//#define FLASH_ADDR_TILT_ADJUST_YL     0x0173      //��Ǵ�����У׼ֵYL
//#define FLASH_ADDR_TILT_ADJUST_YH    	0x0174      //��Ǵ�����У׼ֵYH
//#define FLASH_ADDR_TILT_ADJUST_ZERO   0x0175      //����У��д1ʱ�Զ�У׼��ƫ
//#define FLASH_ADDR_TILT_TYPE     			0x0176      //��Ǵ���������


#define FLASH_ADDR_PGJS_1_NAME        0x0180     	//���˽�����Ŀ����
#define FLASH_ADDR_PGJS_1_N0     			0x0181     	//���˽�����Ŀ���
#define FLASH_ADDR_PGJS_1_COUNT      	0x0182     	//��Ŀ�˵�����,���հ�˳�����ΰ�
#define FLASH_ADDR_PGJS_1_TYPE      	0x0183     	//��Ŀ�˵�����

#define FLASH_ADDR_PGJS_2_NAME       	0x0184     	//���˽�����Ŀ����
#define FLASH_ADDR_PGJS_2_N0    			0x0185     	//���˽�����Ŀ���
#define FLASH_ADDR_PGJS_2_COUNT      	0x0186     	//��Ŀ�˵�����,���հ�˳�����ΰ�
#define FLASH_ADDR_PGJS_2_TYPE      	0x0187     	//��Ŀ�˵�����

#define FLASH_ADDR_PGJS_3_NAME       	0x0188     	//���˽�����Ŀ����
#define FLASH_ADDR_PGJS_3_N0     			0x0189     	//���˽�����Ŀ���
#define FLASH_ADDR_PGJS_3_COUNT      	0x018A     	//��Ŀ�˵�����,���հ�˳�����ΰ�
#define FLASH_ADDR_PGJS_3_TYPE      	0x018B     	//��Ŀ�˵�����

#define FLASH_ADDR_PGJS_4_NAME       	0x018C     	//���˽�����Ŀ����
#define FLASH_ADDR_PGJS_4_N0    			0x018D     	//���˽�����Ŀ���
#define FLASH_ADDR_PGJS_4_COUNT     	0x018E     	//��Ŀ�˵�����,���հ�˳�����ΰ�
#define FLASH_ADDR_PGJS_4_TYPE      	0x018F     	//��Ŀ�˵�����



#define FLASH_ADDR_ZS_IDLIN_MIN       0x01D0      //������С�������
#define FLASH_ADDR_ZS_BS              0x01D1      //�����������
#define FLASH_ADDR_ZS_SAMPLING_TIME 	0x01D2      //�������ʱ��
#define FLASH_ADDR_ZS_INIT_VALUE     	0x01D3      //��ʼת�� 0=Ĭ��0��1=Ĭ��800
#define FLASH_ADDR_ZS_PIN							0x01D4      //ת������ܽ�

//#define adds_OBD_on_off           0x01D8      	//OBD����
//#define adds_Card_data_mode       0x01E0     		//���巢������ģʽ0=�������ݣ�1=��������+GPS����
//#define adds_Card_com_mode        0x01E1     		//����ͨѶģʽ0=232ģʽͨѶ��1=485��ʽͨѶ

#define FLASH_ADDR_END                0x01ff     	//������ַ


//ָ�볣����ָ��flash�������ڴ��е��׵�ַ��ȫ�ֱ������ڸ����ļ���ʹ��
extern xdata FlashParameterTypeDef const *const pFlash;
   
void BSP_GetFlashConfig();
void BSP_FlashWriteByte(u16 addr, u8 value);



#endif

