#ifndef GIANTSTRENGTH_H
#define GIANTSTRENGTH_H

#include "../lib.h"
#include "enchantment.h"

class GiantStrength: public Enchantment {

  int getAtk() const override {
    return (*next).getAtk() + 2;
  };
  int getDef() const override {
    return (*next).getDef() + 2;
  };
  std::string getBottomLeft() override {return "+2";}
  std::string getBottomRight() override {return "+2";}
  std::string description() override {return "";}
};



#endif // GIANTSTRENGTH_H