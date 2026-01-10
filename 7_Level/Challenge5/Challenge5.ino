#include <avr/io.h>                                               //Header file for AVR chip
#include <util/delay.h>                                           //Header file for delay
#include <avr/interrupt.h>                                        //Header file for interrupt
#define checkbit(x,y) ((x) & (y))                                 //Define macro for checkbit
#define bitn(p) (0x01 << (p))                                     //Define macro for bit position
#define clearbit(x,y) (x&= ~y)                                    //Define macro to make a bit/bits low
#define setbit(x,y) (x|=y)                                        //Define macro to make a bit/bits high
int x;                                                            //Initialize variable x
int y;                                                            //Initialize variable y
int main(void)
{
  DDRB = 0xFF;                                                    //Making all the rows pin output
  DDRC = 0xFF;                                                    //Making all the column pin output
  PORTB = 0xFF;                                                   //Making all the cathode pins HIGH
  PORTC = 0x00;                                                   //Making all the anode pins LOW
  forward_arrow();                                                //Set forward arrow function
  backward_arrow();                                               //Set backward arrow function
  right_arrow();                                                  //Set right arrow function
  left_arrow();                                                   //Set left arrow function
  while (1)
  {
    Serial.begin(2000000);
    ADMUX = 0x46;                                                 //ADMUX is set to read A5
    ADCSRA = 0xC7;                                                //Start ADC conversion
    while ((ADCSRA & (1 << ADSC)));                               //Wait until the conversion is finished
    y = ADCW;                                                     //Store the ADC conversion value in y
    ADMUX = 0x47;                                                 //ADMUX is set to read A6
    ADCSRA = 0xC7;                                                //Start ADC conversion
    while ((ADCSRA & (1 << ADSC)));                               //Wait until the conversion is finished
    x = ADCW;                                                     //Store the ADC conversion value in x

    Serial.println("X-axis: ");
    Serial.println(x);
    Serial.println("Y-axis: ");
    Serial.println(y);
     _delay_ms(100);
     
    if (x < 100)                                                  //Check if joystick is moved to the right
    {
      right_arrow();                                              //Display right arrow
    }
    else if (x > 800)                                             //Check if joystick is moved to the left
    {
      left_arrow();                                               //Display left arrow
    }
    else if (y < 100)                                             //Check if joystick is moved down
    {
      backward_arrow();                                           //Display down arrow
    }
    else if (y > 800)                                             //Check if joystick is moved up
    {
      forward_arrow();                                            //Display up arrow
    }
  }
}
void forward_arrow()                                             //Up arrow display
{
  PORTC = 0b00000001;                                             //Making C1 high
  PORTB = 0b11111011;                                             //Making R3 low, R3C1 glows
  _delay_ms(1);
  PORTC = 0b00000010;                                             //Making C2 high
  PORTB = 0b11111101;                                             //Making R2 low, R1C2 glows
  _delay_ms(1);
  PORTC = 0b00000100;                                             //Making C3 high
  PORTB = 0b11100000;                                             //Making all rows low, C3 glows
  _delay_ms(1);
  PORTC = 0b00001000;                                             //Making C4 high
  PORTB = 0b11111101;                                             //Making R2 low, R2C4 glows
  _delay_ms(1);
  PORTC = 0b00010000;                                             //Making C5 high
  PORTB = 0b11111011;                                             //Making R3 low, R3C5 glows
  _delay_ms(1);
}
void  backward_arrow()                                             //Down arrow display
{
  PORTC = 0b00000100;                                             //Making C5 high
  PORTB = 0b11111100;                                             //Making R3 low, R3C5 glows
  _delay_ms(1);
  PORTC = 0b00010101;                                             //Making C5 high
  PORTB = 0b11111011;                                             //Making R3 low, R3C5 glows
  _delay_ms(1);
  PORTC = 0b00001110;                                             //Making C5 high
  PORTB = 0b11110111;                                             //Making R3 low, R3C5 glows
  _delay_ms(1);
  PORTC = 0b00000100;                                             //Making C5 high
  PORTB = 0b11101111;                                             //Making R3 low, R3C5 glows
  _delay_ms(1);
}
void right_arrow()                                                //Right arrow display
{
  PORTC = 0b00000001;                                             //Making C1 high
  PORTB = 0b11111011;                                             //Making R3 low, R3C1 glows
  _delay_ms(1);                                                   //Wait for 1 ms
  PORTC = 0b00000010;                                             //Making C2 only high
  PORTB = 0b11110001;                                             //Making R2 R3 R4 low, R234C2 glows
  _delay_ms(1);                                                   //Wait for 1 ms
  PORTC = 0b00000100;                                             //Making C3 only high
  PORTB = 0b11101010;                                             //Making R1 R3 R5 low, R135C3 glows
  _delay_ms(1);                                                   //Wait for 1 ms
  PORTC = 0b00001000;                                             //Making C4 only high
  PORTB = 0b11111011;                                             //Making R3 low, R3C4 glows
  _delay_ms(1);                                                   //Wait for 1 ms
  PORTC = 0b00010000;                                             //Making C5 only high
  PORTB = 0b11111011;                                             //Making R3 low, R3C5 glows
  _delay_ms(1);                                                   //Wait for 1 ms
}
void left_arrow()                                                 //Left arrow display
{
  PORTC = 0b00000001;                                             //Making C1 high
  PORTB = 0b11111011;                                             //Making R2 & R3 low, R2C1 and R3C1 glows
  _delay_ms(1);                                                   //Wait for 1 ms
  PORTC = 0b00000010;                                             //Making C2 only high
  PORTB = 0b11111011;                                             //Making R1 & R4 low, R1C2 & R4C2 glows
  _delay_ms(1);                                                   //Wait for 1 ms
  PORTC = 0b00000100;                                             //Making C3 only high
  PORTB = 0b11101010;                                             //Making R2 & R5 low, R2C3 & R5C3 glows
  _delay_ms(1);                                                   //Wait for 1 ms
  PORTC = 0b00001000;                                             //Making C4 only high
  PORTB = 0b11110001;                                             //Making R1 & R4 low, R1C4 & R4C4 glows
  _delay_ms(1);                                                   //Wait for 1 ms
  PORTC = 0b00010000;                                             //Making C5 only high
  PORTB = 0b11111011;                                             //Making R2 & R3 low, R2C5 & R3C5 glows
  _delay_ms(1);                                                   //Wait for 1 ms
}
