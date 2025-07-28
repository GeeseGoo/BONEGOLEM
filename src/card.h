#ifndef CARD_h
#define CARD_h
#include <string>
#include "lib.h"

class Player;
class Trigger;
class Board;
class Game;



class Card {
  std::unique_ptr<Trigger> trigger;
  Player& player;
  
  protected:
    std::string name;  
  public:
    Card(std::string name, Player& player);
    Card(std::string name, std::unique_ptr<Trigger> trigger, Player& player);

    virtual void play(Game& game, std::unique_ptr<Card>&& self) = 0;
    virtual void addToBoard(Board& board) {
      throw std::runtime_error("called card.addtoboard");
    };

    std::string getName() {
      return name;
    };

    Player& getPlayer() {return player;};

    Trigger* getTrigger();
};



#endif // CARD_h