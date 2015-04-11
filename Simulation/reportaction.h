#ifndef REPORTACTION_H
#define REPORTACTION_H

#include <string>

#include "Simulation/turnaction.h"

namespace Simulation {
class ReportAction : public Simulation::TurnAction {
public:
    ReportAction(const std::string &msg);

    void makeTurn(Simulation::TurnContext &) override;

private:
    std::string m_message;
};

}
#endif // REPORTACTION_H
