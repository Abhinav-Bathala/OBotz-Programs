#include <avr/io.h>
#include <util/delay.h>
#include <LCD.h> 

int main (void)
{
   LCD lcd;
   lcd.init();
   while(1)
   {
    for (int i = 0; i < 16; i++)
    {
      lcd.cmd(0x01);
      lcd.line1(16-i);
      lcd.string("Hello");
      lcd.line2(16-i);
      lcd.string("World");
      _delay_ms(500);
    }
   }
}
