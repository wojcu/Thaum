#ifndef HUMANINPUT_H
#define HUMANINPUT_H

#include <QSharedPointer>

#include "Logic/inputtarget.h"

namespace Simulation {
class Simulation;

class HumanInput : public Logic::InputTarget {
public:
    HumanInput();

    void keyEvent(QKeyEvent *ev) override;

    void mouseEvent(QMouseEvent *ev) override;

    void viewportChanged(const QSize &vp) override;

    QPoint delta() const;

    void clearDelta();

    void setSimulator(const QSharedPointer<Simulation> &sim);

private:
    QPoint m_delta;
    QSize m_viewport;
    QSharedPointer<Simulation> m_simulator;
};
}

#endif // HUMANINPUT_H
