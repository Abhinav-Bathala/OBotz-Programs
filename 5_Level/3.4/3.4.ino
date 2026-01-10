#include <avr/io.h>
#include <util/delay.h>
int count = 0;
int main(void)
{
  Serial.begin(2000000);
  while(1)  
  {
    _delay_ms(1000);
    Serial.println(count);
    count = count - 1;
  }
}
