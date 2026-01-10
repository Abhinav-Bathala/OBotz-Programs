#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main()
{
  DDRC = 0b111111111;
  DDRB = 0b111111111;
  PORTB = 0b11111111;
  PORTC = 0b00000000;

  while(1)
  {

//----------Row-Wise from here----------\\

    PORTB = 0b11111110;
    PORTC = 0b00000001;
    _delay_ms(1000);
    PORTB = 0b11111101;
    PORTC = 0b00000001;
    _delay_ms(1000);
    PORTB = 0b11111011;
    PORTC = 0b00000001;
    _delay_ms(1000);
    PORTB = 0b11110111;
    PORTC = 0b00000001;
    _delay_ms(1000);
    PORTB = 0b11101111;
    PORTC = 0b00000001;
    _delay_ms(1000);
    PORTB = 0b11110111;
    PORTC = 0b00000001;
    _delay_ms(1000);
    PORTB = 0b11111011;
    PORTC = 0b00000001;
    _delay_ms(1000);
    PORTB = 0b11111101;
    PORTC = 0b00000001;
    _delay_ms(1000);
    PORTB = 0b11111110;
    PORTC = 0b00000001;
    _delay_ms(1000);
    PORTB = 0b00000000;
    PORTC = 0b00000000;
    

//----------Column-Wise from here----------\\

    PORTC = 0b00000001;
    PORTB = 0b00000001;
    _delay_ms(1000);
    PORTC = 0b00000010;
    PORTB = 0b00000001;
    _delay_ms(1000);
    PORTC = 0b00000100;
    PORTB = 0b00000001;
    _delay_ms(1000);
    PORTC = 0b00001000;
    PORTB = 0b00000001;
    _delay_ms(1000);
    PORTC = 0b00010000;
    PORTB = 0b00000001;
    _delay_ms(1000);
    PORTC = 0b00001000;
    PORTB = 0b00000001;
    _delay_ms(1000);
    PORTC = 0b00000100;
    PORTB = 0b00000001;
    _delay_ms(1000);
    PORTC = 0b00000010;
    PORTB = 0b00000001;
    _delay_ms(1000);
    PORTC = 0b00000001;
    PORTB = 0b00000001;
    _delay_ms(1000);
    PORTC = 0b00000000;
    PORTB = 0b00000000;
    
    
  }
}
