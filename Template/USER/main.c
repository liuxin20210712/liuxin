#include "sys.h"
#include "delay.h"
#include "usart.h"
/************************************************
 ALIENTEK 精英板STM32F103??板??0-1
 Template工程模板-新建工程章?使用-HAL?版本
 技?支持：www.openedv.com
 淘?店?： http://eboard.taobao.com 
 ?注微信公?平台微信?："正?原子"，免??取STM32?料。
 ?州市星翼?子科技有限公司  
 作者：正?原子 @ALIENTEK
************************************************/


/***注意：本工程和教程中的新建工程3.3小???***/


void Delay(__IO uint32_t nCount);

void Delay(__IO uint32_t nCount)
{
  while(nCount--){}
}

int main(void)
{
	GPIO_InitTypeDef GPIO_Initure;
     
    HAL_Init();                    	 			//初始化HAL?    
    Stm32_Clock_Init(RCC_PLL_MUL9);   			//?置??,72M

    __HAL_RCC_GPIOB_CLK_ENABLE();           	//??GPIOB??
	__HAL_RCC_GPIOE_CLK_ENABLE();           	//??GPIOE??
	
    GPIO_Initure.Pin=GPIO_PIN_5; 				//PB5
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  	//推挽?出
    GPIO_Initure.Pull=GPIO_PULLUP;          	//上拉
    GPIO_Initure.Speed=GPIO_SPEED_FREQ_HIGH;    //高速
    HAL_GPIO_Init(GPIOB,&GPIO_Initure);

	GPIO_Initure.Pin=GPIO_PIN_5; 				//PE5
	HAL_GPIO_Init(GPIOE,&GPIO_Initure);
	
	while(1)
	{
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);		//PB5置1 
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,GPIO_PIN_SET);		//PE5置1  			
		Delay(0x7FFFFF);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET);		//PB5置0
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,GPIO_PIN_RESET);		//PE5置0  
		Delay(0x7FFFFF);
	}
}
