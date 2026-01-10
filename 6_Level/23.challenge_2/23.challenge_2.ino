#include <avr/io.h>
#include <util/delay.h>>
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))

int c = 0;
int d = 0;
int i = 0;
long result, average;


//------------------------------------------------------------------------------------------------------------------\\

int main(void)
{ 
  DDRC = 0xFF;
  PORTD = 0;
  Serial.begin(2000000);
  while(1)
  {
    ADMUX = 0x44;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, bitn(ADSC)));
    result  = result + ADCW;
    i++;
    if(i > 99)
    {
      average = result / 100;
      Serial.println(average);
      compare();
      result = 0;
      average = 0;
      i = 0;
    }
  }
}

//------------------------------------------------------------------------------------------------------------------\\

void compare()
{
  if(average > 515 && average < 519)
  {
    d++;
    
    if (d == 1)     //"d" just variable name (Need a variable to increment for the program to work)
    { 
       d = d + 1;
       PORTD = 0b11100000;
      _delay_ms(500);
       d = d + 1;
      PORTD = 0b11010000;
      _delay_ms(500);
       d = d + 1;
      PORTD = 0b10110000;
      _delay_ms(500);
       d = d + 1;
      PORTD = 0b01110000;
      _delay_ms(500);
       d = 0;
    }
    if (c == 2)     //"c" just variable name (Need a variable to increment for the program to work)
    {       
       c = 0;      //"c" just variable name (Need a variable to increment for the program to work)
    } 
  }  
  
  if(average > 586 && average < 690)
  {
      if (c == 1)
      {
        c = c + 1;
        PORTD = 0b01110000;
        _delay_ms(500);
        c = c + 1;
        PORTD = 0b10110000;
        _delay_ms(500);
        c = c + 1;
        PORTD = 0b11010000;
        _delay_ms(500);
        c = c + 1;
        PORTD = 0b11100000;
        _delay_ms(500);
        c = c + 1;  
      }
      
      if (c == 2)     //"c" just variable name (Need a variable to increment for the program to work)
      {       
        c = 0;      //"c" just variable name (Need a variable to increment for the program to work)
      }   
  } 
}
