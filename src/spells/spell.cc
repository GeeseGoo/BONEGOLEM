#include "spell.h"
#include "../actions/enterplay.h"

void Spell::play(Game &game, Player &player, EnterPlay* action){
    vector<unique_ptr<Ability>> abilityList = getAbilities(game, player, action->getOnto());
    for(unique_ptr<Ability>& a : abilityList){
        a.get()->activate(game, this, action, action->getPlayer(), action->getOnto());
    }
}