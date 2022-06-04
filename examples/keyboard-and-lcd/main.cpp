#include <Arduino.h>
#include <Merkurino.h>

Merkurino m;
Merkurino::Button btn;

void setup() {
  m.initKbdPin();
  m.lcd.setCursor(0,0);
  m.lcd.print("Press button");
}

void loop() {
  m.lcd.setCursor(0,1);
  btn = m.readKbd();
  switch (btn)
  {
    case Merkurino::Button::Right:
    {
      m.lcd.print("Right ");
      break;
    }
    case Merkurino::Button::Left:
    {
      m.lcd.print("Left  ");
      break;
    }
    case Merkurino::Button::Up:
    {
      m.lcd.print("Up    ");
      break;
    }
    case Merkurino::Button::Down:
    {
      m.lcd.print("Down  ");
      break;
    }
    case Merkurino::Button::Enter:
    {
      m.lcd.print("Enter ");
      break;
    }
    case Merkurino::Button::Escape:
    {
      m.lcd.print("Escape");
      break;
    }
    case Merkurino::Button::None:
    {
      m.lcd.print("      ");
      break;
    }
  }
}