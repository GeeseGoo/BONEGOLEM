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
    Ritual(std::string name, int cost, std::unique_ptr<Trigger> trigger, Player& player, int initialCharges, int ritualCost);
    void play(Game& game, std::unique_ptr<Card>&& self);

    void addToBoard(Board& board) override;
    
    std::string getBottomLeft() override;
    std::string getBottomRight() override;
    std::string getTopLeft() override;

    // WHY DOES THIS BREAK STUFF?
    // virtual ~Ritual() = 0;
};


#endif // RITUAL_H