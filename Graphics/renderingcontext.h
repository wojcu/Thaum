#ifndef RENDERINGCONTEXT_H
#define RENDERINGCONTEXT_H

#include <QOpenGLFunctions>
#include <QOpenGLContext>
#include <QOpenGLShaderProgram>
#include <QOpenGLShader>
#include <QMatrix4x4>

namespace Graphics {
class SceneRenderer;
class RenderingContext
{
    friend class SceneRenderer;
public:
    RenderingContext();
    ~RenderingContext();

    void initialize();
    bool initialized() const;
    QSize viewport() const;
    float aspect() const;

    QOpenGLShaderProgram *flatShader() const;

private:
    bool m_initialized;
    QOpenGLShaderProgram *m_flatShader;
    QSize m_viewport;
};

}

#endif // RENDERINGCONTEXT_H
