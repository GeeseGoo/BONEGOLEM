#include "minion.h"
#include "../lib.h"
#include "../player.h"
#include "../board.h"
#include "../game.h"
#include "../triggers/trigger.h"
#include "../actions/enterplay.h"
using namespace std;

void Minion::attack(Player &other) {
  cout << name << " attacked " << other.getName() << endl;
  other.takeDamage(atk);
}

Minion::Minion(string name, int cost, int atk, int def, int actions, int playerNum) : Card(name, cost, playerNum), atk(atk), def(def), actions(actions) {}

Minion::Minion(string name, int cost, unique_ptr<Trigger> trigger, int atk, int def, int actions, int playerNum, int abilityCost) : Card(name, cost, std::move(trigger), playerNum), atk(atk), def(def), actions(actions), abilityCost(abilityCost) {}

void Minion::play(Game &game, Player &player, EnterPlay* action) {
  this->game = &game;
  isDead = false;
  action->iAmMinion();
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

void Minion::takeDamage(int dmg) {
  if(!game){
    throw std::runtime_error("Minion has been attacked without being played.");
  }
  def -= dmg;
  if (def<= 0 && !isDead) {
    isDead = true;
    std::cout << name << " has died!"<< std::endl;
    game->action(make_unique<KillMinion>(*this, game->getPlayers().at(playerNum)));
  }
}
