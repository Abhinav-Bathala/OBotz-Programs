#include <avr/io.h>
#include <util/delay.h>
#define bitn(p) (0x01 << (p))
#define checkbit(x,y) ((x) & (bitn(y)))

int main()
{
  int left_IR, right_IR;
  Serial.begin(2000000);
  DDRD = 0xFF;
  while(1)
  {
    ADMUX = 0x40;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, ADSC));
    right_IR = ADCW;
    ADMUX = 0x41;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, ADSC));
    left_IR = ADCW;
    Serial.println(left_IR);
    Serial.println(right_IR);
    _delay_ms(1000);

    if (right_IR > 150 && left_IR > 150) //backwards, then right
    {
      PORTD = 0b01100000;
      _delay_ms(500);
      PORTD = 0b10100000;
      
    }
    if (right_IR < 150 && left_IR > 150) // right
    {
      PORTD = 0b10100000;
    }
    if (right_IR > 150 && left_IR < 150) // left
    {
      PORTD = 0b01010000;
    }  
    if (right_IR < 150 && left_IR < 150) //forward
    {
      PORTD = 0b10010000;
    }
  }
} 
