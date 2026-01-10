#include <avr/io.h>
#include <util/delay.h>
#define bitn(p) (0x01 << (p))
#define setbit(x, y) (x |= y)
#define clearbit(x,y) (x &= ~y)
#define checkbit(x,y) ((x) & (y))

// 0b00010000; 0b00001000; 0b00000100; 0b00000010; 0b00000001; - Column Values
// 0b11101111; 0b11110111; 0b11111011; 0b11111101; 0b11111110; - Row Values

//------------------------------------------------------------------------------------\\


void number_1()
{ 
  PORTC = 0b00000100;
  PORTB = 0b11101111;
  _delay_ms(1);
  PORTC = 0b00000100;
  PORTB = 0b11110111;
  _delay_ms(1);
  PORTC = 0b00000100;
  PORTB = 0b11111011;
  _delay_ms(1);
  PORTC = 0b00000100;
  PORTB = 0b11111101;
  _delay_ms(1);
  PORTC = 0b00011111;
  PORTB = 0b11111110;
  _delay_ms(1);
  PORTC = 0b00001000;
  PORTB = 0b11110111;
  _delay_ms(1);
  
}
void number_2()
{
  PORTC = 0b00010000;
  PORTB = 0b11110111;
  _delay_ms(1);
  PORTC = 0b00001100;
  PORTB = 0b11101111;
  _delay_ms(1);
  PORTC = 0b00000100;
  PORTB = 0b11111011;
  _delay_ms(1);
  PORTC = 0b00001000;
  PORTB = 0b11111101;
  _delay_ms(1);
  PORTC = 0b00001010;
  PORTB = 0b11110111;
  _delay_ms(1); 
  PORTC = 0b00011111;
  PORTB = 0b11111110;
  _delay_ms(1);
  PORTC = 0b00001000;
  PORTB = 0b11110111;
}
void number_3()
{
  PORTC = 0b00001110;
  PORTB = 0b11101111;
  _delay_ms(1);
  PORTC = 0b00001110;
  PORTB = 0b11111011;
  _delay_ms(1);
  PORTC = 0b00001110;
  PORTB = 0b11111110;
  _delay_ms(1);
  PORTC = 0b00000010;
  PORTB = 0b11110111;
  _delay_ms(1);
  PORTC = 0b00000010;
  PORTB = 0b11111101;
  _delay_ms(1);
}
void number_4()
{ 
  PORTC = 0b00001010;
  PORTB = 0b11101111;
  _delay_ms(1);
  PORTC = 0b00001010;
  PORTB = 0b11110111;
  _delay_ms(1);
  PORTC = 0b00001010;
  PORTB = 0b11111011;
  _delay_ms(1);
  PORTC = 0b00000010;
  PORTB = 0b11111101;
  _delay_ms(1);
  PORTC = 0b00000010;
  PORTB = 0b11111110;
  _delay_ms(1);
  
}
void number_5()
{
  PORTC = 0b00001110;
  PORTB = 0b11101111;
  _delay_ms(1);
  PORTC = 0b00001000;
  PORTB = 0b11110111;
  _delay_ms(1);
  PORTC = 0b00001110;
  PORTB = 0b11111011;
  _delay_ms(1);
  PORTC = 0b00000010;
  PORTB = 0b11111101;
  _delay_ms(1);
  PORTC = 0b00001100;
  PORTB = 0b11111110;
  _delay_ms(1);
  
}

void reset_matrix()                // Reset Matrix Function
{
  PORTC = 0x00;
  PORTB = 0xFF;
  _delay_ms(1000);
}


int main (void)
{
  DDRB = 0xFF;                      //Setting all pins in PORTB as OUTPUT
  DDRC = 0xFF;                      //Setting all pins in PORTC as OUTPUT
  PORTB = 0xFF;                     //Setting all pins in PORTB as HIGH
  PORTC = 0x00;                     //Setting all pins in PORTC as LOW


  while(1)
  {
    number_1();
    reset_matrix();
    number_2();
    reset_matrix();
    number_3();
    reset_matrix();
    number_4();
    reset_matrix();
    number_5();
    reset_matrix();
  }
}
