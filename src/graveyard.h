#ifndef GRAVEYARD_H
#define GRAVEYARD_H

#include <vector>
#include <memory>
class Card;
class Graveyard {
  std::vector<std::unique_ptr<Card>> cards;
  public:
    void add(std::unique_ptr<Card> Card);
    void pop(int);
};
#endif // HAND_H