#include "minion.h"
#include "lib.h"
#include "player.h"

using namespace std;

void Minion::attack(Player& other) {
  cout << name << " attacked " << other.getName() << endl;
  other.dealDamage(atk);
}

Minion::Minion(string name, int def, int atk, int actions):  Card(name), atk(atk), def(def), actions(actions) {}