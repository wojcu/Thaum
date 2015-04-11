#include "map.h"

#include <QDebug>

#include "Simulation/organism.h"
#include "Simulation/objectinfo.h"

namespace Simulation {
Map::Map(const QSize &size)
{
    m_size = size;
    m_map = new std::vector<QSharedPointer<Organism>>*[size.width()];
    for (int i = 0; i < size.width(); ++i) {
        m_map[i] = new std::vector<QSharedPointer<Organism>>[size.height()];
    }
}

Map::~Map()
{
    for (int i = 0; i < size().width(); ++i) {
        delete[] m_map[i];
    }
    delete[] m_map;
}

QSize Map::size() const
{
    return m_size;
}

QSharedPointer<Organism> Map::organismAt(const MapLocation &loc) const
{
    if (!validPosition(loc.position()))
        return QSharedPointer<Organism>();
    std::vector<QSharedPointer<Organism>> &vec =
            m_map[loc.position().x()][loc.position().y()];
    if (loc.index() >= (int)vec.size() || loc.index() < 0)
        return QSharedPointer<Organism>();
    return vec[loc.index()];
}

int Map::organismsAt(const QPoint &pos) const
{
    if (!validPosition(pos))
        return 0;
    return (int)m_map[pos.x()][pos.y()].size();
}

void Map::spawnOrganism(QSharedPointer<Organism> org, const QPoint &pos)
{
    if (!validPosition(pos))
        return;
    if (!org)
        return;
    int alive = 0;
    TileInfo inf = tileInfo(pos);
    for (int i = 0; i < inf.objectCount(); ++i) {
        if (!inf.objectAt(i).isNull()) {
            if (inf.objectAt(i).alive()) {
                alive++;
            }
        }
    }
    if (alive > 0) {
        qDebug() << "Spawning to collision";
    }
    m_map[pos.x()][pos.y()].push_back(org);
}

QSharedPointer<Organism> Map::despawnOrganism(const MapLocation &loc)
{
    if (!validPosition(loc.position()))
        return QSharedPointer<Organism>();
    std::vector<QSharedPointer<Organism>> &vec =
            m_map[loc.position().x()][loc.position().y()];
    if (loc.index() < 0 || loc.index() >= (int)vec.size())
        return QSharedPointer<Organism>();
    QSharedPointer<Organism> res = vec[loc.index()];
    vec[loc.index()] = QSharedPointer<Organism>();
    return res;
}

TileInfo Map::tileInfo(const QPoint &pos) const
{
    return TileInfo(*this, pos);
}

bool Map::validPosition(const QPoint &pos) const
{
    if (pos.x() < 0 || pos.y() < 0)
        return false;
    if ((pos.x() > size().width() - 1) || (pos.y() > size().height() - 1))
        return false;
    return true;
}

void Map::pruneDead(const QPoint &pos)
{
    if (!validPosition(pos))
        return;
    std::vector<QSharedPointer<Organism>> &vec = m_map[pos.x()][pos.y()];
    for (unsigned int i = 0; i < vec.size(); ++i) {
        if (!vec[i] || vec[i]->dead()) {
            std::swap(vec[i], vec.back());
            vec.pop_back();
            --i;
        }
    }
}

}
