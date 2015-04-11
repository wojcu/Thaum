#include "grass.h"

#include "Simulation/spreadaction.h"

namespace Simulation {

Grass::Grass() {
    setSpreadAction(QSharedPointer<Simulation::TurnAction>(new SpreadAction<Grass>(25, 1)));
    addFlag("type.Grass");
    m_color = QVector4D(0.4, 0.6, 0.4, 1.0);
}

}

