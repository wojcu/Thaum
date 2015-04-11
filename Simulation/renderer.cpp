#include "renderer.h"

#include <QOpenGLShaderProgram>

#include "Graphics/renderingcontext.h"
#include "Simulation/simulation.h"
#include "Simulation/organism.h"
#include "Simulation/map.h"

namespace Simulation {
Renderer::Renderer() {
    setRenderDepth(10.f);
    m_initialized = false;
}

Renderer::~Renderer()
{

}

void Renderer::beforeRendering(Graphics::RenderingContext &) {
    if (!m_simulation)
        return;
    if (!m_initialized) {
        m_vertices.clear();
        QSize mSize = m_simulation->map().size();
        for (int i = -mSize.width() / 2; i < mSize.width() / 2; ++i) {
            for (int j = -mSize.height() / 2; j < mSize.height() / 2; ++j) {
                m_vertices.push_back(QVector2D(i, j));
                m_vertices.push_back(QVector2D(i, j+1));
                m_vertices.push_back(QVector2D(i+1, j+1));
                m_vertices.push_back(QVector2D(i, j));
                m_vertices.push_back(QVector2D(i+1, j+1));
                m_vertices.push_back(QVector2D(i+1, j));
                for (int k = 0; k < 6; ++k) {
                    m_colors.push_back(QVector4D(0.7f, 0.5f, 0.4f, 1.f));
                }
            }
        }
        m_initialized = true;
    }

    if (m_simulation->updatePending()) {
        m_simulation->step();
    }

    for (int i = 0; i < m_simulation->map().size().width(); ++i) {
        for (int j = 0; j < m_simulation->map().size().height(); ++j) {
            QPoint pos(i, j);
            int beg = 6 * (j * m_simulation->map().size().width() + i);
            QVector4D col = QVector4D(0.7f, 0.5f, 0.4f, 1.f);
            if (m_simulation->map().organismsAt(pos) > 0) {
                col = QVector4D(0.f, 0.f, 0.f, 0.f);
                int count = 0;
                int alive = 0;
                for (int k = 0; k < m_simulation->map().organismsAt(pos); ++k) {
                    MapLocation loc(pos, k);
                    if (m_simulation->map().organismAt(loc)) {
                        if (!m_simulation->map().organismAt(loc)->dead()) {
                            col += m_simulation->map().organismAt(loc)->color();
                            ++count;
                            if (m_simulation->map().organismAt(loc)->alive()) {
                                alive++;
                            }
                        }
                    }
                }
                if (alive > 1) {
                    qDebug() << "Multiple live objects at one tile.";
                }
                if (count > 0) {
                    col /= count;
                } else {
                    col = QVector4D(0.7f, 0.5f, 0.4f, 1.f);
                }
            }
            for (int k = 0; k < 6; ++k) {
                m_colors[beg + k] = col;
            }
        }
    }
}

void Renderer::render(Graphics::RenderingContext &cont) {
    QOpenGLShaderProgram *prog = cont.flatShader();
    prog->bind();
    prog->setAttributeArray("v_vertex", m_vertices.data());
    prog->enableAttributeArray("v_vertex");
    prog->setAttributeArray("v_color", m_colors.data());
    prog->enableAttributeArray("v_color");
    int screen = std::min(cont.viewport().width(), cont.viewport().height());
    int sim = std::max(m_simulation->map().size().width(), m_simulation->map().size().height());
    float tile = ((float)screen) / ((float)sim);
    QMatrix4x4 proj, view, model;
    model.scale(tile);
    proj.ortho(-cont.viewport().width() / 2, cont.viewport().width() / 2,
               -cont.viewport().height() / 2, cont.viewport().height() / 2, 1.0, 100.0);
    view.lookAt(QVector3D(0.f, 0.f, 2.f), QVector3D(0.f, 0.f, 0.f), QVector3D(0.f, 1.f, 0.f));
    prog->setUniformValue("u_mvp", proj * view * model);
    glDrawArrays(GL_TRIANGLES, 0, m_vertices.size());
    prog->disableAttributeArray("v_vertex");
    prog->release();
}

QSharedPointer<Simulation> Renderer::simulation() const {
    return m_simulation;
}

void Renderer::setSimulation(const QSharedPointer<Simulation> &sim) {
    m_simulation = sim;
    m_initialized = false;
}


}
