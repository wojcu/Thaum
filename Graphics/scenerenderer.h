#ifndef SCENERENDERER_H
#define SCENERENDERER_H

#include <QSize>
#include <QMutex>
#include <QSharedPointer>
#include <QVector>

#include "renderingobject.h"
#include "renderingcontext.h"
#include "Utility/utility.h"

namespace Graphics {
class Renderable;

class SceneRenderer : public RenderingObject
{
    class RenderableCmp {
    public:
        inline RenderableCmp() {

        }

        bool operator() (const QWeakPointer<Graphics::Renderable> &a,
                         const QWeakPointer<Graphics::Renderable> &b) const;
    };

public:
    SceneRenderer();
    ~SceneRenderer();

    SHAREDCONSTRUCTOR(SceneRenderer)

    void beforeRender() override;
    void render() override;
    void afterRender() override;
    void viewportChanged(QSize vp) override;

    void addRenderable(QSharedPointer<Graphics::Renderable> obj);

    QSize viewport() const;

private:
    void prepareRenerables();

    mutable QMutex m_mutex;
    QSize m_viewport;
    RenderingContext m_context;
    QVector<QWeakPointer<Graphics::Renderable>> m_renderables;
};

SHAREDPTRS(SceneRenderer)

}

#endif // SCENERENDERER_H
