#include "minion.h"
#include "../lib.h"
#include "../player.h"
#include "../board.h"
#include "../game.h"
#include "../triggers/trigger.h"
#include "../actions/enterplay.h"
using namespace std;

void Minion::attack(Player &other)
{
  cout << name << " attacked " << other.getName() << endl;
  other.takeDamage(atk);
}

void Minion::attack(Minion &other)
{
  cout << name << " attacked " << other.getName() << endl;
  other.takeDamage(atk);
}

Minion::Minion(string name, int cost, int def, int atk, int actions, Player &player) : Card(name, cost, player), atk(atk), def(def), actions(actions) {}

Minion::Minion(string name, int cost, unique_ptr<Trigger> trigger, int def, int atk, int actions, Player &player) : Card(name, cost, std::move(trigger), player), atk(atk), def(def), actions(actions) {}

void Minion::play(Game &game, Player &player, EnterPlay* action)
{
  // add trigger to game
  action->iAmMinion();
  action->iEnter(this);
  player.getBoard().addTrigger(this->getTrigger());
  game.getActivePlayer().getBoard().addCard(this);
}

string Minion::getBottomLeft()
{
  return to_string(atk);
}

string Minion::getBottomRight()
{
  return to_string(def);
}

string Minion::getTopLeft()
{
  if (abilityCost == -1)
  {
    return "";
  }
  else
  {
    return to_string(abilityCost);
  }
}