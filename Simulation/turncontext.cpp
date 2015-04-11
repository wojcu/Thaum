#include "turncontext.h"

#include <QDebug>

#include "Simulation/map.h"
#include "Simulation/tileinfo.h"
#include "Simulation/objectinfo.h"
#include "Simulation/FightActions/fightcontext.h"
#include "Simulation/FightActions/fightaction.h"

namespace Simulation {
TurnContext::TurnContext(Map &map, const MapLocation &loc)
    : m_map(map) {
    m_location = loc;
}

MapLocation TurnContext::location() const
{
    return m_location;
}

ObjectInfo TurnContext::objectInfo() const
{
    return ObjectInfo(m_map, m_location);
}

TileInfo TurnContext::tileInfo(const QPoint &pos) const
{
    return m_map.tileInfo(pos);
}

TileInfo TurnContext::objectTileInfo() const
{
    return tileInfo(location().position());
}

bool TurnContext::validPosition(const QPoint &pos)
{
    return m_map.validPosition(pos);
}

void TurnContext::spawn(const QSharedPointer<Organism> &obj, const QPoint &pos)
{
    m_map.spawnOrganism(obj, pos);
}

void TurnContext::move(const QPoint &pos)
{
    if (!m_map.validPosition(pos)) {
        //qDebug() << "Position invalid, move canceled.";
        return;
    }
    TileInfo tinfo(m_map, pos);
    bool canMove = true;
    for (int i = 0; i < tinfo.objectCount(); i++) {
        if (!tinfo.objectAt(i).isNull()) {
            FightContext ctx(m_map, location(), MapLocation(pos, i));
            if (ctx.attacker().fightAction() && ctx.attacker().alive()) {
                canMove = canMove && (ctx.attacker().fightAction()->attack(ctx) == FightAction::AllowMove);
            }
            if (ctx.defender().fightAction() && ctx.defender().alive()) {
                canMove = canMove && (ctx.defender().fightAction()->defend(ctx) == FightAction::AllowMove);
            }
        }
    }
    if (canMove) {
        m_map.spawnOrganism(m_map.despawnOrganism(location()), pos);
        m_location = MapLocation(pos, m_map.organismsAt(pos) - 1);
        //qDebug() << "Moving object.";
    } else {
        //qDebug() << "Move denied.";
    }
}

}
