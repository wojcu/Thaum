#ifndef SIMULATION_H
#define SIMULATION_H

#include <QSize>

#include "objectupdater.h"
#include "map.h"
#include "Utility/utility.h"

namespace Simulation {
class Human;

class Simulation {
public:
    enum UpdateModel {Automatic, WithPlayer, Manual};

    Simulation(const QSize &size);

    static QSharedPointer<Simulation> newSharedSimulation(const QSize &size) {
        return QSharedPointer<Simulation>(new Simulation(size));
    }

    void step();
    Map &map();
    bool updatePending() const;
    UpdateModel updateModel() const;
    void setUpdateModel(const UpdateModel &updateModel);
    void playerMoved();
    void requestUpdate();
    void setHuman(const QSharedPointer<Human> &human);
    QSharedPointer<Human> human() const;

private:
    Map m_map;
    ObjectUpdater m_updater;
    UpdateModel m_updateModel;
    int m_updatesPending;
    QWeakPointer<Human> m_human;
};

SHAREDPTRS(Simulation)

}

#endif // SIMULATION_H
