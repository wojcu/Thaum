#ifndef RENDERER_H
#define RENDERER_H

#include <QVector4D>
#include <QVector2D>
#include <QVector>

#include "Utility/utility.h"
#include "Graphics/renderable.h"

namespace Simulation {
class Simulation;

class Renderer: public Graphics::Renderable {
public:
    Renderer();

    ~Renderer();

    SHAREDCONSTRUCTOR(Renderer)

    void beforeRendering(Graphics::RenderingContext &) override;

    void render(Graphics::RenderingContext &cont) override;

    QSharedPointer<Simulation> simulation() const;

    void setSimulation(const QSharedPointer<Simulation> &sim);

private:
    bool m_initialized;
    QVector<QVector2D> m_vertices;
    QVector<QVector4D> m_colors;
    QSharedPointer<Simulation> m_simulation;
};

SHAREDPTRS(Renderer)
}

#endif // RENDERER_H
