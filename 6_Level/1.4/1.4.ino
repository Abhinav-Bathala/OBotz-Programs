#include <avr/io.h>
#include <util/delay.h>
int on_count = 0;
int off_count = 0;
int main(void)
{
  DDRD = 0x01;                      //DDRD = 0b00000001
  TCCR0A = 0x00;                    //Timer 0 (Normal Mode)
  TCCR0B = 0x03;                    //Prescaler of 64
  while(1)                          //Forever Loop
  {
    if (TCNT0 == 249)               //249 = 1 ms (Milliseconds)
    {
      off_count++;                  //off_count = off_count + 1
      TCNT0 = 0;                    //Timer gets reset
    }
    if(off_count == 100)            //Checking if the off_counter variable is equal to 500
    {
      PORTD ^= 0x01;                //Toggle PD0 pin
      off_count = 0;                //Setting off_count variable as 0
      TCCR0A = 0x00;                //Timer 0 (Normal Mode)
      TCCR0B = 0x03;                //Prescaler of 64
    }

    if (TCNT0 == 249)               //249 = 1 ms (Milliseconds)
    {
      on_count++;                   //on_count = on_count + 1
      TCNT0 = 0;                    //Timer gets reset
    }
    if(on_count == 400)             //Checking if the on_counter variable is equal to 500
    {
      PORTD ^= 0x01;                //Toggle PD0 pin
      on_count = 0;                 //Setting on_count variable as 0
      TCCR0A = 0x00;                //Timer 0 (Normal Mode)
      TCCR0B = 0x03;                //Prescaler of 64
    }
  }
}
