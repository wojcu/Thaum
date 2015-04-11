#include "antilope.h"

#include "Simulation/FightActions/antilopefight.h"
#include "Simulation/MoveActions/antilopemove.h"
#include "Utility/classcache.h"

namespace Simulation {

Antilope::Antilope() : Animal("type.Antilope") {
    setStrength(4);
    setInitiative(4);
    setMoveAction(QSharedPointer<AntilopeMove>(new AntilopeMove()));
    setFightAction(QSharedPointer<AntilopeFight>(new AntilopeFight()));
    m_color = QVector4D(0.3, 0.2, 0.1, 1.0);
}

CACHEADD(Antilope)

}

