#ifndef SUMMON_MINION_H
#define SUMMON_MINION_H

#include "ability.h"
#include "../game.h"
#include "../player.h"
#include "../card.h"
#include "../actions/action.h"
#include "../lib.h"
#include "../actions/enterplay.h"

// makes a number of new minions and puts them on the board
class SummonMinion : public Ability
{
    std::string minionName;
    int number;

    void execute(Game &game, Card *card, Action *action, int player, int onto) override;
  public:
    SummonMinion(std::string minionName, int number) : minionName{minionName}, number{number} {};
};

#endif // SUMMON_MINION_H