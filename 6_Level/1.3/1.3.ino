#include <avr/io.h>
#include <util/delay.h>
int count = 0;
int main(void)
{
  DDRD = 0x0F;                      //DDRD = 0b00000001
  TCCR0A = 0x00;                    //Timer 0 (Normal Mode)
  TCCR0B = 0x03;                    //Prescaler of 64
  while(1)                          //Forever Loop
  {
    if (TCNT0 == 249)               //249 = 1 ms (Milliseconds)
    {
      count++;                      //count = count + 1
      TCNT0 = 0;                    //Timer gets reset
    }
    if(count == 400)                //Checking if the counter variable is equal to 400
    {
      PORTD ^= 0x0F;                //Toggle PD0, PD1, PD2, and PD3 pin
      count = 0;                    //Setting count variable as 0
    }
  }
}
