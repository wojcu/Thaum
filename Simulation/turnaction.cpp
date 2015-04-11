#include "turnaction.h"

namespace Simulation {
TurnAction::TurnAction() {
    m_state = Enabled;
}

TurnAction::~TurnAction()
{

}

TurnAction::State TurnAction::state() const {
    return m_state;
}

void TurnAction::kill() {
    m_state = Expired;
}

void TurnAction::enable() {
    if (state() != Expired)
        m_state = Enabled;
}

void TurnAction::disable() {
    if (state() != Expired)
        m_state = Disabled;
}

bool TurnAction::expired() const {
    return state() == Expired;
}

bool TurnAction::enabled() const {
    return state() == Enabled;
}

}
