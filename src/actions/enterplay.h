#ifndef ENTERPLAY_H
#define ENTERPLAY_H

#include "action.h"
#include "../lib.h"

class Game;

class EnterPlay : public Action
{

  int cardID;
  int onto;
  bool minion = false;

public:
  EnterPlay(int cardID, int onto) : cardID(cardID), onto{onto} {}
  void execute(Game &game) override;
  int getOnto() const;
  bool isMinion() {return minion;}
  void iAmMinion() {minion = true;}
};

#endif // ENTERPLAY_H