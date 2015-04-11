#include "tileinfo.h"

#include "Simulation/map.h"
#include "Simulation/objectinfo.h"

namespace Simulation {
TileInfo::TileInfo(const Map &m, const QPoint &pos)
    : m_map(m){
    m_position = pos;
}

TileInfo::~TileInfo()
{

}

QPoint TileInfo::position() const
{
    return m_position;
}

int TileInfo::objectCount() const
{
    return m_map.organismsAt(m_position);
}

ObjectInfo TileInfo::objectAt(const int &id) const
{
    return ObjectInfo(m_map, MapLocation(position(), id));
}

bool TileInfo::valid() const
{
    return m_map.validPosition(m_position);
}

}
