#ifndef SPELL_h
#define SPELL_h
#include "../card.h"
#include "../lib.h"
#include "../game.h"
class Player;
class Spell: public Card {
    virtual Ability* getAbility() = 0;
    public:
    Spell(std::string name, int cost, Player& player): Card(name, cost, player) {};
    void play(Game& game, Player& player, int onto) override; // DO THIS SOMETIME
    std::string getBottomLeft() override {return "";}
    std::string getBottomRight() override {return "";}
    std::string getTopLeft() override {return "";}
    std::string getType() override {return "Spell";}
};

#endif // SPELL_h

