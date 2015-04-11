#include "wolf.h"

#include "Utility/classcache.h"
#include "Simulation/reportaction.h"

namespace Simulation {

Wolf::Wolf() : Animal("type.Wolf") {
    setStrength(9);
    setInitiative(5);
    addDeathAction(QSharedPointer<ReportAction>(new ReportAction("Wolf dead")));
    m_color = QVector4D(0.3, 0.3, 0.3, 1.0);
    count()++;
}

int &Simulation::Wolf::count()
{
    static int m_count = 0;
    return m_count;
}

CACHEADD(Wolf)

}
