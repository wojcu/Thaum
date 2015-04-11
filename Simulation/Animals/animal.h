#ifndef ANIMAL_H
#define ANIMAL_H

#include "Simulation/organism.h"

namespace Simulation {
class MoveAction;

class Animal : public Organism {
public:
    Animal(const std::string &typeFlag);

    void setMoveAction(const QSharedPointer<MoveAction> &action);

    QSharedPointer<MoveAction> moveAction() const;

private:
    QSharedPointer<MoveAction> m_moveAction;
};
}

#endif // ANIMAL_H
