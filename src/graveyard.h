#ifndef GRAVEYARD_H
#define GRAVEYARD_H

#include <stack>
#include <memory>
class Card;
class Graveyard {
  std::stack<std::unique_ptr<Card>> cards;
  public:
    void add(std::unique_ptr<Card> Card);
    Card* pop(int);
    Card* top();
};
#endif // HAND_H