#include "fightaction.h"
#include <vector>
#include <QPoint>

#include "Simulation/FightActions/fightcontext.h"
#include "Simulation/map.h"
#include "Simulation/organism.h"
#include "Utility/classcache.h"
#include "Simulation/MoveActions/movetofree.h"
#include "Simulation/MoveActions/moveaction.h"
#include "Simulation/turncontext.h"

namespace Simulation {
FightAction::FightAction()
{
    m_breedChance = 2;
}

FightAction::~FightAction()
{

}

void FightAction::breed(FightContext &ctx)
{
    if (rand() % m_breedChance != 0)
        return;
    TurnContext tctx = ctx.defendersTurn();
    std::vector<QPoint> moves = {{-1, -1}, {-1, 0}, {-1,1}, {0, -1},
                                {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int around = 0;
    for (int i = 0; i < (int)moves.size(); ++i) {
        TileInfo tinf = tctx.tileInfo(ctx.defendersTile().position() + moves[i]);
        around += tinf.objectCount();
    }
    if (around > 5) {
        return;
    }

    for (auto &mv : moves) {
        auto tgt = ctx.defendersTile().position() + mv;
        if (tctx.validPosition(tgt) && (tctx.tileInfo(tgt).objectCount() == 0)) {
            std::string className = m_friendlyFlag.substr(5, m_friendlyFlag.length() - 5);
            auto org = Utility::ClassCache::instance().create<Organism>(className);
            if (org) {
                tctx.spawn(org, tgt);
                static int cnt = 0;
                qDebug() << "Spawned: " << className.c_str() << " nr. " << cnt++;
            }
            return;
        }
    }
}

std::string FightAction::friendlyFlag() const
{
    return m_friendlyFlag;
}

void FightAction::setFriendlyFlag(const std::string &str)
{
    m_friendlyFlag = str;
}
int FightAction::breedChance() const
{
    return m_breedChance;
}

void FightAction::setBreedChance(int breedChance)
{
    m_breedChance = breedChance;
}


}
