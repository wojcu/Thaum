#include "fox.h"

#include "Simulation/MoveActions/smartmove.h"
#include "Utility/classcache.h"

namespace Simulation {

Fox::Fox() : Animal("type.Fox") {
    setStrength(3);
    setInitiative(7);
    setMoveAction(QSharedPointer<SmartMove>(new SmartMove()));
    m_color = QVector4D(1.0, 0.8, 0.4, 1.0);
}

CACHEADD(Fox)

}

