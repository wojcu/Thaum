#ifndef ANTILOPEMOVE_H
#define ANTILOPEMOVE_H

#include "moveaction.h"

namespace Simulation {
class AntilopeMove : public MoveAction {
public:
    AntilopeMove();

    QPoint nextPosition(TurnContext & ctx) override;
};
}

#endif // ANTILOPEMOVE_H
