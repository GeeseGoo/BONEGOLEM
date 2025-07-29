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
    int cost; 
  public:
    Card(std::string name, int cost, Player& player);
    Card(std::string name, int cost, std::unique_ptr<Trigger> trigger, Player& player);

    virtual void play(Game& game, std::unique_ptr<Card>&& self, Player& player) = 0;
    virtual void addToBoard(Board& board) {
      throw std::runtime_error("called card.addtoboard");
    };

    std::string getName() {
      return name;
    };
    int getCost() {return cost;}
    virtual std::string getBottomLeft() = 0;
    virtual std::string getBottomRight() = 0;
    virtual std::string getTopLeft() = 0;
    virtual std::string description() = 0;
    virtual std::string getType() = 0;


    Player& getPlayer() {return player;};

    Trigger* getTrigger();
};



#endif // CARD_h