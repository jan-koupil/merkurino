#include <Arduino.h>
#include <Merkurino.h>
#include <MerkurinoInput.h>

Merkurino m;
MerkurinoInput mi {m, 0, 1}; //input will be on row 1, column 0

void showInput(String input);

void setup() {
  Serial.begin(9600);
  m.initKbdPin();
  m.lcd.clear();
  mi.setKeyDelay(200);
}

void loop() {
  String input;
  
  /* numeric input */

  char defaultText[] = {'0','0','0','0','0','0'};
  mi.useNumberChars(); //set of allowed chars - numbers only
  mi.startReading(defaultText, 6); //for input of type char[], length is required

  while(!mi.isReady()) //waiting for enter key
  {
     mi.readKeys();
     delay(1);
  };
  //this is unblocking mode - can be in mail loop, run other code meanwhile

  input = mi.getInput(); //read out the input text
  mi.clearInputArea(); //clears typed characters
  showInput(input);

  delay(3000);


  /* text input */

  mi.useStandardChars(); //letters, numbers, space, dash and underscore
  mi.startReading("xyz-1234");

  while(!mi.isReady())
  {
     mi.readKeys();
     delay(1);
  }

  input = mi.getInput();
  mi.clearInputArea();
  showInput(input);

  delay(3000);


  /* custom input */

  char symbolList[] = {'T', 'F'};
  mi.useSymbolList(symbolList, 2);
  mi.startReading("TFTTFTF");

  while(!mi.isReady())
  {
     mi.readKeys();
     delay(1);
  }

  input = mi.getInput();
  mi.clearInputArea();
  showInput(input);

  delay(3000);
}

void showInput(String input)
{
  Serial.println(input);
  m.lcd.setCursor(0,0);
  m.lcd.print("                "); //just a cleanup of top line
  m.lcd.setCursor(0,0);
  m.lcd.print("Typed: ");
  m.lcd.print(input);
}