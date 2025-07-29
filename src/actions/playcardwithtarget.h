// #ifndef PLAYCARDWITHTARGET
// #define PLAYCARDWITHTARGET

// #include "action.h"
// #include "../lib.h"
// #include "../game.h"

// class PlayCardWithTarget : public Action
// {

//   int magicID;
//   int targetCardID;
//   int playerIdx;

// public:
//   PlayCardWithTarget(int magicID, int targetCardID, int playerNum) : magicID(magicID), targetCardID(targetCardID), playerIdx(playerNum - 1) {}
//   void execute(Game &game)
//   {
//     auto &player = game.getActivePlayer();
//     Player &targetPlayer = game.getPlayers()[playerIdx];
//     auto &hand = player.getHand();
//     auto cardToCast = hand.extractCard(magicID);
//     cardToCast->play(game, std::move(cardToCast), std::move(cardToCast), targetPlayer.getBoard().getMinion(targetCardID));

//     std::cout << "played card" << std::endl;
//   }
// };

// #endif // PLAYCARDWITHTARGET