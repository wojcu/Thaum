#ifndef CONTROLWIDGET_H
#define CONTROLWIDGET_H

#include <QQuickItem>
#include "Utility/utility.h"

namespace Simulation {
class Simulation;

class ControlWidget : public QQuickItem
{
    Q_OBJECT
public:
    ControlWidget();
    ~ControlWidget();

    Q_INVOKABLE void setManual();
    Q_INVOKABLE void setWithPlayer();
    Q_INVOKABLE void setAutomatic();
    Q_INVOKABLE void requestUpdate();
    Q_INVOKABLE void humanCastSpecial(const int &);

    QSharedPointer<Simulation> simulation() const;
    void setSimulator(const QSharedPointer<Simulation> &simulation);

private:
    QWeakPointer<Simulation> m_simulation;
};

SHAREDPTRS(ControlWidget)

}

#endif // CONTROLWIDGET_H
