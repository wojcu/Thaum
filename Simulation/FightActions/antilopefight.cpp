#include "antilopefight.h"

#include "Simulation/FightActions/fightcontext.h"
#include "Simulation/organism.h"
#include "Simulation/MoveActions/movetofree.h"
#include "Simulation/MoveActions/moveaction.h"
#include "Simulation/turncontext.h"
#include "Simulation/objectinfo.h"

namespace Simulation {

AntilopeFight::AntilopeFight() {
    setFriendlyFlag("type.Antilope");
}

FightAction::MoveStatus AntilopeFight::defend(FightContext &ctx) {
    if (ctx.attacker().hasFlag(friendlyFlag())) {
        breed(ctx);
        return DenyMove;
    }
    if (ctx.defender().strength() < ctx.attacker().strength()) {
        if (rand() % 2 == 0) {
            ctx.defender().kill();
            return AllowMove;
        } else {
            MoveToFree mv;
            TurnContext tctx = ctx.defendersTurn();
            mv.makeTurn(tctx);
            return DenyMove;
            if (!mv.success()) {
                ctx.defender().kill();
                return AllowMove;
            }
        }
    } else if (ctx.defender().strength() > ctx.attacker().strength()) {
        ctx.attacker().kill();
        return DenyMove;
    } else if (rand() % 2 == 0) {
        ctx.defender().kill();
        return AllowMove;
    } else
        ctx.attacker().kill();
    return DenyMove;
}

FightAction::MoveStatus AntilopeFight::attack(FightContext &ctx) {
    if (!ctx.defender().fightAction()) {
        ctx.defender().kill();
    }
    return AllowMove;
}

}

