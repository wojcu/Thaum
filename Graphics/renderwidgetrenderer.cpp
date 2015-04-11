#include "renderwidgetrenderer.h"
#include <QDebug>

#include "renderingobject.h"

namespace Graphics {
RenderWidgetRenderer::RenderWidgetRenderer()
    : QObject(nullptr), m_mutex(QMutex::Recursive) {
    m_initialized = false;
    m_active = false;
}

RenderWidgetRenderer::~RenderWidgetRenderer()
{

}

void RenderWidgetRenderer::onUpdate()
{
    QMutexLocker lock(&m_mutex);
    if (!active()) {
        return;
    }
    if (!m_initialized) {
        initializeOpenGLFunctions();
        m_initialized = true;
    }

    glViewport(0, 0, m_viewport.width(), m_viewport.height());
    //glClearDepthf(1.0);
    //glDepthFunc(GL_LEQUAL);
    //glEnable(GL_DEPTH_TEST);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glDisable(GL_DEPTH_TEST);
    glClearColor(0.2, 0.2, 0.2, 1.0);
    //glCullFace(GL_BACK);
    glClear(GL_COLOR_BUFFER_BIT);

    if (!m_renderingObject.isNull()) {
        m_renderingObject->beforeRender();
        m_renderingObject->render();
        m_renderingObject->afterRender();
    }
}

QSharedPointer<RenderingObject> RenderWidgetRenderer::renderingObject() const
{
    QMutexLocker lock(&m_mutex);
    return m_renderingObject;
}

void RenderWidgetRenderer::setRenderingObject(const QSharedPointer<RenderingObject> &renderingObject)
{
    QMutexLocker lock(&m_mutex);
    m_renderingObject = renderingObject;
    if (!m_renderingObject.isNull()) {
        m_renderingObject->viewportChanged(m_viewport);
    }
}

bool RenderWidgetRenderer::active() const
{
    QMutexLocker lock(&m_mutex);
    return m_active;
}

void RenderWidgetRenderer::setActive(bool active)
{
    QMutexLocker lock(&m_mutex);
    m_active = active;
}

QSize RenderWidgetRenderer::viewport() const
{
    QMutexLocker lock(&m_mutex);
    return m_viewport;
}

void RenderWidgetRenderer::setViewport(const QSize &viewport)
{
    QMutexLocker lock(&m_mutex);
    m_viewport = viewport;
    if (!m_renderingObject.isNull()) {
        m_renderingObject->viewportChanged(viewport);
    }
}


}
