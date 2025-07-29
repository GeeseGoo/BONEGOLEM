#include "graveyard.h"

Card* Graveyard::top(){
    if(cards.size() == 0){
        return nullptr;
    }
    return cards.top().get();
}
