#include <avr/io.h>        //Header file for AVR microcontroller
#include <util/delay.h>    //Header file for delay


int main (void)            
{
  DDRB = 0b11111111;       //Setting entire Port B as output
  while(1)                 //Forever loop starts
  {
    PORTB = 0b11111111;    //Set all pins of Port B as High(logic 1)
    _delay_ms(1000);       //1 second delay
    PORTB = 0b00000000;    //Set all pins of Port B as Low(logic 0)
    _delay_ms(300);       //1 second delay
  }                        //Forever loop ends
}
