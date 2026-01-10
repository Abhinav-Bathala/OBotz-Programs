#include <avr/io.h>        
#include <util/delay.h>    

int main (void)            
{
  DDRB = 0xFF;
  DDRD = 0xFF;
  
  while(1)                
  {
    PORTB = 0xFF;
    PORTD = 0x03; 
    _delay_ms(1000);       
    PORTB = 0x00; 
    PORTD = 0x00;  
    _delay_ms(1000);       
  }   
}  
