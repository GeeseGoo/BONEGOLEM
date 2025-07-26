#ifndef BOARD_H
#define BOARD_H

#include "lib.h"
#include "minions/minion.h"
#include "spells/spell.h"
#include "rituals/ritual.h"
#include <string>
#include <stdexcept>
#include "card.h"
class Board {
  std::vector<std::unique_ptr<Minion>> minions;
  std::unique_ptr<Ritual> ritual;

  public:
void addCard(Minion* minion) {
    minions.emplace_back(std::unique_ptr<Minion>(minion));
}
void addCard(Ritual* r) {
    ritual = std::unique_ptr<Ritual>(r);
}
    Minion* getMinion(int i) {
      if (minions.size() == 0) throw std::runtime_error("empty board");
      if (!(minions.at(i))) {
        throw std::runtime_error("no minion at index" + std::to_string(i));
      }
      return minions[i].get();
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