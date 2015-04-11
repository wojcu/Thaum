#include "plant.h"

#include "Simulation/turnaction.h"

namespace Simulation {

Plant::Plant() {
    addFlag("type.Plant");
    setInitiative(0);
    setStrength(0);
}

void Plant::setSpreadAction(const QSharedPointer<Simulation::TurnAction> &action) {
    if (m_spreadAction) {
        m_spreadAction->kill();
    }
    addTurnAction(action);
    m_spreadAction = action;
}

QSharedPointer<Simulation::TurnAction> Plant::spreadAction() const {
    return m_spreadAction;
}

}

