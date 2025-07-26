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
    virtual void play(Game& game, std::unique_ptr<Card>&& self) = 0;
    virtual ~Card() = 0;
};

inline Card::~Card() {}


#endif // CARD_h