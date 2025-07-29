#ifndef SPELL_h
#define SPELL_h
#include "../card.h"
#include "../lib.h"
#include "../game.h"
#include <memory>

class Player;
class Spell: public Card {
    virtual vector<unique_ptr<Ability>> getAbilities(Game& game, Player& player, int onto) = 0;
  public:
    Spell(std::string name, int cost, Player& player): Card(name, cost, player) {};
    void play(Game &game, Player &player, EnterPlay* action) override; // DO THIS SOMETIME
    std::string getBottomLeft() override {return "";}
    std::string getBottomRight() override {return "";}
    std::string getTopLeft() override {return "";}
    std::string getType() override {return "Spell";}
};

#endif // SPELL_h

