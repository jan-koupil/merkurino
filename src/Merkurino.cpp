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
    
Button Merkurino::ReadKbd(){
    int adc_key_in = analogRead(A0); // čtení "napětí" na vstupu A0
    
    if (adc_key_in < 40) return Button::Escape; 
    else if (adc_key_in < 110) return Button::Left;
    else if (adc_key_in < 300) return Button::Down;
    else if (adc_key_in < 450) return Button::Up;
    else if (adc_key_in < 700) return Button::Right;
    else if (adc_key_in < 850) return Button::Enter;
    else return Button::None;
};

void Merkurino::Buzzer(bool on){
    digitalWrite(A3, on ? HIGH : LOW);      
}

