#ifndef MOVEACTION_H
#define MOVEACTION_H

#include <QPoint>

#include "Simulation/turnaction.h"

namespace Simulation {
class MoveAction : public TurnAction {
public:
    MoveAction();

    virtual ~MoveAction();

    void makeTurn(TurnContext &ctx) override;

    virtual QPoint nextPosition(TurnContext &) = 0;

    QPoint previousPosition() const;

    void requestReverse();

    bool success() const;

private:
    QPoint m_previous;
    bool m_initialized;
    bool m_reverseRequest;
    bool m_success;
};

}

#endif // MOVEACTION_H
