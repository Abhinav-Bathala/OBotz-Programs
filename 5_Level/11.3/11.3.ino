#include <avr/io.h>               //Defining Library AVR controller
#include <util/delay.h>           //Defining Library for delay
#define checkbit(x,y) ((x) & (y)) //Define Macro for bit of register
#define bitn(p) (0x01 << (p))     //Define Macro for bit position
int main(void)                    //int main
{
  DDRD = 0xFB;                     //Setting PD2 as output
  DDRB = 0xFF;
  while(1)                        //While-Loop
  {
  if(checkbit(PIND,bitn(2)))      //Checking if Tact Switch is pressed
    {
      PORTB = 0b00100000;         //Set PD0 Low
      _delay_ms(200);             //Delay 200 miliseconds
    }
  else                            //Else...
    {
      PORTB = 0b00000000;         //Set PD1 as High
    }
  }
}
