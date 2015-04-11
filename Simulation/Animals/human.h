#ifndef HUMAN_H
#define HUMAN_H

#include "Simulation/Animals/animal.h"

namespace Simulation {
class HumanMove;

class Human : public Animal {
public:
    Human();

    QSharedPointer<HumanMove> humanMove() const;

private:
    QSharedPointer<HumanMove> m_humanMove;
};
}

#endif // HUMAN_H
