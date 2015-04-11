#ifndef TURTLEMOVE_H
#define TURTLEMOVE_H

#include "Simulation/MoveActions/moveaction.h"

namespace Simulation {
class TurtleMove : public MoveAction {
public:
    TurtleMove();

    QPoint nextPosition(TurnContext &ctx) override;
};
}

#endif // TURTLEMOVE_H
