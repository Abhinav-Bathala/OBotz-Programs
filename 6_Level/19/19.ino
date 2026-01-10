#include <avr/io.h>
#include <util/delay.h>

int numbers[] = {0b11110110, 0b01100000, 0b11010101, 0b11110001, 0b01100011, 0b10110011, 0b10110111, 0b11100000, 0b11110111, 0b11110011}; //Including all the SSD values into an array
int main(void)                                                                                                                           //Declaring main function
{
  DDRC = 0xFF;                                                                                                                           //Setting all PORTC pins at output
  while(1)
  {
    for (int i = 0; i < 10; i++)                                                                                                         //Declaring for loop with the following arguements
    {
      PORTC = numbers[i];                                                                                                                //Setting the numbers on SSD from 1 - 9 by incrementing the array
      _delay_ms(500);                                                                                                                    //Delay of 500ms
    }
  }
}
