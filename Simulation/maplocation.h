#ifndef MAPLOCATION_H
#define MAPLOCATION_H

#include <QPoint>

namespace Simulation {
class MapLocation
{
public:
    MapLocation(const QPoint &pos = QPoint(), const int &index = 0);
    ~MapLocation();

    QPoint position() const;
    int index() const;

private:
    QPoint m_position;
    int m_index;
};

}

#endif // MAPLOCATION_H
