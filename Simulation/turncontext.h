#ifndef TURNCONTEXT_H
#define TURNCONTEXT_H

#include <QSharedPointer>
#include <QPoint>

#include "Simulation/maplocation.h"

namespace Simulation {
class Organism;
class Map;
class TileInfo;
class ObjectInfo;

class TurnContext {
public:
    TurnContext(Map &map, const MapLocation &loc);

    MapLocation location() const;
    ObjectInfo objectInfo() const;
    TileInfo tileInfo(const QPoint &pos) const;
    TileInfo objectTileInfo() const;
    bool validPosition(const QPoint &pos);
    void spawn(const QSharedPointer<Organism> &obj, const QPoint &pos);
    void move(const QPoint &pos);

private:
    Map &m_map;
    MapLocation m_location;
};

}

#endif // TURNCONTEXT_H
