#include "bsp_key.h"
#include "stm32f0xx_gpio.h"

void KEY_GPIO_Config()
{
	/*GPIO��ʼ���ṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*ʹ��GPIO�˿�ʱ��*/
	RCC_AHBPeriphClockCmd(RCC_KEY_CMD,ENABLE);
	
	/*��ʼ��GPIO�ṹ��*/
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;  //����ģʽ
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;  //��������
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2;  //��2������
	
	GPIO_Init(KEY_GPIO_PORT,&GPIO_InitStructure);
}


//��ⰴ��״̬����
uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{
	/*��ⰴ���Ƿ���*/
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON)
	{
		/*�ȴ������ͷ�*/
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON)
		{
			return KEY_ON;
		}
	}else
		return KEY_OFF;
}


