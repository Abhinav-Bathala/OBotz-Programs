#include <avr/io.h>
#include <util/delay.h>

// 0b00010000; 0b0
0001000; 0b00000100; 0b00000010; 0b00000001; - Column Values
// 0b11101111; 0b11110111; 0b11111011; 0b11111101; 0b11111110; - Row Values

void letter_A()                        // Letter A
{
  PORTC = 0b00010001;
  PORTB = 0b11111110;
  _delay_ms(1);
  PORTC = 0b00011111;
  PORTB = 0b11111101; 
  _delay_ms(1);
  PORTC = 0b00001010;
  PORTB = 0b11110111;
  _delay_ms(1);
  PORTC = 0b00000100;
  PORTB = 0b11101111;
  _delay_ms(1);
  PORTC = 0b00010001;
  PORTB = 0b11111011;
  _delay_ms(1);
}

void letter_B()                       // Letter B
{
  PORTC = 0b00011110;
  PORTB = 0b11101111;
  _delay_ms(1);
  PORTC = 0b00011110; 
  PORTB = 0b11111110;
  _delay_ms(1);
  PORTC = 0b00010001;
  PORTB = 0b11110111; 
  _delay_ms(1);
  PORTC = 0b00010110; 
  PORTB = 0b11111011; 
  _delay_ms(1);
  PORTC = 0b00010001;  
  PORTB = 0b11111101; 
  _delay_ms(1);
}

void letter_H()                       // Letter H
{
   PORTC = 0b00010000;
   PORTB = 0b11100000;
   _delay_ms(1);
   PORTC = 0b00001000;
   PORTB = 0b11111011;
   _delay_ms(1);
   PORTC = 0b00000010;
   PORTB = 0b11111011;
   _delay_ms(1);
   PORTC = 0b00000001;
   PORTB = 0b11100000;
   _delay_ms(1);
   PORTC = 0b00000100; 
   PORTB = 0b11111011; 
   _delay_ms(1);
}

void letter_I()                      // Letter I
{
  PORTC = 0b00011111;
  PORTB = 0b11101111; 
  _delay_ms(1);
  PORTC = 0b00000100; 
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

void letter_N()                     // Letter N
{
  PORTC = 0b00010000; 
  PORTB = 0b11100000;
  _delay_ms(1);
  PORTC = 0b00001000; 
  PORTB = 0b11110111; 
  _delay_ms(1);
  PORTC = 0b00000100; 
  PORTB = 0b11111011; 
  _delay_ms(1);
  PORTC = 0b00000010; 
  PORTB = 0b11111101; 
  _delay_ms(1);
  PORTC = 0b00000001;
  PORTB = 0b11100000;
  _delay_ms(1);
}

void letter_V()                     // Letter V
{
  PORTC = 0b00010000; 
  PORTB = 0b11100011;
  _delay_ms(1);
  PORTC = 0b00001000; 
  PORTB = 0b11111101; 
  _delay_ms(1);
  PORTC = 0b00000100; 
  PORTB = 0b11111110;
  _delay_ms(1);
  PORTC = 0b00000010;     
  PORTB = 0b11111101; 
  _delay_ms(1);
  PORTC = 0b00000001;
  PORTB = 0b11100011;
  _delay_ms(1);
}

void winky_face()                   // Winky Face
{
  PORTC = 0b00001000;
  PORTB = 0b11110101;
  _delay_ms(1);
  PORTC = 0b00010000;
  PORTB = 0b11111110;
  _delay_ms(1);
  PORTC = 0b00000010;
  PORTB = 0b11101110;
  _delay_ms(1);
  PORTC = 0b00000001;
  PORTB = 0b11110001;
  _delay_ms(1);
}

void reset_matrix()                // Reset Matrix Function
{
  PORTC = 0x00;
  PORTB = 0xFF; 
  _delay_ms(2000); 
  
}

//-------------------------------------------------------------------------\\

int main()
{
  DDRB = 0xFF;                      //Setting all pins in PORTB as OUTPUT
  DDRC = 0xFF;                      //Setting all pins in PORTC as OUTPUT
  PORTB = 0xFF;                     //Setting all pins in PORTB as HIGH
  PORTC = 0x00;                     //Setting all pins in PORTC as LOW
/*
  while(1)
  { 
    letter_A();                     //Calling Letter A to be displayed
    reset_matrix();                 //Reseting the Matrix
    letter_B();                     //Calling Letter B to be displayed
    reset_matrix();                 //Reseting the Matrix
    letter_H();                     //Calling Letter H to be displayed
    reset_matrix();                 //Reseting the Matrix
    letter_I();                     //Calling Letter I to be displayed
    reset_matrix();                 //Reseting the Matrix
    letter_N();                     //Calling Letter N to be displayed
    reset_matrix();                 //Reseting the Matrix
    letter_A();                     //Calling Letter A to be displayed    
    reset_matrix();                 //Reseting the Matrix
    letter_V();                     //Calling Letter V to be displayed
    reset_matrix();                 //Reseting the Matrix
    winky_face();                   //Calling Winky Face to be displayed
    reset_matrix();                 //Reseting the Matrix
  }
 */
  
  while(1)
  { 
    for (int i = 0; i <= 500; i++)
    {
      letter_A();                     //Calling Letter A to be displayed
    } 
    for (int i = 0; i <= 500; i++)
    {
      letter_B();                     //Calling Letter B to be displayed
    }
    for (int i = 0; i <= 500; i++)
    {
      letter_H();                     //Calling Letter H to be displayed
    }
    for (int i = 0; i <= 500; i++)
    {
      letter_I();                     //Calling Letter I to be displayed 
    }
    for (int i = 0; i <= 500; i++)
    {
      letter_N();                     //Calling Letter N to be displayed    
    }
    for (int i = 0; i <= 500; i++)
    {
      letter_A();                     //Calling Letter A to be displayed 
    }
    for (int i = 0; i <= 500; i++)
    {
      letter_V();                     //Calling Letter A to be displayed 
    }
    for (int i = 0; i <= 500; i++)
    {
      winky_face();                     //Calling Winky Face to be displayed
    }
    

  }
 
} 
