#ifndef GRAVEYARD_H
#define GRAVEYARD_H

#include <stack>
#include <memory>
class Card;
class Minion;
class Graveyard
{
  std::stack<std::unique_ptr<Minion>> cards;

public:
  void add(Minion *card);
  std::unique_ptr<Minion> pop()
  {
    std::unique_ptr<Minion> minion = std::move(cards.top());
    cards.pop();
    return minion;
  }
  Minion *top(); // may also want to change this to return Minion*
};
#endif // HAND_H