#include "maplocation.h"

namespace Simulation {
MapLocation::MapLocation(const QPoint &pos, const int &index)
{
    m_position = pos;
    m_index = index;
}

MapLocation::~MapLocation()
{

}

QPoint MapLocation::position() const
{
    return m_position;
}

int MapLocation::index() const
{
    return m_index;
}

}
