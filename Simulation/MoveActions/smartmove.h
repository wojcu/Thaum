#ifndef SMARTMOVE_H
#define SMARTMOVE_H

#include "moveaction.h"

namespace Simulation {
class SmartMove : public MoveAction {
public:
    SmartMove();

    QPoint nextPosition(Simulation::TurnContext &ctx) override;
};
}

#endif // SMARTMOVE_H
