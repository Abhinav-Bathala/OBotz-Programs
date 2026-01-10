#include <avr/io.h>
#include <util/delay.h>>
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))

int i = 0;
long result, average;
int number[] = {0b11110110, 0b01100000, 0b11010101, 0b11110001, 0b01100011, 0b10110011, 0b10110111, 0b11100000, 0b11110111, 0b11110011, 0b00111101, 0b00110111, 0b10010110, 0b01110101, 0b01100110, 0b10010000};
//                  0            1           2           3           4           5          6            7          8            9           a           b          c            d          #           =
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
    PORTC = number[1];
  }
  if(average > 686 && average < 690)
  {
    PORTC = number[2];
  }
  if(average > 763 && average < 769)
  {
    PORTC = number[3];
  }
  if(average > 1012 && average < 1016)
  {
    PORTC = number[10];
  }
  if(average > 486 && average < 490)
  {
    PORTC = number[4];
  } 
  if(average > 634 && average < 638)
  {
    PORTC = number[5];
  }
  if(average > 700 && average < 704)
  {
    PORTC = number[6];
  }
  if(average > 904 && average < 908)
  {
    PORTC = number[11];
  }
  if(average > 470 && average < 474)
  {
    PORTC = number[7];
  }
  if(average > 608 && average < 612)
  {
    PORTC = number[8];
  }
  if(average > 668 && average < 672)
  {
    PORTC = number[9];
  }
  if(average > 852 && average < 856)
  {
    PORTC = number[12];
  }
  if(average > 458 && average < 462)
  {
    PORTC = number[15];
  }
  if(average > 588 && average < 592)
  {
    PORTC = number[0];
  }
  if(average > 643 && average < 647)
  {
    PORTC = number[14];
  }
  if(average > 813 && average < 817)
  {
    PORTC = number[13];
  }
  
}
