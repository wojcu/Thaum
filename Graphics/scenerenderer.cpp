#include "scenerenderer.h"

#include "Graphics/renderable.h"
#include <cassert>

namespace Graphics {
SceneRenderer::SceneRenderer()
    : m_mutex(QMutex::Recursive) {

}

SceneRenderer::~SceneRenderer()
{

}

void SceneRenderer::beforeRender()
{
    QMutexLocker lock(&m_mutex);
    if (!m_context.initialized()) {
        m_context.initialize();
    }
    for (QWeakPointer<Renderable> r : m_renderables) {
        if (!r.isNull()) {
            r.lock()->beforeRendering(m_context);
        }
    }
    prepareRenerables();
}

void SceneRenderer::render()
{
    QMutexLocker lock(&m_mutex);
    for (QWeakPointer<Renderable> r : m_renderables) {
        assert(!r.isNull());
        r.lock()->render(m_context);
    }
}

void SceneRenderer::afterRender()
{
    QMutexLocker lock(&m_mutex);
    for (QWeakPointer<Renderable> r : m_renderables) {
        assert(!r.isNull());
        r.lock()->afterRendering(m_context);
    }
}

void SceneRenderer::viewportChanged(QSize vp)
{
    QMutexLocker lock(&m_mutex);
    m_viewport = vp;
    m_context.m_viewport = vp;
}

void SceneRenderer::addRenderable(QSharedPointer<Graphics::Renderable> obj)
{
    QMutexLocker lock(&m_mutex);
    m_renderables.push_back(obj);
}

QSize SceneRenderer::viewport() const
{
    QMutexLocker lock(&m_mutex);
    return m_viewport;
}

void SceneRenderer::prepareRenerables()
{
    QMutexLocker lock(&m_mutex);
    for (int i = 0; i < m_renderables.size(); ++i) {
        if (m_renderables[i].isNull()) {
            std::swap(m_renderables.back(), m_renderables[i]);
            m_renderables.pop_back();
            --i;
        }
    }
    qSort(m_renderables.begin(), m_renderables.end(), RenderableCmp());
}

bool SceneRenderer::RenderableCmp::operator()(const QWeakPointer<Graphics::Renderable> &a,
                                              const QWeakPointer<Graphics::Renderable> &b) const
{
    assert(!a.isNull() && !b.isNull());
    if (a.lock()->renderDepth() < b.lock()->renderDepth())
        return true;
    if (a.lock()->renderDepth() > b.lock()->renderDepth())
        return false;
    return true;
}

}
