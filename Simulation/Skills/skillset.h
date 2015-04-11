#ifndef SKILLSET_H
#define SKILLSET_H

#include <QSharedPointer>

namespace Simulation {
class SpecialSkill;
class Organism;

class SkillSet
{
public:
    SkillSet();
    ~SkillSet();

    void addSkill(const QSharedPointer<SpecialSkill> &skill);
    QSharedPointer<SpecialSkill> removeSkill(const int &id);
    QSharedPointer<SpecialSkill> skill(const int &id) const;
    void setOwner(const QSharedPointer<Organism> &owner);
    QSharedPointer<Organism> owner() const;
    void cast(const int &id, const QSharedPointer<Organism> &tgt);
    void selfCast(const int &id);

private:
    QWeakPointer<Organism> m_owner;
    std::vector<QSharedPointer<SpecialSkill>> m_skills;
};

}

#endif // SKILLSET_H
