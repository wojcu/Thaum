#ifndef TURNACTION_H
#define TURNACTION_H


namespace Simulation {
class TurnContext;

class TurnAction {
public:
    enum State {Enabled, Disabled, Expired};
    TurnAction();

    virtual ~TurnAction();

    virtual void makeTurn(TurnContext &cont) = 0;

    State state() const;

    void kill();

    void enable();

    void disable();

    bool expired() const;

    bool enabled() const;

private:
    State m_state;
};

}

#endif // TURNACTION_H
