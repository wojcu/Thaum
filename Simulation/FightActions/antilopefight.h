#ifndef ANTILOPEFIGHT_H
#define ANTILOPEFIGHT_H

#include "Simulation/FightActions/fightaction.h"

namespace Simulation {
class AntilopeFight : public FightAction {
public:
    AntilopeFight();

    MoveStatus defend(FightContext &ctx) override;

    MoveStatus attack(FightContext &ctx) override;
};
}

#endif // ANTILOPEFIGHT_H
