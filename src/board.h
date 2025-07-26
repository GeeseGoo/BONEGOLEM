#ifndef BOARD_H
#define BOARD_H

#include "lib.h"
#include "minions/minion.h"
#include "spells/spell.h"
#include <string>
#include <stdexcept>
#include "card.h"
class Board {
  std::vector<std::unique_ptr<Minion>> minions;

  public:
void addCard(std::unique_ptr<Card> card) {
    // check if card is minion
    if (Minion* minionRaw = dynamic_cast<Minion*>(card.release())) {
        minions.push_back(std::unique_ptr<Minion>(minionRaw));
    }
    
    else {
        throw std::runtime_error("Card type not found");
    }
}
    Minion& getMinion(int i) {
      if (!(minions[i])) {
        throw std::runtime_error("no minion at index" + std::to_string(i));
      }
      return *(minions[i]);
    }

    std::vector<Minion*> getMinions() {
      std::vector<Minion*> result;
      for(const auto& ptr: minions) {
        result.push_back(ptr.get());
      }
      return result;
    }

};



#endif // BOARD_H