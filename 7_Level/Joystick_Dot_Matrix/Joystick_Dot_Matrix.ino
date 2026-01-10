#include <avr/io.h>
#include <util/delay.h>
#define bitn(p) (0x01 << (p))
#define setbit(x, y) (x |= y)
#define clearbit(x,y) (x &= ~y)
#define checkbit(x,y) ((x) & (y))

// 0b00010000; 0b00001000; 0b00000100; 0b00000010; 0b00000001; - Column Values
// 0b11101111; 0b11110111; 0b11111011; 0b11111101; 0b11111110; - Row Values

//------------------------------------------------------------------------------------\\

int x = 0;
int y = 0;

int main(void)
{
  
  Serial.begin(2000000);
  while(1)
  {
    ADMUX = 0x45;
    ADCSRA = 0xC7;
    while((ADCSRA&(1<<ADSC)));
    x = ADCW;
    ADMUX = 0x46;
    ADCSRA = 0xC7;
    while((ADCSRA&(1<<ADSC)));
    y = ADCW;
  
    if ((x > 1000) && ((y < 550) && (y > 450)))
    {
      up_arrow();
    }

    if ((x < 100) && ((y < 550) && (y > 450)))
    {
      down_arrow();
    }

    if (((x < 550) && (x > 450)) && (y < 100))
    {
      left_arrow();
    }

    if (((x > 450 && (x < 550)) && (y > 1000)))
    {
      right_arrow();
    }
    
    Serial.println("X-axis: ");
    Serial.println(x);
    Serial.println("Y-axis: ");
    Serial.println(y);
     _delay_ms(1000);
    
  }
  
}

//------------------------------------------------------------------------------------\\

void up_arrow()
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

void down_arrow()
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

void left_arrow()
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
  _delay_ms(1); 
}

void right_arrow()
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
  _delay_ms(1);   
  
}
