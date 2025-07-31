#ifndef MAGIC_FATIGUE_H
#define MAGIC_FATIGUE_H

#include "../lib.h"
#include "enchantment.h"

class MagicFatigue: public Enchantment {
  public:
    MagicFatigue(int playerNum) : Enchantment("Magic Fatigue", 0, playerNum) {}
    std::string enchantmentDescription() override{
        return "Enchanted minion's abilities cost 2 more.";
    }
    int getAbilityCost() const override{
        return next->getAbilityCost() + 2;
    }
    std::string getTopLeft() override {
        if (!next)
            return enchantmentTopLeft();
        if (next->getTopLeft() != ""){
            return std::to_string(std::stoi(next->getTopLeft())+2);
        }
        return next->getTopLeft();
    }


};


#endif // MAGIC_FATIGUE_H