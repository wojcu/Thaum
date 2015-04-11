#ifndef OBJECTUPDATER_H
#define OBJECTUPDATER_H

#include <QPoint>

namespace Simulation {
class Map;
class MapLocation;
class TurnContext;

class ObjectUpdater {
public:
    ObjectUpdater(Map &map);
    ~ObjectUpdater();

    void update();

private:
    Map &map();
    void updateObject(const MapLocation &);
    void queueObjects();

    std::vector<MapLocation> m_updateQueue;
    Map &m_map;
};

}

#endif // OBJECTUPDATER_H
