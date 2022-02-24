#include "stm32f103x6.h"

#define delay_ms(time) for(volatile int i=0; i<time*1000; i++)

int main()
{
    RCC->APB2ENR=RCC_BASE+0x18;
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;

    GPIOB->CRL=GPIOB_BASE+0x00;
    GPIOB->CRH=GPIOB_BASE+0x04;

    GPIOB->CRL &= 0x44444400; 
    GPIOB->CRH &= 0x44444044; 

    GPIOB->CRL |= 0x00000022; 
    GPIOB->CRH |= 0x00000200; 

    GPIOB->ODR = GPIOB_BASE+0x0C;

    while(1)
    {
        GPIOB->ODR |= (1<<0);
        GPIOB->ODR &= ~(1<<1);
        GPIOB->ODR &= ~(1<<10);
        delay_ms(2000);
        GPIOB->ODR &= ~(1<<0);
        GPIOB->ODR |= (1<<1);
        GPIOB->ODR &= ~(1<<10);
        delay_ms(500);
        GPIOB->ODR &= ~(1<<0);
        GPIOB->ODR &= ~(1<<1);
        GPIOB->ODR |= (1<<10);
        delay_ms(1000);
    } 

}