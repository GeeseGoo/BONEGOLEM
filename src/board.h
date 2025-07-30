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
class Enchantment;
class Board
{
  std::vector<std::unique_ptr<Minion>> minions;
  std::unique_ptr<Ritual> ritual;

public:
  void addCard(Minion *minion);
  void addCard(Ritual *r);
  void trigger(Action *action, Game &game);

  Minion *getMinion(int i);
  std::vector<Minion *> getMinions();
  Ritual *getRitual()
  {
    return ritual.get();
  };
  void removeMinion(Minion &minion);

  // Pick up the new enchantment and return what was previously at the index
  Minion *attach(Enchantment *newEnchantment, int index);
  void detach(int index); // detach top enchantment of minion
  void detachAll(int index);
  void removeRitual();
};

#endif // BOARD_H