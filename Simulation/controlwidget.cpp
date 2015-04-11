#include "controlwidget.h"

#include "Simulation/simulation.h"

namespace Simulation {
ControlWidget::ControlWidget()
{
    setObjectName("ControlWidget");
}

ControlWidget::~ControlWidget()
{

}

void ControlWidget::setManual()
{
    if (m_simulation) {
        m_simulation.lock()->setUpdateModel(Simulation::Simulation::Manual);
    }
}

void ControlWidget::setWithPlayer()
{
    if (m_simulation) {
        m_simulation.lock()->setUpdateModel(Simulation::Simulation::WithPlayer);
    }
}

void ControlWidget::setAutomatic()
{
    if (m_simulation) {
        m_simulation.lock()->setUpdateModel(Simulation::Simulation::Automatic);
    }
}

void ControlWidget::requestUpdate()
{
    if (m_simulation) {
        m_simulation.lock()->requestUpdate();
    }
}

void ControlWidget::humanCastSpecial(const int &)
{
    if (m_simulation) {

    }
}

QSharedPointer<Simulation> ControlWidget::simulation() const
{
    return m_simulation.lock();
}

void ControlWidget::setSimulator(const QSharedPointer<Simulation> &simulation)
{
    m_simulation = simulation;
}

}
