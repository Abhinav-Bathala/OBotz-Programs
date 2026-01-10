#include <avr/io.h>                 //Including "avr" header file
#include <util/delay.h>                  //Including "delay" header file
#define setbit(x,y) (x |= y)        //Defining "setbit" macro
#define clearbit(x,y) (x &= y)      //Defining "clearbit" macro
#define bitn(p) (0x01 << (p))       //Defining "bit position" macro

//----------------------------------------------------------------------------------------------------------\\

int count = 0;                     //Introducing "count" variable
int right_hip, left_hip;           //Introducing both "hips" variables
int right_hand, left_hand;         //Introducing both "hands" variables
int right_foot, left_foot;         //Introducing both "foots" variables

int count_angle, count_angle1, count_angle2, count_angle3, count_angle4, count_angle5;        //Indroducing multiple "count_angle" variables

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
    for (left_hip = 90; left_hip >= 45; left_hip--)           //For loop will be running as long as "right_foot" is greater or equal to 80 (right_foot is decrementing itself and in the beginning is set to 90)
    {
      convert();                                                    //"convert" function is being called
    }
    _delay_ms(20);                                                  //Delay of 20ms

    for (left_hip = 45; left_hip <= 90; left_hip++)           //For loop will be running as long as "right_foot" is greater or equal to 90 (right_foot is incrementing itself and in the beginning is set to 80)       
    {
      convert();                                                    //"convert" function is being called
    }
    _delay_ms(20);                                                  //Delay of 20ms
    
  }
}

//----------------------------------------------------------------------------------------------------------\\

void convert()
{
  count_angle = right_hip + 46;
  count_angle1 = right_foot + 46;
  count_angle2 = left_hip + 46;
  count_angle3 = left_foot + 46;
  count_angle4 = left_hand + 46;
  count_angle5 = right_hand + 46;
  _delay_us(1500);
}

void home_position()
{
  right_hip = 90;
  right_foot = 90;
  left_hip = 90;
  left_foot = 90;
  left_hand = 140;
  right_hand = 40;
}

ISR(TIMER1_COMPA_vect)    //Actual Function (ISR Interrupt)
{
  count++;
  if(count <= count_angle)          //1 Motor
  {
    setbit(PORTD, bitn(2));
  }
  else if((count > count_angle) && (count < 1818))
  {
    clearbit(PORTD, bitn(2));
  }
  else if(count >= 1818)
  {
    count = 0;        
  }
  
  if (count <= count_angle1)        //2 Motors
  {
    setbit(PORTD, bitn(3));
  }
  else if((count > count_angle1) && (count < 1818))
  {
    clearbit(PORTD, bitn(3));
  }
    else if(count >= 1818)
  {
    count = 0;
  }
  
  if (count <= count_angle2)        //3 Motors
  {
    setbit(PORTD, bitn(4));
  }
  else if((count > count_angle2) && (count < 1818))
  {
    clearbit(PORTD, bitn(4));
  }
  else if(count >= 1818)
  {
    count = 0;
  }
  
  if (count <= count_angle3)        //4 Motors
  {
    setbit(PORTD, bitn(5));
  }
  else if((count > count_angle3) && (count < 1818))
  {
    clearbit(PORTD, bitn(5));
  }
  else if(count >= 1818)
  {
    count = 0;
  }
  
  if (count <= count_angle4)        //5 Motors
  {
    setbit(PORTD, bitn(6));
  }
  else if((count > count_angle4) && (count < 1818))
  {
    clearbit(PORTD, bitn(6));
  }
  else if(count >= 1818)
  {
    count = 0;
  }
  
  if (count <= count_angle5)        //6 Motors
  {
    setbit(PORTD, bitn(7));
  }
  else if((count > count_angle5) && (count < 1818))
  {
    clearbit(PORTD, bitn(7));
  }
  else if(count >= 1818)
  {
    count = 0;
  }
}
