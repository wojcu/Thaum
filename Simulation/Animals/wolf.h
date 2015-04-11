#ifndef WOLF_H
#define WOLF_H

#include <QDebug>

#include "Simulation/Animals/animal.h"

namespace Simulation {
class Wolf : public Animal {
public:
    Wolf();

    ~Wolf() {
        count()--;
        qDebug() << "Wolf removed. Left: " << count();
    }

    static int &count();
};
}

#endif // WOLF_H
