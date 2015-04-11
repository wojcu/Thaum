#include "renderingcontext.h"

namespace Graphics {
RenderingContext::RenderingContext()
{
    m_initialized = false;
    m_flatShader = nullptr;
}

RenderingContext::~RenderingContext()
{
    if (m_flatShader) {
        delete m_flatShader;
    }
}

void RenderingContext::initialize()
{
    m_flatShader = new QOpenGLShaderProgram();
    m_flatShader->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/GLSL/flat.vsh");
    m_flatShader->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/GLSL/flat.fsh");
    m_flatShader->link();
    m_initialized = true;
}

bool RenderingContext::initialized() const
{
    return m_initialized;
}

float RenderingContext::aspect() const
{
    return static_cast<float>(m_viewport.width()) / static_cast<float>(m_viewport.height());
}

QSize RenderingContext::viewport() const
{
    return m_viewport;
}

QOpenGLShaderProgram *RenderingContext::flatShader() const
{
    return m_flatShader;
}

}
