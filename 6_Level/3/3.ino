#include<avr/io.h>                            //Including header file in beginnning of program
int main(void)                                //Declaring int main
{
  DDRD = 0x01;                                //Setting pin 0 as output (rest as input)
  while(1)
  {
    PORTD = 0x00;                             //LED off
    waitms(500);                              //waitms function for 500ms 
    PORTD = 0x01;                             //LED red on
    waitms(500);                              //waitms function for 500ms
  }
}

void waitms(int a)                            //Declaring wait function
{ 
  int count = 0;                              //Declaring variable "count" and setting its value to 0
  TCCR0A = 0x00;                              //Setting timer 0 to normal mode
  TCCR0B = 0x03;                              //Setting timer to prescaler 64
  while(!(count == a))                        //While loop (if count DOESN'T equal to variable a)
  {
    if(TCNT0 == 249)                          //Checking if timer is 249 (if its 1 millisecond)
    {
      count++;                                //incrementing variable count by 1
      TCNT0 = 0;                              //Resetting timer back to 0
    }
  }
}
