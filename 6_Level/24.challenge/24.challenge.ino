#include <avr/io.h>
#include <util/delay.h>>
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))

int i = 0;
int count = 0;
int error = 0;
long result, average;


//------------------------------------------------------------------------------------------------------------------\\

int main(void)
{ 
  DDRB = 0xFF;
  OCR1A = 21;
  TCCR1A = 0x00;
  TCCR1B = 0x0A;
  TIMSK1 = 0x02;
  SREG = 0x80;
  DDRD = 0xFF;
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
   if((count == 0)
   {
       count++;
       PORTD = 0b00000010;
       if((average > 515 && average < 519) && (count == 1))
       {
         count++;
         if((average > 486 && average < 490) && (count == 2))
         {  
            count++;
            if((average > 634 && average < 638) (count == 3)
            {
               count++;
               if((average > 470 && average < 474) && (count == 4))
               {
                  PORTD = 0b00000001;
               }
               else
               {
                  error++;
                  count = 0;
               }
            }
            else
            {
               error++;
               count = 0;
            }
         }
         else
         {
            error++;  
            count = 0;                                           
         }
      }
      else
      {
        error++;
        count = 0;
      }
   }
   else if(error == 4)
   {
      error = 0;
      count = 0;
      PORTD = 0b00000111; 
   }
   
  if(average > 643 && average < 647)
  {
    PORTD = 0b00000000;
  }
  else
  {
    PORTD = 0b00000010;
  }
}
