#ifndef ENTERPLAY_H
#define ENTERPLAY_H

#include "action.h"
#include "../lib.h"
#include "../card.h"

class Game;

class EnterPlay : public Action
{

  int cardID;
  int player;
  int onto;
  bool minion = false;
  Card* entering = nullptr;

public:
  EnterPlay(int cardID, int player, int onto) : cardID(cardID), player{player}, onto{onto} {}
  void execute(Game &game) override;
  int getOnto() const;
  int getPlayer() const;
  bool isMinion() {return minion;}
  void iAmMinion() {minion = true;}
  bool checkTrigger(Trigger* trig, Board &board, Game &game) override;
};

#endif // ENTERPLAY_H