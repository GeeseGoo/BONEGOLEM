#ifndef HASTE_H
#define HASTE_H

#include "../lib.h"
#include "enchantment.h"

class Haste: public Enchantment {
  public:
    Haste(int playerNum) : Enchantment("Haste", 1, playerNum) {}
    void setActions(int a) override {   
        next->setActions(a+1);
    };
    std::string enchantmentDescription() override{
        return "Enchanted minion gets +1 action each turn.";
    }
};


#endif // HASTE_H