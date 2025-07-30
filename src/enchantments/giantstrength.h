#ifndef GIANTSTRENGTH_H
#define GIANTSTRENGTH_H

#include "../lib.h"
#include "enchantment.h"

class GiantStrength: public Enchantment {
  public:
    GiantStrength(int playerNum) : Enchantment("Giant Strength", 1, playerNum) {}
    std::string enchantmentBottomLeft() override {return "+2";}
    std::string enchantmentBottomRight() override {return "+2";}
    void onEquip() override {next->setAtk(next->getAtk()+2); next->setDef(next->getDef()+2);}
    void onRemove() override {next->setAtk(next->getAtk()-2); next->setDef(next->getDef()-2);}
};


#endif // GIANTSTRENGTH_H