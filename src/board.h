#ifndef BOARD_H
#define BOARD_H

#include "lib.h"
#include "minions/minion.h"
#include "rituals/ritual.h"
#include <string>
#include <stdexcept>

class Minion;
class Trigger;
class Action;
class Board
{
  std::vector<std::unique_ptr<Minion>> minions;
  std::unique_ptr<Ritual> ritual;

public:
  void addCard(Minion *minion);
  void addCard(Ritual *r);
  void trigger(Action *action, Game& game);

  Minion *getMinion(int i);
  std::vector<Minion *> getMinions();
  Ritual *getRitual()
  {
    return ritual.get();
  };
  void removeMinion(Minion &minion)
  {
    for (auto m = minions.begin(); m != minions.end(); ++m)
    {
      if (m->get() == &minion)
      {
        minions.erase(m);
        return;
      }
    }

    throw std::runtime_error("Minion not found to be erased");
  }
};

#endif // BOARD_H