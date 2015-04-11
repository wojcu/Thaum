#ifndef FIGHTCONTEXT_H
#define FIGHTCONTEXT_H

#include <memory>
#include <QPoint>
#include <QSharedPointer>

#include "Simulation/maplocation.h"

namespace Simulation {
class ObjectInfo;
class Map;
class TurnContext;
class TileInfo;

class FightContext {
public:
    FightContext(Map &map, const MapLocation &locA = MapLocation(),
                 const MapLocation &locB = MapLocation());
    ~FightContext();

    ObjectInfo attacker() const;
    ObjectInfo defender() const;

    TileInfo attackersTile() const;
    TileInfo defendersTile() const;

    TurnContext attackersTurn() const;
    TurnContext defendersTurn() const;

private:
    MapLocation m_locationA;
    MapLocation m_locationB;
    Map &m_map;
};

}

#endif // FIGHTCONTEXT_H
