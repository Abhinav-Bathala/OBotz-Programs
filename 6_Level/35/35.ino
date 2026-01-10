#include <avr/io.h>
#include <util/delay.h>
#define checkbit (x, y) ((x) & (y)) 
#define bitn (p) (0x01 << (p))

int i, c, d;

//----------------------------------------------------------------------------------------------------------\\

void antistepper()    //Anticlockwise Rotation
{
  if (d == 1)     //"d" just variable name (Need a variable to increment for the program to work)
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
void clkstepper()   //Clockwise Rotation
{
  if (c == 1)     //"c" just variable name (Need a variable to increment for the program to work)
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

void compare()
{
  if (average > 515 && average < 520)
  {
    c++;
    antistepper();
    _delay_ms(50);
  }
  if (average > 685 && average < 690)
  {
    d++;
    clkstepper();
    _delay_ms(50);
  }
}

//----------------------------------------------------------------------------------------------------------\\

int main(void)
{
  DDRD = 0xFF;
  int result, average;
  while(1)
  {
    ADMUX = 0x04;
    ADCSRA = 0xC7; 
    while(checkbit(ADCSRA, bitn(ADSC)));
    result = result + ADCW;
    i++;
  }

  if(i > 99)
  {
    average = result / 100;
    compare();
    result = 0
    average = 0
    i = 0;
  }
}
