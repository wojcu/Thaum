#include "skillset.h"

#include "Simulation/Skills/specialskill.h"

namespace Simulation {
SkillSet::SkillSet()
{

}

SkillSet::~SkillSet()
{

}

void SkillSet::addSkill(const QSharedPointer<SpecialSkill> &skill)
{
    m_skills.push_back(skill);
}

QSharedPointer<SpecialSkill> SkillSet::removeSkill(const int &id)
{
    if (id < 0 || id >= (int)m_skills.size())
        return QSharedPointer<SpecialSkill>();
    QSharedPointer<SpecialSkill> sk = skill(id);
    m_skills.erase(m_skills.begin() + id);
    return sk;
}

QSharedPointer<SpecialSkill> SkillSet::skill(const int &id) const
{
    if (id < 0 || id >= (int)m_skills.size())
        return QSharedPointer<SpecialSkill>();
    return m_skills[id];
}

void SkillSet::setOwner(const QSharedPointer<Organism> &owner)
{
    m_owner = owner;
}

QSharedPointer<Organism> SkillSet::owner() const
{
    return m_owner;
}

void SkillSet::cast(const int &id, const QSharedPointer<Organism> &tgt)
{
    if (id < 0 || id >= (int)m_skills.size())
        return;
    if (!tgt)
        return;
    m_skills[id]->cast(tgt);
}

void SkillSet::selfCast(const int &id)
{
    cast(id, owner());
}

}
