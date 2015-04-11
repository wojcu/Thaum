#include "smartmove.h"

#include "Simulation/turncontext.h"
#include "Simulation/map.h"
#include "Simulation/organism.h"
#include "Simulation/objectinfo.h"

namespace Simulation {

SmartMove::SmartMove() {

}

QPoint SmartMove::nextPosition(TurnContext &ctx) {
    std::vector<QPoint> moves = {{-1, -1}, {-1,  1}, { 1,  1}, { 1, -1},
                                 { 1,  0}, {-1,  0}, { 0,  1}, { 0, -1}};
    std::random_shuffle(moves.begin(), moves.end());
    for (unsigned int i = 0; i < moves.size(); ++i) {
        QPoint tgt = ctx.location().position() + moves[i];
        if (ctx.validPosition(tgt)) {
            int stronger = 0;
            for (int j = 0; j < ctx.tileInfo(tgt).objectCount(); ++j) {
                if (!ctx.tileInfo(tgt).objectAt(j).isNull()) {
                    if (ctx.tileInfo(tgt).objectAt(j).strength() > 3) {
                        ++stronger;
                    }
                }
            }
            if (stronger == 0)
                return tgt;
        }
    }
    ctx.objectInfo().kill();
    return ctx.location().position();
}

}
