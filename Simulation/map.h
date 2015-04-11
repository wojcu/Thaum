#ifndef MAP_H
#define MAP_H

#include <QSize>
#include <QSharedPointer>
#include <QPoint>

#include "Simulation/maplocation.h"
#include "Simulation/tileinfo.h"

namespace Simulation {
class Organism;
class Map {
public:
    Map(const QSize &size);

    ~Map();

    QSize size() const;

    QSharedPointer<Organism> organismAt(const MapLocation &loc) const;

    int organismsAt(const QPoint &pos) const;

    void spawnOrganism(QSharedPointer<Organism> org, const QPoint &pos);

    QSharedPointer<Organism> despawnOrganism(const MapLocation &loc);

    TileInfo tileInfo(const QPoint &pos) const;

    bool validPosition(const QPoint &pos) const;

    void pruneDead(const QPoint &pos);

private:
    std::vector<QSharedPointer<Organism>> **m_map;
    QSize m_size;
};

}

#endif // MAP_H
