#include "card.h"
#include "triggers/trigger.h"
#include "player.h"
Card::Card(std::string name, Player& player): player(player), name(name) {};
Card::Card(std::string name, std::unique_ptr<Trigger> trigger, Player& player): trigger(std::move(trigger)),player(player), name(name) {};
Trigger* Card::getTrigger() {
      return trigger.get();
    }