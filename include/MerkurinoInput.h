#ifndef MerkurinoInput_H
#define MerkurinoInput_H

#include <Arduino.h>
#include <Merkurino.h>
#include <SimpleTimer.h>

#define MERKURINO_DEFAULT_KEY_DELAY 200

class MerkurinoInput
{
private:
    Merkurino merkurino_;
    SimpleTimer keyTimer_;
    
    char symbolList_[128];
    int symbolCnt_;

    int inputStartCol_;
    int inputStartRow_;

    int cursorX_;
    int inputLength_;
    char initialText_[16];
    char currentText_[16];
    
    bool isReady_;
    Merkurino::Button pressedBtn_;

    void initDisplay();
    void displayCurrentSymbol();
    int findSymbolIndex(char symbol);
    void changeSymbol(int shift);
    void moveCursor(int shift);
    void submit();

public:
    MerkurinoInput(Merkurino m);
    
    bool isReady();
    void startReading(char defaultText[], int inputLength);
    void startReading(String defaultText);
    void clearInputArea();
    void resetInput();
    String getInput();
    void readKeys();
    void handleKeyPress();
    void setKeyDelay(unsigned int delay);

    void useSymbols(char symbolList[], int count);
    void useNumberChars();
    void useLowercaseChars();
    void useUppercaseChars();
    void useStandardChars();
};

#endif