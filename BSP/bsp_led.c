#include "stm32f0xx_gpio.h"
#include "bsp_led.h"

/*����LED_GPIO��ʼ������*/
void LED_GPIO_Config(void)
{
	/*����GPIO��ʼ���ṹ�����*/
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*����LED��ص�ʱ��*/
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA,ENABLE);
	
	/*��ʼ��GPIO�ṹ���еı���*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;  //��������
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;  //���ģʽ
	
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;  //�������
	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Level_2;  //�������
	
	/*���ÿ⺯������ʼ���ṹ��*/
	GPIO_Init(LED_GPIO_PORT,&GPIO_InitStructure);
	
	/*�ر�LED��*/
	GPIO_SetBits(LED_GPIO_PORT,LED_GPIO_PIN);
			
}

