#include "minion.h"
#include "../lib.h"
#include "../player.h"

using namespace std;

void Minion::attack(Player& other) {
  cout << name << " attacked " << other.getName() << endl;
  other.takeDamage(atk);
}

void Minion::attack(Minion& other) {
    cout << name << " attacked " << other.getName() << endl;
    other.takeDamage(atk);
}

Minion::Minion(string name, int def, int atk, int actions):  Card(name), atk(atk), def(def), actions(actions) {}

void Minion::play(Game& game, std::unique_ptr<Card>&& self) {
  game.getActivePlayer().getBoard().addCard(std::move(self));
}