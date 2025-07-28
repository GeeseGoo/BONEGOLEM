#ifndef CREATECARD_H
#define CREATECARD_H

#include "lib.h"
#include "minions/minionLib.h"
#include "spells/spelllib.h"
#include "rituals/rituallib.h"
#include "card.h"
#include <stdexcept>

inline std::unique_ptr<Card> createCard(const std::string &cardName, Player &player)
{
  if (cardName == "Air Elemental")
    return std::make_unique<AirElemental>(player);
  else if (cardName == "Earth Elemental")
    return std::make_unique<EarthElemental>(player);
  else if (cardName == "Bone Golem")
    return std::make_unique<BoneGolem>(player);
  // else if (cardName == "Fire Elemental") return std::make_unique<FireElemental>(player);
  else if (cardName == "Potion Seller")
    return std::make_unique<PotionSeller>(player);
  // else if (cardName == "Novice Pyromancer") return std::make_unique<NovicePyromancer>(player);
  // else if (cardName == "Apprentice Summoner") return std::make_unique<ApprenticeSummoner>(player);
  // else if (cardName == "Master Summoner") return std::make_unique<MasterSummoner>(player);
  // else if (cardName == "Banish") return std::make_unique<Banish>(player);
  // else if (cardName == "Unsummon") return std::make_unique<Unsummon>(player);
  // else if (cardName == "Recharge") return std::make_unique<Recharge>(player);
  // else if (cardName == "Disenchant") return std::make_unique<Disenchant>(player);
  // else if (cardName == "Raise Dead") return std::make_unique<RaiseDead>(player);
  else if (cardName == "Blizzard")
    return std::make_unique<Blizzard>(player);
  // else if (cardName == "Giant Strength") return std::make_unique<GiantStrength>(player);
  // else if (cardName == "Magic Fatigue") return std::make_unique<MagicFatigue>(player);
  // else if (cardName == "Silence") return std::make_unique<Silence>(player);
  else if (cardName == "Dark Ritual")
    return std::make_unique<DarkRitual>(player);
  // else if (cardName == "Aura of Power") return std::make_unique<AuraofPower>(player);
  // else if (cardName == "Standstill") return std::make_unique<Standstill>(player);

  throw std::invalid_argument("Card not found: " + cardName);
};

#endif // CREATECARD_H