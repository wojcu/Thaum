#include "renderwidget.h"
#include <QQuickWindow>
#include <QTimer>
#include "renderwidgetrenderer.h"
#include <QDebug>
#include <QQmlProperty>
#include "Logic/clock.h"
#include "Logic/engine.h"
#include "Logic/inputwidget.h"

namespace Graphics {
RenderWidget::RenderWidget()
{
    connect(this, &RenderWidget::windowChanged,
            this, &RenderWidget::onWindowChanged);
    m_refreshRate = 16;
    m_active = false;
    m_timer = QSharedPointer<QTimer>(new QTimer(this));
    m_timer->setSingleShot(false);
    m_timer->setInterval(m_refreshRate);
    connect(m_timer.data(), &QTimer::timeout,
            this, &RenderWidget::onRefresh,
            Qt::DirectConnection);
    m_timer->start();
    m_engine = nullptr;
    setObjectName("RenderWidget");
    m_renderer = QSharedPointer<RenderWidgetRenderer>(new RenderWidgetRenderer());

}

RenderWidget::~RenderWidget()
{

}

void RenderWidget::onWindowChanged(QQuickWindow *wnd)
{
    if (wnd) {
        connect(wnd, &QQuickWindow::beforeSynchronizing,
                this, &RenderWidget::onSync,
                Qt::DirectConnection);
        connect(wnd, &QQuickWindow::sceneGraphInvalidated,
                this, &RenderWidget::onCleanup,
                Qt::DirectConnection);
        connect(window(), &QQuickWindow::beforeRendering,
                m_renderer.data(), &RenderWidgetRenderer::onUpdate,
                Qt::DirectConnection);

        wnd->setClearBeforeRendering(false);
    }
}

void RenderWidget::onRefresh()
{
    if (window()) {
        if (m_clock) {
            m_clock->nextFrame();
        }
        window()->update();
    }
}

void RenderWidget::onSync()
{
    QSize newViewport = window()->size() * window()->devicePixelRatio();
    m_renderer->setViewport(newViewport);
    if (m_engine) {
        if (m_engine->inputWidget()) {
            m_engine->inputWidget()->setViewport(newViewport);
        }
    }
}

void RenderWidget::onCleanup()
{
    if (m_renderer) {
        m_renderer.clear();
    }
}

QSharedPointer<RenderingObject> RenderWidget::renderingObject() const
{
    if (m_renderer) {
        return m_renderer->renderingObject();
    } else {
        return QSharedPointer<RenderingObject>();
    }
}

void RenderWidget::setRenderingObject(const QSharedPointer<RenderingObject> &renderingObject)
{
    m_renderer->setRenderingObject(renderingObject);
}

void RenderWidget::setClock(const QSharedPointer<Logic::Clock> &clock)
{
    m_clock = clock;
}

void RenderWidget::setEngine(Logic::Engine *eng)
{
    m_engine = eng;
}

bool RenderWidget::active() const
{
    return m_active;
}

void RenderWidget::setActive(bool active)
{
    m_active = active;
    if (m_renderer) {
        m_renderer->setActive(active);
    }
    emit activeChanged();
}

int RenderWidget::refreshRate() const
{
    return m_refreshRate;
}

void RenderWidget::setRefreshRate(int refreshRate)
{
    m_refreshRate = refreshRate;
}


}
