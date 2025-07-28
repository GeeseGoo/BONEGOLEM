#ifndef ENDTURN_h
#define ENDTURN_h

#include "../actions/endTurn.h"
#include "trigger.h"
#include "../game.h"
#include "../lib.h"
#include "../board.h"
class EndTurnTrigger: public Trigger {

  public:
    EndTurnTrigger(std::unique_ptr<Ability>&& ability, Card* card): Trigger(std::move(ability), card) {};
    void beTriggered(EndTurn* action, Board& board, Game& game) override {
std::cout << "end turn triggered" << std::endl;
        ability->activate(game, card, action);
    };
};


#endif // ENDTURN_h