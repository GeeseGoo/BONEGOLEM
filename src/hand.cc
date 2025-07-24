#include "hand.h"
#include "lib.h"
using namespace std;

bool Hand::isHandFull() const {
  if (cards.size() >= 5) return true;
  return false;
}

void Hand::add(string card) {
  cards.emplace_back(make_unique<Card>(card));
}