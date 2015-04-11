#include "humanmove.h"

#include "Simulation/humaninput.h"
#include "Simulation/turncontext.h"

namespace Simulation {

HumanMove::HumanMove() {
    m_input = QSharedPointer<HumanInput>(new HumanInput());
}

QPoint HumanMove::nextPosition(TurnContext &ctx) {
    QPoint tgt = ctx.location().position();
    tgt.setX(tgt.x() + m_input->delta().x());
    tgt.setY(tgt.y() + m_input->delta().y());
    m_input->clearDelta();
    return tgt;
}

QSharedPointer<HumanInput> HumanMove::input() const {
    return m_input;
}

}

