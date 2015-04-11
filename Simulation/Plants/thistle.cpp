#include "thistle.h"

#include "Simulation/spreadaction.h"

namespace Simulation {

Thistle::Thistle() {
    addFlag("type.Thistle");
    setSpreadAction(QSharedPointer<SpreadAction<Thistle>>(new SpreadAction<Thistle>(50, 3)));
    m_color = QVector4D(0.4, 0.4, 0.6, 1.0);
}

}
