#include<avr/io.h>
#include<util/delay.h>
#define clearbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))
int main(void)
{
  int x;
  int y;
  DDRD = 0xFF;
  DDRC = 0xFF;
  DDRB = 0x00;  
  Serial.begin(2000000);
  while(1)
  {
    ADMUX = 0x42;
    ADCSRA = 0xC7;
    while (ADCSRA & (1 << ADSC));
    y = ADCW;
    ADMUX = 0x43;
    ADCSRA = 0xC7;
    while (ADCSRA & (1 << ADSC));
    x = ADCW;

    if(PINB & 0x01)
    {
      PORTC = 0xFF;
    }
    else
    {
      PORTC = 0x00;
    }
    if(x > 900)
    {
      PORTD = 0b00000001;
    }
    if(x < 100)
    {
      PORTD = 0b00000010;
    }
    if(y > 900)
    {
      PORTD = 0b00000100;
    }
    if(y < 100)
    {
      PORTD = 0b00001000;
    }
    else
    {
      PORTD = 0b00000000;
    }

  }
}
