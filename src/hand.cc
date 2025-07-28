#include "hand.h"
#include "lib.h"
#include "createCard.h"
using namespace std;

bool Hand::isHandFull() const {
  if (cards.size() >= 5) return true;
  return false;
}
void Hand::setPlayer(Player* p) {
      player = p;
    }
Hand::Hand(){};

void Hand::add(string cardName) {
  cards.emplace_back(createCard(cardName, *player));
}