#include "stm32f103x6.h"

int main()
{
    RCC->APB2ENR = RCC_BASE+0x18; 
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;

    GPIOA->CRH = GPIOA_BASE+0x04;
    GPIOB->CRL = GPIOB_BASE+0x00;
    GPIOB->CRH = GPIOB_BASE+0x04;

    GPIOA->CRH &= 0x44400044;
    GPIOA->CRH |= 0x00088800;
    GPIOB->CRL &= 0x44444400;
    GPIOB->CRL |= 0x00000022;
    GPIOB->CRH &= 0x44444044;
    GPIOB->CRH |= 0x00000200;

    GPIOA->IDR = GPIOA_BASE+0x08;
    GPIOA->ODR = GPIOA_BASE+0x0C;
    GPIOB->ODR = GPIOB_BASE+0x0C;

    GPIOA->ODR |= (1<<10);
    GPIOA->ODR |= (1<<11);
    GPIOA->ODR |= (1<<12);

    while(1)
    {
        if(!(GPIOA->IDR & (1<<10)))
        {
            GPIOB->ODR |= (1<<0);
        }
        else
        {
            GPIOB->ODR &= ~(1<<0);
        }
        if(!(GPIOA->IDR & (1<<11)))
        {
            GPIOB->ODR |= (1<<1);
        }
        else
        {
            GPIOB->ODR &= ~(1<<1);
        }
        if(!(GPIOA->IDR & (1<<12)))
        {
            GPIOB->ODR |= (1<<10);
        }
        else
        {
            GPIOB->ODR &= ~(1<<10);
        }
    }
}
