#include "nightshade.h"

#include "Simulation/spreadaction.h"
#include "Simulation/FightActions/nightshadefight.h"

namespace Simulation {

Nightshade::Nightshade() {
    addFlag("type.Nightshade");
    setSpreadAction(QSharedPointer<SpreadAction<Nightshade>>(new SpreadAction<Nightshade>(50, 1)));
    setFightAction(QSharedPointer<NightshadeFight>(new NightshadeFight()));
    m_color = QVector4D(0.8, 0.6, 0.6, 1.0);
    setStrength(99);
}

}
