#include <avr/io.h>
#include <util/delay.h>


// 0b00010000; 0b00001000; 0b00000100; 0b00000010; 0b00000001; - Column Values
// 0b11101111; 0b11110111; 0b11111011; 0b11111101; 0b11111110; - Row Values


void small_box()
{
  PORTC = 0b00000100; 
  PORTB = 0b11111011; 
  _delay_ms(100); 
} 
void middle_box() 
{

}
void large_box()

int main()
{
  DDRB = 0xFF;
  DDRC = 0xFF;
  PORTB = 0xFF;
  PORTC = 0x00;
  while(1)
  {  

      
    for (int i = 1; i <= 300; i++)
    {
      PORTC = 0b00000010;
      PORTB = 0b11110001;
      _delay_ms(1);
      PORTC = 0b00000100;
      PORTB = 0b11110101;
      _delay_ms(1);
      PORTC = 0b00001000;
      PORTB = 0b11110001;
      _delay_ms(1);
    } 
    
    for (int i = 1; i <= 300; i++)
    {
      PORTC = 0b00000001;
      PORTB = 0b11100000;
      _delay_ms(1);
      PORTC = 0b00000010;
      PORTB = 0b11101110;
      _delay_ms(1);
      PORTC = 0b00000100;
      PORTB = 0b11101110;
      _delay_ms(1);
      PORTC = 0b00001000;
      PORTB = 0b11101110;
      _delay_ms(1);
      PORTC = 0b00010000;
      PORTB = 0b11100000;
      _delay_ms(1);
    }
    
    for (int i = 1; i <= 300; i++)
    {
      PORTC = 0b00000010;
      PORTB = 0b11110001;
      _delay_ms(1);
      PORTC = 0b00000100;
      PORTB = 0b11110101;
      _delay_ms(1);
      PORTC = 0b00001000;
      PORTB = 0b11110001;
      _delay_ms(1);
    } 
    
  }
}
