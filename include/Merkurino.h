#ifndef Merkurino_H
#define Merkurino_H

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>

#define MERKURINO_BUZZER_PIN A3
#define MERKURINO_KBD_PIN A0

class Merkurino {
    
  public:

    enum Button : byte {None, Up, Down, Left, Right, Enter, Escape};

    LiquidCrystal lcd {13, 12, 8, 7, 4, 2};
    
    Merkurino();

    void initKbdPin();
    void initBuzzerPin();
    Merkurino::Button readKbd();
    void toggleBuzzer(bool on);

};

#endif