#ifndef ALLMINIONBUFF_H
#define ALLMINIONBUFF_H

#include "ability.h"
#include "../game.h"
#include "../player.h"
#include "../card.h"
#include "../actions/action.h"
#include "../lib.h"

// buffs all minions belongning to a specific player
class AllMinionBuff : public Ability
{
  int atkBuff;
  int defBuff;
  Player* player;
  void execute(Game &game, Card *card, Action *action, int p, int onto) override
  {
    if(!player){
      player = &game.getActivePlayer();
    }
    for (auto m : player->getBoard().getMinions())
    {
      // std::cout << "buffing minion " << m->getName() << std::endl;
      m->setAtk(m->getAtk() + atkBuff);
      m->takeDamage(-1 * defBuff);
    }
  };

public:
  AllMinionBuff(int atkBuff, int defBuff, Player* player = nullptr) : atkBuff(atkBuff), defBuff(defBuff), player{player} {};
};

#endif // ALLMINIONSTATCHANGE_H