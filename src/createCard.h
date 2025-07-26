#ifndef CREATECARD_H
#define CREATECARD_H

#include "lib.h"
#include "minions/minionLib.h"
#include "spells/spelllib.h"
#include "card.h"
#include <stdexcept>

inline std::unique_ptr<Card> createCard(const std::string &cardName) {
if (cardName == "Air Elemental") return std::make_unique<AirElemental>();
else if (cardName == "Earth Elemental") return std::make_unique<EarthElemental>();
// else if (cardName == "Fire Elemental") return std::make_unique<FireElemental>();
// else if (cardName == "Potion Seller") return std::make_unique<PotionSeller>();
// else if (cardName == "Novice Pyromancer") return std::make_unique<NovicePyromancer>();
// else if (cardName == "Apprentice Summoner") return std::make_unique<ApprenticeSummoner>();
// else if (cardName == "Master Summoner") return std::make_unique<MasterSummoner>();
// else if (cardName == "Banish") return std::make_unique<Banish>();
// else if (cardName == "Unsummon") return std::make_unique<Unsummon>();
// else if (cardName == "Recharge") return std::make_unique<Recharge>();
// else if (cardName == "Disenchant") return std::make_unique<Disenchant>();
// else if (cardName == "Raise Dead") return std::make_unique<RaiseDead>();
else if (cardName == "Blizzard") return std::make_unique<Blizzard>();
// else if (cardName == "Giant Strength") return std::make_unique<GiantStrength>();
// else if (cardName == "Magic Fatigue") return std::make_unique<MagicFatigue>();
// else if (cardName == "Silence") return std::make_unique<Silence>();
// else if (cardName == "Dark Ritual") return std::make_unique<DarkRitual>();
// else if (cardName == "Aura of Power") return std::make_unique<AuraofPower>();
// else if (cardName == "Standstill") return std::make_unique<Standstill>();

  throw std::invalid_argument("Card not found: " + cardName);
};



#endif // CREATECARD_H