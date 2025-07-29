#ifndef ABILITY_h
#define ABILITY_h

#include "../actions/action.h"

class Game;
class Card;
class Action;
class Ability {

  virtual void execute(Game& game, Card* card, Action* action, int player, int onto) = 0;
  public:
    void activate(Game& game, Card* card, Action* action, int player, int onto) {
      execute(game, card, action, player, onto);
    };
};



#endif // ABILITY_h