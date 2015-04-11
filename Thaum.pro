TEMPLATE = app

QT += qml quick widgets

CONFIG += c++11

SOURCES += main.cpp \
    Graphics/renderwidget.cpp \
    Graphics/renderwidgetrenderer.cpp \
    Graphics/renderingobject.cpp \
    Logic/engine.cpp \
    Graphics/scenerenderer.cpp \
    Graphics/renderingcontext.cpp \
    Graphics/renderable.cpp \
    Logic/inputwidget.cpp \
    Logic/inputtarget.cpp \
    Logic/clock.cpp \
    Logic/clockwidget.cpp \
    Simulation/simulation.cpp \
    Simulation/objectupdater.cpp \
    Simulation/map.cpp \
    Simulation/organism.cpp \
    Simulation/turnaction.cpp \
    Simulation/turncontext.cpp \
    Utility/classcache.cpp \
    Simulation/renderer.cpp \
    Simulation/reportaction.cpp \
    Simulation/humaninput.cpp \
    Simulation/Animals/animal.cpp \
    Simulation/Animals/antilope.cpp \
    Simulation/Animals/fox.cpp \
    Simulation/Animals/human.cpp \
    Simulation/Animals/sheep.cpp \
    Simulation/Animals/turtle.cpp \
    Simulation/Animals/wolf.cpp \
    Simulation/controlwidget.cpp \
    Simulation/FightActions/antilopefight.cpp \
    Simulation/FightActions/fightaction.cpp \
    Simulation/FightActions/fightcontext.cpp \
    Simulation/FightActions/guaranafight.cpp \
    Simulation/FightActions/nightshadefight.cpp \
    Simulation/FightActions/standardfight.cpp \
    Simulation/FightActions/turtlefight.cpp \
    Simulation/MoveActions/antilopemove.cpp \
    Simulation/MoveActions/humanmove.cpp \
    Simulation/MoveActions/moveaction.cpp \
    Simulation/MoveActions/movetofree.cpp \
    Simulation/MoveActions/simplemove.cpp \
    Simulation/MoveActions/smartmove.cpp \
    Simulation/MoveActions/turtlemove.cpp \
    Simulation/Plants/grass.cpp \
    Simulation/Plants/guarana.cpp \
    Simulation/Plants/nightshade.cpp \
    Simulation/Plants/plant.cpp \
    Simulation/Plants/thistle.cpp \
    Simulation/Skills/specialskill.cpp \
    Simulation/Skills/skillset.cpp \
    Simulation/tileinfo.cpp \
    Simulation/maplocation.cpp \
    Simulation/objectinfo.cpp

RESOURCES += qml.qrc \
    glsl.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Graphics/renderwidget.h \
    Graphics/renderwidgetrenderer.h \
    Graphics/renderingobject.h \
    Logic/engine.h \
    Graphics/scenerenderer.h \
    Graphics/renderingcontext.h \
    Graphics/renderable.h \
    Logic/inputwidget.h \
    Logic/inputtarget.h \
    Logic/clock.h \
    Logic/clockwidget.h \
    Simulation/simulation.h \
    Simulation/objectupdater.h \
    Simulation/map.h \
    Simulation/organism.h \
    Simulation/turnaction.h \
    Simulation/turncontext.h \
    Utility/utility.h \
    Utility/classcache.h \
    Simulation/renderer.h \
    Simulation/spreadaction.h \
    Simulation/reportaction.h \
    Simulation/humaninput.h \
    Simulation/Animals/animal.h \
    Simulation/Animals/antilope.h \
    Simulation/Animals/fox.h \
    Simulation/Animals/human.h \
    Simulation/Animals/sheep.h \
    Simulation/Animals/turtle.h \
    Simulation/Animals/wolf.h \
    Simulation/controlwidget.h \
    Simulation/FightActions/antilopefight.h \
    Simulation/FightActions/fightaction.h \
    Simulation/FightActions/fightcontext.h \
    Simulation/FightActions/guaranafight.h \
    Simulation/FightActions/nightshadefight.h \
    Simulation/FightActions/standardfight.h \
    Simulation/FightActions/turtlefight.h \
    Simulation/MoveActions/antilopemove.h \
    Simulation/MoveActions/humanmove.h \
    Simulation/MoveActions/moveaction.h \
    Simulation/MoveActions/movetofree.h \
    Simulation/MoveActions/simplemove.h \
    Simulation/MoveActions/smartmove.h \
    Simulation/MoveActions/turtlemove.h \
    Simulation/Plants/grass.h \
    Simulation/Plants/guarana.h \
    Simulation/Plants/nightshade.h \
    Simulation/Plants/plant.h \
    Simulation/Plants/thistle.h \
    Simulation/Skills/specialskill.h \
    Simulation/Skills/skillset.h \
    Simulation/tileinfo.h \
    Simulation/maplocation.h \
    Simulation/objectinfo.h

DISTFILES += \
    GLSL/flat.fsh \
    GLSL/flat.vsh
