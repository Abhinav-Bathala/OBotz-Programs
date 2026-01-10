#include <avr/io.h>         //initializing avr header file
#include <util/delay.h>     //intializing delay header file
#include <LCD.h>            //initializing lcd header file
#include <avr/interrupt.h>  //initializing interrupt header file
#define bitn(p) (0x01 << (p)) //bit macro
#define setbit(x, y) (x |= y) //setbit macro
#define clearbit(x,y) (x &= ~y) //clearbit macro
#define checkbit(x,y) ((x) & (y)) //checkbit macro
int count, angle, count_angle;

//---------------------------------------------------------------------------\\

int main(void)
{
  DDRD = 0xFF;
  TCNT1 = 0x00;
  OCR1A = 21;
  TCCR1A = 0x00;
  TCCR1B = 0x0A;
  TIMSK1 = 0x02;
  SREG = 0x80;
  while(1)
  {
    for (angle = 90; angle <= 150; angle++)
    {
      convert();
    } 
    for (angle = 150; angle >= 90; angle--)
    {
      convert();
    }
  }
}

//---------------------------------------------------------------------------\\

void convert()
{

  count_angle = angle + 46;
  _delay_us(5000);
}  
  
ISR(TIMER1_COMPA_vect)    //Actual Function
{
  count++;
  if(count <= count_angle)        //For 1 Motor
  {
    setbit(PORTD, bitn(7));
  } 
  else if((count > count_angle) && (count < 1818))
  {
    clearbit(PORTD, bitn(7));
  }
  else if(count >= 1818)
  {
    count = 0;        
  } 
}
