#include <avr/io.h>
#include <util/delay.h>
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))

int number[] = {0b11110110, 0b01100000, 0b11010101, 0b11110001, 0b01100011, 0b10110011, 0b10110111, 0b11100000, 0b11110111, 0b11110011};
int x, y;

int main(void)
{
  DDRC = 0xFF;
  Serial.begin(2000000);
  while(1)
  {
    ADMUX = 0x42;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, bitn(ADSC)));
    x = ADCW;
    ADMUX = 0x43;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, bitn(ADSC)));
    y = ADCW;
    Serial.println("x = ");
    Serial.println(x);
    Serial.println("y = ");
    Serial.println(y);
    _delay_ms(500);
  }

  if(x < 300)
  {
    PORTC = number[1];
  }
  else if(x > 350)
  {
    PORTC = number[2];
  }
  if(y < 300)
  {
    PORTC = number[3];
  }
  else if(y > 350)
  {
    PORTC = number[4];
  }
  else
  {
    PORTC = number[0];
  }
  
}
