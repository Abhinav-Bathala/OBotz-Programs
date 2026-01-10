#include <avr/io.h>
#include <util/delay.h>
#define checkbit(x, y) ((x) & (y))
#define bitn(p) (0x01 << (p))

double logR2, R2, T, Tc;
int c, d;
int main(void)
{
  float c1 = 0.001125307752122;
  float c2 = 0.000234711863267;
  float c3 = 0.000000085663516;
  Serial.begin(2000000);
  while(1)
  {
    ADMUX = 0x40;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, bitn(ADSC)));
    R2 = (10000/(1023 - ADCW)) * ADCW;
    logR2 = log(R2);
    T = (1.0 /  (c1 + c2*logR2 + c3*logR2*logR2*logR2));
    Tc = T - 273.15;

    if (Tc > 25)
    {
      c++;
      antistepper();
      _delay_ms(50);
    }
    if (Tc < 25)
    {
      d++;
      clkstepper();
      _delay_ms(50);
    }
  }
}

//------------------------------------------------------------------------------------------------------\\

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
