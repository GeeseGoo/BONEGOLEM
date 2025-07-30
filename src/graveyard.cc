#include "graveyard.h"
#include "minions/minion.h"
#include "lib.h"

Minion* Graveyard::top(){
    if(cards.size() == 0){
        return nullptr;
    }
    return cards.top().get();
}

void Graveyard::add(Minion* card) {
    cards.push(std::unique_ptr<Minion>(card));
}

