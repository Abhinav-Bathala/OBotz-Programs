#include <avr/io.h>
#include <util/delay.h>

// 0b00010000; 0b00001000; 0b00000100; 0b00000010; 0b00000001; - Column Values
// 0b11101111; 0b11110111; 0b11111011; 0b11111101; 0b11111110; - Row 

void number1()                    //Includes all the LEDs Values to display the number '1'
{
  PORTC = 0b00000100;
  PORTB = 0b11101111;
  _delay_ms(1); 
  PORTC = 0b00001100;
  PORTB = 0b11110111;
  _delay_ms(1); 
  PORTC = 0b00000100;
  PORTB = 0b11111011;
  _delay_ms(1); 
  PORTC = 0b00000100;
  PORTB = 0b11111101;
  _delay_ms(1); 
  PORTC = 0b00011111;
  PORTB = 0b11111110;
  _delay_ms(1); 
}

void number2()                    //Includes all the LEDs Values to display the number '2'
{
  PORTC = 0b00000100;
  PORTB = 0b11101111;
  _delay_ms(1); 
  PORTC = 0b00001010;
  PORTB = 0b11110111;
  _delay_ms(1); 
  PORTC = 0b00000100;
  PORTB = 0b11111011;
  _delay_ms(1); 
  PORTC = 0b00000010;
  PORTB = 0b11111101;
  _delay_ms(1); 
  PORTC = 0b00011111;
  PORTB = 0b11111110;
  _delay_ms(1); 
 
} 

void number3()                    //Includes all the LEDs Values to display the number '2'
{
  PORTC = 0b00001110;
  PORTB = 0b11101111;
  _delay_ms(1); 
  PORTC = 0b00000010;
  PORTB = 0b11110111;
  _delay_ms(1); 
  PORTC = 0b00001110;
  PORTB = 0b11111011;
  _delay_ms(1); 
  PORTC = 0b00000010;
  PORTB = 0b11111101;
  _delay_ms(1); 
  PORTC = 0b00001110;
  PORTB = 0b11111110;
  _delay_ms(1); 
}

void cleardisplay()              //Clears all the LED's on display making none of the LEDs off
{
  PORTC = 0xFF;
  PORTB = 0x00;
}
int main(void)
{
  DDRB = 0xFF;                   //All pins in PORTB is set as OUTPUT
  DDRC = 0xFF;                   //All pins in PORTC is set as INPUT
  PORTC = 0x00;                  //All pins in PORTC is set to LOW
  PORTB = 0xFF;                  //All pins in PORTB is set to HIGH

  while(1)
  {
    number1();                  //Displaying number 1
    cleardisplay();              //Resetting Display
    _delay_ms(1000);             //Delay for 1 second
    number2();                  //Displaying number 2
    cleardisplay();              //Resetting Display
    _delay_ms(1000);             //Delay for 1 second
    number3();                  //Displaying number 3
    cleardisplay();              //Resetting Display
    _delay_ms(1000);             //Delay for 1 second
  }
}
