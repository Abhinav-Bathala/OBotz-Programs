#include <avr/io.h>
#include <util/delay.h> 
#define setbit(x,y) (x|=y)
#define clearbit(x,y) (x&= ~y)
#define bitn(p) (0x01 << (p))

int main(void)
{
  setbit(DDRD, 0xFF);
  for(int i = 0; i < 5; i++)
  {
    
    for(int x = 0; x < 5; x++)
    {
      setbit(PORTD,0b00000001);
      _delay_ms(500);
      clearbit(PORTD,0b0000001);
      _delay_ms(500);
    }
    for(int x = 0; x < 5; x++)
    {
      setbit(PORTD,0b00000010);
      _delay_ms(500);
      clearbit(PORTD,0b00000010);
      _delay_ms(500);
    } 
  }
}
