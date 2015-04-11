#ifndef NIGHTSHADEFIGHT_H
#define NIGHTSHADEFIGHT_H

#include "Simulation/FightActions/fightaction.h"

namespace Simulation {
class NightshadeFight : public Simulation::FightAction {
public:
    NightshadeFight();

    MoveStatus defend(FightContext &ctx) override;

    MoveStatus attack(FightContext &) override;
};
}

#endif // NIGHTSHADEFIGHT_H
