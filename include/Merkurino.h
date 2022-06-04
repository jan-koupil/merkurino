#ifndef Merkurino_H
#define Merkurino_H

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>

class Merkurino {
    
  public:

    enum Button {None, Up, Down, Left, Right, Enter, Escape};

    LiquidCrystal *lcd = new LiquidCrystal(13, 12, 8, 7, 4, 2);    
    
    Merkurino();

    void InitKbdPin();
    void InitBuzzerPin();    
    Merkurino::Button ReadKbd();
    void Buzzer(bool on);

};

#endif