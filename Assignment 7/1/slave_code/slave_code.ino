#include <SPI.h>
char buff[15];
byte index = 0;
boolean is_data_sent = false;
int num;

void setup() {
  Serial3.begin(9600);
  pinMode(MOSI, INPUT_PULLUP);
  SPCR |= _BV(SPE);
  SPCR |= _BV(SPIE);
  index = 0;
  is_data_sent = false;
  SPI.attachInterrupt();
}

ISR(SPI_STC_vect){ 
  byte tmp = SPDR;
  if(index < 15) {
    buff[index] = tmp;
    index++;
    if (index == 15) {
      is_data_sent = true;
      Serial3.println(buff);
    }
  }
}

void loop (void) {
  if (is_data_sent) {
    is_data_sent = false;
    index = 0;
  }
}
