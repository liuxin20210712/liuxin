#include "sys.h"
#include "delay.h"
#include "usart.h"
/************************************************
 ALIENTEK ��^�OSTM32F103??�O??0-1
 Template�u�{�ҪO-�s�ؤu�{��?�ϥ�-HAL?����
 ��?����Gwww.openedv.com
 �^?��?�G http://eboard.taobao.com 
 ?�`�L�H��?���x�L�H?�G"��?��l"�A�K??��STM32?�ơC
 ?�{���P�l?�l��ަ������q  
 �@�̡G��?��l @ALIENTEK
************************************************/


/***�`�N�G���u�{�M�е{�����s�ؤu�{3.3�p???***/


void Delay(__IO uint32_t nCount);

void Delay(__IO uint32_t nCount)
{
  while(nCount--){}
}

int main(void)
{
	GPIO_InitTypeDef GPIO_Initure;
     
    HAL_Init();                    	 			//��l��HAL?    
    Stm32_Clock_Init(RCC_PLL_MUL9);   			//?�m??,72M

    __HAL_RCC_GPIOB_CLK_ENABLE();           	//??GPIOB??
	__HAL_RCC_GPIOE_CLK_ENABLE();           	//??GPIOE??
	
    GPIO_Initure.Pin=GPIO_PIN_5; 				//PB5
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  	//����?�X
    GPIO_Initure.Pull=GPIO_PULLUP;          	//�W��
    GPIO_Initure.Speed=GPIO_SPEED_FREQ_HIGH;    //���t
    HAL_GPIO_Init(GPIOB,&GPIO_Initure);

	GPIO_Initure.Pin=GPIO_PIN_5; 				//PE5
	HAL_GPIO_Init(GPIOE,&GPIO_Initure);
	
	while(1)
	{
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);		//PB5�m1 
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,GPIO_PIN_SET);		//PE5�m1  			
		Delay(0x7FFFFF);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET);		//PB5�m0
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,GPIO_PIN_RESET);		//PE5�m0  
		Delay(0x7FFFFF);
	}
}
