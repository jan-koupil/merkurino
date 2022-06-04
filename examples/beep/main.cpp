#include <Arduino.h>
#include <Merkurino.h>

Merkurino m;

void setup() {
  m.initBuzzerPin();
  m.toggleBuzzer(true);
  delay(500);
  m.toggleBuzzer(false);
}

void loop() {
  delay(1000);
}