#include "board.h"

uint32_t time=0;

int main(void)
{
	//set up systick
	SysTick_Config(SystemCoreClock / 1000);
	
	//set up gpio
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin = 0xFF00;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	
	GPIO_ResetBits(GPIOE, 0xFF00);
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	while(1)
	{
		GPIO_SetBits(GPIOE, 0xFF00);
		delay(1000);
		GPIO_ResetBits(GPIOE, 0xFF00);
		delay(1000);
	}
}
