#include "guaranafight.h"

#include "Simulation/FightActions/fightcontext.h"
#include "Simulation/objectinfo.h"

namespace Simulation {

GuaranaFight::GuaranaFight() {

}

FightAction::MoveStatus GuaranaFight::defend(FightContext &ctx) {
    ctx.attacker().setStrength(ctx.attacker().strength() + 3);
    ctx.defender().kill();
    return AllowMove;
}

FightAction::MoveStatus GuaranaFight::attack(FightContext &) {
    return AllowMove;
}

}

