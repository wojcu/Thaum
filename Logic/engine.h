#ifndef ENGINE_H
#define ENGINE_H

#include <QQmlApplicationEngine>
#include "Utility/utility.h"

namespace Graphics {
class RenderWidget;
class RenderingObject;
}

namespace Simulation {
class ControlWidget;
}

namespace Logic {
class InputWidget;
class Clock;
class ClockWidget;

class Engine
{
    class AnyBase {
    public:
        AnyBase() {

        }

        virtual ~AnyBase() {

        }

        virtual void destroy() = 0;
    };

    template<typename T>
    class Any : public AnyBase {
    public:
        Any(const T &ptr) {
            obj = new T(ptr);
        }

        void destroy() {
            delete obj;
        }

    private:
        T *obj;
    };

    class ThrashCan {
    public:
        ThrashCan() {

        }

        ~ThrashCan() {
            clear();
        }

        template<typename T>
        void queue(const T &obj) {
            m_objects.push_back(new Any<T>(obj));
        }

        void clear() {
            for (AnyBase *obj : m_objects) {
                obj->destroy();
                delete obj;
            }
            m_objects.clear();
        }

    private:
        std::vector<AnyBase*> m_objects;
    };

public:
    Engine();
    ~Engine();

    SHAREDCONSTRUCTOR(Engine)

    void initialize();
    Graphics::RenderWidget *renderWidget() const;
    InputWidget *inputWidget() const;
    QSharedPointer<QQmlApplicationEngine> qmlEngine() const;
    ThrashCan &thrashCan();
    QSharedPointer<Clock> clock() const;
    Simulation::ControlWidget *simulationControl() const;

private:
    QSharedPointer<QQmlApplicationEngine> m_qmlEngine;
    QSharedPointer<Clock> m_clock;
    Graphics::RenderWidget *m_renderWidget;
    ClockWidget *m_clockWidget;
    InputWidget *m_inputWidget;
    ThrashCan m_thrash;
    Simulation::ControlWidget *m_simControl;
};

SHAREDPTRS(Engine)


}

#endif // ENGINE_H
