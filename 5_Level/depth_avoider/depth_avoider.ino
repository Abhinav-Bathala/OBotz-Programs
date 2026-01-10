#include <avr/io.h>
#include <util/delay.h>
#define checkbit(x,y) ((x) & (y)) 
#define bitn(p) (0x01 << (p))

int main (void)
{
  int left_ir, right_ir;
  DDRD = 0xFF;
  DDRB = 0xFF;

  while(1)
  {
    ADMUX = 0x40;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, bitn(ADSC)));
    left_ir = ADCW;

    ADMUX = 0x41;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, bitn(ADSC)));
    right_ir = ADCW;
   

    if ((left_ir > 300) && (right_ir > 300))
    {
       PORTB = 0b10100000;
    }
    if ((left_ir < 300) && (right_ir < 300))
    {
       PORTB = 0b01010000;
    }
    if ((left_ir > 300) && (right_ir < 300))
    {
       PORTB = 0b01100000;
    }
    if ((left_ir < 300) && (right_ir > 300))
    {
       PORTB = 0b10010000;
    }
  
  }
  
  return 0;
}
