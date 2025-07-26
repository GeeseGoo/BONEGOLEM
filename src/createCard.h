#ifndef CREATECARD_H
#define CREATECARD_H

#include "lib.h"
#include "minions/minionLib.h"
#include "spells/spelllib.h"
#include "card.h"
#include <stdexcept>

inline std::unique_ptr<Card> createCard(const std::string &cardName) {
  if (cardName == "Air Elemental") return std::make_unique<AirElemental>();
  else if (cardName == "Blizzard") return std::make_unique<Blizzard>();

  throw std::invalid_argument("Card not found: " + cardName);
};



#endif // CREATECARD_H