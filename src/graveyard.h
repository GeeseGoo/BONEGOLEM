#ifndef GRAVEYARD_H
#define GRAVEYARD_H

#include <stack>
#include <memory>
class Card;
class Minion;
class Graveyard {
  std::stack<std::unique_ptr<Minion>> cards;
  public:
    void add(Minion* card);
    Minion* pop(int); // not implemented currently
    Minion* top(); // may also want to change this to return Minion*
};
#endif // HAND_H