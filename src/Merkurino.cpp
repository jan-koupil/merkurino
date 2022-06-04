#include "Merkurino.h"

Merkurino::Merkurino(){
    lcd->begin(16, 2);
};

void Merkurino::InitKbdPin(){
    pinMode(A0, INPUT);
};

void Merkurino::InitBuzzerPin(){
    pinMode(A3, OUTPUT);
}
    
Merkurino::Button Merkurino::ReadKbd(){
    int adc_key_in = analogRead(A0); // čtení "napětí" na vstupu A0
    
    if (adc_key_in < 40) return Merkurino::Button::Escape; 
    else if (adc_key_in < 110) return Merkurino::Button::Left;
    else if (adc_key_in < 300) return Merkurino::Button::Down;
    else if (adc_key_in < 450) return Merkurino::Button::Up;
    else if (adc_key_in < 700) return Merkurino::Button::Right;
    else if (adc_key_in < 850) return Merkurino::Button::Enter;
    else return Merkurino::Button::None;
};

void Merkurino::Buzzer(bool on){
    digitalWrite(A3, on ? HIGH : LOW);      
}

