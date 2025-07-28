#ifndef BOARD_H
#define BOARD_H

#include "lib.h"
#include "minions/minion.h"
#include "rituals/ritual.h"
#include <string>
#include <stdexcept>

class Board {
  std::vector<std::unique_ptr<Minion>> minions;
  std::unique_ptr<Ritual> ritual;

  public:
    void addCard(Minion* minion);
    void addCard(Ritual* r);
    Minion* getMinion(int i);
    std::vector<Minion*> getMinions();
    Ritual* getRitual() {
      return ritual.get();
    };
};



#endif // BOARD_H