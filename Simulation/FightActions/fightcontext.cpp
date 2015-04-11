#include "fightcontext.h"

#include "Simulation/map.h"
#include "Simulation/turncontext.h"
#include "Simulation/objectinfo.h"

namespace Simulation {
FightContext::FightContext(Map &map, const MapLocation &locA, const MapLocation &locB)
    : m_map(map) {
    m_locationA = locA;
    m_locationB = locB;
}

FightContext::~FightContext()
{

}

ObjectInfo FightContext::attacker() const
{
    return ObjectInfo(m_map, m_locationA);
}

ObjectInfo FightContext::defender() const
{
    return ObjectInfo(m_map, m_locationB);
}

TileInfo FightContext::attackersTile() const
{
    return m_map.tileInfo(m_locationA.position());
}

TileInfo FightContext::defendersTile() const
{
    return m_map.tileInfo(m_locationB.position());
}

TurnContext FightContext::attackersTurn() const
{
    return TurnContext(m_map, m_locationA);
}

TurnContext FightContext::defendersTurn() const
{
    return TurnContext(m_map, m_locationB);
}

}
