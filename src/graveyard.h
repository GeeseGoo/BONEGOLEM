#ifndef GRAVEYARD_H
#define GRAVEYARD_H

#include <stack>
#include <memory>
class Card;
class Minion;
class Graveyard {
  std::stack<std::unique_ptr<Card>> cards;
  public:
    void add(Minion* card);
    Card* pop(int); // not implemented currently
    Card* top();
};
#endif // HAND_H