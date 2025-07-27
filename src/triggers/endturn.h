#ifndef ENDTURN_h
#define ENDTURN_h

#include "../actions/endTurn.h"
#include "trigger.h"
#include "../game.h"
#include "../lib.h"
class EndTurnTrigger: public Trigger {

  public:
    EndTurnTrigger(std::unique_ptr<Ability>&& ability, Card* card): Trigger(std::move(ability), card) {};
    void beTriggered(EndTurn* action, Game& game) override {
std::cout << "end turn triggered" << std::endl;
      if (action->getPlayerNum() == game.getPlayerNum()){
        ability->activate(game, card, action);
      }
    };
};


#endif // ENDTURN_h