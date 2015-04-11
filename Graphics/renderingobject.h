#ifndef RENDERINGOBJECT_H
#define RENDERINGOBJECT_H

#include <QSize>

namespace Graphics {
class RenderingContext;
class RenderingObject
{
public:
    RenderingObject();
    virtual ~RenderingObject();

    virtual void beforeRender() = 0;
    virtual void render() = 0;
    virtual void afterRender() = 0;
    virtual void viewportChanged(QSize) = 0;
};

}

#endif // RENDERINGOBJECT_H
