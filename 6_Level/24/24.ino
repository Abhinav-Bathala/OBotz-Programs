#include <avr/io.h>
#include <util/delay.h>
#define checkbit(x, y) ((x) & (y))
#define setbit(x, y) (x |= y)
#define clearbit(x, y) (x&= ~y)
#define bitn(p) (0x01 << (p))

int count = 0;
int count_angle;
int i = 0;
int p = 60;
long average, result;

//------------------------------------------------------------------------------------------------------------\\

void angle(int a)
{
  count_angle = a + 46;
}

ISR(TIMER1_COMPA_vect)    //Actual Function
{
  count++;
  if(count <= count_angle)
  {
    setbit(PORTB, bitn(5));
  }
  else if((count > count_angle) && (count < 1818))
  {
    clearbit(PORTB, bitn(5));
  }
  else if(count >= 1818)
  {
    count = 0;
  }
 
}

//------------------------------------------------------------------------------------------------------------\\

int main(void)
{
  DDRB = 0xFF;
  OCR1A = 21;
  TCCR1A = 0x00;
  TCCR1B = 0x0A;
  TIMSK1 = 0x02;
  SREG = 0x80;
  
  while(1)
  {
    ADMUX = 44;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, bitn(ADSC)));
    result = result + ADCW;
    i++;
    if(i > 99)
    {
      average = result / 100;
      compare();
      result = 0;
      average = 0;
      i = 0;
    }    
  }
}

void compare()
{
  if (average > 515 && average < 520)
  {
    p++;
    angle(p);
    Serial.println(average); 
    _delay_ms(50);
  }
  if (average > 685 && average < 690)
  {
    p--;
    angle(p);
    Serial.println(average);
    _delay_ms(50);
  }
}
