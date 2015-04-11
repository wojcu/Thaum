#include "nightshadefight.h"

#include "Simulation/FightActions/fightcontext.h"
#include "Simulation/objectinfo.h"

namespace Simulation {

NightshadeFight::NightshadeFight() {

}

FightAction::MoveStatus NightshadeFight::defend(FightContext &ctx) {
    ctx.attacker().kill();
    ctx.defender().kill();
    return DenyMove;
}

FightAction::MoveStatus NightshadeFight::attack(FightContext &) {
    return AllowMove;
}

}

