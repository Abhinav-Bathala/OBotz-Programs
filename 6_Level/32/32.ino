#include <avr/io.h>
#include <util/delay.h>
char data;
int number[] = {0b11110110, 0b01100000, 0b11010101, 0b11110001, 0b01100011, 0b10110011, 0b10110111, 0b11100000, 0b11110111, 0b11110011, 0b00111101, 0b00110111, 0b10010110, 0b01110101, 0b01100110, 0b10010000, 0b11110111, 0b11110011}
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
      PORTC = number[0];
    }
    if(data == '1')
    {
      PORTC = number[1];
    }
    if(data == '2')
    {
      PORTC = number[2];
    }
    if(data == '3')
    {
      PORTC = number[3];
    }
    if(data == '4')
    {
      PORTC = number[4];
    }
    if(data == '5')
    {
      PORTC = number[5];
    }
    if(data == '6')
    {
      PORTC = number[6];
    }
    if(data == '7')
    {
      PORTC = number[7];
    }
    if(data == '8')
    {
      PORTC = number[8];
    }
    if(data == '9')
    {
      PORTC = number[9];
    }
    
    
  }
}
ISR(USART1_RX_vect)
{
  data = UDR1;
}
