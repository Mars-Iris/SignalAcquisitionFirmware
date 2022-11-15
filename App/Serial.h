#ifndef	__SERIAL_H
#define	__SERIAL_H


typedef struct 
{ 
	u8	Adjust_XL;					//X��Ƕȵ��ֽ�
	u8 	Adjust_XH;  				//X��Ƕȸ��ֽ�
	u8	Adjust_YL;					//Y��Ƕȵ��ֽ�
	u8 	Adjust_YH;  				//Y��Ƕȸ��ֽ�	

}TiltAdjustTypeDef;   		//




void SerialHandle(u8 USARTx);
void SerialDataUpload(u8 upload_usart);

#ifdef  STC15W4K48S4	
u8 Serial_HighSensorShock_Analy(u8 bump_usart,SignalLineTypeDef *pole); //��ɭHS-SKR�����𶯴��������ݽ���

u8 Serial_TiltSensor_Analy(u8 Tilt_usart,TiltSensorTypeDef *Tilt);//������Ǵ���������

void Serial_Sensor24GShock_Analy(u8 bump24g_usart,PengganTypeDef *pole); //2.4G�𶯴��������ݽ���

#endif



#endif