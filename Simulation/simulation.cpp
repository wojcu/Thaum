#include "simulation.h"
#include <QDebug>

namespace Simulation {
Simulation::Simulation(const QSize &size)
    : m_map(size), m_updater(m_map) {
    m_updatesPending = 0;
}

void Simulation::step()
{
    if (updateModel() != Automatic) {
        m_updatesPending -= 1;
    }
    m_updater.update();
}

Map &Simulation::map()
{
    return m_map;
}

bool Simulation::updatePending() const
{
    return m_updatesPending != 0;
}

Simulation::UpdateModel Simulation::updateModel() const
{
    return m_updateModel;
}

void Simulation::setUpdateModel(const Simulation::UpdateModel &updateModel)
{
    m_updateModel = updateModel;
    if (updateModel == Automatic) {
        m_updatesPending = 1;
    }
}

void Simulation::playerMoved()
{
    if (updateModel() == WithPlayer) {
        requestUpdate();
    }
}

void Simulation::requestUpdate()
{
    m_updatesPending = 1;
}

void Simulation::setHuman(const QSharedPointer<Human> &human)
{
    m_human = human;
}

QSharedPointer<Human> Simulation::human() const
{
    return m_human.lock();
}

}
