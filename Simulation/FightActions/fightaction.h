#ifndef FIGHTACTION_H
#define FIGHTACTION_H

#include <string>

namespace Simulation {
class FightContext;

class FightAction {
public:
    enum MoveStatus {AllowMove, DenyMove};
    FightAction();

    virtual ~FightAction();

    virtual MoveStatus defend(FightContext &) = 0;

    virtual MoveStatus attack(FightContext &) = 0;

    void breed(FightContext &);

    std::string friendlyFlag() const;
    void setFriendlyFlag(const std::string &str);

    int breedChance() const;
    void setBreedChance(int breedChance);

private:
    std::string m_friendlyFlag;
    int m_breedChance;
};

}

#endif // FIGHTACTION_H
