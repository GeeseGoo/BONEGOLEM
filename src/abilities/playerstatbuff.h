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
  void execute(Game& game, Card* card, Action* action, int player, int onto) override {
    std::cout << "buffed player" << std::endl;
    Player& active = game.getActivePlayer();
    active.takeDamage(-1 * hpDelta);
    active.setMagic(active.getMagic() + magicDelta);
  };

  public:
    PlayerStatBuff(int hpDelta, int magicDelta): hpDelta(hpDelta), magicDelta(magicDelta) {};
};


#endif // PLAYERSTATBUFF