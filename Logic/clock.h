#ifndef CLOCK_H
#define CLOCK_H

#include <QTime>
#include <QMutex>

namespace Logic {
class Clock
{
public:
    Clock();
    ~Clock();

    int elapsed() const;
    int fps() const;
    void nextFrame();

private:
    mutable QMutex m_mutex;
    QTime m_time;
    int m_previousFrame;
    int m_frameDelta;
    int m_fps;
    int m_framesStored;
};

}

#endif // CLOCK_H
