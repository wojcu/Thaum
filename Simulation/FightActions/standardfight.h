#ifndef STANDARDFIGHT_H
#define STANDARDFIGHT_H

#include <string>

#include "Simulation/FightActions/fightaction.h"

namespace Simulation {
class FightContext;

class StandardFight : public Simulation::FightAction {
public:
    StandardFight(const std::string &str = "");

    MoveStatus defend(Simulation::FightContext &ctx) override;

    MoveStatus attack(Simulation::FightContext &ctx) override;
};
}

#endif // STANDARDFIGHT_H
