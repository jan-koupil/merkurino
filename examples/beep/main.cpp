#include <Arduino.h>
#include <Merkurino.h>

Merkurino m;

void setup() {
  m.initBuzzerPin();
  m.buzzer(true);
  delay(500);
  m.buzzer(false);
}

void loop() {
  delay(1000);
}