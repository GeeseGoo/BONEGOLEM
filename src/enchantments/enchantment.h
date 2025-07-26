#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include "../lib.h"
#include "../minions/minion.h"

class Enchantment: public Minion {
  protected:
    std::unique_ptr<Minion> next;

  public:
    Enchantment(std::string name, std::unique_ptr<Minion>&& minion): Minion(name, 0, 0, 0), next(std::move(minion)) {};
    virtual Minion* getNext() = 0;

};


#endif // ENCHANTMENT_H