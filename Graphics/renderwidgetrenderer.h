#ifndef RENDERWIDGETRENDERER_H
#define RENDERWIDGETRENDERER_H

#include <QObject>
#include <QOpenGLFunctions>
#include <QSize>
#include <QWeakPointer>
#include <QMutex>

namespace Graphics {
class RenderingObject;
class RenderWidgetRenderer : public QObject, public QOpenGLFunctions
{
    Q_OBJECT
public:
    RenderWidgetRenderer();
    ~RenderWidgetRenderer();

    QSize viewport() const;
    void setViewport(const QSize &viewport);

    bool active() const;
    void setActive(bool active);

    QSharedPointer<RenderingObject> renderingObject() const;
    void setRenderingObject(const QSharedPointer<RenderingObject> &renderingObject);

public slots:
    void onUpdate();

private:
    mutable QMutex m_mutex;
    QSize m_viewport;
    bool m_initialized;
    bool m_active;
    QSharedPointer<RenderingObject> m_renderingObject;
};

}

#endif // RenderWidgetRenderer_H
