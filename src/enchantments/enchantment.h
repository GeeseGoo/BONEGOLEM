#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include "../lib.h"
#include "../minions/minion.h"

class Enchantment: public Minion {
  protected:
    std::unique_ptr<Minion> next;

  public:
    Enchantment(std::string name, int cost, std::unique_ptr<Minion>&& minion, Player& player): Minion(name, cost, 0, 0, 0, player), next(std::move(minion)) {};
    virtual Minion* getNext() = 0;
    std::string getTopLeft() override {return "";}
    std::string getType() override {return "Enchantment";}

};


#endif // ENCHANTMENT_H