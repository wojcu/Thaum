#ifndef MOVETOFREE_H
#define MOVETOFREE_H

#include "Simulation/MoveActions/moveaction.h"

namespace Simulation {
class MoveToFree : public MoveAction {
public:
    MoveToFree();

    QPoint nextPosition(TurnContext &ctx) override;
};
}

#endif // MOVETOFREE_H
