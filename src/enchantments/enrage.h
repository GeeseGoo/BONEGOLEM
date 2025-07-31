#ifndef ENRAGE_H
#define ENRAGE_H

#include "../lib.h"
#include "enchantment.h"

class Enrage: public Enchantment {
  public:
    Enrage(int playerNum) : Enchantment("Giant Strength", 2, playerNum) {}
    std::string enchantmentBottomLeft() override {return "*2";}
    std::string enchantmentBottomRight() override {return "*2";}
    void onEquip() override {next->setAtk(next->getAtk()*2); next->setDef(next->getDef()*2);}
    void onRemove() override {next->setAtk(next->getAtk()/2); next->setDef(next->getDef()/2);}
};


#endif // ENRAGE_H