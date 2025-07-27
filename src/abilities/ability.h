#ifndef ABILITY_h
#define ABILITY_h

class Game;
class Ability {
  
  virtual void activate(Game& game) = 0;
};



#endif // ABILITY_h