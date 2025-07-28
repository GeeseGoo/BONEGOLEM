#ifndef PLAYERSTATBUFF
#define PLAYERSTATBUFF

#include "ability.h"
#include "../game.h"
#include "../player.h"
#include "../card.h"
#include "../actions/action.h"
#include "../lib.h"

class PlayerStatBuff: public Ability {
  int hpDelta;
  int magicDelta;
  void execute(Game& game, Card* card, Action* action) override {
    std::cout << "buffed player" << std::endl;
    Player& player = game.getActivePlayer();
    player.takeDamage(-1 * hpDelta);
    player.setMagic(player.getMagic() + magicDelta);
  };

  public:
    PlayerStatBuff(int hpDelta, int magicDelta): hpDelta(hpDelta), magicDelta(magicDelta) {};
};


#endif // PLAYERSTATBUFF