#include "human.h"

#include "Simulation/MoveActions/humanmove.h"

namespace Simulation {

Human::Human() : Animal("type.Human") {
    m_humanMove = QSharedPointer<HumanMove>(new HumanMove());
    setMoveAction(m_humanMove);
    setStrength(5);
    setInitiative(4);
    addFlag("type.Human");
    m_color = QVector4D(0.6, 0.4, 0.4, 1.0);
}

QSharedPointer<HumanMove> Human::humanMove() const {
    return m_humanMove;
}

}

