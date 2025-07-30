#ifndef USEABILITY_H
#define USEABILITY_H

#include "action.h"
#include "../lib.h"
#include "../card.h"

class Game;
class Minion;

// action that is activated by the use command -> triggers activated abilities
class UseAbility : public Action
{
  int cardID;
  int player;
  int onto;
  bool validUse = false;
  Card* user;
public:
  UseAbility(int cardID, int player, int onto) : cardID(cardID), player{player}, onto{onto} {}
  void execute(Game &game) override;
  int getOnto() const;
  Card* getUser() const;
  int getPlayer() const;
  bool checkTrigger(Trigger* trig, Board &board, Game &game) override;
  void act(Game& game) override;
};

#endif // USEABILITY_H