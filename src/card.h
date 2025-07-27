#ifndef CARD_h
#define CARD_h
#include <string>
#include "lib.h"
#include "triggers/trigger.h"

class Board;
class Game;


class Card {
  std::unique_ptr<Trigger> trigger;
  
  protected:
    std::string name;  
    Board* boardPtr;
  public:
    Card(std::string name): name(name) {};
    Card(std::string name, std::unique_ptr<Trigger> trigger): trigger(std::move(trigger)), name(name) {};

    virtual void play(Game& game, std::unique_ptr<Card>&& self) = 0;
    virtual ~Card() = 0;
    virtual void addToBoard(Board& board) {
      throw std::runtime_error("called card.addtoboard");
    };

    std::string getName() {
      return name;
    };

    Trigger* getTrigger() {
      return trigger.get();
    };
};

inline Card::~Card() {}


#endif // CARD_h