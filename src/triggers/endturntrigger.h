#ifndef ENDTURNTRIGGER_h
#define ENDTURNTRIGGER_h

#include "../actions/endTurn.h"
#include "trigger.h"
#include "../game.h"
#include "../lib.h"
#include "../board.h"
class EndTurnTrigger: public Trigger {

  public:
    EndTurnTrigger(std::unique_ptr<Ability>&& ability, Card* card): Trigger(std::move(ability), card) {};
    bool beTriggered(EndTurn* action, Board& board, Game& game) override {
std::cout << "end turn triggered" << std::endl;
        ability->activate(game, card, action, game.getPlayerIdx(),-1);
        return true;
    }
};


#endif // ENDTURNTRIGGER_h