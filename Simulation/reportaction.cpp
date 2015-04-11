#include "reportaction.h"
#include <QDebug>

namespace Simulation {

ReportAction::ReportAction(const std::string &msg) {
    m_message = msg;
}

void ReportAction::makeTurn(TurnContext &) {
    qDebug() << m_message.c_str();
}

}

