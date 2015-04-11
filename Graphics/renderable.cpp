#include "renderable.h"

namespace Graphics {
Renderable::Renderable()
{
    m_renderDepth = 0.f;
}

Renderable::~Renderable()
{

}

void Renderable::beforeRendering(RenderingContext &)
{

}

void Renderable::afterRendering(RenderingContext &)
{

}

float Renderable::renderDepth() const
{
    return m_renderDepth;
}

void Renderable::setRenderDepth(const float &depth)
{
    m_renderDepth = depth;
}

}
