#include <avr/io.h>
#include <util/delay.h>
int count = 0;
int main(void)
{
  DDRD = 0b00000101;                //DDRD = 0b00000101
  TCCR0A = 0x00;                    //Timer 0 (Normal Mode)
  TCCR0B = 0x03;                    //Prescaler of 64
  while(1)                          //Forever Loop
  {
    if (TCNT0 == 249)               //249 = 1 ms (Milliseconds)
    {
      count++;                      //count = count + 1
      TCNT0 = 0;                    //Timer gets reset
    }
    if(count == 500)                //Checking if the counter variable is equal to 500
    {
      PORTD ^= 0b00000001;          //Toggle PD0 pin
      count = 0;                    //Setting red_count variable as 0
    }
    PORTD ^= 0b00000100;            //Toggle PD2 pin

  }
}
