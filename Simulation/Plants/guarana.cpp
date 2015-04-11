#include "guarana.h"

#include "Simulation/spreadaction.h"
#include "Simulation/FightActions/guaranafight.h"

namespace Simulation {

Guarana::Guarana() {
    addFlag("type.Guarana");
    setSpreadAction(QSharedPointer<SpreadAction<Guarana>>(new SpreadAction<Guarana>(50, 1)));
    setFightAction(QSharedPointer<GuaranaFight>(new GuaranaFight()));
    m_color = QVector4D(0.6, 0.4, 0.6, 1.0);
}

}
