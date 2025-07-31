#ifndef MOVEFROMGRAVEYARD
#define MOVEFROMGRAVEYARD

#include "ability.h"
#include "../game.h"
#include "../player.h"
#include "../card.h"
#include "../actions/leaveplay.h"
#include "../lib.h"

class MoveFromGraveyard : public Ability
{
  int newDef;
  void execute(Game &game, Card *card, Action *action, int player, int onto) override
  {

    Player &playerRef = game.getPlayers().at(player);
    std::unique_ptr<Minion> minion = playerRef.getGraveyard().pop();
    minion->setDef(newDef);
    playerRef.getBoard()
        .addCard(std::move(minion));
  }

public:
  MoveFromGraveyard(int newDef) : newDef(newDef) {};
};

#endif // MOVEFROMGRAVEYARD