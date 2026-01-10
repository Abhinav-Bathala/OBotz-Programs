#include <avr/io.h>
#include <util/delay.h>
#define checkbit(x,y) ((x) & (y)) 
#define bitn(p) (0x01 << (p))

int main (void)
{
  int left, right;
  DDRB = 0xFF;

  while(1)
  {
    ADMUX = 0x40;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, bitn(ADSC)));
    right = ADCW;
    ADMUX = 0x41;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, bitn(ADSC)));
    left = ADCW;
   

    if ((left < 500) && (right < 500))
    {
      PORTB = 0xFF;
      
    }
    else
    {
      PORTB = 0x00;
    }
   
  }
}
