#include <avr/io.h>
#include <util/delay.h>
#define bitn(p) (0x01 << (p))
#define checkbit(x,y) ((x) & (y))

long keycode = 0;

void compare()
{
  Serial.println(keycode, HEX);
  if(keycode == 0x01FED827){ //forward
    PORTD = 0b01010000;
    PORTC = 0x00;
    PORTB = 0b01000000;
  }
  if(keycode == 0x01FE30CF){ //left
    PORTD = 0b01100000;
    PORTC = 0x00;
    PORTB = 0x00;
  }
  if(keycode == 0x01FE708F){ //right
    PORTD = 0b10010000;
    PORTC = 0x00;
    PORTB = 0x00;
  }
  if(keycode == 0x01FEF00F){ //backwards
    PORTD = 0b10100000;
    PORTC = 0b00001000;
    PORTB = 0b10000000;
  }
  if(keycode == 0x01FEB04F){ //stop
    PORTD = 0x00;
    PORTC = 0x00;
    PORTB = 0x00;
  }

}


int main(void)
{
  DDRD = 0xFF;
  DDRB = 0xFB;
  DDRC = 0xFF;
  Serial.begin(2000000);
  PORTD = 0x00;
  int on_time = 0;
  int off_time = 0;
  int bit_position = -2;
  while(1)
  {
    while(!(checkbit(PINB, bitn(2))))
    {
      on_time++;
      if(on_time == 1){
        bit_position++;
        if(bit_position >= 1 && bit_position <= 32){
          if(off_time > 700){
            keycode |= (long)1<<(32 - bit_position);
          }
        }
        if(bit_position >= 32){
          //Serial.println(keycode, HEX);
          compare();
          bit_position = -2;
          keycode = 0;
        }
      }
      off_time = 0;
    }

    while((checkbit(PINB, bitn(2))))
    {
      off_time++;
      on_time = 0;
      if(off_time > 6000){
        off_time = 0;
        bit_position = -2;
      }
    }
  }
}
