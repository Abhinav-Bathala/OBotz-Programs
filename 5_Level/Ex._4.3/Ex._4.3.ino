#include <avr/io.h>         
#include <util/delay.h>     
             
int main(void)             
{
  Serial.begin(2000000);
  //int x = 0b00100000;
           
  while(1)
  {
    byte result = ~(0b00100000);
    Serial.println(result, BIN);
    _delay_ms(5000); 
  }
}
