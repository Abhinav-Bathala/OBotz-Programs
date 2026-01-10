#include <avr/io.h>
#include <util/delay.h>
char data;
int c, d;
int main (void)
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
    if (data == '1')
    {
      c++;
      antistepper();
      _delay_ms(50);
    }
    if (data == '2')
    {
      d++;
      clkstepper();
      _delay_ms(50);
    }
    if (data == '3')
    {
      PORTD = 0x00;
    }
  }
}

ISR (USART1_RX_vect)
{
  data = UDR1;
}

void antistepper()    //Anticlockwise Rotation
{
  if (d == 1)     //"d" just variable name (Need a variable to increment for the program to work)
  { 
    PORTD = 0b11100000;
  }
  if (d == 2)     //"d" just variable name (Need a variable to increment for the program to work)
  {
    PORTD = 0b11010000;
  }
  if (d == 3)     //"d" just variable name (Need a variable to increment for the program to work)
  {
    PORTD = 0b10110000;
  }
  if (d == 4)     //"d" just variable name (Need a variable to increment for the program to work)
  {
    PORTD = 0b01110000;
    d = 0;      //"d" just variable name (Need a variable to increment for the program to work)
  }
}
void clkstepper()   //Clockwise Rotation
{
  if (c == 1)     //"c" just variable name (Need a variable to increment for the program to work)
  {
    PORTD = 0b01110000;
  }
  if (c == 2)     //"c" just variable name (Need a variable to increment for the program to work)
  {
    PORTD = 0b10110000;
  }
  if (c == 3)     //"c" just variable name (Need a variable to increment for the program to work)
  {
    PORTD = 0b11010000;
  }
  if (c == 4)     //"c" just variable name (Need a variable to increment for the program to work)
  { 
    PORTD = 0b11100000;
    c = 0;      //"c" just variable name (Need a variable to increment for the program to work)
  }
}
