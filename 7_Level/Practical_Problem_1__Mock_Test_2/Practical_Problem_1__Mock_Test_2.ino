#include <avr/io.h>
#include <util/delay.h>

// 0b00010000; 0b00001000; 0b00000100; 0b00000010; 0b00000001; - Column Values
// 0b11101111; 0b11110111; 0b11111011; 0b11111101; 0b11111110; - Row Values

void letter_A()                        // Letter A
{
  PORTC = 0b00010001;                  //Column 1, 5
  PORTB = 0b11111110;                  //Row 5
  _delay_ms(1);
  PORTC = 0b00011111;                  //Column 1, 2, 3, 4, 5
  PORTB = 0b11111101;                  //Row 4
  _delay_ms(1);
  PORTC = 0b00001010;                  //Column 2, 4
  PORTB = 0b11110111;                  //Row 2
  _delay_ms(1);
  PORTC = 0b00000100;                  //Column 3
  PORTB = 0b11101111;                  //Row 1
  _delay_ms(1);
  PORTC = 0b00010001;                  //Column 1, 5
  PORTB = 0b11111011;                  //Row 3
  _delay_ms(1);
}

void letter_B()                       // Letter B
{
  PORTC = 0b00011110;                 //Column 1, 2, 3, 4
  PORTB = 0b11101111;                 //Row 1
  _delay_ms(1);
  PORTC = 0b00011110;                 //Column 1, 2, 3, 4
  PORTB = 0b11111110;                 //Row 5
  _delay_ms(1);
  PORTC = 0b00010001;                 //Column 1, 5
  PORTB = 0b11110111;                 //Row 2
  _delay_ms(1);
  PORTC = 0b00010110;                 //Column 1, 3, 4
  PORTB = 0b11111011;                 //Row 3
  _delay_ms(1); 
  PORTC = 0b00010001;                 //Column 1, 5
  PORTB = 0b11111101;                 //Row 4
  _delay_ms(1);
}

void letter_H()                       // Letter H
{
   PORTC = 0b00010000;                //Column 1
   PORTB = 0b11100000;                //Row 1, 2, 3, 4, 5
   _delay_ms(1);
   PORTC = 0b00001000;                //Column 2
   PORTB = 0b11111011;                //Row 3
   _delay_ms(1);
   PORTC = 0b00000010;                //Column 4
   PORTB = 0b11111011;                //Row 3
   _delay_ms(1);
   PORTC = 0b00000001;                //Column 5
   PORTB = 0b11100000;                //Row 1, 2, 3, 4, 5
   _delay_ms(1);
   PORTC = 0b00000100;                //Column 3
   PORTB = 0b11111011;                //Row 3
   _delay_ms(1);
}

void letter_I()                      // Letter I
{
  PORTC = 0b00011111;               //Column 1, 2, 3, 4, 5
  PORTB = 0b11101111;               //Row 1 
  _delay_ms(1);
  PORTC = 0b00000100;               //Column 3 
  PORTB = 0b11110111;               //Row 2
  _delay_ms(1);
  PORTC = 0b00000100;               //Column 3
  PORTB = 0b11111011;               //Row 3
  _delay_ms(1);
  PORTC = 0b00000100;               //Column 3 
  PORTB = 0b11111101;               //Row 4 
  _delay_ms(1);
  PORTC = 0b00011111;               //Column 1, 2, 3, 4, 5
  PORTB = 0b11111110;               //Row 5 
  _delay_ms(1); 
}

void letter_N()                     // Letter N
{
  PORTC = 0b00010000;               //Column 1
  PORTB = 0b11100000;               //Row 1, 2, 3, 4, 5               
  _delay_ms(1);
  PORTC = 0b00001000;               //Column 2
  PORTB = 0b11110111;               //Row 2 
  _delay_ms(1);
  PORTC = 0b00000100;               //Column 3
  PORTB = 0b11111011;               //Row 3 
  _delay_ms(1);
  PORTC = 0b00000010;               //Column 4 
  PORTB = 0b11111101;               //Row 4 
  _delay_ms(1);
  PORTC = 0b00000001;               //Column 5
  PORTB = 0b11100000;               //Row 1, 2, 3, 4, 5
  _delay_ms(1);
}

