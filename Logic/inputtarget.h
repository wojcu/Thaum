#ifndef INPUTTARGET_H
#define INPUTTARGET_H

#include <QMouseEvent>
#include <QKeyEvent>

namespace Logic {
class InputTarget
{
public:
    InputTarget();
    virtual ~InputTarget();
    virtual void mouseEvent(QMouseEvent *);
    virtual void keyEvent(QKeyEvent *);
    virtual void viewportChanged(const QSize&);
};

}

#endif // INPUTTARGET_H
