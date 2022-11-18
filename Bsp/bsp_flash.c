#include "./User/includes.h"

xdata FlashParameterTypeDef FlashCacheBuf;//���ڴ���FLASH�еĵ����ݣ���flash�����ݶ���SRAM�У�

//ָ�볣����ָ��flash�������ڴ��е��׵�ַ��ȫ�ֱ������ڸ����ļ���ʹ��
xdata FlashParameterTypeDef const *const pFlash  =  &FlashCacheBuf;
//========================================================================
// ����:BSP_GetFlashConfig(SignalLineTotalTypeDef *pFlash)
// ����: ��ȡflash��������ò���
// ������*pFlashָ����Ҫ�������ݵ��ڴ��׵�ַ3
// �汾: V1.0, 2022-10-17
//========================================================================
void BSP_GetFlashConfig(void)
{

			//��������λ�������Ӵ��ں�
			pFlash->upload.com       			=     IapReadByte(FLASH_ADDR_UPLOAD_COM);     		//��������λ�������Ӵ��ں�
			pFlash->upload.bote         	=     IapReadByte(FLASH_ADDR_UPLOAD_BOTE);      	//��������λ�������Ӵ��ڲ�����
	
			//��������λ�������Ӵ��ں�
			pFlash->gps.com       				=     IapReadByte(FLASH_ADDR_GPS_COM);     				//������GPS�����Ӵ��ں�
			pFlash->gps.bote          		=     IapReadByte(FLASH_ADDR_GPS_BOTE);      			//������GPS�����Ӵ��ڲ�����
	
	
			//�������ɭ���˴��������ӵĴ���
			pFlash->bump_hs.com       		=     IapReadByte(FLASH_ADDR_BUMP_HS_COM);     		//��������λ�������Ӵ��ں�
			pFlash->bump_hs.bote         	=     IapReadByte(FLASH_ADDR_BUMP_HS_BOTE);      	//��������λ�������Ӵ��ڲ�����
	
			//������2.4G���˴��������ӵĴ���
			pFlash->bump_24g.com       		=     IapReadByte(FLASH_ADDR_BUMP_24G_COM);     	//������2.4G���˴��������Ӵ��ں�
			pFlash->bump_24g.bote        	=     IapReadByte(FLASH_ADDR_BUMP_24G_BOTE);      //������2.4G���˴��������Ӵ��ڲ�����
	
	
			//������������ӵĴ��ڣ����ܺ��ϴ���
			pFlash->titl_all.com       		=     IapReadByte(FLASH_ADDR_TILT_ALL_COM);    		//������������ӵĴ��ڣ����ܺ��ϴ������ں�
			pFlash->titl_all.bote       	=     IapReadByte(FLASH_ADDR_TILT_BOTE);      		//������������ӵĴ��ڲ�����
	
			//������ǰ����Ǵ����������Ӵ��ںţ������������ӣ�
			pFlash->titl_q.com       			=     IapReadByte(FLASH_ADDR_TILT_Q_COM);     		//������ǰ����Ǵ����������Ӵ��ںţ������������ӣ�
			pFlash->titl_q.bote       		=     IapReadByte(FLASH_ADDR_TILT_BOTE);      	  //������������ӵĴ��ڲ�����
			
			//�����������Ǵ����������Ӵ��ںţ������������ӣ�
			pFlash->titl_h.com       			=     IapReadByte(FLASH_ADDR_TILT_H_COM);     		//�����������Ǵ����������Ӵ��ںţ������������ӣ�
			pFlash->titl_h.bote       		=     IapReadByte(FLASH_ADDR_TILT_BOTE);      	  //������������ӵĴ��ڲ�����
			
			//�����������Ǵ����������Ӵ��ںţ������������ӣ�
			pFlash->titl_g.com       			=     IapReadByte(FLASH_ADDR_TILT_G_COM);     		//�����������Ǵ����������Ӵ��ںţ������������ӣ�
			pFlash->titl_g.bote       		=     IapReadByte(FLASH_ADDR_TILT_BOTE);      	  //������������ӵĴ��ڲ�����
			
			//���������Ħ�г���Ǵ����������Ӵ��ںţ������������ӣ�
			pFlash->titl_mtc.com       		=     IapReadByte(FLASH_ADDR_TILT_MTC_COM);     	//���������Ħ�г���Ǵ����������Ӵ��ںţ������������ӣ�
			pFlash->titl_mtc.bote       	=     IapReadByte(FLASH_ADDR_TILT_BOTE);      	  //������������ӵĴ��ڲ�����
			
			//��������ģ��
			pFlash->network.com       		=     IapReadByte(FLASH_ADDR_NETWORK_COM);     		//��������ģ���Ƿ�����
	
			//���ο��أ����ڣ�
			pFlash->zytj.pin       		 		=     IapReadByte(FLASH_ADDR_ZYTJ_PIN);     			//���ο��أ����ڣ�����ܽ�λ��
			pFlash->zytj.modle           	=     IapReadByte(FLASH_ADDR_ZYTJ_MODEL);      		//���ο��أ����ڣ�����ģʽ
			pFlash->zytj.rising_ed     		=     IapReadByte(FLASH_ADDR_ZYTJ_RISING_ED);    	//���ο��أ����ڣ�����������
			pFlash->zytj.falling_ed     	=     IapReadByte(FLASH_ADDR_ZYTJ_FALLING_ED);  	//���ο��أ����ڣ��½�������
			pFlash->zytj.type     				=     IapReadByte(FLASH_ADDR_ZYTJ_TYPE);  				//���ο��أ����ڣ��������ͺͷ�ʽ
			//��ɲ����
	    pFlash->ss.pin               	=     IapReadByte(FLASH_ADDR_SS_PIN);           	//��ɲ��������ܽ�λ��
			pFlash->ss.modle             	=     IapReadByte(FLASH_ADDR_SS_MODEL);        		//��ɲ��������ģʽ
			pFlash->ss.rising_ed         	=     IapReadByte(FLASH_ADDR_SS_RISING_ED);      	//��ɲ��������������
			pFlash->ss.falling_ed        	=     IapReadByte(FLASH_ADDR_SS_FALLING_ED);    	//��ɲ�����½�������
			pFlash->ss.type     					=     IapReadByte(FLASH_ADDR_SS_TYPE);  					//��ɲ�����������ͺͷ�ʽ
			//��ת����
		  pFlash->zz.pin               	=     IapReadByte(FLASH_ADDR_ZZ_PIN);           	//��ת��������ܽ�λ��
			pFlash->zz.modle             	=     IapReadByte(FLASH_ADDR_ZZ_MODEL);        		//��ת��������ģʽ
			pFlash->zz.rising_ed         	=     IapReadByte(FLASH_ADDR_ZZ_RISING_ED);      	//��ת��������������
			pFlash->zz.falling_ed        	=     IapReadByte(FLASH_ADDR_ZZ_FALLING_ED);    	//��ת�����½�������
			pFlash->zz.type     					=     IapReadByte(FLASH_ADDR_ZZ_TYPE);  					//��ת�����������ͺͷ�ʽ
			//��ת����
			pFlash->yz.pin               	=     IapReadByte(FLASH_ADDR_YZ_PIN);           	//��ת��������ܽ�λ��
			pFlash->yz.modle             	=     IapReadByte(FLASH_ADDR_YZ_MODEL);        		//��ת��������ģʽ
			pFlash->yz.rising_ed         	=     IapReadByte(FLASH_ADDR_YZ_RISING_ED);      	//��ת��������������
			pFlash->yz.falling_ed        	=     IapReadByte(FLASH_ADDR_YZ_FALLING_ED);    	//��ת�����½�������
			pFlash->yz.type     					=     IapReadByte(FLASH_ADDR_YZ_TYPE);  					//��ת�����������ͺͷ�ʽ
			//Զ�⿪��
			pFlash->yg.pin               	=     IapReadByte(FLASH_ADDR_YG_PIN);           	//Զ�⿪������ܽ�λ��
			pFlash->yg.modle             	=     IapReadByte(FLASH_ADDR_YG_MODEL);        		//Զ�⿪������ģʽ
			pFlash->yg.rising_ed         	=     IapReadByte(FLASH_ADDR_YG_RISING_ED);      	//Զ�⿪������������
			pFlash->yg.falling_ed       	=     IapReadByte(FLASH_ADDR_YG_FALLING_ED);    	//Զ�⿪���½�������
			pFlash->yg.type     					=     IapReadByte(FLASH_ADDR_YG_TYPE);  					//Զ�⿪���������ͺͷ�ʽ
			//���⿪��
			pFlash->jg.pin               	=     IapReadByte(FLASH_ADDR_JG_PIN);           	//���⿪������ܽ�λ��
			pFlash->jg.modle             	=     IapReadByte(FLASH_ADDR_JG_MODEL);        		//���⿪������ģʽ
			pFlash->jg.rising_ed         	=     IapReadByte(FLASH_ADDR_JG_RISING_ED);       //���⿪������������
			pFlash->jg.falling_ed        	=     IapReadByte(FLASH_ADDR_JG_FALLING_ED);    	//���⿪���½�������
			pFlash->jg.type     					=     IapReadByte(FLASH_ADDR_JG_TYPE);  					//���⿪���������ͺͷ�ʽ
			//��Ͽ���
		  pFlash->lh.pin               	=     IapReadByte(FLASH_ADDR_LH_PIN);           	//��Ͽ�������ܽ�λ��
			pFlash->lh.modle             	=     IapReadByte(FLASH_ADDR_LH_MODEL);        		//��Ͽ�������ģʽ
			pFlash->lh.rising_ed         	=     IapReadByte(FLASH_ADDR_LH_RISING_ED);      	//��Ͽ�������������
			pFlash->lh.falling_ed       	=     IapReadByte(FLASH_ADDR_LH_FALLING_ED);    	//��Ͽ����½�������
			pFlash->lh.type     					=     IapReadByte(FLASH_ADDR_LH_TYPE);  					//��Ͽ����������ͺͷ�ʽ
			//��ɲ����
		  pFlash->js.pin               	=     IapReadByte(FLASH_ADDR_JS_PIN);             //��ɲ��������ܽ�λ��
			pFlash->js.modle             	=     IapReadByte(FLASH_ADDR_JS_MODEL);           //��ɲ��������ģʽ
			pFlash->js.rising_ed         	=     IapReadByte(FLASH_ADDR_JS_RISING_ED);       //��ɲ��������������
			pFlash->js.falling_ed        	=     IapReadByte(FLASH_ADDR_JS_FALLING_ED);      //��ɲ�����½�������
			pFlash->js.type     					=     IapReadByte(FLASH_ADDR_JS_TYPE);  					//��ɲ�����������ͺͷ�ʽ
			//Ϩ�𿪹�
	    pFlash->xh.pin               	=     IapReadByte(FLASH_ADDR_XH_PIN);           	//Ϩ�𿪹�����ܽ�λ��
			pFlash->xh.modle             	=     IapReadByte(FLASH_ADDR_XH_MODEL);        		//Ϩ�𿪹�����ģʽ
			pFlash->xh.rising_ed         	=     IapReadByte(FLASH_ADDR_XH_RISING_ED);      	//Ϩ�𿪹�����������
			pFlash->xh.falling_ed        	=     IapReadByte(FLASH_ADDR_XH_FALLING_ED);    	//Ϩ�𿪹��½�������
			pFlash->xh.type              	=     IapReadByte(FLASH_ADDR_XH_TYPE);          	//Ϩ�𿪹����з�ʽ
			//��������
		  pFlash->qd.pin               	=     IapReadByte(FLASH_ADDR_QD_PIN);             //������������ܽ�λ��
			pFlash->qd.modle             	=     IapReadByte(FLASH_ADDR_QD_MODEL);           //������������ģʽ
			pFlash->qd.rising_ed         	=     IapReadByte(FLASH_ADDR_QD_RISING_ED);      	//������������������
			pFlash->qd.falling_ed        	=     IapReadByte(FLASH_ADDR_QD_FALLING_ED);    	//���������½�������
			pFlash->qd.type              	=     IapReadByte(FLASH_ADDR_QD_TYPE);          	//������ʽ	
			//��ȫ������
			pFlash->aqd.pin             	=     IapReadByte(FLASH_ADDR_AQD_PIN);           	//��ȫ����������ܽ�λ��
			pFlash->aqd.modle            	=     IapReadByte(FLASH_ADDR_AQD_MODEL);        	//��ȫ����������ģʽ
			pFlash->aqd.rising_ed        	=     IapReadByte(FLASH_ADDR_AQD_RISING_ED);      //��ȫ����������������
			pFlash->aqd.falling_ed       	=     IapReadByte(FLASH_ADDR_AQD_FALLING_ED);    	//��ȫ�������½�������
			pFlash->aqd.type     					=     IapReadByte(FLASH_ADDR_AQD_TYPE);  					//��ȫ�������������ͺͷ�ʽ
			//С�ƿ���
			pFlash->xd.pin               	=     IapReadByte(FLASH_ADDR_XD_PIN);           	//С�ƿ�������ܽ�λ��
			pFlash->xd.modle             	=     IapReadByte(FLASH_ADDR_XD_MODEL);        		//С�ƿ�������ģʽ
			pFlash->xd.rising_ed         	=     IapReadByte(FLASH_ADDR_XD_RISING_ED);      	//С�ƿ�������������
			pFlash->xd.falling_ed        	=     IapReadByte(FLASH_ADDR_XD_FALLING_ED);    	//С�ƿ����½�������
			pFlash->xd.type     					=     IapReadByte(FLASH_ADDR_XD_TYPE);  					//С�ƿ����������ͺͷ�ʽ
			//���ȿ���
		  pFlash->lb.pin               	=     IapReadByte(FLASH_ADDR_LB_PIN);           	//���ȿ�������ܽ�λ��
			pFlash->lb.modle             	=     IapReadByte(FLASH_ADDR_LB_MODEL);        		//���ȿ�������ģʽ
			pFlash->lb.rising_ed         	=     IapReadByte(FLASH_ADDR_LB_RISING_ED);      	//���ȿ�������������
			pFlash->lb.falling_ed        	=     IapReadByte(FLASH_ADDR_LB_FALLING_ED);    	//���ȿ����½�������
			pFlash->lb.type     					=     IapReadByte(FLASH_ADDR_LB_TYPE);  					//���ȿ����������ͺͷ�ʽ
			//���ſ���
		  pFlash->cm.pin               	=     IapReadByte(FLASH_ADDR_CM_PIN);           	//���ſ�������ܽ�λ��
			pFlash->cm.modle             	=     IapReadByte(FLASH_ADDR_CM_MODEL);        		//���ſ�������ģʽ
			pFlash->cm.rising_ed         	=     IapReadByte(FLASH_ADDR_CM_RISING_ED);      	//���ſ�������������
			pFlash->cm.falling_ed       	=     IapReadByte(FLASH_ADDR_CM_FALLING_ED);    	//���ſ����½�������
			pFlash->cm.type     					=     IapReadByte(FLASH_ADDR_CM_TYPE);  					//���ſ����������ͺͷ�ʽ
			//��λ������
		  pFlash->dw.pin1              	=     IapReadByte(FLASH_ADDR_DW_PIN1);          	//��λ�������ź���1����ܽ�λ��
			pFlash->dw.pin2            		=     IapReadByte(FLASH_ADDR_DW_PIN2);       			//��λ�������ź���2����ܽ�λ��
			pFlash->dw.pin3         			=     IapReadByte(FLASH_ADDR_DW_PIN3);     				//��λ�������ź���3����ܽ�λ��
			pFlash->dw.pin4       				=     IapReadByte(FLASH_ADDR_DW_PIN4);   					//��λ�������ź���4����ܽ�λ��
			pFlash->dw.modle             	=     IapReadByte(FLASH_ADDR_DW_MODEL);       		//��λ����������ģʽ
			pFlash->dw.rising_ed        	=     IapReadByte(FLASH_ADDR_DW_RISING_ED);     	//��λ����������������
			pFlash->dw.falling_ed        	=     IapReadByte(FLASH_ADDR_DW_FALLING_ED);   		//��λ�������½�������
			pFlash->dw.type              	=     IapReadByte(FLASH_ADDR_DW_TYPE);         		//��λ����������
			//����ӿ���
			pFlash->zhs.pin              	=     IapReadByte(FLASH_ADDR_ZHS_PIN);          	//����ӿ�������ܽ�λ��
			pFlash->zhs.modle            	=     IapReadByte(FLASH_ADDR_ZHS_MODEL);       		//����ӿ�������ģʽ
			pFlash->zhs.rising_ed        	=     IapReadByte(FLASH_ADDR_ZHS_RISING_ED);     	//����ӿ�������������
			pFlash->zhs.falling_ed      	=     IapReadByte(FLASH_ADDR_ZHS_FALLING_ED);   	//����ӿ����½�������
			pFlash->zhs.type     					=     IapReadByte(FLASH_ADDR_ZHS_TYPE);  					//����ӿ����������ͺͷ�ʽ
			//�ں��ӿ���
			pFlash->nhs.pin              	=     IapReadByte(FLASH_ADDR_NHS_PIN);          	//�ں��ӿ�������ܽ�λ��
			pFlash->nhs.modle            	=     IapReadByte(FLASH_ADDR_NHS_MODEL);       		//�ں��ӿ�������ģʽ
			pFlash->nhs.rising_ed        	=     IapReadByte(FLASH_ADDR_NHS_RISING_ED);     	//�ں��ӿ�������������
			pFlash->nhs.falling_ed       	=     IapReadByte(FLASH_ADDR_NHS_FALLING_ED);   	//�ں��ӿ����½�������
			pFlash->nhs.type     				 	=     IapReadByte(FLASH_ADDR_NHS_TYPE);  					//�ں��ӿ����������ͺͷ�ʽ
			//��ɲ����
			pFlash->fsc.pin              	=     IapReadByte(FLASH_ADDR_FSC_PIN);           	//��ɲ��������ܽ�λ��
			pFlash->fsc.modle            	=     IapReadByte(FLASH_ADDR_FSC_MODEL);        	//��ɲ��������ģʽ
			pFlash->fsc.rising_ed        	=     IapReadByte(FLASH_ADDR_FSC_RISING_ED);      //��ɲ��������������
			pFlash->fsc.falling_ed       	=     IapReadByte(FLASH_ADDR_FSC_FALLING_ED);    	//��ɲ�����½�������
			pFlash->fsc.type     					=     IapReadByte(FLASH_ADDR_FSC_TYPE);  					//��ɲ�����������ͺͷ�ʽ
			//��ƿ���
			pFlash->wd.pin               	=     IapReadByte(FLASH_ADDR_WD_PIN);           	//��ƿ�������ܽ�λ��
			pFlash->wd.modle             	=     IapReadByte(FLASH_ADDR_WD_MODEL);        		//��ƿ�������ģʽ
			pFlash->wd.rising_ed         	=     IapReadByte(FLASH_ADDR_WD_RISING_ED);      	//��ƿ�������������
			pFlash->wd.falling_ed        	=     IapReadByte(FLASH_ADDR_WD_FALLING_ED);    	//��ƿ����½�������
			pFlash->wd.type     					=     IapReadByte(FLASH_ADDR_WD_TYPE);  					//��ƿ����������ͺͷ�ʽ
			//��ˢ����
	    pFlash->ys.pin               	=     IapReadByte(FLASH_ADDR_YS_PIN);           	//��ˢ��������ܽ�λ��
			pFlash->ys.modle             	=     IapReadByte(FLASH_ADDR_YS_MODEL);        		//��ˢ��������ģʽ
			pFlash->ys.rising_ed         	=     IapReadByte(FLASH_ADDR_YS_RISING_ED);      	//��ˢ��������������
			pFlash->ys.falling_ed        	=     IapReadByte(FLASH_ADDR_YS_FALLING_ED);    	//��ˢ�����½�������
			pFlash->ys.type     					=     IapReadByte(FLASH_ADDR_YS_TYPE);  					//��ˢ�����������ͺͷ�ʽ
			//�����ƿ���
			pFlash->dcd.pin              	=     IapReadByte(FLASH_ADDR_DCD_PIN);           	//�����ƿ�������ܽ�λ��
			pFlash->dcd.modle           	=     IapReadByte(FLASH_ADDR_DCD_MODEL);        	//�����ƿ�������ģʽ
			pFlash->dcd.rising_ed        	=     IapReadByte(FLASH_ADDR_DCD_RISING_ED);      //�����ƿ�������������
			pFlash->dcd.falling_ed       	=     IapReadByte(FLASH_ADDR_DCD_FALLING_ED);    	//�����ƿ����½�������
			pFlash->dcd.type     					=     IapReadByte(FLASH_ADDR_DCD_TYPE);  					//�����ƿ����������ͺͷ�ʽ
			//Կ���ſ���
			pFlash->ysm.pin            		=     IapReadByte(FLASH_ADDR_YSM_PIN);           	//Կ���ſ�������ܽ�λ��
			pFlash->ysm.modle          		=     IapReadByte(FLASH_ADDR_YSM_MODEL);       		//Կ���ſ�������ģʽ
			pFlash->ysm.rising_ed      		=     IapReadByte(FLASH_ADDR_YSM_RISING_ED);      //Կ���ſ�������������
			pFlash->ysm.falling_ed    		=     IapReadByte(FLASH_ADDR_YSM_FALLING_ED);    	//Կ���ſ����½�������
			pFlash->ysm.type     					=     IapReadByte(FLASH_ADDR_YSM_TYPE);  					//Կ���ſ����������ͺͷ�ʽ
			//�Ƴ�����1
		  pFlash->rc.pin1             	=     IapReadByte(FLASH_ADDR_RC_PIN1);           	//�Ƴ�1�ſ�������ܽ�λ��
			pFlash->rc.pin2           		=     IapReadByte(FLASH_ADDR_RC_PIN2);        		//�Ƴ�2�ſ�������ܽ�λ��
			pFlash->rc.pin3       				=     IapReadByte(FLASH_ADDR_RC_PIN3);      			//�Ƴ�3�ſ�������ܽ�λ��
			pFlash->rc.modle           		=     IapReadByte(FLASH_ADDR_RC_MODEL);        		//�Ƴ���������ģʽ
			pFlash->rc.rising_ed       		=     IapReadByte(FLASH_ADDR_RC_RISING_ED);      	//�Ƴ���������������
			pFlash->rc.falling_ed      		=     IapReadByte(FLASH_ADDR_RC_FALLING_ED);    	//�Ƴ������½�������
			pFlash->rc.type            		=     IapReadByte(FLASH_ADDR_RC_TYPE);          	//�Ƴ�����1����
			//��������
			pFlash->cd.pin            		=     IapReadByte(FLASH_ADDR_CD_PIN);            	//������������ܽ�λ��
			pFlash->cd.modle         			=     IapReadByte(FLASH_ADDR_CD_MODEL);         	//������������ģʽ
			pFlash->cd.rising_ed      		=     IapReadByte(FLASH_ADDR_CD_RISING_ED);       //������������������
			pFlash->cd.falling_ed     		=     IapReadByte(FLASH_ADDR_CD_FALLING_ED);     	//���������½�������
			pFlash->cd.type     					=     IapReadByte(FLASH_ADDR_CD_TYPE);  					//���������������ͺͷ�ʽ
			//���ο��أ�ѹ����
		  pFlash->zyyl.pin             	=     IapReadByte(FLASH_ADDR_ZYYL_PIN);          	//���ο��أ�ѹ��������ܽ�λ��
			pFlash->zyyl.modle           	=     IapReadByte(FLASH_ADDR_ZYYL_MODEL);       	//���ο��أ�ѹ��������ģʽ
			pFlash->zyyl.rising_ed       	=     IapReadByte(FLASH_ADDR_ZYYL_RISING_ED);     //���ο��أ�ѹ��������������
			pFlash->zyyl.falling_ed      	=     IapReadByte(FLASH_ADDR_ZYYL_FALLING_ED);   	//���ο����½�������
			pFlash->zyyl.type     				=     IapReadByte(FLASH_ADDR_ZYYL_TYPE);  				//���ο����������ͺͷ�ʽ
			//�۲��Ǳ���
		  pFlash->gcybp.pin            	=     IapReadByte(FLASH_ADDR_GCYBP_PIN);          //�۲��Ǳ�������ܽ�λ��
			pFlash->gcybp.modle          	=     IapReadByte(FLASH_ADDR_GCYBP_MODEL);       	//�۲��Ǳ�������ģʽ
			pFlash->gcybp.rising_ed      	=     IapReadByte(FLASH_ADDR_GCYBP_RISING_ED);    //�۲��Ǳ�������������
			pFlash->gcybp.falling_ed     	=     IapReadByte(FLASH_ADDR_GCYBP_FALLING_ED);   //�۲��Ǳ����½�������
			pFlash->gcybp.type     				=     IapReadByte(FLASH_ADDR_GCYBP_TYPE);  				//�۲��Ǳ����������ͺͷ�ʽ
			//ת��
			pFlash->zs.pin            		=     IapReadByte(FLASH_ADDR_ZS_PIN);         		 //ת������ܽ�λ��
			pFlash->zs.min          			=     IapReadByte(FLASH_ADDR_ZS_IDLIN_MIN);        //ת�ٵ�����С�������
			pFlash->zs.bs      						=     IapReadByte(FLASH_ADDR_ZS_BS);    					 //ת����������Ŵ���
			pFlash->zs.sampling_time     	=     IapReadByte(FLASH_ADDR_ZS_SAMPLING_TIME);    //ת���������ʱ��
			pFlash->zs.init_value     		=     IapReadByte(FLASH_ADDR_ZS_INIT_VALUE);			 //��ʼת�� 0=Ĭ��0��1=Ĭ��800
			//�����Ŵ�����
			pFlash->dbq.pin1            	=     IapReadByte(FLASH_ADDR_DBQ_PIN1);         		//�������ź�����ܽ�λ��1
			pFlash->dbq.pin2          		=     IapReadByte(FLASH_ADDR_DBQ_PIN2);        			//�������ź�����ܽ�λ��2
			pFlash->dbq.pin3      				=     IapReadByte(FLASH_ADDR_DBQ_PIN3);    					//�������ź�����ܽ�λ��3
			pFlash->dbq.pin4     					=     IapReadByte(FLASH_ADDR_DBQ_PIN4);    					//�������ź�����ܽ�λ��4
			pFlash->dbq.pin5     					=     IapReadByte(FLASH_ADDR_DBQ_PIN5);			 				//�������ź�����ܽ�λ��5
			pFlash->dbq.pin6            	=     IapReadByte(FLASH_ADDR_DBQ_PIN6);         		//�������ź�����ܽ�λ��6
			pFlash->dbq.modle          		=     IapReadByte(FLASH_ADDR_DBQ_MODEL);        		//�������ź�����ģʽ
			pFlash->dbq.rising_ed      		=     IapReadByte(FLASH_ADDR_DBQ_RISING_ED);    		//�������ź���������������ʱ��
			pFlash->dbq.falling_ed    		=     IapReadByte(FLASH_ADDR_DBQ_FALLING_ED);    		//�������ź������½�������ʱ��
			pFlash->dbq.type     					=     IapReadByte(FLASH_ADDR_DBQ_TYPE);			 				//�������ź����봫��������		
#ifdef  STC15W4K48S4			
			//Ħ�г�ͷ��������
		  pFlash->tk.pin             		=     	IapReadByte(FLASH_ADDR_TK_PIN);          			//Ħ�г�ͷ�����أ�ѹ��������ܽ�λ��
			pFlash->tk.modle           		=     	IapReadByte(FLASH_ADDR_TK_MODEL);       			//Ħ�г�ͷ�����أ�ѹ��������ģʽ
			pFlash->tk.rising_ed       		=     	IapReadByte(FLASH_ADDR_TK_RISING_ED);     		//Ħ�г�ͷ�����أ�ѹ��������������
			pFlash->tk.falling_ed      		=     	IapReadByte(FLASH_ADDR_TK_FALLING_ED);   			//Ħ�г�ͷ�������½�������
			pFlash->tk.type     					=     	IapReadByte(FLASH_ADDR_TK_TYPE);  						//Ħ�г�ͷ�������������ͺͷ�ʽ	
			
			//Ħ�г�����ִ�����
		  pFlash->zbs.pin             	=     	IapReadByte(FLASH_ADDR_ZBS_PIN);          		//Ħ�г�����ֿ��أ�ѹ��������ܽ�λ��
			pFlash->zbs.modle           	=     	IapReadByte(FLASH_ADDR_ZBS_MODEL);       			//Ħ�г�����ֿ��أ�ѹ��������ģʽ
			pFlash->zbs.rising_ed       	=     	IapReadByte(FLASH_ADDR_ZBS_RISING_ED);     		//Ħ�г�����ֿ��أ�ѹ��������������
			pFlash->zbs.falling_ed      	=     	IapReadByte(FLASH_ADDR_ZBS_FALLING_ED);   		//Ħ�г�����ֿ����½�������
			pFlash->zbs.type     					=     	IapReadByte(FLASH_ADDR_ZBS_TYPE);  						//Ħ�г�����ֿ����������ͺͷ�ʽ	
			
			//Ħ�г��Ұ��ִ�����
		  pFlash->ybs.pin             	=     	IapReadByte(FLASH_ADDR_YBS_PIN);          		//Ħ�г��Ұ��ֿ��أ�ѹ��������ܽ�λ��
			pFlash->ybs.modle           	=     	IapReadByte(FLASH_ADDR_YBS_MODEL);       			//Ħ�г��Ұ��ֿ��أ�ѹ��������ģʽ
			pFlash->ybs.rising_ed       	=     	IapReadByte(FLASH_ADDR_YBS_RISING_ED);     		//Ħ�г��Ұ��ֿ��أ�ѹ��������������
			pFlash->ybs.falling_ed      	=     	IapReadByte(FLASH_ADDR_YBS_FALLING_ED);   		//Ħ�г��Ұ��ֿ����½�������
			pFlash->ybs.type     					=     	IapReadByte(FLASH_ADDR_YBS_TYPE);  						//Ħ�г��Ұ��ֿ����������ͺͷ�ʽ	
			
			//Ħ�г���̤�崫����
		  pFlash->zjtb.pin             	=     	IapReadByte(FLASH_ADDR_ZJTB_PIN);          		//Ħ�г���̤�忪�أ�ѹ��������ܽ�λ��
			pFlash->zjtb.modle           	=     	IapReadByte(FLASH_ADDR_ZJTB_MODEL);       		//Ħ�г���̤�忪�أ�ѹ��������ģʽ
			pFlash->zjtb.rising_ed       	=     	IapReadByte(FLASH_ADDR_ZJTB_RISING_ED);     	//Ħ�г���̤�忪�أ�ѹ��������������
			pFlash->zjtb.falling_ed      	=     	IapReadByte(FLASH_ADDR_ZJTB_FALLING_ED);   		//Ħ�г���̤�忪���½�������
			pFlash->zjtb.type     				=     	IapReadByte(FLASH_ADDR_ZJTB_TYPE);  					//Ħ�г���̤�忪���������ͺͷ�ʽ	
			
			//Ħ�г���̤�崫����
		  pFlash->yjtb.pin             	=     	IapReadByte(FLASH_ADDR_YJTB_PIN);          		//Ħ�г���̤�忪�أ�ѹ��������ܽ�λ��
			pFlash->yjtb.modle           	=     	IapReadByte(FLASH_ADDR_YJTB_MODEL);       		//Ħ�г���̤�忪�أ�ѹ��������ģʽ
			pFlash->yjtb.rising_ed       	=     	IapReadByte(FLASH_ADDR_YJTB_RISING_ED);     	//Ħ�г���̤�忪�أ�ѹ��������������
			pFlash->yjtb.falling_ed      	=     	IapReadByte(FLASH_ADDR_YJTB_FALLING_ED);   		//Ħ�г���̤�忪���½�������
			pFlash->yjtb.type     				=     	IapReadByte(FLASH_ADDR_YJTB_TYPE);  					//Ħ�г���̤�忪���������ͺͷ�ʽ	
			
			//���˽���
		  pFlash->pgjs.pin             	=     	IapReadByte(FLASH_ADDR_PGJS_PIN);          		//������Ŀ�ܽ�λ��
			pFlash->pgjs.modle          	=     	IapReadByte(FLASH_ADDR_PGJS_MODEL);       		//������Ŀ����ģʽ
			pFlash->pgjs.rising_ed       	=     	IapReadByte(FLASH_ADDR_PGJS_RISING_ED);     	//������Ŀ����������
			pFlash->pgjs.falling_ed      	=     	IapReadByte(FLASH_ADDR_PGJS_FALLING_ED);   		//������Ŀ�½�������
			pFlash->pgjs.type     				=     	IapReadByte(FLASH_ADDR_PGJS_TYPE);  					//������Ŀ�������ͺͷ�ʽ	
			
			//������Ŀ1
		  pFlash->bump[0].name          =     	IapReadByte(FLASH_ADDR_PGJS_1_NAME);          //������Ŀ����
			pFlash->bump[0].number        =     	IapReadByte(FLASH_ADDR_PGJS_1_N0);       			//������Ŀ���
			pFlash->bump[0].count       	=     	IapReadByte(FLASH_ADDR_PGJS_1_COUNT);     		//������Ŀ��Ӧ�˵�����
			pFlash->bump[0].type       		=     	IapReadByte(FLASH_ADDR_PGJS_1_TYPE);     			//������Ŀ��Ӧ����������
			
			//������Ŀ2
		  pFlash->bump[1].name          =     	IapReadByte(FLASH_ADDR_PGJS_2_NAME);          //������Ŀ����
			pFlash->bump[1].number        =     	IapReadByte(FLASH_ADDR_PGJS_2_N0);       			//������Ŀ���
			pFlash->bump[1].count       	=     	IapReadByte(FLASH_ADDR_PGJS_2_COUNT);     		//������Ŀ��Ӧ�˵�����
			pFlash->bump[1].type       		=     	IapReadByte(FLASH_ADDR_PGJS_2_TYPE);     			//������Ŀ��Ӧ����������
			
			//������Ŀ3
		  pFlash->bump[2].name          =     	IapReadByte(FLASH_ADDR_PGJS_3_NAME);          //������Ŀ����
			pFlash->bump[2].number        =     	IapReadByte(FLASH_ADDR_PGJS_3_N0);       			//������Ŀ���
			pFlash->bump[2].count       	=     	IapReadByte(FLASH_ADDR_PGJS_3_COUNT);     		//������Ŀ��Ӧ�˵�����
			pFlash->bump[2].type       		=     	IapReadByte(FLASH_ADDR_PGJS_3_TYPE);     			//������Ŀ��Ӧ����������
			
			//������Ŀ4
		  pFlash->bump[3].name          =     	IapReadByte(FLASH_ADDR_PGJS_4_NAME);          //������Ŀ����
			pFlash->bump[3].number        =     	IapReadByte(FLASH_ADDR_PGJS_4_N0);       			//������Ŀ���
			pFlash->bump[3].count       	=     	IapReadByte(FLASH_ADDR_PGJS_4_COUNT);     		//������Ŀ��Ӧ�˵�����
			pFlash->bump[3].type       		=     	IapReadByte(FLASH_ADDR_PGJS_4_TYPE);     			//������Ŀ��Ӧ����������
#endif
}
//========================================================================
// ����: BPS_FlashWriteByte(u16 addr, u8 value)
// ����: �����ֽ�д��flash��д��ǰ�ȱ�������
// ������addrΪҪд���ֽ����ݵĵ�ַ��valueΪ�ֽ�����
// �汾: V1.0, 2022-10-17
//========================================================================
void BSP_FlashWriteByte(u16 addr, u8 value)
{

	BSP_GetFlashConfig();//����flash����
	IapEraseSector(addr);//��������
	//д������
	
	//��������λ�������Ӵ��ں�
	addr == FLASH_ADDR_UPLOAD_COM 				? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_UPLOAD_COM, FlashCacheBuf.upload.com);
	addr == FLASH_ADDR_UPLOAD_BOTE 				? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_UPLOAD_BOTE, FlashCacheBuf.upload.bote);
	
	//������GPS���Ӵ��ں�
	addr == FLASH_ADDR_GPS_COM 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_GPS_COM, FlashCacheBuf.gps.com);
	addr == FLASH_ADDR_GPS_BOTE 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_GPS_BOTE, FlashCacheBuf.gps.bote);
	
	//�������ɭ���˴��������ӵĴ���
	addr == FLASH_ADDR_BUMP_HS_COM 				? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_BUMP_HS_COM, FlashCacheBuf.bump_hs.com);
	addr == FLASH_ADDR_BUMP_HS_BOTE 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_BUMP_HS_BOTE, FlashCacheBuf.bump_hs.bote);
	
	//������2.4G���˴��������ӵĴ���
	addr == FLASH_ADDR_BUMP_24G_COM 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_BUMP_24G_COM, FlashCacheBuf.bump_24g.com);
	addr == FLASH_ADDR_BUMP_24G_BOTE 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_BUMP_24G_BOTE, FlashCacheBuf.bump_24g.bote);
		
	//������������ӵĴ��ڣ����ܺ���룩
	addr == FLASH_ADDR_TILT_ALL_COM 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_TILT_ALL_COM, FlashCacheBuf.titl_all.com);
	addr == FLASH_ADDR_TILT_BOTE 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_TILT_BOTE, FlashCacheBuf.titl_all.bote);
	
	//������ǰ����Ǵ����������Ӵ��ںţ������������ӣ�
	addr == FLASH_ADDR_TILT_Q_COM 				? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_TILT_Q_COM, FlashCacheBuf.titl_q.com);
	addr == FLASH_ADDR_TILT_BOTE 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_TILT_BOTE, FlashCacheBuf.titl_q.bote);
	
	//�����������Ǵ����������Ӵ��ںţ������������ӣ�
	addr == FLASH_ADDR_TILT_H_COM 				? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_TILT_H_COM, FlashCacheBuf.titl_h.com);
	addr == FLASH_ADDR_TILT_BOTE 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_TILT_BOTE, FlashCacheBuf.titl_h.bote);
	
	//�����������Ǵ����������Ӵ��ںţ������������ӣ�
	addr == FLASH_ADDR_TILT_G_COM 				? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_TILT_G_COM, FlashCacheBuf.titl_g.com);
	addr == FLASH_ADDR_TILT_BOTE 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_TILT_BOTE, FlashCacheBuf.titl_g.bote);
	
	//���������Ħ�г���Ǵ����������Ӵ��ںţ������������ӣ�
	addr == FLASH_ADDR_TILT_MTC_COM 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_TILT_MTC_COM, FlashCacheBuf.titl_mtc.com);
	addr == FLASH_ADDR_TILT_BOTE 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_TILT_BOTE, FlashCacheBuf.titl_mtc.bote);
	
	//��������ģ��
	addr == FLASH_ADDR_NETWORK_COM 				? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_NETWORK_COM, FlashCacheBuf.network.com);

	//���ο��أ����ڣ�
	addr == FLASH_ADDR_ZYTJ_PIN 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZYTJ_PIN, FlashCacheBuf.zytj.pin);
	addr == FLASH_ADDR_ZYTJ_MODEL 				? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZYTJ_MODEL,FlashCacheBuf.zytj.modle);
	addr == FLASH_ADDR_ZYTJ_RISING_ED 		? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZYTJ_RISING_ED,FlashCacheBuf.zytj.rising_ed);
	addr == FLASH_ADDR_ZYTJ_FALLING_ED 		? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZYTJ_FALLING_ED,FlashCacheBuf.zytj.falling_ed);
	addr == FLASH_ADDR_ZYTJ_TYPE 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZYTJ_TYPE,	FlashCacheBuf.zytj.type);
  //��ɲ����
	addr == FLASH_ADDR_SS_PIN 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_SS_PIN, FlashCacheBuf.ss.pin);
	addr == FLASH_ADDR_SS_MODEL 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_SS_MODEL,FlashCacheBuf.ss.modle);
	addr == FLASH_ADDR_SS_RISING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_SS_RISING_ED,FlashCacheBuf.ss.rising_ed);
	addr == FLASH_ADDR_SS_FALLING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_SS_FALLING_ED,	FlashCacheBuf.ss.falling_ed);
	addr == FLASH_ADDR_SS_TYPE 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_SS_TYPE,	FlashCacheBuf.ss.type);
	//��ת����
	addr == FLASH_ADDR_ZZ_PIN 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZZ_PIN, FlashCacheBuf.zz.pin);
	addr == FLASH_ADDR_ZZ_MODEL 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZZ_MODEL,FlashCacheBuf.zz.modle);
	addr == FLASH_ADDR_ZZ_RISING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZZ_RISING_ED,FlashCacheBuf.zz.rising_ed);
	addr == FLASH_ADDR_ZZ_FALLING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZZ_FALLING_ED,	FlashCacheBuf.zz.falling_ed);
	addr == FLASH_ADDR_ZZ_TYPE 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZZ_TYPE,	FlashCacheBuf.zz.type);
	//��ת����
	addr == FLASH_ADDR_YZ_PIN 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YZ_PIN, FlashCacheBuf.yz.pin);
	addr == FLASH_ADDR_YZ_MODEL 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YZ_MODEL,FlashCacheBuf.yz.modle);
	addr == FLASH_ADDR_YZ_RISING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YZ_RISING_ED,FlashCacheBuf.yz.rising_ed);
	addr == FLASH_ADDR_YZ_FALLING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YZ_FALLING_ED,	FlashCacheBuf.yz.falling_ed);
	addr == FLASH_ADDR_YZ_TYPE 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YZ_TYPE,	FlashCacheBuf.yz.type);
	//Զ�⿪��
	addr == FLASH_ADDR_YG_PIN 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YG_PIN, FlashCacheBuf.yg.pin);
	addr == FLASH_ADDR_YG_MODEL 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YG_MODEL,FlashCacheBuf.yg.modle);
	addr == FLASH_ADDR_YG_RISING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YG_RISING_ED,FlashCacheBuf.yg.rising_ed);
	addr == FLASH_ADDR_YG_FALLING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YG_FALLING_ED,	FlashCacheBuf.yg.falling_ed);
	addr == FLASH_ADDR_YG_TYPE 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YZ_TYPE,	FlashCacheBuf.yg.type);
	//���⿪��
	addr == FLASH_ADDR_JG_PIN 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_JG_PIN, FlashCacheBuf.jg.pin);
	addr == FLASH_ADDR_JG_MODEL 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_JG_MODEL,FlashCacheBuf.jg.modle);
	addr == FLASH_ADDR_JG_RISING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_JG_RISING_ED,FlashCacheBuf.jg.rising_ed);
	addr == FLASH_ADDR_JG_FALLING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_JG_FALLING_ED,	FlashCacheBuf.jg.falling_ed);
	addr == FLASH_ADDR_JG_TYPE 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_JG_TYPE,	FlashCacheBuf.jg.type);
	//��Ͽ���
	addr == FLASH_ADDR_LH_PIN 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_LH_PIN, FlashCacheBuf.lh.pin);
	addr == FLASH_ADDR_LH_MODEL 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_LH_MODEL,FlashCacheBuf.lh.modle);
	addr == FLASH_ADDR_LH_RISING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_LH_RISING_ED,FlashCacheBuf.lh.rising_ed);
	addr == FLASH_ADDR_LH_FALLING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_LH_FALLING_ED,	FlashCacheBuf.lh.falling_ed);
	addr == FLASH_ADDR_LH_TYPE 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_LH_TYPE,	FlashCacheBuf.lh.type);
	//��ɲ����
	addr == FLASH_ADDR_JS_PIN 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_JS_PIN, FlashCacheBuf.js.pin);
	addr == FLASH_ADDR_JS_MODEL 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_JS_MODEL,FlashCacheBuf.js.modle);
	addr == FLASH_ADDR_JS_RISING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_JS_RISING_ED,FlashCacheBuf.js.rising_ed);
	addr == FLASH_ADDR_JS_FALLING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_JS_FALLING_ED,	FlashCacheBuf.js.falling_ed);
	addr == FLASH_ADDR_JS_TYPE 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_JS_TYPE,	FlashCacheBuf.js.type);
	//Ϩ�𿪹�
	addr == FLASH_ADDR_XH_PIN 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_XH_PIN, FlashCacheBuf.xh.pin);
	addr == FLASH_ADDR_XH_MODEL 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_XH_MODEL,FlashCacheBuf.xh.modle);
	addr == FLASH_ADDR_XH_RISING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_XH_RISING_ED,FlashCacheBuf.xh.rising_ed);
	addr == FLASH_ADDR_XH_FALLING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_XH_FALLING_ED,	FlashCacheBuf.xh.falling_ed);
	addr == FLASH_ADDR_XH_TYPE 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_XH_TYPE,	FlashCacheBuf.xh.type);
	//��������
	addr == FLASH_ADDR_QD_PIN 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_QD_PIN, FlashCacheBuf.qd.pin);
	addr == FLASH_ADDR_QD_MODEL 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_QD_MODEL,FlashCacheBuf.qd.modle);
	addr == FLASH_ADDR_QD_RISING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_QD_RISING_ED,FlashCacheBuf.qd.rising_ed);
	addr == FLASH_ADDR_QD_FALLING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_QD_FALLING_ED,	FlashCacheBuf.qd.falling_ed);
	addr == FLASH_ADDR_QD_TYPE 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_QD_TYPE,	FlashCacheBuf.qd.type);
	//��ȫ������
	addr == FLASH_ADDR_AQD_PIN 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_AQD_PIN, FlashCacheBuf.aqd.pin);
	addr == FLASH_ADDR_AQD_MODEL 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_AQD_MODEL,FlashCacheBuf.aqd.modle);
	addr == FLASH_ADDR_AQD_RISING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_AQD_RISING_ED,FlashCacheBuf.aqd.rising_ed);
	addr == FLASH_ADDR_AQD_FALLING_ED			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_AQD_FALLING_ED,	FlashCacheBuf.aqd.falling_ed);
	addr == FLASH_ADDR_AQD_TYPE 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_AQD_TYPE,	FlashCacheBuf.aqd.type);
	//С�ƿ���
	addr == FLASH_ADDR_XD_PIN 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_XD_PIN, FlashCacheBuf.xd.pin);
	addr == FLASH_ADDR_XD_MODEL 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_XD_MODEL,FlashCacheBuf.xd.modle);
	addr == FLASH_ADDR_XD_RISING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_XD_RISING_ED,FlashCacheBuf.xd.rising_ed);
	addr == FLASH_ADDR_XD_FALLING_ED			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_XD_FALLING_ED,	FlashCacheBuf.xd.falling_ed);
	addr == FLASH_ADDR_XD_TYPE 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_XD_TYPE,	FlashCacheBuf.xd.type);
	//���ȿ���
	addr == FLASH_ADDR_LB_PIN 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_LB_PIN, FlashCacheBuf.lb.pin);
	addr == FLASH_ADDR_LB_MODEL 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_LB_MODEL,FlashCacheBuf.lb.modle);
	addr == FLASH_ADDR_LB_RISING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_LB_RISING_ED,FlashCacheBuf.lb.rising_ed);
	addr == FLASH_ADDR_LB_FALLING_ED			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_LB_FALLING_ED,	FlashCacheBuf.lb.falling_ed);
	addr == FLASH_ADDR_LB_TYPE 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_LB_TYPE,	FlashCacheBuf.lb.type);
	//���ſ���
	addr == FLASH_ADDR_CM_PIN 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_CM_PIN, FlashCacheBuf.cm.pin);
	addr == FLASH_ADDR_CM_MODEL 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_CM_MODEL,FlashCacheBuf.cm.modle);
	addr == FLASH_ADDR_CM_RISING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_CM_RISING_ED,FlashCacheBuf.cm.rising_ed);
	addr == FLASH_ADDR_CM_FALLING_ED			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_CM_FALLING_ED,	FlashCacheBuf.cm.falling_ed);
	addr == FLASH_ADDR_CM_TYPE 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_CM_TYPE,	FlashCacheBuf.cm.type);
	//��λ������
	addr == FLASH_ADDR_DW_PIN1 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_DW_PIN1,FlashCacheBuf.dw.pin1);
	addr == FLASH_ADDR_DW_PIN2 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_DW_PIN2,FlashCacheBuf.dw.pin2);
	addr == FLASH_ADDR_DW_PIN3 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_DW_PIN3,FlashCacheBuf.dw.pin3);
	addr == FLASH_ADDR_DW_PIN4 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_DW_PIN4,FlashCacheBuf.dw.pin4);
	addr == FLASH_ADDR_DW_MODEL 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_DW_MODEL,FlashCacheBuf.dw.modle);
	addr == FLASH_ADDR_DW_RISING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_DW_RISING_ED,FlashCacheBuf.dw.rising_ed);
	addr == FLASH_ADDR_DW_FALLING_ED			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_DW_FALLING_ED,FlashCacheBuf.dw.falling_ed);
	addr == FLASH_ADDR_DW_TYPE						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_DW_TYPE,FlashCacheBuf.dw.type);
	//����ӿ���
	addr == FLASH_ADDR_ZHS_PIN 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZHS_PIN, FlashCacheBuf.zhs.pin);
	addr == FLASH_ADDR_ZHS_MODEL 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZHS_MODEL,FlashCacheBuf.zhs.modle);
	addr == FLASH_ADDR_ZHS_RISING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZHS_RISING_ED,FlashCacheBuf.zhs.rising_ed);
	addr == FLASH_ADDR_ZHS_FALLING_ED			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZHS_FALLING_ED,	FlashCacheBuf.zhs.falling_ed);
	addr == FLASH_ADDR_ZHS_TYPE 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZHS_TYPE,	FlashCacheBuf.zhs.type);
	//�ں��ӿ���
	addr == FLASH_ADDR_NHS_PIN 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_NHS_PIN, FlashCacheBuf.nhs.pin);
	addr == FLASH_ADDR_NHS_MODEL 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_NHS_MODEL,FlashCacheBuf.nhs.modle);
	addr == FLASH_ADDR_NHS_RISING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_NHS_RISING_ED,FlashCacheBuf.nhs.rising_ed);
	addr == FLASH_ADDR_NHS_FALLING_ED			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_NHS_FALLING_ED,	FlashCacheBuf.nhs.falling_ed);
	addr == FLASH_ADDR_NHS_TYPE 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_NHS_TYPE,	FlashCacheBuf.nhs.type);
	//��ɲ����
	addr == FLASH_ADDR_FSC_PIN 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_FSC_PIN, FlashCacheBuf.fsc.pin);
	addr == FLASH_ADDR_FSC_MODEL 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_FSC_MODEL,FlashCacheBuf.fsc.modle);
	addr == FLASH_ADDR_FSC_RISING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_FSC_RISING_ED,FlashCacheBuf.fsc.rising_ed);
	addr == FLASH_ADDR_FSC_FALLING_ED			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_FSC_FALLING_ED,	FlashCacheBuf.fsc.falling_ed);
	addr == FLASH_ADDR_FSC_TYPE 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_FSC_TYPE,	FlashCacheBuf.fsc.type);
	//��ƿ���
	addr == FLASH_ADDR_WD_PIN 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_WD_PIN, FlashCacheBuf.wd.pin);
	addr == FLASH_ADDR_WD_MODEL 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_WD_MODEL,FlashCacheBuf.wd.modle);
	addr == FLASH_ADDR_WD_RISING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_WD_RISING_ED,FlashCacheBuf.wd.rising_ed);
	addr == FLASH_ADDR_WD_FALLING_ED			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_WD_FALLING_ED,	FlashCacheBuf.wd.falling_ed);
	addr == FLASH_ADDR_WD_TYPE 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_WD_TYPE,	FlashCacheBuf.wd.type);
	//��ˢ����
	addr == FLASH_ADDR_YS_PIN 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YS_PIN, FlashCacheBuf.ys.pin);
	addr == FLASH_ADDR_YS_MODEL 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YS_MODEL,FlashCacheBuf.ys.modle);
	addr == FLASH_ADDR_YS_RISING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YS_RISING_ED,FlashCacheBuf.ys.rising_ed);
	addr == FLASH_ADDR_YS_FALLING_ED			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YS_FALLING_ED,	FlashCacheBuf.ys.falling_ed);
	addr == FLASH_ADDR_YS_TYPE 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YS_TYPE,	FlashCacheBuf.ys.type);
	//�����ƿ���
	addr == FLASH_ADDR_DCD_PIN 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_DCD_PIN, FlashCacheBuf.dcd.pin);
	addr == FLASH_ADDR_DCD_MODEL 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_DCD_MODEL,FlashCacheBuf.dcd.modle);
	addr == FLASH_ADDR_DCD_RISING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_DCD_RISING_ED,FlashCacheBuf.dcd.rising_ed);
	addr == FLASH_ADDR_DCD_FALLING_ED			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_DCD_FALLING_ED,	FlashCacheBuf.dcd.falling_ed);
	addr == FLASH_ADDR_DCD_TYPE 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_DCD_TYPE,	FlashCacheBuf.dcd.type);
	//Կ���ſ���
	addr == FLASH_ADDR_YSM_PIN 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YSM_PIN, FlashCacheBuf.ysm.pin);
	addr == FLASH_ADDR_YSM_MODEL 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YSM_MODEL,FlashCacheBuf.ysm.modle);
	addr == FLASH_ADDR_YSM_RISING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YSM_RISING_ED,FlashCacheBuf.ysm.rising_ed);
	addr == FLASH_ADDR_YSM_FALLING_ED			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YSM_FALLING_ED,	FlashCacheBuf.ysm.falling_ed);
	addr == FLASH_ADDR_YSM_TYPE 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YSM_TYPE,	FlashCacheBuf.ysm.type);
	//�Ƴ�����1
	addr == FLASH_ADDR_RC_PIN1 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_RC_PIN1,FlashCacheBuf.rc.pin1);
	addr == FLASH_ADDR_RC_PIN2 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_RC_PIN2,FlashCacheBuf.rc.pin2);
	addr == FLASH_ADDR_RC_PIN3 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_RC_PIN3,FlashCacheBuf.rc.pin3);
	addr == FLASH_ADDR_RC_MODEL 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_RC_MODEL,FlashCacheBuf.rc.modle);
	addr == FLASH_ADDR_RC_RISING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_RC_RISING_ED,FlashCacheBuf.rc.rising_ed);
	addr == FLASH_ADDR_RC_FALLING_ED			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_RC_FALLING_ED,	FlashCacheBuf.rc.falling_ed);
	addr == FLASH_ADDR_RC_TYPE						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_RC_TYPE,	FlashCacheBuf.rc.type);
	//��������
	addr == FLASH_ADDR_CD_PIN 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_CD_PIN, FlashCacheBuf.cd.pin);
	addr == FLASH_ADDR_CD_MODEL 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_CD_MODEL,FlashCacheBuf.cd.modle);
	addr == FLASH_ADDR_CD_RISING_ED 			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_CD_RISING_ED,FlashCacheBuf.cd.rising_ed);
	addr == FLASH_ADDR_CD_FALLING_ED			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_CD_FALLING_ED,	FlashCacheBuf.cd.falling_ed);
	addr == FLASH_ADDR_CD_TYPE 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_CD_TYPE,	FlashCacheBuf.cd.type);
	//���ο��أ�ѹ��)
	addr == FLASH_ADDR_ZYYL_PIN						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZYYL_PIN, FlashCacheBuf.zyyl.pin);
	addr == FLASH_ADDR_ZYYL_MODEL					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZYYL_MODEL,FlashCacheBuf.zyyl.modle);
	addr == FLASH_ADDR_ZYYL_RISING_ED			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZYYL_RISING_ED,FlashCacheBuf.zyyl.rising_ed);
	addr == FLASH_ADDR_ZYYL_FALLING_ED		? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZYYL_FALLING_ED,	FlashCacheBuf.zyyl.falling_ed);
	addr == FLASH_ADDR_ZYYL_TYPE 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZYYL_TYPE,	FlashCacheBuf.zyyl.type);
	//�۲��Ǳ���
	addr == FLASH_ADDR_GCYBP_PIN					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_GCYBP_PIN, FlashCacheBuf.gcybp.pin);
	addr == FLASH_ADDR_GCYBP_MODEL				? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_GCYBP_MODEL,FlashCacheBuf.gcybp.modle);
	addr == FLASH_ADDR_GCYBP_RISING_ED		? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_GCYBP_RISING_ED,FlashCacheBuf.gcybp.rising_ed);
	addr == FLASH_ADDR_GCYBP_FALLING_ED		? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_GCYBP_FALLING_ED,	FlashCacheBuf.gcybp.falling_ed);
	addr == FLASH_ADDR_GCYBP_TYPE 				? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_GCYBP_TYPE,	FlashCacheBuf.gcybp.type);
	//ת��
	addr == FLASH_ADDR_ZS_PIN							? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZS_PIN, FlashCacheBuf.zs.pin);
	addr == FLASH_ADDR_ZS_IDLIN_MIN				? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZS_IDLIN_MIN,FlashCacheBuf.zs.min);
	addr == FLASH_ADDR_ZS_BS							? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZS_BS,FlashCacheBuf.zs.bs);
	addr == FLASH_ADDR_ZS_SAMPLING_TIME		? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZS_SAMPLING_TIME,FlashCacheBuf.zs.sampling_time);
	addr == FLASH_ADDR_ZS_INIT_VALUE			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZS_INIT_VALUE,	FlashCacheBuf.zs.init_value);	

	//�����Ŵ�����
	addr == FLASH_ADDR_DBQ_PIN1						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_DBQ_PIN1,FlashCacheBuf.dbq.pin1);
	addr == FLASH_ADDR_DBQ_PIN2						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_DBQ_PIN2,FlashCacheBuf.dbq.pin2);
	addr == FLASH_ADDR_DBQ_PIN3						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_DBQ_PIN3,FlashCacheBuf.dbq.pin3);
	addr == FLASH_ADDR_DBQ_PIN4						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_DBQ_PIN4,FlashCacheBuf.dbq.pin4);
	addr == FLASH_ADDR_DBQ_PIN5						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_DBQ_PIN5,FlashCacheBuf.dbq.pin5);	
	addr == FLASH_ADDR_DBQ_PIN6						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_DBQ_PIN6,FlashCacheBuf.dbq.pin6);
	addr == FLASH_ADDR_DBQ_MODEL					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_DBQ_MODEL,FlashCacheBuf.dbq.modle);
	addr == FLASH_ADDR_DBQ_RISING_ED			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_DBQ_RISING_ED,FlashCacheBuf.dbq.rising_ed);
	addr == FLASH_ADDR_DBQ_FALLING_ED		  ? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_DBQ_FALLING_ED,	FlashCacheBuf.dbq.falling_ed);
	addr == FLASH_ADDR_DBQ_TYPE						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_DBQ_TYPE,	FlashCacheBuf.dbq.type);	
	
