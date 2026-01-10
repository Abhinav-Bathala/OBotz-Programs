#include <avr/io.h>
#include <util/delay.h>
#define checkbit(x, y) ((x) & (y))
#define bitn(p) (0x01 << (p))

double logR2, R2, T, Tc;
int main(void)
{
  float c1 = 0.001125307752122;
  float c2 = 0.000234711863267;
  float c3 = 0.000000085663516;
  Serial.begin(2000000);
  while(1)
  {
    ADMUX = 0x40;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, bitn(ADSC)));
    R2 = (10000/(1023 - ADCW)) * ADCW;
    logR2 = log(R2);
    T = (1.0 /  (c1 + c2*logR2 + c3*logR2*logR2*logR2));
    Tc = T - 273.15;
    Serial.print("Temperature");
    Serial.print(Tc);
    Serial.println(" C ");
    _delay_ms(500);
  }
}
