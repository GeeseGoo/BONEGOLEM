#ifndef STARTTURN_h
#define STARTTURN_h

#include "../actions/startTurn.h"
#include "trigger.h"
#include "../game.h"

class StartTurnTrigger: public Trigger {

  public:
    StartTurnTrigger(std::unique_ptr<Ability>&& ability, Card* card): Trigger(std::move(ability), card) {};
    void beTriggered(StartTurn* action, Board& board, Game& game) override{
      std::cout << "start turn triggered" << std::endl;
        ability->activate(game, card, action);
    };
};


#endif // STARTTURN