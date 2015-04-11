#include "animal.h"

#include "Simulation/MoveActions/simplemove.h"
#include "Simulation/FightActions/standardfight.h"

namespace Simulation {
Animal::Animal(const std::string &typeFlag) {
    addFlag(typeFlag);
    addFlag("type.Animal");
    setMoveAction(QSharedPointer<SimpleMove>(new SimpleMove()));
    setFightAction(QSharedPointer<StandardFight>(new StandardFight(typeFlag)));
}

void Animal::setMoveAction(const QSharedPointer<MoveAction> &action) {
    if (m_moveAction) {
        m_moveAction->kill();
    }
    addTurnAction(action);
    m_moveAction = action;
}

QSharedPointer<MoveAction> Animal::moveAction() const {
    return m_moveAction;
}

}

