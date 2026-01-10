#include <avr/io.h>         // header file AVR microcontroller
#include <util/delay.h>     // header file for delay
int count = 0;              // declaring variable "count"
int main(void)              // main func
{
  Serial.begin(2000000);    // beginning serial moniter at baud rate 2000000
  while(1)                  // forever loop
  {
    _delay_ms(1000);        // delay for 1 second
    Serial.println(count);  // printing values of "count"
    count = count + 2;      // adding 2 each time to "count"
  }
}
