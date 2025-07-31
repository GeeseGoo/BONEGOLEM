#ifndef ENDTURNTRIGGER_h
#define ENDTURNTRIGGER_h

#include "../actions/endTurn.h"
#include "trigger.h"
#include "../game.h"
#include "../lib.h"
#include "../board.h"
class EndTurnTrigger: public Trigger {

  public:
      int playerNum;
    EndTurnTrigger(std::unique_ptr<Ability>&& ability, Card* card, int playerNum): Trigger(std::move(ability), card) , playerNum{playerNum} {};
    bool beTriggered(EndTurn* action, Board& board, Game& game) override {
      if(action->getPlayerNum() == playerNum +1){
        std::cout << "end turn triggered" << std::endl;
        ability->activate(game, card, action, game.getPlayerIdx(),-1);
        return true;
      }
    return false;
    }
};


#endif // ENDTURNTRIGGER_h