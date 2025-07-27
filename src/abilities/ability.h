#ifndef ABILITY_h
#define ABILITY_h

class Game;
class Card;
class Action;
class Ability {

  virtual void execute(Game& game, Card* card, Action* action) = 0;
  public:
     void activate(Game& game, Card* card, Action* action) {
      execute(game, card, action);
     };
};



#endif // ABILITY_h