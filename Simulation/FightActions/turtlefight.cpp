#include "turtlefight.h"

#include "Simulation/FightActions/fightcontext.h"
#include "Simulation/Animals/animal.h"
#include "Simulation/MoveActions/moveaction.h"
#include "Simulation/objectinfo.h"

namespace Simulation {

TurtleFight::TurtleFight() {
    setFriendlyFlag("type.Turtle");
}

FightAction::MoveStatus TurtleFight::defend(FightContext &ctx) {
    if (ctx.attacker().hasFlag(friendlyFlag())) {
        breed(ctx);
        return DenyMove;
    }
    if (ctx.attacker().strength() < 20) {
        return DenyMove;
    } else {
        ctx.defender().kill();
        return AllowMove;
    }
}

FightAction::MoveStatus TurtleFight::attack(FightContext &ctx) {
    if (!ctx.defender().fightAction()) {
        ctx.defender().kill();
    }
    return AllowMove;
}

}

