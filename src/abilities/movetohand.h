#ifndef MOVETOHAND_H
#define MOVETOHAND_H

#include "ability.h"
#include "../game.h"
#include "../player.h"
#include "../card.h"
#include "../actions/leaveplay.h"
#include "../lib.h"

class MoveToHand : public Ability
{

  void execute(Game &game, Card *card, Action *action, int player, int onto) override
  {

    Player &playerRef = game.getPlayers().at(player);
    Minion *minion = playerRef.getBoard().getMinion(onto);
    game.action(std::make_unique<LeavePlay>(*minion, playerRef.getBoard()));
    playerRef.getHand().add(std::unique_ptr<Minion>(minion));
  }

public:
};

#endif // MOVETOHAND_H