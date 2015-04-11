#include "clock.h"

namespace Logic {
Clock::Clock()
    : m_mutex(QMutex::Recursive) {
    m_time.start();
    m_fps = 0;
    m_framesStored = 0;
    m_frameDelta = 16;
    m_fps = 60;
    m_previousFrame = 0;
}

Clock::~Clock()
{

}

int Clock::elapsed() const
{
    QMutexLocker lock(&m_mutex);
    return m_time.elapsed();
}

int Clock::fps() const
{
    QMutexLocker lock(&m_mutex);
    return m_fps;
}

void Clock::nextFrame()
{
    int time = elapsed();
    QMutexLocker lock(&m_mutex);
    if (m_framesStored == 60) {
        m_fps = (int)(1000.f * ((float)m_framesStored) / ((float)m_frameDelta));
        m_framesStored = 1;
        m_frameDelta = 0;
    } else
        ++m_framesStored;
    m_frameDelta += time - m_previousFrame;
    m_previousFrame = time;
}

}
