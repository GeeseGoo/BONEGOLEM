#ifndef CREATECARD_H
#define CREATECARD_H

#include "lib.h"
#include "minions/minionLib.h"
#include "spells/spelllib.h"
#include "rituals/rituallib.h"
#include "enchantments/enchantmentlib.h"
#include "card.h"
#include <stdexcept>

inline std::unique_ptr<Card> createCard(const std::string &cardName, int playerNum)
{
  std::cout << "Making card for player: " << playerNum << std::endl;
  if (cardName == "Air Elemental")
    return std::make_unique<AirElemental>(playerNum);
  else if (cardName == "Earth Elemental")
    return std::make_unique<EarthElemental>(playerNum);
  else if (cardName == "Bone Golem")
    return std::make_unique<BoneGolem>(playerNum);
  else if (cardName == "Fire Elemental")
    return std::make_unique<FireElemental>(playerNum);
  else if (cardName == "Potion Seller")
    return std::make_unique<PotionSeller>(playerNum);
  else if (cardName == "Novice Pyromancer") return std::make_unique<NovicePyromancer>(playerNum);
  else if (cardName == "Apprentice Summoner")
    return std::make_unique<ApprenticeSummoner>(playerNum);
  // else if (cardName == "Master Summoner") return std::make_unique<MasterSummoner>(playerNum);
  else if (cardName == "Banish")
    return std::make_unique<Banish>(playerNum);
  else if (cardName == "Unsummon")
    return std::make_unique<Unsummon>(playerNum);
  else if (cardName == "Recharge") return std::make_unique<Recharge>(playerNum);
  else if (cardName == "Disenchant")
    return std::make_unique<Disenchant>(playerNum);
  else if (cardName == "Raise Dead")
    return std::make_unique<RaiseDead>(playerNum);
  else if (cardName == "Blizzard")
    return std::make_unique<Blizzard>(playerNum);
  else if (cardName == "Giant Strength")
    return std::make_unique<GiantStrength>(playerNum);
  // else if (cardName == "Magic Fatigue") return std::make_unique<MagicFatigue>(playerNum);
  // else if (cardName == "Silence") return std::make_unique<Silence>(playerNum);
  else if (cardName == "Dark Ritual")
    return std::make_unique<DarkRitual>(playerNum);
  // else if (cardName == "Aura of Power") return std::make_unique<AuraofPower>(playerNum);
  else if (cardName == "Standstill")
    return std::make_unique<Standstill>(playerNum);

  throw std::invalid_argument("Card not found: " + cardName);
};

#endif // CREATECARD_H