#ifndef BONEGOLEM_H
#define BONEGOLEM_H
#include "../minions/minion.h"
#include "../triggers/triggerlib.h"
#include "../abilities/playerstatbuff.h"
#include "../lib.h"

class BoneGolem : public Minion
{

public:
  BoneGolem(Player &player) : Minion("Bone Golem", 2,
                                     std::make_unique<MinionLeavesTrigger>(std::make_unique<PlayerStatBuff>(1, 1), this),
                                     1, 1, 1, player) {};
  std::string description() override { return "Gain +1/+1 whenever a minion leaves play."; }
};

#endif // BONEGOLEM_H
