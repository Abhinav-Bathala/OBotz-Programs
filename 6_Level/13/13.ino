#include <avr/io.h>           //including header file for avr chip
#include <util/delay.h>       //including delay file
#include <avr/interrupt.h>    //including interrupt file

#define key1 0x1FE50AF        //setting key 1 with proper value (macro)
#define key2 0x1FED827        //setting key 2 with proper value (macro)
#define key3 0x1FEF807        //setting key 3 with proper value (macro)

long keycode = 0;             //Declaring variable "keycode" -> data type "long"
int timervalue;               //Declaring variable "timervalue" -> data type "integer"
int bitposition = 0;          //Declaring variable "bitposition" -> data type "integer"
int x = 0;

ISR(TIMER0_OVF_vect)          //ISR Register
{
  x++;                        //incrementing variable "x"
  TCNT0 = 125;                //Changing TCNT0 Value to 125
}
ISR(INT2_vect)                //other ISR register
{
  timervalue = x;             //setting variable "x" to the same value as "timervalue"
  x = 0;
  bitposition++;              //incrementing variable "bitposition"
  if((timervalue >= 100))     //checking if timervalue variable is greater or equal to 100
  {
    bitposition = -2;         //changing bitposition value to -2
    keycode = 0;              //keycode value back to 0
  }
  if((bitposition >= 0) && (bitposition < 32))      //checking if bitposition is greater or equal to 0 AND bitposition is less than 32
  {
    if(timervalue > 3)                              //checking if timervalue is more than 3
    {
      keycode |=(long)1<<(31 - bitposition);        //keycode OR gate or equal to 
    }
  }
  else if(bitposition >= 32)                        //if none of the above is true, if bitposition is greater than or equal to 32...
  {
    bitposition = 0;                                //bitposition is equal to 0
    compare();                                      //calling compare function
  }
}
int main(void)              //main function                                              
{
  DDRB = 0x00;              //Setting all pins in PORTB as input
  DDRD = 0xFF;              //Setting all pins in PORTD as output
  TIMSK0 = 0x01;            //TIMSK0 register is in hexa_decimal value of 0x01
  EICRA = 0x20;             //EICRA register is in hexa_decimal value of 0x20
  EIMSK = 0x04;             //EIMSK register is in hexa_decimal value of 0x04
  SREG = 0x80;              //SREG register is in hexa_decimal value of 0x80
  TCCR0A = 0x00;            //TCCR0A register is in hexa_decimal value of 0x00
  TCCR0B = 0x03;            //TCCR0B register is in hexa_decimal value of 0x03
  while(1)                  //forever loop
  {
    
  }
}

void compare()              //compare fuction declaration 
{
  if(keycode == key1)       //Checking if number 1 is pressed on IR Remote
  {
    PORTD = 0x04;           //Turning on LED - Blue
  }
  if(keycode == key2)       //Checking if number 2 is pressed on IR Remote
  {
    PORTD = 0x08;           //Turning on LED - Yellow
  }
  if(keycode == key3)       //Checking if number 3 is pressed on IR Remote
  {
    PORTD = 0x0C;           //Turning on LED - Blue and LED - Yellow
  }
}
