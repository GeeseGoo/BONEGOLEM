#ifndef BONEGOLEM_H
#define BONEGOLEM_H
#include "../minions/minion.h"
#include "../triggers/triggerlib.h"
#include "../abilities/buffme.h"
#include "../lib.h"

class BoneGolem : public Minion
{

public:
  BoneGolem(int playerNum) : Minion("Bone Golem", 2,
                                     std::make_unique<MinionLeavesTrigger>(std::make_unique<BuffMe>(1, 1, this), this),
                                     1, 3, 1, playerNum) {};
  std::string description() override { return "Gain +1/+1 whenever a minion leaves play."; }
};

#endif // BONEGOLEM_H
