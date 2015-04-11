#include "turtlemove.h"

#include "Simulation/turncontext.h"
#include "Simulation/map.h"

namespace Simulation {

TurtleMove::TurtleMove() {

}

QPoint TurtleMove::nextPosition(TurnContext &ctx) {
    if (rand() % 4 != 0)
        return ctx.location().position();
    std::vector<QPoint> moves = {{-1, -1}, {-1,  1}, { 1,  1}, { 1, -1},
                                 { 1,  0}, {-1,  0}, { 0,  1}, { 0, -1}};
    std::random_shuffle(moves.begin(), moves.end());
    for (unsigned int i = 0; i < moves.size(); ++i) {
        QPoint tgt = ctx.location().position() + moves[i];
        if (ctx.validPosition(tgt)) {
            return tgt;
        }
    }
    return ctx.location().position();
}

}
