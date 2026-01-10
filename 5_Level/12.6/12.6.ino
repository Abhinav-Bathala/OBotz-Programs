#include <avr/io.h>               
#include <util/delay.h>         
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))

int main(void)
{
  DDRB = 0xFF;
  DDRC = 0xFF;
  int count = 0;
  while(1)
  {
    if(checkbit(PIND,bitn(2)))
    {
      count++;
      _delay_ms(500);
    }
    if(count == 1)
    {
      PORTB = 0x40;
    }
    if(count == 2)
    {
      PORTB = 0x80
    }
    if(count == 3)
    {   
      PORTB = 0x00; 
    }
     if(count == 50)
    {   
      PORTC = 0xFF;
    }
     if(count == 51)
    {   
      count = 0;
    }
    
    
  }
}
