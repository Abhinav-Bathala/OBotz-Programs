#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main()
{
  DDRB = 0xFF;
  DDRC = 0xFF;
  PORTB = 0xFF;
  PORTC = 0x00;
  int period = 1;
  while(1)
  {
    PORTC = 0b00010000;
    PORTB = 0b11110111;
    _delay_ms(period);
    PORTC = 0b00000001;
    PORTB = 0b11111011;
    _delay_ms(period);
    
  }

}
