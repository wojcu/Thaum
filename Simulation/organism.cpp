#include "organism.h"

#include <QDebug>

#include "turnaction.h"

namespace Simulation {
Organism::Organism()
{
    m_state = Alive;
    m_age = 0;
    m_initiative = 0;
    m_strength = 0;
}

Organism::~Organism()
{

}

void Organism::kill()
{
    if (dead())
        return;
    m_state = Dying;
}

bool Organism::alive() const
{
    return state() == Alive;
}

void Organism::addTurnAction(QSharedPointer<TurnAction> action)
{
    if (!action)
        return;
    if (dead())
        return;
    m_turnActions.push_back(action);
}

void Organism::addDeathAction(QSharedPointer<TurnAction> action)
{
    if (!action)
        return;
    if (dead())
        return;
    m_deathActions.push_back(action);
}

void Organism::addOnceAction(QSharedPointer<TurnAction> action)
{
    if (!action)
        return;
    if (dead())
        return;
    m_onceActions.push_back(action);
}

void Organism::makeTurn(TurnContext &cont)
{
    if (state() == Dead) {
        m_updateFinished = true;
        return;
    }
    runActions(m_onceActions, cont);
    m_onceActions.clear();
    if (state() == Dying) {
        runActions(m_deathActions, cont);
        m_deathActions.clear();
        m_turnActions.clear();
        m_onceActions.clear();
        m_state = Dead;
    } else {
        ++m_age;
        runActions(m_turnActions, cont);
    }
    m_updateFinished = true;
}

Organism::State Organism::state() const
{
    return m_state;
}

bool Organism::updateFinished() const
{
    return m_updateFinished;
}

void Organism::setUpdateFinished(const bool &fin)
{
    m_updateFinished = fin;
}

bool Organism::dead() const
{
    return state() == Dead;
}

QVector4D Organism::color() const
{
    return m_color;
}

void Organism::setColor(const QVector4D &col)
{
    m_color = col;
}

void Organism::addFlag(const std::string &flag)
{
    m_flags.insert(flag);
}

bool Organism::hasFlag(const std::string &flag) const
{
    return m_flags.find(flag) != m_flags.end();
}

std::string Organism::allFlags() const
{
    std::string flags;
    for (auto &flag : m_flags) {
        flags += flag + ", ";
    }
    if (!flags.empty()) {
        flags.pop_back();
        flags.pop_back();
    }
    return flags;
}

QSharedPointer<FightAction> Organism::fightAction() const
{
    if (!alive())
        return QSharedPointer<FightAction>();
    return m_fight;
}

void Organism::setFightAction(const QSharedPointer<FightAction> &fight)
{
    m_fight = fight;
}
int Organism::age() const
{
    return m_age;
}

void Organism::setAge(int age)
{
    m_age = age;
}
int Organism::strength() const
{
    return m_strength;
}

void Organism::setStrength(int strength)
{
    m_strength = strength;
}
int Organism::initiative() const
{
    return m_initiative;
}

void Organism::setInitiative(int initiative)
{
    m_initiative = initiative;
}

void Organism::runActions(std::vector<QSharedPointer<TurnAction> > &turns, TurnContext &cont)
{
    for (unsigned int i = 0; i < turns.size(); ++i) {
        if (turns[i]->expired()) {
            std::swap(turns[i], turns.back());
            turns.pop_back();
            --i;
        } else if (turns[i]->enabled()) {
            turns[i]->makeTurn(cont);
        }
    }
}




}
