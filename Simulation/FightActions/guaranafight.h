#ifndef GUARANAFIGHT_H
#define GUARANAFIGHT_H

#include "Simulation/FightActions/fightaction.h"

namespace Simulation {
class GuaranaFight : public FightAction {
public:
    GuaranaFight();

    MoveStatus defend(Simulation::FightContext &ctx) override;

    MoveStatus attack(Simulation::FightContext &) override;
};
}

#endif // GUARANAFIGHT_H
