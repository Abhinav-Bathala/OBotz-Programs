#include <avr/io.h>
#include <util/delay.h>
#include <LCD.h> 

int main (void)
{
   LCD lcd;
   lcd.init();
   lcd.string("a b c d e");
}
