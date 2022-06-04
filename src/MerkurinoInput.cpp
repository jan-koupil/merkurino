#include <MerkurinoInput.h>

void MerkurinoInput::initDisplay()
{
    for (int i = 0; i < inputLength_; i++)
    {
        cursorX_ = i;
        displayCurrentSymbol();
    }
    cursorX_ = 0;
    merkurino_.lcd.setCursor(inputStartCol_, inputStartRow_);
    merkurino_.lcd.blink();
};

void MerkurinoInput::displayCurrentSymbol()
{
    merkurino_.lcd.setCursor(inputStartCol_ + cursorX_, inputStartRow_);
    merkurino_.lcd.print(currentText_[cursorX_]);
    merkurino_.lcd.setCursor(inputStartCol_ + cursorX_, inputStartRow_);
};

int MerkurinoInput::findSymbolIndex(char symbol)
{
    for (int i = 0; i < symbolCnt_; i++)
    {
        if (symbol == symbolList_[i])
            return i;
    }
    return 0;
};

void MerkurinoInput::changeSymbol(int shift)
{
    int index = findSymbolIndex(currentText_[cursorX_]);
    index += shift;
    while (index >= symbolCnt_)
        index -= symbolCnt_;
    while (index < 0)
        index += symbolCnt_;
    currentText_[cursorX_] = symbolList_[index];
    displayCurrentSymbol();
};

void MerkurinoInput::moveCursor(int shift)
{
    cursorX_ += shift;
    if (cursorX_ >= inputLength_)
        cursorX_ = inputLength_ - 1;
    else if (cursorX_ < 0)
        cursorX_ = 0;
};

void MerkurinoInput::submit()
{
    isReady_ = true;
    merkurino_.lcd.noBlink();
    keyTimer_.stop();
};

MerkurinoInput::MerkurinoInput(Merkurino m, int inputStartCol, int inputStartRow)
{
    merkurino_ = m;
    inputStartCol_ = inputStartCol;
    inputStartRow_ = inputStartRow;
    setKeyDelay(MERKURINO_DEFAULT_KEY_DELAY);
};

bool MerkurinoInput::isReady()
{
    return isReady_;
};

void MerkurinoInput::startReading(char defaultText[], int inputLength)
{
    this->inputLength_ = inputLength;

    for (int i = 0; i < inputLength; i++)
    {
        initialText_[i] = defaultText[i];
    }

    resetInput();
};

void MerkurinoInput::startReading(String defaultText)
{
    this->inputLength_ = defaultText.length();

    for (int i = 0; i < inputLength_; i++)
    {
        initialText_[i] = defaultText[i];
    }

    resetInput();
};

void MerkurinoInput::clearInputArea()
{
    for (int i = 0; i < inputLength_; i++)
    {
        merkurino_.lcd.setCursor(inputStartCol_ + i, inputStartRow_);
        merkurino_.lcd.print(' ');
    }
}

void MerkurinoInput::resetInput()
{
    this->cursorX_ = 0;
    this->isReady_ = false;

    for (int i = 0; i < inputLength_; i++)
    {
        currentText_[i] = initialText_[i];
    }

    merkurino_.initKbdPin();
    keyTimer_.start();
    pressedBtn_ = Merkurino::Button::None;
    initDisplay();
};

String MerkurinoInput::getInput()
{
    String inputText = "";
    for (int i = 0; i < inputLength_; i++)
    {
        inputText += currentText_[i];
    }
    return inputText;
};

void MerkurinoInput::readKeys()
{
    if (isReady_)
        return;

    Merkurino::Button pressedBtn = merkurino_.readKbd();
    if (pressedBtn != Merkurino::Button::None)
        pressedBtn_ = pressedBtn;

    if (keyTimer_.hasTicked())
        handleKeyPress();
};

void MerkurinoInput::handleKeyPress()
{
    switch (merkurino_.readKbd())
    {
    case Merkurino::Button::Up:
        changeSymbol(+1);
        break;

    case Merkurino::Button::Down:
        changeSymbol(-1);
        break;

    case Merkurino::Button::Left:
        moveCursor(-1);
        break;

    case Merkurino::Button::Right:
        moveCursor(+1);
        break;

    case Merkurino::Button::Enter:
        submit();
        break;

    case Merkurino::Button::Escape:
        resetInput();
        break;

    default:
        break;
    }

    pressedBtn_ = Merkurino::Button::None;
    displayCurrentSymbol();
};

void MerkurinoInput::setKeyDelay(unsigned int delay) // milliseconds
{
    keyTimer_.setInterval(delay);
};

void MerkurinoInput::useSymbols(char symbolList[], int count)
{
    for (int i = 0; i < count; i++)
        symbolList[i] = symbolList[i];

    symbolCnt_ = count;
};

void MerkurinoInput::useNumberChars()
{
    char symbol = '0';

    for (int i = 0; i < 10; i++)
        symbolList_[i] = symbol++;

    symbolCnt_ = 10;
};

void MerkurinoInput::useLowercaseChars()
{
    symbolList_[0] = ' ';

    char symbol = 'a';

    for (int i = 0; i < 26; i++)
        symbolList_[i + 1] = symbol++;

    symbolCnt_ = 27;
};

void MerkurinoInput::useUppercaseChars()
{
    symbolList_[0] = ' ';

    char symbol = 'A';

    for (int i = 0; i < 26; i++)
        symbolList_[i + 1] = symbol++;

    symbolCnt_ = 27;
};

void MerkurinoInput::useStandardChars()
{
    symbolList_[0] = ' ';
    int i = 1;
    char symbol;

    symbol = 'A';
    for (int j = 0; j < 26; i++, j++)
        symbolList_[i] = symbol++;

    symbol = 'a';
    for (int j = 0; j < 26; i++, j++)
        symbolList_[i] = symbol++;

    symbol = '0';
    for (int j = 0; j < 10; i++, j++)
        symbolList_[i] = symbol++;

    symbolList_[i++] = '-';
    symbolList_[i++] = '_';

    symbolCnt_ = i;
};
