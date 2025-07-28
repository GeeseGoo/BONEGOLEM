#ifndef TRIGGER_H
#define TRIGGER_H

#include "../abilities/ability.h"
#include "../lib.h"
#include "../card.h"
class Action;
class EndTurn;
class StartTurn;
class PlayCard;
class UseCard;
class Board;
class LeavePlay;
class Trigger
{
protected:
  std::unique_ptr<Ability> ability;
  Card *card;

public:
  Trigger(std::unique_ptr<Ability> &&ability, Card *card) : ability(std::move(ability)), card(card) {};
  virtual void beTriggered(Action *action, Board &board, Game &game) {};
  virtual void beTriggered(EndTurn *action, Board &board, Game &game) {};
  virtual void beTriggered(StartTurn *action, Board &board, Game &game) {};
  virtual void beTriggered(PlayCard *action, Board &board, Game &game) {};
  virtual void beTriggered(LeavePlay *action, Board &board, Game &game) {};
};

#endif // TRIGGER_H