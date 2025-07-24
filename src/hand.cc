#include "hand.h"

bool Hand::isHandFull() const {
  if (cards.size() >= 5) return true;
  return false;
}