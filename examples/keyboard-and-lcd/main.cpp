#include <Arduino.h>
#include <Merkurino.h>

Merkurino m;
Merkurino::Button btn;

void setup() {
  m.InitKbdPin();
  m.lcd->setCursor(0,0);
  m.lcd->print("Stiskni tlacitko");
}

void loop() {
  m.lcd->setCursor(8,1);
  m.lcd->print(millis()/1000);
  m.lcd->setCursor(0,1);
  btn = m.ReadKbd();
  switch (btn)
  {
    case Merkurino::Button::Right:
    {
      m.lcd->print("vpravo  ");
      break;
    }
    case Merkurino::Button::Left:
    {
      m.lcd->print("vlevo   ");
      break;
    }
    case Merkurino::Button::Up:
    {
      m.lcd->print("nahoru     ");
      break;
    }
    case Merkurino::Button::Down:
    {
      m.lcd->print("dolu   ");
      break;
    }
    case Merkurino::Button::Enter:
    {
      m.lcd->print("potvrd ");
      break;
    }
    case Merkurino::Button::Escape:
    {
      m.lcd->print("zpet    ");
      break;
    }
    case Merkurino::Button::None:
    {
      m.lcd->print("nic   ");
      break;
    }
  }
}