#ifndef __BSP_LED_H
#define __BSP_LED_H

//GPIOA的11号引脚
#define LED_GPIO_PORT  GPIOA
#define LED_GPIO_CLK   RCC_AHBPeriph_GPIOA
#define LED_GPIO_PIN   GPIO_Pin_11   //这里GPIO_PIN_11的值为0x0800，第11位为1

/*直接操作寄存器的方法控制IO*/
#define digitalHi(p,i)      {p->BSRR=i;}   //输出高电平
#define digitalLo(p,i)      {p->BRR=i;}    //输出低电平
#define digitalToggle(p,i)  {p->ODR ^=i;}  //输出反转状态

/*定义控制IO的宏*/
#define LED_TOGGLE  digitalToggle(LED_GPIO_PORT,GPIO_Pin_11)
#define LED_ON      digitalLo(LED_GPIO_PORT,GPIO_Pin_11)
#define LED_OFF     digitalHi(LED_GPIO_PORT,GPIO_Pin_11)

#endif
