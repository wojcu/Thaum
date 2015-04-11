#include "antilopemove.h"

#include "Simulation/turncontext.h"
#include "Simulation/map.h"

namespace Simulation {

AntilopeMove::AntilopeMove() {

}

QPoint AntilopeMove::nextPosition(Simulation::TurnContext &ctx) {
    std::vector<QPoint> moves;
    for (int i = -2; i <= 2; ++i) {
        for (int j = -2; j <= 2; ++j) {
            if (i != 0 || j != 0) {
                moves.push_back(QPoint(i, j));
            }
        }
    }
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
