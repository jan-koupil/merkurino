#include <Arduino.h>
#include <Merkurino.h>

Merkurino m;

void setup() {
  m.InitBuzzerPin();
  m.Buzzer(true);
  delay(500);
  m.Buzzer(false);
}

void loop() {
  delay(1000);
}