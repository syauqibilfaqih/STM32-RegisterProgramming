#include "stm32f103x6.h"

void usartInit () {
  RCC->APB2ENR |= RCC_APB2ENR_USART1EN | RCC_APB2ENR_IOPAEN; 
  GPIOA->CRH |= GPIO_CRH_MODE9 | GPIO_CRH_CNF9_1;
  GPIOA->CRH &= ~(GPIO_CRH_CNF9_0);
  USART1->BRR = 0x341;                 // set baudrate
  USART1->CR1 |= USART_CR1_RE | USART_CR1_TE | USART_CR1_UE;
  }
  

int sendChar (char ch)  {
  while (!(USART1->SR & USART_SR_TXE));
  USART1->DR |= (ch & 0xFF);
  return (ch);
}

int getChar (void)  {
  while (!(USART1->SR & USART_SR_RXNE));
  return ((int)(USART1->DR & 0xFF));
}

int main()
{
  usartInit();
  while (1)
  {
    sendChar(getChar());
  }
}
