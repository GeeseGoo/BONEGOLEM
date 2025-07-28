#ifndef SPELL_h
#define SPELL_h
#include "../card.h"
#include "../lib.h"
#include "../game.h"

class Spell: public Card {
    int cost;

    virtual void execute(Game& game) = 0;
    public:
    Spell(int cost, std::string name, Player& player): Card(name, player), cost(cost) {};
    void play(Game& game, std::unique_ptr<Card>&& self) {
      execute(game);
    };

};

#endif // SPELL_h

