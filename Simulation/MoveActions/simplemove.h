#ifndef SIMPLEMOVE_H
#define SIMPLEMOVE_H

#include <QPoint>

#include "Simulation/MoveActions/moveaction.h"

namespace Simulation {
class TurnContext;

class SimpleMove : public MoveAction {
public:
    SimpleMove();

    QPoint nextPosition(TurnContext &ctx) override;
};

}

#endif // SIMPLEMOVE_H
