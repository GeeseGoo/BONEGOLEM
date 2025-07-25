#ifndef CARD_h
#define CARD_h
#include <string>
#include "actions/action.h"

class Board;
class Card {
  protected:
    std::string name;  
  public:
    Card(std::string name): name(name) {};
    // not sure why we need this, should be pure virtual?
    void action(Action* action);
    virtual ~Card() = 0;
};

inline Card::~Card() {}


#endif // CARD_h