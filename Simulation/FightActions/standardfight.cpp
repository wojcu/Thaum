#include "standardfight.h"

#include "Simulation/FightActions/fightcontext.h"
#include "Simulation/objectinfo.h"
#include "Simulation/MoveActions/movetofree.h"
#include "Simulation/map.h"

#include "Utility/classcache.h"

namespace Simulation {

StandardFight::StandardFight(const std::string &str) {
    setFriendlyFlag(str);
}

FightAction::MoveStatus StandardFight::defend(FightContext &ctx) {
    if (ctx.attacker().hasFlag(friendlyFlag())) {
        breed(ctx);
        return DenyMove;
    }
    if (ctx.defender().strength() < ctx.attacker().strength()) {
        ctx.defender().kill();
        return AllowMove;
    } else if(ctx.defender().strength() > ctx.attacker().strength()) {
        ctx.attacker().kill();
        return DenyMove;
    } else {
        if (rand() % 2 == 0) {
            ctx.attacker().kill();
            return DenyMove;
        } else {
            ctx.defender().kill();
            return AllowMove;
        }
    }
}

FightAction::MoveStatus StandardFight::attack(FightContext &ctx) {
    if (!ctx.defender().fightAction()) {
        ctx.defender().kill();
    }
    return AllowMove;
}

}

