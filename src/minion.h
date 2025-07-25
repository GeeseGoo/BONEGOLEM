#ifndef MINION_H
#define MINION_H

#include "lib.h"
#include "card.h"
class Player;
class Minion: public Card {
  int atk;
  int def;
  int actions;
  public:
    Minion(std::string name, int atk, int def, int actions);
    void attack(Minion& other);
    void attack(Player& other);
};


#endif // MINION_H