#include<SoftwareSerial.h>
SoftwareSerial mySerial(3,4);
uint16_t voltage;
uint16_t readVcc(void) 
{
  uint16_t result;
  
  ADMUX = (0<<REFS0) | (12<<MUX0);
  delay(2); 
  ADCSRA |= (1<<ADSC);
  while (bit_is_set(ADCSRA,ADSC));
  result = ADCW;
  return 1125300L / result; 
}


void setup() {
  mySerial.begin(9600);
  

}

void loop() {
  voltage=readVcc();
  mySerial.println(voltage);
  delay(200);

}
