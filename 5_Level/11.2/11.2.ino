#include <avr/io.h>
#include <util/delay.h> 
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))
int main(void)
{
  DDRD = 0xFB;
  while(1)
  {
  if(checkbit(PIND,bitn(2)))
    {
      PORTD = 0b10000000;
      _delay_ms(200);
    }
  else
    {
      PORTD = 0b00000010;
    }
  }
}
