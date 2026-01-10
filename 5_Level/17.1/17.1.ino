#include <avr/io.h>               
#include <util/delay.h>           
#define checkbit(x,y) ((x) & (y)) 
#define bitn(p) (0x01 << (p))

int main(void)
{
  int x, y;
  Serial.begin(2000000);
  while(1)
  {
    ADMUX = 0x40;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA,bitn(ADSC)));
    x = ADCW;
    ADMUX = 0x41;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA,bitn(ADSC)));
    y = ADCW;
    Serial.println("Left IR = ");
    Serial.println(x);
    Serial.println("Right IR = ");
    Serial.println(y);
    _delay_ms(1000);
  }
}
