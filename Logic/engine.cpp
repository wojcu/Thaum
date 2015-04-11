#include "engine.h"
#include "Graphics/renderwidget.h"
#include <QQmlContext>

#include "inputwidget.h"
#include "clockwidget.h"
#include "clock.h"
#include "Simulation/controlwidget.h"

namespace Logic {
Engine::Engine()
{

    m_renderWidget = nullptr;
    qmlRegisterType<Graphics::RenderWidget>("Thaum", 1, 0, "RenderWidget");
    qmlRegisterType<InputWidget>("Thaum", 1, 0, "InputWidget");
    qmlRegisterType<ClockWidget>("Thaum", 1, 0, "ClockWidget");
    qmlRegisterType<Simulation::ControlWidget>("Thaum", 1, 0, "SimulationControl");
    m_clock.reset(new Clock());
    m_qmlEngine.reset(new QQmlApplicationEngine());
    m_qmlEngine->load(QUrl(QStringLiteral("qrc:/main.qml")));
    m_renderWidget = m_qmlEngine->rootObjects().first()->findChild<Graphics::RenderWidget*>("RenderWidget");
    if (m_renderWidget) {
        m_renderWidget->setClock(m_clock);
        m_renderWidget->setEngine(this);
    }
    m_inputWidget = m_qmlEngine->rootObjects().first()->findChild<InputWidget*>("InputWidget");
    m_clockWidget = m_qmlEngine->rootObjects().first()->findChild<ClockWidget*>("ClockWidget");
    if (m_clockWidget) {
        m_clockWidget->setClock(m_clock);
    }
    m_simControl = m_qmlEngine->rootObjects().first()->findChild<Simulation::ControlWidget*>("ControlWidget");
}

Engine::~Engine()
{
    m_qmlEngine.reset();
}

Graphics::RenderWidget *Engine::renderWidget() const
{
    return m_renderWidget;
}

InputWidget *Engine::inputWidget() const
{
    return m_inputWidget;
}

QSharedPointer<QQmlApplicationEngine> Engine::qmlEngine() const
{
    return m_qmlEngine;
}

Engine::ThrashCan &Engine::thrashCan()
{
    return m_thrash;
}

QSharedPointer<Clock> Engine::clock() const
{
    return m_clock;
}

Simulation::ControlWidget *Engine::simulationControl() const
{
    return m_simControl;
}

}
