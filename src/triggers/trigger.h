#ifndef TRIGGER_H
#define TRIGGER_H

#include "../abilities/ability.h"
#include "../lib.h"
#include "../card.h"


class EndTurn;
class StartTurn;
class EnterPlay;
class UseCard;
class Board;
class LeavePlay;
class UseAbility;
class AttackPlayer;
class AttackMinion;
class MinionCreate;
class KillMinion;
class Trigger
{
protected:
  std::unique_ptr<Ability> ability;
  Card *card; // card that owns this ability

public:
  Trigger(std::unique_ptr<Ability> &&ability, Card *card) : ability(std::move(ability)), card(card) {};
  virtual ~Trigger() = default;
  bool trigger(Action *action, Board &board, Game &game);
  virtual bool beTriggered(EndTurn *action, Board &board, Game &game) {return false;}
  virtual bool beTriggered(StartTurn *action, Board &board, Game &game) {return false;}
  virtual bool beTriggered(EnterPlay *action, Board &board, Game &game) {return false;}
  virtual bool beTriggered(LeavePlay *action, Board &board, Game &game) {return false;}
  virtual bool beTriggered(UseAbility *action, Board &board, Game &game) {return false;}
  virtual bool beTriggered(AttackMinion *action, Board &board, Game &game) {return false;}
  virtual bool beTriggered(AttackPlayer *action, Board &board, Game &game) {return false;}
  virtual bool beTriggered(MinionCreate *action, Board &board, Game &game) {return false;}
  virtual bool beTriggered(KillMinion *action, Board &board, Game &game) {return false;}
};

#endif // TRIGGER_H