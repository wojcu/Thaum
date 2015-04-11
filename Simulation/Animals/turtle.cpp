#include "turtle.h"

#include "Simulation/MoveActions/turtlemove.h"
#include "Simulation/FightActions/turtlefight.h"
#include "Utility/classcache.h"

namespace Simulation {

Turtle::Turtle() : Animal("type.Turtle") {
    setStrength(2);
    setInitiative(1);
    setMoveAction(QSharedPointer<TurtleMove>(new TurtleMove()));
    setFightAction(QSharedPointer<TurtleFight>(new TurtleFight()));
    m_color = QVector4D(0.3, 0.5, 0.3, 1.0);
}

CACHEADD(Turtle)

}
