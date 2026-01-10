#include <avr/io.h>
#include <util/delay.h>
#define bitn(p) (0x01 << (p))
#define setbit(x, y) (x |= y)
#define clearbit(x,y) (x &= ~y)
#define checkbit(x,y) ((x) & (y))

// 0b00010000; 0b00001000; 0b00000100; 0b00000010; 0b00000001; - Column Values
// 0b11101111; 0b11110111; 0b11111011; 0b11111101; 0b11111110; - Row Values

//------------------------------------------------------------------------------------\\

long result, average;
int i = 0;

int main(void)
{
  
  Serial.begin(2000000);
  while(1)
  {
    /*
    ADMUX = 0x46;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, bitn(ADSC)));
    result = result + ADCW;
    i++;

    if(i > 99)
    {
      average = result/100;
      Serial.println(average);
      _delay_ms(1000);
      result = 0;
      average = 0;
      i = 0;  
      compare();
    }
      */

      PORTC = 0b00000100;
  PORTB = 0b11101111;
  _delay_ms(1);
  PORTC = 0b00001110;
  PORTB = 0b11110111;
  _delay_ms(1);
  PORTC = 0b00000100;
  PORTB = 0b11111011;
  _delay_ms(1);
  PORTC = 0b00000100;
  PORTB = 0b11111101;
  _delay_ms(1);
  PORTC = 0b00000100;
  PORTB = 0b11111110;
  _delay_ms(1);
      
 
    
  
  }
  
}

//------------------------------------------------------------------------------------\\

void up_arrow()
{
  PORTC = 0b00000100;
  PORTB = 0b11101111;
  _delay_ms(1);
  PORTC = 0b00001110;
  PORTB = 0b11110111;
  _delay_ms(1);
  PORTC = 0b00000100;
  PORTB = 0b11111011;
  _delay_ms(1);
  PORTC = 0b00000100;
  PORTB = 0b11111101;
  _delay_ms(1);
  PORTC = 0b00000100;
  PORTB = 0b11111110;
  _delay_ms(1);
}

void down_arrow()
{
  PORTC = 0b00000100;
  PORTB = 0b11101111;
  _delay_ms(1);
  PORTC = 0b00000100;
  PORTB = 0b11110111;
  _delay_ms(1);
  PORTC = 0b00010101;
  PORTB = 0b11111011;
  _delay_ms(1);
  PORTC = 0b00001110;
  PORTB = 0b11111101;
  _delay_ms(1);
  PORTC = 0b00000100;
  PORTB = 0b11111110; 
  _delay_ms(1);
}

void left_arrow()
{
  PORTC = 0b00011111;
  PORTB = 0b11111011;
  _delay_ms(1);
  PORTC = 0b00001000;
  PORTB = 0b11110111;
  _delay_ms(1);
  PORTC = 0b00000100;
  PORTB = 0b11101111;
  _delay_ms(1);
  PORTC = 0b00001000;
  PORTB = 0b11111101;
  _delay_ms(1);
  PORTC = 0b00000100;
  PORTB = 0b11111110;
}

void right_arrow()
{
  PORTC = 0b00011111;
  PORTB = 0b11111011;
  _delay_ms(1);
  PORTC = 0b00000010;
  PORTB = 0b11110111;
  _delay_ms(1);
  PORTC = 0b00000100;
  PORTB = 0b11101111;
  _delay_ms(1);
  PORTC = 0b00000010;
  PORTB = 0b11111101;
  _delay_ms(1);
  PORTC = 0b00000100;
  PORTB = 0b11111110;
  
}

void compare()
{
    while ((average > 685) && (average < 695))
    {
      left_arrow();
    }

    while ((average > 698) && (average < 708))
    {
      right_arrow();
    }

    while ((average > 485) && (average < 495))
    {
      up_arrow();
    }

    while ((average > 605) && (average < 615))
    {
      down_arrow();
    }
    
}
