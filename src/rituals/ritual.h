#ifndef RITUAL_H
#define RITUAL_H

#include "../lib.h"
#include "../card.h"
#include <string>
class Trigger;
class Game;
class Board;
class Player;

class Ritual: public Card {
  protected:
    int charges;
    int ritualCost;
  public:
    Ritual(std::string name, int cost, std::unique_ptr<Trigger> trigger, int playerNum, int initialCharges, int ritualCost);
    void play(Game &game, Player &player, EnterPlay* action) override;
    
    std::string getBottomLeft() override;
    std::string getBottomRight() override;
    std::string getTopLeft() override;
    std::string getType() override {return "Ritual";}
};


#endif // RITUAL_H