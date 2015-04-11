#include <QApplication>
#include <QQuickWindow>

#include "Simulation/simulation.h"
#include "Logic/engine.h"
#include "Graphics/scenerenderer.h"
#include "Simulation/renderer.h"
#include "Graphics/renderwidget.h"
#include "Simulation/controlwidget.h"
#include "Simulation/Animals/human.h"
#include "Simulation/Animals/antilope.h"
#include "Simulation/Animals/fox.h"
#include "Simulation/Plants/grass.h"
#include "Simulation/Plants/guarana.h"
#include "Simulation/Animals/turtle.h"
#include "Simulation/Animals/wolf.h"
#include "Logic/inputwidget.h"
#include "Simulation/humaninput.h"
#include "Simulation/MoveActions/humanmove.h"
#include "Simulation/Animals/sheep.h"
#include "Simulation/Plants/thistle.h"
#include "Simulation/Plants/nightshade.h"

template<typename T>
void spawnCreature(const int &num, Simulation::Map &map) {
    /*for (int i = 0; i < num; ++i) {
        QPoint tgt(rand() % map.size().width(), rand() % map.size().height());
        if (map.organismsAt(tgt) == 0) {
            QSharedPointer<T> obj(new T());
            map.spawnOrganism(obj, tgt);
        } else --i;
    }*/
    std::vector<QPoint> positions;
    for (int i = 0; i < map.size().width(); ++i) {
        for (int j = 0; j < map.size().height(); ++j) {
            QPoint pos(i, j);
            if (map.organismsAt(pos) == 0)
                positions.push_back(pos);
        }
    }
    std::random_shuffle(positions.begin(), positions.end());
    for (int i = 0; i < num; ++i) {
        if (!positions.empty()) {
            map.spawnOrganism(QSharedPointer<T>(new T), positions.back());
            positions.pop_back();
        }
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Logic::SharedEngine engine = Logic::Engine::newSharedEngine();
    Graphics::SharedSceneRenderer scene = Graphics::SceneRenderer::newSharedSceneRenderer();
    Simulation::SharedRenderer quad = Simulation::Renderer::newSharedRenderer();

    engine->renderWidget()->setRenderingObject(scene);
    engine->thrashCan().queue(quad);
    scene->addRenderable(quad);

    QSize simSize(32, 32);
    Simulation::SharedSimulation simulation = Simulation::Simulation::newSharedSimulation(simSize);
    quad->setSimulation(simulation);
    engine->simulationControl()->setSimulator(simulation);
    simulation->setUpdateModel(Simulation::Simulation::Manual);
    QSharedPointer<Simulation::Human> human(new Simulation::Human());
    simulation->setHuman(human);
    engine->inputWidget()->addInputTarget(human->humanMove()->input());
    QQuickWindow *wnd = reinterpret_cast<QQuickWindow*>(engine->qmlEngine()->rootObjects().first());
#ifdef Q_OS_LINUX
    wnd->setVisibility(QQuickWindow::Windowed);
    wnd->setWidth(640);
    wnd->setHeight(480);
#endif
#ifdef Q_OS_ANDROID
    wnd->setVisibility(QQuickWindow::FullScreen);
#endif

    human->humanMove()->input()->setSimulator(simulation);
    quad->simulation()->map().spawnOrganism(human ,QPoint(simSize.width() / 2, simSize.height() / 2));

    human.reset();
    spawnCreature<Simulation::Grass>(5, quad->simulation()->map());
    spawnCreature<Simulation::Wolf>(5, quad->simulation()->map());
    spawnCreature<Simulation::Sheep>(5, quad->simulation()->map());
    spawnCreature<Simulation::Fox>(5, quad->simulation()->map());
    spawnCreature<Simulation::Turtle>(5, quad->simulation()->map());
    spawnCreature<Simulation::Antilope>(5, quad->simulation()->map());
    spawnCreature<Simulation::Thistle>(5, quad->simulation()->map());
    spawnCreature<Simulation::Guarana>(5, quad->simulation()->map());
    spawnCreature<Simulation::Nightshade>(5, quad->simulation()->map());

    return app.exec();
}

