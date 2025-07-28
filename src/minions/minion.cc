#include "minion.h"
#include "../lib.h"
#include "../player.h"
#include "../board.h"
#include "../game.h"
#include "../triggers/trigger.h"

using namespace std;

void Minion::attack(Player& other) {
  cout << name << " attacked " << other.getName() << endl;
  other.takeDamage(atk);
}

void Minion::attack(Minion& other) {
    cout << name << " attacked " << other.getName() << endl;
    other.takeDamage(atk);
}

Minion::Minion(string name, int def, int atk, int actions):  
Card(name), atk(atk), def(def), actions(actions) {}

Minion::Minion(string name, unique_ptr<Trigger> trigger, int def, int atk, int actions):  
Card(name, std::move(trigger)), atk(atk), def(def), actions(actions) {}


void Minion::play(Game& game, std::unique_ptr<Card>&& self) {
  // add trigger to game
  game.addTrigger(this->getTrigger());

  Card* rawCard = self.release();
  rawCard->addToBoard(game.getActivePlayer().getBoard());
}

void Minion::addToBoard(Board& board) {
  board.addCard(this);
}