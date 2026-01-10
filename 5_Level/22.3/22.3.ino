#include <avr/io.h>
#include <util/delay.h>
#define checkbit(x,y) ((x) & (y)) 
#define bitn(p) (0x01 << (p))

int main (void)
{
  int yval;
  Serial.begin(2000000);
  DDRB = 0xFF;
  DDRC = 0xFF;

  while(1)
  {
    ADMUX = 0x46;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA,bitn(ADSC)));
    yval = ADCW;
    Serial.println(yval);

    if (yval > 370)
    {
      PORTC = 0xFF;
      PORTB = 0x00;
    }

    if (yval < 300)
    {
      PORTC = 0x00;
      PORTB = 0xFF;
    }
    

  }

}
