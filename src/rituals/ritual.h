#ifndef RITUAL_H
#define RITUAL_H

#include "../lib.h"
#include "../card.h"

class Ritual: public Card {
  int charges;
  int cost;
  public:
    Ritual(std::string name): Card(name) {};
};

#endif // RITUAL_H