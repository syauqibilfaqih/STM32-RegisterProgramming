#include "stm32f103x6.h"

// inacurate delay function
#define delay_ms(x) for (volatile int i = 0; i < x*1000; i++);

int main(void)
{
    RCC->APB2ENR = RCC_BASE+0x18; 
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN; //Enabling APB2

    GPIOC->CRH = GPIOC_BASE+0x04;
    GPIOC->CRH &= 0x44044444; //Reset pins on Port C
    GPIOC->CRH |= 0x00200000; //Set PIN 13 as Output

    GPIOC->ODR = GPIOC_BASE+0x0C;

    while(1)
    {
        GPIOC->ODR |= (1<<13); //Set 
        delay_ms(500); 
        GPIOC->ODR &= ~(1<<13); //Reset
        delay_ms(500);
    }
}
