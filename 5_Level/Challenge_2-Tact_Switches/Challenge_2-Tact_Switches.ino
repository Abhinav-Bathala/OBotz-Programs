#include <avr/io.h>               
#include <util/delay.h>           
#define checkbit(x,y) ((x) & (y)) 
#define bitn(p) (0x01 << (p))     
int main(void)                    
{
  DDRB = 0xFB;                    
  while(1)                        
  {
  if(checkbit(PIND,bitn(2)))      
    {
      PORTB = 0b00100000;               
      _delay_ms(1000);             
    }
  if(checkbit(PIND,bitn(3)))
    {
      PORTD = 0b00000000;
      _delay_ms(1000);
    }
  }
}
