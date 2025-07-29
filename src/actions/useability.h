#ifndef USEABILITY_H
#define USEABILITY_H

#include "action.h"
#include "../lib.h"
#include "../card.h"

class Game;
class Minion;

class UseAbility : public Action
{
  int cardID;
  int player;
  int onto;
  Card* user;
public:
  UseAbility(int cardID, int player, int onto) : cardID(cardID), player{player}, onto{onto} {}
  void execute(Game &game) override;
  int getOnto() const;
  Card* getUser() const;
  int getPlayer() const;
  void checkTrigger(Trigger* trig, Board &board, Game &game) override;
};

#endif // USEABILITY_H