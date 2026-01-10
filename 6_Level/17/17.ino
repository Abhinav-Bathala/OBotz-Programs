#include<avr/io.h>
#include<util/delay.h>
#define clearbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))
int x, z;
int count = 0;

int main(void)
{
  DDRB = 0xFF;
  OCR1A = 21;
  TCCR1A = 0x00;
  TCCR1B = 0x0A;
  TIMSK1 - 0x02;
  SREG = 0x80;
  while (1)
  {
    ADMUX = 0x42
    ADCSRA = 0xC7;
    while(checkbit(ADSCRA,bitn (ADSC));
    x = ADCW;
    angle(z);
  }
}
