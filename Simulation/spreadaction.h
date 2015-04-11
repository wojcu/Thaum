#ifndef SPREADACTION_H
#define SPREADACTION_H

#include <vector>
#include <QPoint>

#include "Simulation/turnaction.h"
#include "Simulation/turncontext.h"
#include "Simulation/map.h"

namespace Simulation {
template<typename T>
class SpreadAction : public Simulation::TurnAction {
public:
    SpreadAction(const int &chance = 1, const int &attempts = 1) {
        m_attempts = attempts;
        m_chance = chance;
    }

    void makeTurn(Simulation::TurnContext &ctx) override {
        std::vector<QPoint> moves = {{-1, -1}, {-1,  1}, { 1,  1}, { 1, -1},
                                       { 1,  0}, {-1,  0}, { 0,  1}, { 0, -1}};
        std::random_shuffle(moves.begin(), moves.end());
        int spawned = 0;
        for (unsigned int i = 0; i < moves.size(); ++i) {
            QPoint tgt = ctx.location().position() + moves[i];
            if (ctx.validPosition(tgt)
                    && ctx.tileInfo(tgt).objectCount() == 0) {
                for (int j = 0; j < m_attempts - spawned; ++j) {
                    spawned++;
                    if (spawned > m_attempts) {
                        return;
                    }
                    if (rand() % m_chance == 0) {
                        ctx.spawn(QSharedPointer<T>(new T), tgt);
                        break;
                    }
                }

            }
        }
    }

private:
    int m_attempts;
    int m_chance;
};
}

#endif // SPREADACTION_H
