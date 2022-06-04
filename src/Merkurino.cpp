#include "Merkurino.h"

Merkurino::Merkurino(){
    lcd.begin(16, 2);
};

void Merkurino::initKbdPin(){
    pinMode(MERKURINO_KBD_PIN, INPUT);
};

void Merkurino::initBuzzerPin(){
    pinMode(MERKURINO_BUZZER_PIN, OUTPUT);
}
    
Merkurino::Button Merkurino::readKbd(){
    int adc_key_in = analogRead(MERKURINO_KBD_PIN); // čtení "napětí" na vstupu A0
    
    if (adc_key_in < 40) return Merkurino::Button::Escape; 
    else if (adc_key_in < 110) return Merkurino::Button::Left;
    else if (adc_key_in < 300) return Merkurino::Button::Down;
    else if (adc_key_in < 450) return Merkurino::Button::Up;
    else if (adc_key_in < 700) return Merkurino::Button::Right;
    else if (adc_key_in < 850) return Merkurino::Button::Enter;
    else return Merkurino::Button::None;
};

void Merkurino::buzzer(bool on){
    digitalWrite(MERKURINO_BUZZER_PIN, on ? HIGH : LOW);      
}