void letter_V()                     // Letter V
{
  PORTC = 0b00010000;               //Column 1 
  PORTB = 0b11100011;               //Row 1, 2, 3
  _delay_ms(1);
  PORTC = 0b00001000;               //Column 2 
  PORTB = 0b11111101;               //Row 4 
  _delay_ms(1);
  PORTC = 0b00000100;               //Column 3 
  PORTB = 0b11111110;               //Row 5
  _delay_ms(1);
  PORTC = 0b00000010;               //Column 4 
  PORTB = 0b11111101;               //Row 4 
  _delay_ms(1);
  PORTC = 0b00000001;               //Column 5
  PORTB = 0b11100011;               //Row 1, 2, 3
  _delay_ms(1);
}

void letter_T()                     // Letter T
{
  PORTC = 0b00011111;               //Column 1, 2, 3, 4, 5
  PORTB = 0b11101111;               //Row 1
  _delay_ms(1);
  PORTC = 0b00000100;               //Column 3
  PORTB = 0b11110111;               //Row 2
  _delay_ms(1);
  PORTC = 0b00000100;               //Column 3
  PORTB = 0b11111011;               //Row 3
  _delay_ms(1);
  PORTC = 0b00000100;               //Column 3
  PORTB = 0b11111101;               //Row 4
  _delay_ms(1);
  PORTC = 0b00000100;               //Column 3
  PORTB = 0b11111110;               //Row 5
  _delay_ms(1);
} 

void letter_L()                     // Letter L
{
  PORTC = 0b00010000;               //Column 1
  PORTB = 0b11101111;               //Row 1
  _delay_ms(1);
  PORTC = 0b00010000;               //Column 1
  PORTB = 0b11110111;               //Row 2
  _delay_ms(1);
  PORTC = 0b00010000;               //Column 1
  PORTB = 0b11111011;               //Row 3
  _delay_ms(1); 
  PORTC = 0b00010000;               //Column 1
  PORTB = 0b11111101;               //Row 4
  _delay_ms(1);
  PORTC = 0b00011111;               //Column 1, 2, 3, 4, 5
  PORTB = 0b11111110;               //Row 5
  _delay_ms(1);
}

void reset_matrix()                // Reset Matrix Function
{
  PORTC = 0x00;
  PORTB = 0xFF;
  _delay_ms(1000);
}

//-------------------------------------------------------------------------\\

int main()
{
  DDRB = 0xFF;                      //Setting all pins in PORTB as OUTPUT
  DDRC = 0xFF;                      //Setting all pins in PORTC as OUTPUT
  PORTB = 0xFF;                     //Setting all pins in PORTB as HIGH
  PORTC = 0x00;                     //Setting all pins in PORTC as LOW

  
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
    _delay_ms(2000);                //Delay for 2 seconds

    
    letter_B();                     //Calling Letter B to be displayed
    reset_matrix();                 //Reseting the Matrix
    letter_A();                     //Calling Letter A to be displayed
    reset_matrix();                 //Reseting the Matrix
    letter_T();                     //Calling Letter T to be displayed
    reset_matrix();                 //Reseting the Matrix
    letter_H();                     //Calling Letter H to be displayed
    reset_matrix();                 //Reseting the Matrix
    letter_A();                     //Calling Letter A to be displayed
    reset_matrix();                 //Reseting the Matrix
    letter_L();                     //Calling Letter L to be displayed
    reset_matrix();                 //Reseting the Matrix
    letter_A();                     //Calling Letter A to be displayed
    reset_matrix();                 //Reseting the Matrix
    _delay_ms(2000);                //Delay for 2 seconds
    
  }
  
  /*
  while(1)
  { 
    for (int i = 0; i <= 50; i++)
    {
      letter_A();                     //Calling Letter A to be displayed
    }
    for (int i = 0; i <= 50; i++)
    {
      letter_B();                     //Calling Letter B to be displayed
      _delay_ms(1000);
    }
    for (int i = 0; i <= 50; i++)
    {
      letter_H();                     //Calling Letter H to be displayed
    }
    for (int i = 0; i <= 50; i++)
    {
      letter_I();                     //Calling Letter I to be displayed 
    }
    for (int i = 0; i <= 50; i++)
    {
      letter_N();                     //Calling Letter N to be displayed    
    }
    for (int i = 0; i <= 50; i++)
    {
      letter_A();                     //Calling Letter A to be displayed 
    }
    for (int i = 0; i <= 50; i++)
    {
      letter_V();                     //Calling Letter A to be displayed 
    }
   
  }

  */

  
}
