#include <avr/io.h>               
#include <util/delay.h>         
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))

int main(void)
{
  DDRB = 0x0F;
  DDRD = 0x00;
  while(1)
  {
    if((checkbit(PIND,bitn(2))) && (checkbit(PIND,bitn(3))) && (checkbit(PINB,bitn(4))))
    {
      PORTB = 0b00010000;
    }
    else
    {
      PORTB = 0x00;
    }
  }
}
