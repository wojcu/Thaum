#ifndef TURTLEFIGHT_H
#define TURTLEFIGHT_H

#include "fightaction.h"

namespace Simulation {
class TurtleFight : public Simulation::FightAction {
public:
    TurtleFight();

    MoveStatus defend(FightContext &ctx) override;

    MoveStatus attack(FightContext &ctx) override;
};
}

#endif // TURTLEFIGHT_H