#ifdef  STC15W4K48S4	
	//Ħ�г�ͷ��
	addr == FLASH_ADDR_TK_PIN							? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_TK_PIN, FlashCacheBuf.tk.pin);
	addr == FLASH_ADDR_TK_MODEL						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_TK_MODEL,FlashCacheBuf.tk.modle);
	addr == FLASH_ADDR_TK_RISING_ED				? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_TK_RISING_ED,FlashCacheBuf.tk.rising_ed);
	addr == FLASH_ADDR_TK_FALLING_ED			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_TK_FALLING_ED,	FlashCacheBuf.tk.falling_ed);
	addr == FLASH_ADDR_TK_TYPE 						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_TK_TYPE,	FlashCacheBuf.tk.type);
	
	//Ħ�г������
	addr == FLASH_ADDR_ZBS_PIN						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZBS_PIN, FlashCacheBuf.zbs.pin);
	addr == FLASH_ADDR_ZBS_MODEL					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZBS_MODEL,FlashCacheBuf.zbs.modle);
	addr == FLASH_ADDR_ZBS_RISING_ED			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZBS_RISING_ED,FlashCacheBuf.zbs.rising_ed);
	addr == FLASH_ADDR_ZBS_FALLING_ED			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZBS_FALLING_ED,	FlashCacheBuf.zbs.falling_ed);
	addr == FLASH_ADDR_ZBS_TYPE 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZBS_TYPE,	FlashCacheBuf.zbs.type);
	
	//Ħ�г��Ұ���
	addr == FLASH_ADDR_YBS_PIN						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YBS_PIN, FlashCacheBuf.ybs.pin);
	addr == FLASH_ADDR_YBS_MODEL					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YBS_MODEL,FlashCacheBuf.ybs.modle);
	addr == FLASH_ADDR_YBS_RISING_ED			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YBS_RISING_ED,FlashCacheBuf.ybs.rising_ed);
	addr == FLASH_ADDR_YBS_FALLING_ED			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YBS_FALLING_ED,	FlashCacheBuf.ybs.falling_ed);
	addr == FLASH_ADDR_YBS_TYPE 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YBS_TYPE,	FlashCacheBuf.ybs.type);
	
	//Ħ�г����̤��
	addr == FLASH_ADDR_ZJTB_PIN						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZJTB_PIN, FlashCacheBuf.zjtb.pin);
	addr == FLASH_ADDR_ZJTB_MODEL					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZJTB_MODEL,FlashCacheBuf.zjtb.modle);
	addr == FLASH_ADDR_ZJTB_RISING_ED			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZJTB_RISING_ED,FlashCacheBuf.zjtb.rising_ed);
	addr == FLASH_ADDR_ZJTB_FALLING_ED		? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZJTB_FALLING_ED,	FlashCacheBuf.zjtb.falling_ed);
	addr == FLASH_ADDR_ZJTB_TYPE 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_ZJTB_TYPE,	FlashCacheBuf.zjtb.type);
	
	//Ħ�г��ҽ�̤��
	addr == FLASH_ADDR_YJTB_PIN						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YJTB_PIN, FlashCacheBuf.yjtb.pin);
	addr == FLASH_ADDR_YJTB_MODEL					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YJTB_MODEL,FlashCacheBuf.yjtb.modle);
	addr == FLASH_ADDR_YJTB_RISING_ED			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YJTB_RISING_ED,FlashCacheBuf.yjtb.rising_ed);
	addr == FLASH_ADDR_YJTB_FALLING_ED		? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YJTB_FALLING_ED,	FlashCacheBuf.yjtb.falling_ed);
	addr == FLASH_ADDR_YJTB_TYPE 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_YJTB_TYPE,	FlashCacheBuf.yjtb.type);
	
	//���˽���
	addr == FLASH_ADDR_PGJS_PIN						? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_PGJS_PIN, FlashCacheBuf.pgjs.pin);
	addr == FLASH_ADDR_PGJS_MODEL					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_PGJS_MODEL,FlashCacheBuf.pgjs.modle);
	addr == FLASH_ADDR_PGJS_RISING_ED			? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_PGJS_RISING_ED,FlashCacheBuf.pgjs.rising_ed);
	addr == FLASH_ADDR_PGJS_FALLING_ED		? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_PGJS_FALLING_ED,	FlashCacheBuf.pgjs.falling_ed);
	addr == FLASH_ADDR_PGJS_TYPE 					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_PGJS_TYPE,	FlashCacheBuf.pgjs.type);

	//������Ŀ1
	addr == FLASH_ADDR_PGJS_1_NAME				? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_PGJS_1_NAME, FlashCacheBuf.bump[0].name);
	addr == FLASH_ADDR_PGJS_1_N0					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_PGJS_1_N0,FlashCacheBuf.bump[0].number);
	addr == FLASH_ADDR_PGJS_1_COUNT				? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_PGJS_1_COUNT,FlashCacheBuf.bump[0].count);
	addr == FLASH_ADDR_PGJS_1_TYPE				? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_PGJS_1_TYPE,FlashCacheBuf.bump[0].type);
	
	//������Ŀ2
	addr == FLASH_ADDR_PGJS_2_NAME				? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_PGJS_2_NAME, FlashCacheBuf.bump[1].name);
	addr == FLASH_ADDR_PGJS_2_N0					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_PGJS_2_N0,FlashCacheBuf.bump[1].number);
	addr == FLASH_ADDR_PGJS_2_COUNT				? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_PGJS_2_COUNT,FlashCacheBuf.bump[1].count);
	addr == FLASH_ADDR_PGJS_2_TYPE				? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_PGJS_2_TYPE,FlashCacheBuf.bump[1].type);
	
	//������Ŀ3
	addr == FLASH_ADDR_PGJS_3_NAME				? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_PGJS_3_NAME, FlashCacheBuf.bump[2].name);
	addr == FLASH_ADDR_PGJS_3_N0					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_PGJS_3_N0,FlashCacheBuf.bump[2].number);
	addr == FLASH_ADDR_PGJS_3_COUNT				? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_PGJS_3_COUNT,FlashCacheBuf.bump[2].count);
	addr == FLASH_ADDR_PGJS_3_TYPE				? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_PGJS_3_TYPE,FlashCacheBuf.bump[2].type);
	
	//������Ŀ4
	addr == FLASH_ADDR_PGJS_4_NAME				? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_PGJS_4_NAME, FlashCacheBuf.bump[3].name);
	addr == FLASH_ADDR_PGJS_4_N0					? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_PGJS_4_N0,FlashCacheBuf.bump[3].number);
	addr == FLASH_ADDR_PGJS_4_COUNT				? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_PGJS_4_COUNT,FlashCacheBuf.bump[3].count);
	addr == FLASH_ADDR_PGJS_4_TYPE				? IapWriteByte(addr,value) : IapWriteByte(FLASH_ADDR_PGJS_4_TYPE,FlashCacheBuf.bump[3].type);











#endif
	
}

