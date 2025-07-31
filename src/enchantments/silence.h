#ifndef SILENCE_H
#define SILENCE_H

#include "../lib.h"
#include "enchantment.h"

class Silence: public Enchantment {
  public:
    Silence(int playerNum) : Enchantment("Silence", 1, playerNum) {}
    std::string enchantmentDescription() override{
        return "Enchanted minion cannot use abilities.";
    }
    int getAbilityCost() const override{
        return -1;
    }
    std::string getTopLeft() override {
        return "";
    }
    virtual Trigger* getTrigger() override {
        return nullptr;
    }
    std::string description() override {
        if(next){
            return "";
        }else{
            return enchantmentDescription();
        }
    }
};


#endif // SILENCE_H