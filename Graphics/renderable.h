#ifndef RENDERABLE_H
#define RENDERABLE_H


namespace Graphics {
class RenderingContext;
class Renderable
{
public:
    Renderable();
    virtual ~Renderable();

    virtual void beforeRendering(RenderingContext &);

    virtual void render(RenderingContext &) = 0;

    virtual void afterRendering(RenderingContext &);

    float renderDepth() const;

    void setRenderDepth(const float &depth);

private:
    float m_renderDepth;
};

}

#endif // RENDERABLE_H
