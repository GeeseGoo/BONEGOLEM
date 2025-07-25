#ifndef CREATECARD_H
#define CREATECARD_H

#include "lib.h"
#include "minions/minionLib.h"
#include "card.h"
#include <stdexcept>

inline std::unique_ptr<Card> createCard(const std::string &cardName) {
  if (cardName == "Air Elemental") return std::make_unique<AirElemental>();

  throw std::invalid_argument("Card not found: " + cardName);
};



#endif // CREATECARD_H