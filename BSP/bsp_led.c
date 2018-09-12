#include "stm32f0xx_gpio.h"
#include "bsp_led.h"

/*定义LED_GPIO初始化函数*/
void LED_GPIO_Config(void)
{
	/*定义GPIO初始化结构体变量*/
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*开启LED相关的时钟*/
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA,ENABLE);
	
	/*初始化GPIO结构体中的变量*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;  //配置引脚
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;  //输出模式
	
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;  //推挽输出
	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Level_2;  //中速输出
	
	/*调用库函数，初始化结构体*/
	GPIO_Init(LED_GPIO_PORT,&GPIO_InitStructure);
	
	/*关闭LED灯*/
	GPIO_SetBits(LED_GPIO_PORT,LED_GPIO_PIN);
			
}

