#include <avr/io.h>
#include <util/delay.h>
#define bitn(p) (0x01 << (p))
#define setbit(x, y) (x |= y)
#define clearbit(x,y) (x &= ~y)
#define checkbit(x,y) ((x) & (y))

// 0b00010000; 0b00001000; 0b00000100; 0b00000010; 0b00000001; - Column Values
// 0b11101111; 0b11110111; 0b11111011; 0b11111101; 0b11111110; - Row Values

//------------------------------------------------------------------------------------\\

int count = 0;
int period  = 200;
int c;

int right_hip, left_hip;           //Introducing both "hips" variables
int right_hand, left_hand;         //Introducing both "hands" variables
int right_foot, left_foot;         //Introducing both "feet" variables

int count_angle, count_angle1, count_angle2, count_angle3, count_angle4, count_angle5;        //Indroducing multiple "count_angle" variables

//------------------------------------------------------------------------------------\\

int main()
{
  DDRD = 0xFF;                                                    //Setting all pins in PORTD to OUTPUT mode 
  DDRB = 0xFF;                                                    //Setting all pins in PORTB to OUTPUT mode                                 
  DDRC = 0xFF;                                                    //Setting all pins in PORTC to OUTPUT mode 
  PORTB = 0xFF;                                                   //Setting all pins in PORTB to HIGH
  PORTC = 0x00;                                                   //Setting all pins in PORTC to LOW
  TCNT1 = 0x00;
  OCR1A = 21;
  TCCR1A = 0x00;
  TCCR1B = 0x0A;
  TIMSK1 = 0x02;
  SREG = 0x80;                                                    //Initializing Global Registers
  home_position();
  convert();

  while(1)                                                          //Calling "while" loop
  {
    for (right_foot = 90; right_foot <= 130; right_foot++)          //For loop will be running as long as "right_foot" is greater or equal to 80 (right_foot is decrementing itself and in the beginning is set to 90)
    {
      convert();                                                    //"convert" function is being called
      backward_arrow();
    }
    //_delay_ms(20);                                                //Delay of 20ms

    for (left_foot = 90; left_foot <= 100; left_foot++)             //For loop will be running as long as "right_foot" is greater or equal to 90 (right_foot is incrementing itself and in the beginning is set to 80)       
    {
      convert();                                                    //"convert" function is being called
      backward_arrow();
    }
    //_delay_ms(20);                                                //Delay of 20ms
    
   for (int c = 0; c <= 20; c++)
   {
    right_hip++;
    left_hip++;
    left_hand--;
    right_hand--;
    convert();
    backward_arrow();
   }

   for (right_foot = 130; right_foot >= 90; right_foot--)           //For loop will be running as long as "right_foot" is greater or equal to 80 (right_foot is decrementing itself and in the beginning is set to 90)
    {
      convert();                                                    //"convert" function is being called
      backward_arrow();
    }
    //_delay_ms(20);                                                //Delay of 20ms

    for (left_foot = 100; left_foot >= 90; left_foot--)             //For loop will be running as long as "right_foot" is greater or equal to 90 (right_foot is incrementing itself and in the beginning is set to 80)       
    {
      convert();                                                    //"convert" function is being called
      backward_arrow();
    }
    //_delay_ms(20);                                                //Delay of 20ms
    
   for (int c = 0; c <= 20; c++)
   {
    right_hip--;
    left_hip--;
    left_hand++;
    right_hand++;
    convert();
    backward_arrow();
   } 

   for (right_foot = 90; right_foot >= 80; right_foot--)           //For loop will be running as long as "right_foot" is greater or equal to 80 (right_foot is decrementing itself and in the beginning is set to 90)
    {
      convert();                                                   //"convert" function is being called
      backward_arrow();
    }
    //_delay_ms(20);                                               //Delay of 20ms

    for (left_foot = 90; left_foot >= 50; left_foot--)             //For loop will be running as long as "right_foot" is greater or equal to 90 (right_foot is incrementing itself and in the beginning is set to 80)       
    {
      convert();                                                   //"convert" function is being called
      backward_arrow();
    }
    //_delay_ms(20);                                               //Delay of 20ms
    
   for (int c = 0; c <= 20; c++)
   {
    right_hip--;
    left_hip--;
    left_hand++;
    right_hand++;
    convert();
    backward_arrow();
   }
   
   for (right_foot = 80; right_foot <= 90; right_foot++)           //For loop will be running as long as "right_foot" is greater or equal to 80 (right_foot is decrementing itself and in the beginning is set to 90)
    {
      convert();                                                   //"convert" function is being called
      backward_arrow();
    }
    //_delay_ms(20);                                               //Delay of 20ms

    for (left_foot = 50; left_foot <= 90; left_foot++)             //For loop will be running as long as "right_foot" is greater or equal to 90 (right_foot is incrementing itself and in the beginning is set to 80)       
    {
      convert();                                                   //"convert" function is being called
      backward_arrow();
    }
    //_delay_ms(20);                                               //Delay of 20ms
    
   for (int c = 0; c <= 20; c++)
   {
    right_hip++;
    left_hip++;
    left_hand--;
    right_hand--;
    convert();
    backward_arrow();
   }
  }
}
//------------------------------------------------------------------------------------\\

void convert()
{
  count_angle = right_hip + 46;
  count_angle1 = right_foot + 46;
  count_angle2 = left_hip + 46;
  count_angle3 = left_foot + 46;
  count_angle4 = left_hand + 46;
  count_angle5 = right_hand + 46;
}

void backward_arrow()
{
  PORTC = 0b00000100;
  PORTB = 0b11101111;
  _delay_ms(1);
  PORTC = 0b00000100;
  PORTB = 0b11110111;
  _delay_ms(1);
  PORTC = 0b00010101;
  PORTB = 0b11111011;
  _delay_ms(1);
  PORTC = 0b00001110;
  PORTB = 0b11111101;
  _delay_ms(1);
  PORTC = 0b00000100;
  PORTB = 0b11111110; 
  _delay_ms(1);
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
