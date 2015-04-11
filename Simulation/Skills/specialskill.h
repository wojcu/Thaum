#ifndef SPECIALSKILL_H
#define SPECIALSKILL_H

#include <QSharedPointer>

namespace Simulation {
class Organism;

class SpecialSkill
{
public:
    SpecialSkill();
    virtual ~SpecialSkill();

    virtual void cast(const QSharedPointer<Organism> &org) = 0;
};

}

#endif // SPECIALSKILL_H
