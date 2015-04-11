#ifndef HUMANMOVE_H
#define HUMANMOVE_H

#include <QSharedPointer>

#include "Simulation/MoveActions/moveaction.h"

namespace Simulation {
class HumanInput;

class HumanMove : public MoveAction {
public:
    HumanMove();

    QPoint nextPosition(TurnContext &ctx) override;

    QSharedPointer<HumanInput> input() const;

private:
    QSharedPointer<HumanInput> m_input;
};

}

#endif // HUMANMOVE_H
