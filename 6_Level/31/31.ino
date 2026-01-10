#include <avr/io.h>
#include <util/delay.h>
char data;
int main(void)
{
  DDRD = 0xFF;
  UCSR1B = 0x90;
  UCSR1C = 0x06;
  SREG = 0x80;
  UCSR1A = 0x00;
  UBRR1H = 0x00;
  UBRR1L = 0x67;
  while(1)
  {
    if(data == '0')
    { 
      PORTD = 0x01;
    }
    else
    {
      PORTD = 0x02;
    }
  }
}
ISR(USART1_RX_vect)
{
  data = UDR1;
}
