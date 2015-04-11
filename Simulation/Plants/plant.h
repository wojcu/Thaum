#ifndef PLANT_H
#define PLANT_H

#include <memory>

#include "Simulation/organism.h"

namespace Simulation {
class TurnAction;

class Plant : public Organism {
public:
    Plant();

    void setSpreadAction(const QSharedPointer<TurnAction> &action);

    QSharedPointer<TurnAction> spreadAction() const;

private:
    QSharedPointer<TurnAction> m_spreadAction;
};
}

#endif // PLANT_H
