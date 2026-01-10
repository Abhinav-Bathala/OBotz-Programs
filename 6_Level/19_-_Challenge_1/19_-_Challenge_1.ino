#include <avr/io.h>
#include <util/delay.h>

int numbers[] = {0b11110110, 0b01100000, 0b11010101, 0b11110001, 0b01100011, 0b10110011, 0b10110111, 0b11100000, 0b11110111, 0b11110011}; //Including all the SSD values into an array
int i = 0;
int main(void)                                                                                                                 
{
  DDRC = 0xFF;                                                                                                                        
  while(1)
  {
    PORTC = numbers[i];
    i++;
    if (i == 9)
    {
      i = 0;
    }
  }
}
