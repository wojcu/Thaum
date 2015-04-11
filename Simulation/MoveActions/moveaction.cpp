#include "moveaction.h"

#include <QDebug>

#include "Simulation/turncontext.h"
#include "Simulation/map.h"

namespace Simulation {
MoveAction::MoveAction() {
    m_initialized = false;
    m_reverseRequest = false;
    m_success = true;
}

MoveAction::~MoveAction() {

}

void MoveAction::makeTurn(TurnContext &ctx) {
    if (!m_initialized) {
        m_previous = ctx.location().position();
        m_initialized = true;
    }
    QPoint tgt;
    if (m_reverseRequest) {
        m_reverseRequest = false;
        tgt = m_previous;
    } else {
        tgt = nextPosition(ctx);
        if (tgt == ctx.location().position()) {
            m_previous = tgt;
            m_success = false;
            return;
        }
    }
    if (ctx.validPosition(tgt)) {
        m_previous = ctx.location().position();
        m_success = true;
        ctx.move(tgt);
    }
}

QPoint MoveAction::previousPosition() const
{
    return m_previous;
}

void MoveAction::requestReverse() {
    m_reverseRequest = true;
}

bool MoveAction::success() const
{
    return m_success;
}

}
