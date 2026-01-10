#include <avr/io.h>               
#include <util/delay.h>         
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))

int main(void)
{
  DDRD = 0xFB;
  DDRC = 0xFF;
  while(1)
  {
    if(checkbit(PIND,bitn(2)))
    {
      PORTC = 0x02;
      PORTD = 0xFF;
      _delay_ms(500);
    }
    if(checkbit(PIND,bitn(3)))
    {
      PORTC = 0x01;
      PORTD = 0x00;
      _delay_ms(500);
    }
    PORTC = 0x00;
  } 
}
