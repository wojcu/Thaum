#include "clockwidget.h"

#include "clock.h"
#include <QTimer>

namespace Logic {
ClockWidget::ClockWidget()
{
    setObjectName("ClockWidget");
    m_updater = new QTimer(this);
    m_updater->setSingleShot(false);
    m_updater->setInterval(1000);
    connect(m_updater, &QTimer::timeout,
            this, &ClockWidget::updateFps);
    m_updater->start();
}

ClockWidget::~ClockWidget()
{

}

void ClockWidget::setClock(const QSharedPointer<Clock> &clock)
{
    m_clock = clock;
}

QString ClockWidget::timeString() const
{
    int time = 0;
    if (m_clock)
        time = m_clock.lock()->elapsed();
    int secs = time / 1000;
    int mins = secs / 60;
    int hours = mins / 60;
    secs %= 60;
    mins %= 60;
    hours %= 60;

    return QString("%0:%1:%2").arg(hours).arg(mins).arg(secs);
}

QString ClockWidget::fpsString() const
{
    int fps = 0;
    if (m_clock)
        fps = m_clock.lock()->fps();
    return QString("%0").arg(fps);
}

void ClockWidget::updateFps()
{
    emit fpsChanged();
}

}
