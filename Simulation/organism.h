#ifndef ORGANISM_H
#define ORGANISM_H

#include <QSharedPointer>
#include <QVector4D>
#include <unordered_set>

namespace Simulation {
class TurnAction;
class TurnContext;
class FightAction;

class Organism {
public:
    enum State {Alive, Dying, Dead};

    Organism();

    virtual ~Organism();

    void kill();

    bool alive() const;

    void addTurnAction(QSharedPointer<TurnAction> action);

    void addDeathAction(QSharedPointer<TurnAction> action);

    void addOnceAction(QSharedPointer<TurnAction> action);

    void makeTurn(TurnContext &cont);

    State state() const;

    bool updateFinished() const;

    void setUpdateFinished(const bool &fin);

    bool dead() const;

    QVector4D color() const;

    void setColor(const QVector4D &col);

    void addFlag(const std::string &flag);

    bool hasFlag(const std::string &flag) const;

    std::string allFlags() const;

    QSharedPointer<FightAction> fightAction() const;

    void setFightAction(const QSharedPointer<FightAction> &fight);

    int age() const;
    void setAge(int age);

    int strength() const;
    void setStrength(int strength);

    int initiative() const;
    void setInitiative(int initiative);

protected:
    QVector4D m_color;

private:
    void runActions(std::vector<QSharedPointer<TurnAction>> &turns, TurnContext &cont);

    std::vector<QSharedPointer<TurnAction>> m_turnActions;
    std::vector<QSharedPointer<TurnAction>> m_deathActions;
    std::vector<QSharedPointer<TurnAction>> m_onceActions;
    std::unordered_set<std::string> m_flags;
    QSharedPointer<FightAction> m_fight;
    State m_state;
    bool m_updateFinished;
    int m_age;
    int m_strength;
    int m_initiative;
};

}

#endif // ORGANISM_H
