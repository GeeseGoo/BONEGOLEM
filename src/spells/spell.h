#ifndef SPELL_h
#define SPELL_h
#include "../card.h"
#include "../lib.h"
#include "../game.h"
class Player;
class Spell: public Card {
    virtual void execute(Game& game) = 0;
    public:
    Spell(std::string name, int cost, Player& player): Card(name, cost, player) {};
    void play(Game& game, std::unique_ptr<Card>&& self, Player& player) {
      execute(game);
    };
    std::string getBottomLeft() override {return "";}
    std::string getBottomRight() override {return "";}
    std::string getTopLeft() override {return "";}
    std::string getType() override {return "Spell";}
};

#endif // SPELL_h

