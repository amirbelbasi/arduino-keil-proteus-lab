#include <SPI.h>

const int slave1_pin = 49, slave2_pin = 48;
const char message[15] = "belbasi9831109";

void setup (void) {
  pinMode(slave1_pin,OUTPUT);
  pinMode(slave2_pin,OUTPUT);
  digitalWrite(slave1_pin, HIGH);
  digitalWrite(slave2_pin, HIGH);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
}

void loop() {
  sendBytes(slave1_pin, message, 15);
  delay(1000);
}

void sendBytes(int slave_pin, byte *bytes, int bytes_size) {
  digitalWrite(slave_pin, LOW);
  for (int i = 0 ; i < bytes_size ; i++) {
    delay(20);
    SPI.transfer(bytes[i]);
  }
  digitalWrite(slave_pin, HIGH); 
}
