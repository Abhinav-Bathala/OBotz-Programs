#include <avr/io.h>         
#include <util/delay.h>     
          
int main(void)             
{
  Serial.begin(2000000);
  int var1 = 0b10100000;
  int var2 = 0b01100011;
             
  while(1)
  {
    int result = var1 & var2;
    Serial.println(result,BIN);
    _delay_ms(5000);              
  }
}
