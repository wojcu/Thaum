#include "objectupdater.h"

#include <QDebug>

#include "Simulation/map.h"
#include "Simulation/organism.h"
#include "FightActions/fightcontext.h"
#include "FightActions/fightaction.h"
#include "Simulation/turncontext.h"

namespace Simulation {
ObjectUpdater::ObjectUpdater(Map &map)
    : m_map(map) {

}

void ObjectUpdater::update()
{
    queueObjects();
    for (MapLocation &loc : m_updateQueue) {
        updateObject(loc);
    }
    m_updateQueue.clear();
}

Map &ObjectUpdater::map()
{
    return m_map;
}

void ObjectUpdater::updateObject(const MapLocation &loc)
{
    if (!m_map.validPosition(loc.position()))
        return;
    TurnContext ctx(m_map, loc);
    if (m_map.organismAt(loc))
        m_map.organismAt(loc)->makeTurn(ctx);
}

void ObjectUpdater::queueObjects()
{
    m_updateQueue.clear();
    for (int i = 0; i < map().size().width(); ++i) {
        for (int j  = 0; j < map().size().height(); ++j) {
            QPoint pos(i, j);
            map().pruneDead(pos);
            for (int k = 0; k < map().organismsAt(pos); ++k) {
                MapLocation loc(pos, k);
                if (map().organismAt(loc)) {
                    map().organismAt(loc)->setUpdateFinished(false);
                    m_updateQueue.push_back(loc);
                }
            }
        }
    }

    /*qDebug() << "Sort begin";
    std::sort(m_updateQueue.begin(), m_updateQueue.end(),
              [this](const MapLocation &a, const MapLocation &b) -> bool {
        Organism *oa = map().organismAt(a).data();
        Organism *ob = map().organismAt(b).data();
        if (!oa || !ob)
            qDebug() << "Miss";
        if (oa->initiative() > ob->initiative()) {
            return true;
        } else if (oa->initiative() < ob->initiative()) {
            return false;
        } else if (oa->age() > ob->age()) {
            return true;
        } else if (oa->age() < ob->age()) {
            return false;
        } else return rand() % 2;
    });
    qDebug() << "Sort end";*/
}

ObjectUpdater::~ObjectUpdater()
{

}

}
