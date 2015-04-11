#ifndef TILEINFO_H
#define TILEINFO_H

#include <QPoint>
#include <QSharedPointer>

namespace Simulation {
class Map;
class ObjectInfo;

class TileInfo
{
public:
    TileInfo(const Map &m, const QPoint &pos);
    ~TileInfo();

    QPoint position() const;
    int objectCount() const;
    ObjectInfo objectAt(const int &id) const;
    bool valid() const;

private:
    QPoint m_position;
    const Map &m_map;
};

}

#endif // TILEINFO_H
