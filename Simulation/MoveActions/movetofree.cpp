#include "movetofree.h"

#include "Simulation/turncontext.h"
#include "Simulation/map.h"
#include "Simulation/organism.h"

namespace Simulation {

MoveToFree::MoveToFree() {

}

QPoint MoveToFree::nextPosition(TurnContext &ctx) {
    std::vector<QPoint> moves = {{-1, -1}, {-1,  1}, { 1,  1}, { 1, -1},
                                 { 1,  0}, {-1,  0}, { 0,  1}, { 0, -1}};
    std::random_shuffle(moves.begin(), moves.end());
    for (unsigned int i = 0; i < moves.size(); ++i) {
        QPoint tgt = ctx.location().position() + moves[i];
        if (ctx.validPosition(tgt)
                && (ctx.tileInfo(tgt).objectCount() == 0)) {
            return tgt;
        }
    }
    return ctx.location().position();
}

}
