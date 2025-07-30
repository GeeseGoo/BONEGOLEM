#ifndef CARD_h
#define CARD_h
#include <string>
#include "lib.h"

class Player;
class Trigger;
class Board;
class Game;

class EnterPlay;

class Card {
  std::unique_ptr<Trigger> trigger;
  protected:
    int playerNum;
    std::string name; 
    int cost; 
  public:
    Card(std::string name, int cost, int playerNum);
    Card(std::string name, int cost, std::unique_ptr<Trigger> trigger, int playerNum);
    virtual ~Card() = default;

    virtual void play(Game &game, Player &player, EnterPlay* action) = 0;

    virtual std::string getName() {
      return name;
    };
    virtual int getCost() {return cost;}
    virtual std::string getBottomLeft() = 0;
    virtual std::string getBottomRight() = 0;
    virtual std::string getTopLeft() = 0;
    virtual std::string description() = 0;
    virtual std::string getType() = 0;
    Trigger* getTrigger();
};



#endif // CARD_h