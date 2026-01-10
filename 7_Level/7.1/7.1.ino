#include <avr/io.h>
#include <util/delay.h>

int main()
{
  DDRB = 0xFF;
  DDRC = 0xFF;
  PORTB = 0xFF;
  PORTC = 0x00;

  while(1)
  {  
    int i = 0;
    while (i <= 4)
    {
      PORTC = 1 << (i);
      _delay_ms(50);
      i++;
      int j = 0;
      while (j <= 4)
      {
        PORTB = ~(1 << (j));
        j++;
        _delay_ms(50);
      }
    }
  }
}
