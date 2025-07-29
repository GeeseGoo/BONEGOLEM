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
class Trigger
{
protected:
  std::unique_ptr<Ability> ability;
  Card *card; // card that owns this ability

public:
  Trigger(std::unique_ptr<Ability> &&ability, Card *card) : ability(std::move(ability)), card(card) {};
  void trigger(Action *action, Board &board, Game &game);
  virtual void beTriggered(EndTurn *action, Board &board, Game &game) {};
  virtual void beTriggered(StartTurn *action, Board &board, Game &game) {};
  virtual void beTriggered(EnterPlay *action, Board &board, Game &game) {};
  virtual void beTriggered(LeavePlay *action, Board &board, Game &game) {};
  virtual void beTriggered(UseAbility *action, Board &board, Game &game) {};
  virtual void beTriggered(AttackMinion *action, Board &board, Game &game) {};
  virtual void beTriggered(AttackPlayer *action, Board &board, Game &game) {};
};

#endif // TRIGGER_H