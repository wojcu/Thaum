#include "sheep.h"

#include "Utility/classcache.h"

namespace Simulation {

Sheep::Sheep() : Animal("type.Sheep") {
    setStrength(4);
    setInitiative(4);
    m_color = QVector4D(1.0, 1.0, 1.0, 1.0);
}

CACHEADD(Sheep)

}

