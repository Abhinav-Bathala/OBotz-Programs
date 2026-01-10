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
    
    if (d == 1)      //"d" just variable name (Need a variable to increment for the program to work)
    { 
      PORTD = 0b11100000;
    }
    if (d == 2)     //"d" just variable name (Need a variable to increment for the program to work)
    {
      PORTD = 0b11010000;
    }
    if (d == 3)     //"d" just variable name (Need a variable to increment for the program to work)
    {
      PORTD = 0b10110000;
    }
    if (d == 4)     //"d" just variable name (Need a variable to increment for the program to work)
    {
      PORTD = 0b01110000;
      d = 0;      //"d" just variable name (Need a variable to increment for the program to work) 
    }
  }  
  if(average > 586 && average < 690)
  {
    c++;
    
    if (c == 1)      //"c" just variable name (Need a variable to increment for the program to work)
    {
      PORTD = 0b01110000;
    }
    if (c == 2)     //"c" just variable name (Need a variable to increment for the program to work)
    {
      PORTD = 0b10110000;
    }
    if (c == 3)     //"c" just variable name (Need a variable to increment for the program to work)
    {
      PORTD = 0b11010000;
    }
    if (c == 4)     //"c" just variable name (Need a variable to increment for the program to work)
    { 
      PORTD = 0b11100000;
      c = 0;      //"c" just variable name (Need a variable to increment for the program to work)
    }   
  } 
}
