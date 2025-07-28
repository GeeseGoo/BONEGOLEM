#ifndef BOARD_H
#define BOARD_H

#include "lib.h"
#include "minions/minion.h"
#include "rituals/ritual.h"
#include <string>
#include <stdexcept>

class Trigger;
class Board {
  std::vector<std::unique_ptr<Minion>> minions;
  std::unique_ptr<Ritual> ritual;
  std::vector<Trigger*> triggers;

  public:
    void addCard(Minion* minion);
    void addCard(Ritual* r);
    void addTrigger(Trigger* trigger);
    void notifyEndTurnTriggers(EndTurn* action, Board& board, Game& game);

    void notifyStartTurnTriggers(StartTurn* action, Board& board, Game& game);
    Minion* getMinion(int i);
    std::vector<Minion*> getMinions();
    Ritual* getRitual() {
      return ritual.get();
    };
};



#endif // BOARD_H