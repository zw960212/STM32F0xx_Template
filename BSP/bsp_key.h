#ifndef __BSP_KEY_H
#define __BSP_KEY_H

/*按键为GPIOB,PB2引脚*/
#define KEY_GPIO_PORT  GPIOB
#define RCC_KEY_CMD    RCC_AHBPeriph_GPIOB
#define KEY_GPIO_PIN   GPIO_Pin_2

/*按键状态，若按键按下为低电平，不按下为高电平*/
#define KEY_ON   0
#define KEY_OFF  1

#endif
