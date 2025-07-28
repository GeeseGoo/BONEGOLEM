#ifndef ASCII_INTERPRETER_H
#define ASCII_INTERPRETER_H
#include "view.h"

class AsciiInterpreter : public View {
  public:
    void displayMinion(int index) override;
    void displayHand() override;
    void displayBoard() override;
};


#endif // ASCII_INTERPRETER_H