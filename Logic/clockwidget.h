#ifndef CLOCKWIDGET_H
#define CLOCKWIDGET_H

#include <QQuickItem>

namespace Logic {
class Clock;
class ClockWidget : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString fps READ fpsString NOTIFY fpsChanged)
public:
    ClockWidget();
    ~ClockWidget();

    void setClock(const QSharedPointer<Clock> &clock);

    Q_INVOKABLE QString timeString() const;
    Q_INVOKABLE QString fpsString() const;

signals:
    void fpsChanged();

private slots:
    void updateFps();

private:
    QWeakPointer<Clock> m_clock;
    QTimer *m_updater;
};

}

#endif // CLOCKWIDGET_H
