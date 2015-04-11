#include "humaninput.h"

#include "Simulation/simulation.h"

namespace Simulation {

HumanInput::HumanInput() {

}

void HumanInput::keyEvent(QKeyEvent *ev) {
    bool update = true;
    if (ev->type() == QEvent::KeyPress) {
        if (ev->key() == Qt::Key_Left) {
            m_delta.setY(m_delta.y() - 1);
        } else if (ev->key() == Qt::Key_Right) {
            m_delta.setY(m_delta.y() + 1);
        } else if (ev->key() == Qt::Key_Up) {
            m_delta.setX(m_delta.x() + 1);
        } else if (ev->key() == Qt::Key_Down) {
            m_delta.setX(m_delta.x() - 1);
        } else
            update = false;
    } else
        update = false;
    if (update) {
        if (m_simulator)
            m_simulator->playerMoved();
    }
}

void HumanInput::mouseEvent(QMouseEvent *ev) {
    bool update = true;
    if (ev->type() == QEvent::MouseButtonPress) {
        if (ev->button() == Qt::LeftButton) {
            QPoint dx(ev->pos().y() - m_viewport.height() / 2,
                      ev->pos().x() - m_viewport.width() / 2);
            if (std::abs(dx.x()) > std::abs(dx.y())) {
                m_delta.setX(dx.x() < 0 ? 1 : -1);
                m_delta.setY(0);
            } else {
                m_delta.setY(dx.y() < 0 ? -1 : 1);
                m_delta.setX(0);
            }
        } else
            update = false;
    } else
        update = false;
    if (update) {
        if (m_simulator)
            m_simulator->playerMoved();
    }
}

void HumanInput::viewportChanged(const QSize &vp) {
    m_viewport = vp;
}

QPoint HumanInput::delta() const {
    return m_delta;
}

void HumanInput::clearDelta() {
    m_delta = QPoint();
}

void HumanInput::setSimulator(const QSharedPointer<Simulation> &sim) {
    m_simulator = sim;
}

}
