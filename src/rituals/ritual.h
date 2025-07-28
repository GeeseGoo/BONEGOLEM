#ifndef RITUAL_H
#define RITUAL_H

#include "../lib.h"
#include "../card.h"
class Trigger;
class Game;
class Board;

class Ritual: public Card {
  int charges;
  int cost;
  public:
    Ritual(std::string name, std::unique_ptr<Trigger> trigger);
    void play(Game& game, std::unique_ptr<Card>&& self);

    void addToBoard(Board& board) override;

};

#endif // RITUAL_H