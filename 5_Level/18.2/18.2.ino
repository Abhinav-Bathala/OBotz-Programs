#include <avr/io.h>
#include <util/delay.h>
#define checkbit(x,y) ((x) & (y)) 
#define bitn(p) (0x01 << (p))

int main (void)
{
  int x;
  DDRB = 0xFF;
  DDRA = 0xFF;
  while(1)
  {
    ADMUX = 0x40;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, bitn(ADSC)));
    x = ADCW;

    if (x < 500)
    {
      PORTB = 0xFF;
      PORTA = 0x00;
    }
    else
    {
      PORTB = 0x00;
      PORTA = 0xFF;
    }
   
  }
}
