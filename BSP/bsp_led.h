#ifndef __BSP_LED_H
#define __BSP_LED_H

//GPIOA��11������
#define LED_GPIO_PORT  GPIOA
#define LED_GPIO_CLK   RCC_AHBPeriph_GPIOA
#define LED_GPIO_PIN   GPIO_Pin_11   //����GPIO_PIN_11��ֵΪ0x0800����11λΪ1

/*ֱ�Ӳ����Ĵ����ķ�������IO*/
#define digitalHi(p,i)      {p->BSRR=i;}   //����ߵ�ƽ
#define digitalLo(p,i)      {p->BRR=i;}    //����͵�ƽ
#define digitalToggle(p,i)  {p->ODR ^=i;}  //�����ת״̬

/*�������IO�ĺ�*/
#define LED_TOGGLE  digitalToggle(LED_GPIO_PORT,GPIO_Pin_11)
#define LED_ON      digitalLo(LED_GPIO_PORT,GPIO_Pin_11)
#define LED_OFF     digitalHi(LED_GPIO_PORT,GPIO_Pin_11)

#endif
