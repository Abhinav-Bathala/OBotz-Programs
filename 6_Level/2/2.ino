#include <avr/io.h>
#include <util/delay.h>
int on_count = 0;
int off_count = 0;
int main(void)
{
  DDRD = 0x01;
  TCCR2A = 0x00;
  TCCR0A = 0x00;
  TCCR0B = 0x03;
  while(1)
  {
    timer_0();
    timer_2();   
  }
}


void timer_0()            //Using 8-bit Timer (function)
{
  if(TCNT0 == 249)
  {
    off_count++;
    TCNT0 = 0;
  }
  if(off_count == 1000)
  {
    PORTD = 0x01;
    off_count = 0;
    TCCR0B = 0;
    TCCR2B = 0x03;
  }
}
void timer_2()            //Using 16-bit Timer (function)
{
  if(TCNT2 == 249)
  {
    on_count++;
    TCNT2 = 0;
  }
  if(on_count == 1000)
  {
    PORTD = 0x00;
    on_count = 0;
    TCCR0B = 0x03;
    TCCR2B = 0;
   }
 
}
