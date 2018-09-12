#include "bsp_led.h"
#include "bsp_key.h"
#include "stdint.h"
#include "stm32f0xx_gpio.h"

/*Extern Functions-----------*/
extern void LED_GPIO_Config(void);
extern void KEY_GPIO_Config(void);
extern uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin); 

/*延时函数*/
void Delay_ms(uint32_t nCount)
{
	for(;nCount!=0;nCount--);
}

int main(void)
{
	/*LED端口初始化*/
	LED_GPIO_Config();
	
	/*按键端口初始化*/
	KEY_GPIO_Config();
	
	while(1)
	{
		/*
		LED_ON;    //亮
		Delay_ms(500);
		LED_OFF;   //灭
		*/
		if(Key_Scan(KEY_GPIO_PORT,KEY_GPIO_PIN) == KEY_ON)
		{
			//LED反转
			LED_TOGGLE;
		}
	}
	
}

