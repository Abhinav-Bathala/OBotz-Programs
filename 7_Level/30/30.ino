//Humanoid Robot Code Walking Movement

#include <avr/io.h>                 //Including "avr" header file
#include <util/delay.h>             //Including "delay" header file
#include <avr/interrupt.h>
#define setbit(x,y) (x |= y)        //Defining "setbit" macro
#define clearbit(x,y) (x &= y)      //Defining "clearbit" macro
#define bitn(p) (0x01 << (p))       //Defining "bit position" macro

//----------------------------------------------------------------------------------------------------------\\

int count = 0;                     //Introducing "count" variable
int right_fore, left_fore;         //Introducing both "front legs" variables
int right_hind, left_hind;         //Introducing both "back legs" variables

int count_angle, count_angle1, count_angle2, count_angle3;        //Introducing multiple "count_angle" variables

int main()                         //Introducing "main" function
{ 
  DDRD = 0xFF;                     //Setting all pins in PORTD as "output/1"
  TCNT1 = 0x00;                    //Introducing Timer 1
  OCR1A = 21;                      //Setting Output Compare Register as "21"
  TCCR1A = 0x00;                   //Setting all bits in Timer/Counter Control Register to "0"
  TCCR1B = 0x0A;                   //Setting bit '1' and '3' in Timer/Counter Control Register to "1"
  TIMSK1 = 0x02;                   //Setting bit 1 in Timer Interrupt Mask Register to "1"
  SREG = 0x80;                     //Initalizing Global Registers
  home_position();                 //"home_position" function being called
  convert();

  while(1)                                                          //Calling "while" loop
  {
    for (int i = 1; i <= 20; i++)                                   
    {
      right_fore++;
      left_hind--;
      convert();
    }

    for (int i = 1; i <= 10; i++)
    {
      left_fore++;
      right_hind--;
      convert();
    }

    for (int i = 1; i <= 20; i++)
    {
      right_fore--;
      left_hind++;
      convert();
    }

    for (int i = 1; i <= 10; i++)
    {
      left_fore--;
      right_hind++;
      convert();
    }


    for (int i = 1; i <= 20; i++)
    {
      right_hind++;
      left_fore--;
      convert();
    }

    for (int i = 1; i <= 10; i++)
    {
      left_hind++;
      right_fore--;
      convert();
    }

    for (int i = 1; i <= 20; i++)
    {
      right_hind--;
      left_fore++;
      convert();
    }

    for (int i = 1; i <= 10; i++)
    {
      right_fore++;
      left_hind--;
      convert();
    }

  }
}

//----------------------------------------------------------------------------------------------------------\\

void convert()
{
  count_angle = right_fore + 46;
  count_angle1 = right_hind + 46;
  count_angle2 = left_fore + 46;
  count_angle3 = left_hind + 46;
  _delay_us(1200);
}

void home_position()
{
  right_fore = 90;
  right_hind = 90;
  left_fore = 90;
  left_hind = 90;
}

ISR(TIMER1_COMPA_vect)    //Actual Function (ISR Interrupt)
{
  count++;
  if (count <= count_angle)        //1 Motors
  {
    setbit(PORTD, bitn(4));
  }
  else if((count > count_angle) && (count < 1818))
  {
    clearbit(PORTD, bitn(4));
  }
  else if(count >= 1818)
  {
    count = 0;
  }
  
  if (count <= count_angle1)        //2 Motors
  {
    setbit(PORTD, bitn(5));
  }
  else if((count > count_angle1) && (count < 1818))
  {
    clearbit(PORTD, bitn(5));
  }
  else if(count >= 1818)
  {
    count = 0;
  }
  
  if (count <= count_angle2)        //3 Motors
  {
    setbit(PORTD, bitn(6));
  }
  else if((count > count_angle2) && (count < 1818))
  {
    clearbit(PORTD, bitn(6));
  }
  else if(count >= 1818)
  {
    count = 0;
  }
  
  if (count <= count_angle3)        //4 Motors
  {
    setbit(PORTD, bitn(7));
  }
  else if((count > count_angle3) && (count < 1818))
  {
    clearbit(PORTD, bitn(7));
  }
  else if(count >= 1818)
  {
    count = 0;
  }
} 
