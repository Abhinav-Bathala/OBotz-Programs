#include <avr/io.h>               
#include <util/delay.h>         

int main(void)
{
  DDRB = 0xFF;
  DDRD = 0x00;
  int count;
  while(1)
  {
    if((PIND & 0x02) && (PIND & 0x03))
    {
      count = 1;
    }
    if(count == 1)
    {
      PORTB = 0b00010000;
    }
    if(count == 2)
    {
      PORTB = 0x00;
      count = 0;
    }
  }
}
