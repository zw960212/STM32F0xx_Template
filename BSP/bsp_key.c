#include "bsp_key.h"
#include "stm32f0xx_gpio.h"

void KEY_GPIO_Config()
{
	/*GPIO初始化结构体*/
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*使能GPIO端口时钟*/
	RCC_AHBPeriphClockCmd(RCC_KEY_CMD,ENABLE);
	
	/*初始化GPIO结构体*/
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;  //输入模式
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;  //浮空输入
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2;  //第2号引脚
	
	GPIO_Init(KEY_GPIO_PORT,&GPIO_InitStructure);
}


//检测按键状态函数
uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{
	/*检测按键是否按下*/
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON)
	{
		/*等待按键释放*/
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON)
		{
			return KEY_ON;
		}
	}else
		return KEY_OFF;
}


