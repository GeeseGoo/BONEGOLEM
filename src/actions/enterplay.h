#ifndef ENTERPLAY_H
#define ENTERPLAY_H

#include "action.h"
#include "../lib.h"
#include "../card.h"

class Game;

class EnterPlay : public Action
{

  int cardID;
  int onto;
  bool minion = false;
  Card* entering = nullptr;

public:
  EnterPlay(int cardID, int onto) : cardID(cardID), onto{onto} {}
  void execute(Game &game) override;
  int getOnto() const;
  bool isMinion() {return minion;}
  void iAmMinion() {minion = true;}
  void iEnter(Card* card) {entering = card;}
  Card* getCard() {return entering;}
};

#endif // ENTERPLAY_H