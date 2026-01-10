#include <avr/io.h>
#include <util/delay.h> 
int main(void)
{
  DDRD = 0xFB;
  DDRB = 0xFF;
  while(1)
  {
  if(PIND & 0x04)
    {
      PORTB = 0b10000000;
      _delay_ms(500);
    }
  else
    {
      PORTB = 0x00;
    }
  }
}
