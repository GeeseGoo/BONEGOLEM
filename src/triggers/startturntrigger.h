#ifndef STARTTURN_h
#define STARTTURN_h

#include "../actions/startTurn.h"
#include "trigger.h"
#include "../game.h"

class StartTurnTrigger: public Trigger {
  public:
      int playerNum;
    StartTurnTrigger(std::unique_ptr<Ability>&& ability, Card* card, int playerNum): Trigger(std::move(ability), card), playerNum{playerNum} {};
    bool beTriggered(StartTurn* action, Board& board, Game& game) override{
      if(action->getPlayerNum() == playerNum + 1){
        std::cout << "start turn triggered" << std::endl;
        ability->activate(game, card, action, game.getPlayerIdx(), -1);
        return true;
      }
      return false;
    }
};


#endif // STARTTURN