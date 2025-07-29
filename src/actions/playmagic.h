#ifndef PLAYMAGIC
#define PLAYMAGIC

#include "action.h"
#include "../lib.h"
#include "../game.h"

class PlayMagic : public Action
{

  int magicID;
  int targetCardID;
  int playerIdx;

public:
  PlayMagic(int magicID, int targetCardID, int playerNum) : magicID(magicID), targetCardID(targetCardID), playerIdx(playerNum - 1) {}
  void execute(Game &game)
  {
    // auto &player = game.getActivePlayer();
    // Player &targetPlayer = game.getPlayers()[playerIdx];
    // auto &hand = player.getHand();
    // auto magic = hand.extractCard(magicID);
    // // caster->play(game, std::move(caster), player);

    // std::cout << "played card" << std::to_string(cardID) << std::endl;
  }
};

#endif // PLAYMAGIC