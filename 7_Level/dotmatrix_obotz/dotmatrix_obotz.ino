#include <avr/io.h>
#include <util/delay.h>

// 0b00010000; 0b00001000; 0b00000100; 0b00000010; 0b00000001; - Column Values
// 0b11101111; 0b11110111; 0b11111011; 0b11111101; 0b11111110; - Row Values

void letter_O()
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
void letter_B()
{ 
  PORTC = 0b00001111;
  PORTB = 0b11111110;
  _delay_ms(1);
  PORTC = 0b00001111; 
  PORTB = 0b11101111;
  _delay_ms(1);
  PORTC = 0b00010001;
  PORTB = 0b11110111; 
  _delay_ms(1);
  PORTC = 0b00101001; 
  PORTB = 0b11111011; 
  _delay_ms(1);
  PORTC = 0b00010001;  
  PORTB = 0b11111101; 
  _delay_ms(1);
  
}
void letter_T()
{ 
 PORTC = 0b00011111;
 PORTB = 0b11111110; 
 _delay_ms(1); 
 PORTC = 0b00000100; 
 PORTB = 0b11100001; 
 _delay_ms(1);
  
}
void letter_Z()
{
  PORTC = 0b00011111; 
  PORTB = 0b11101110;
  _delay_ms(1); 
  PORTC = 0b00001000; 
  PORTB = 0b11111101;
  _delay_ms(1); 
  PORTC = 0b00000100; 
  PORTB = 0b11111011;
  _delay_ms(1);
  PORTC = 0b00000010; 
  PORTB = 0b11110111;
  _delay_ms(1); 
} 

int main()
{
  DDRB = 0xFF;
  DDRC = 0xFF;
  PORTB = 0xFF;
  PORTC = 0x00;

  while(1)
  {  
    for(int i = 0; i <= 300; i++)
    {
      letter_O(); 
      _delay_ms(1);
    } 
    for(int i = 0; i <= 300; i++)
    {
      letter_B(); 
      _delay_ms(1);
    } 
    for(int i = 0; i <= 300; i++)
    {
      letter_O(); 
      _delay_ms(1);
    }
    for(int i = 0; i <= 500; i++)
    {
      letter_T(); 
      _delay_ms(1);
    }
    for (int i = 0; i <= 300; i++)
    {
      letter_Z(); 
      _delay_ms(1);
    }  
    for (int i = 0; i <= 7 00; i++)
    {
      PORTC = 0x00; 
      PORTB = 0xFF;
      _delay_ms(1);
    }   
    
    
  } 
}
 
