#ifndef __BSP_KEY_H
#define __BSP_KEY_H

/*����ΪGPIOB,PB2����*/
#define KEY_GPIO_PORT  GPIOB
#define RCC_KEY_CMD    RCC_AHBPeriph_GPIOB
#define KEY_GPIO_PIN   GPIO_Pin_2

/*����״̬������������Ϊ�͵�ƽ��������Ϊ�ߵ�ƽ*/
#define KEY_ON   0
#define KEY_OFF  1

#endif
