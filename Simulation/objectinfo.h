#ifndef OBJECTINFO_H
#define OBJECTINFO_H

#include <QSharedPointer>
#include "maplocation.h"

namespace Simulation {
class Organism;
class Map;
class FightAction;

class ObjectInfo
{
public:
    ObjectInfo(const Map &map, const MapLocation &loc);
    ~ObjectInfo();

    MapLocation location() const;
    bool isNull() const;
    bool hasFlag(const std::string &flag) const;
    void addFlag(const std::string &flag) const;
    void kill();
    bool alive() const;
    int strength() const;
    void setStrength(const int &str);
    int initiative() const;
    QSharedPointer<FightAction> fightAction() const;
    bool updateFinished() const;
    std::string allFlags() const;
    int age() const;

private:
    QSharedPointer<Organism> object() const;
    const Map &m_map;
    MapLocation m_location;
};

}

#endif // OBJECTINFO_H
