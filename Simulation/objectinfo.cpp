#include "objectinfo.h"

#include "Simulation/map.h"
#include "Simulation/organism.h"

namespace Simulation {
ObjectInfo::ObjectInfo(const Map &map, const MapLocation &loc)
    : m_map(map) {
    m_location = loc;
}

ObjectInfo::~ObjectInfo()
{

}

MapLocation ObjectInfo::location() const
{
    return m_location;
}

bool ObjectInfo::isNull() const
{
    return object().isNull();
}

bool ObjectInfo::hasFlag(const std::string &flag) const
{
    if (isNull())
        return false;
    return object()->hasFlag(flag);
}

void ObjectInfo::addFlag(const std::string &flag) const
{
    if (isNull())
        return;
    object()->addFlag(flag);
}

void ObjectInfo::kill()
{
    if (isNull())
        return;
    object()->kill();
}

bool ObjectInfo::alive() const
{
    if (isNull())
        return false;
    return object()->alive();
}

int ObjectInfo::strength() const
{
    if (isNull())
        return 0;
    return object()->strength();
}

void ObjectInfo::setStrength(const int &str)
{
    if (isNull())
        return;
    object()->setStrength(str);
}

int ObjectInfo::initiative() const
{
    if (isNull())
        return false;
    return object()->initiative();
}

QSharedPointer<FightAction> ObjectInfo::fightAction() const
{
    if (isNull())
        return QSharedPointer<FightAction>();
    return object()->fightAction();
}

bool ObjectInfo::updateFinished() const
{
    if (isNull())
        return false;
    return object()->updateFinished();
}

std::string ObjectInfo::allFlags() const
{
    if (isNull())
        return "";
    return object()->allFlags();
}

int ObjectInfo::age() const
{
    if (isNull())
        return 0;
    return object()->age();
}

QSharedPointer<Organism> ObjectInfo::object() const
{
    return m_map.organismAt(location());
}

}
