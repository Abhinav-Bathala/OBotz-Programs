#include <avr/io.h>
#include <util/delay.h>
#include <LCD.h> 

int main (void)
{
   LCD lcd;
   lcd.init();
   lcd.string("1 a 2 b 3 c");
}
