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
};



#endif // GIANTSTRENGTH_H