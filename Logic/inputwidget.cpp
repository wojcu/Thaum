#include "inputwidget.h"

#include "inputtarget.h"

namespace Logic {
InputWidget::InputWidget()
{
    setObjectName("InputWidget");
    setAcceptedMouseButtons(Qt::LeftButton);
}

InputWidget::~InputWidget()
{

}

void InputWidget::mouseMoveEvent(QMouseEvent *ev)
{
    mouseEvent(ev);
}

void InputWidget::keyPressEvent(QKeyEvent *ev)
{
    keyEvent(ev);
}

void InputWidget::keyReleaseEvent(QKeyEvent *ev)
{
    keyEvent(ev);
}

void InputWidget::mousePressEvent(QMouseEvent *ev)
{
    mouseEvent(ev);
}

void InputWidget::mouseReleaseEvent(QMouseEvent *ev)
{
    mouseEvent(ev);
}

void InputWidget::addInputTarget(const QSharedPointer<InputTarget> &tgt)
{
    m_targets.push_back(tgt);
    tgt->viewportChanged(m_viewport);
}

void InputWidget::setViewport(const QSize &vp)
{
    for (unsigned int i = 0; i < m_targets.size(); ++i) {
        QWeakPointer<InputTarget> &tgt = m_targets[i];
        if (tgt.isNull()) {
            std::swap(m_targets[i], m_targets.back());
            m_targets.pop_back();
            --i;
        } else {
            tgt.lock()->viewportChanged(vp);
        }
    }
}

void InputWidget::keyEvent(QKeyEvent *ev)
{
    for (unsigned int i = 0; i < m_targets.size(); ++i) {
        QWeakPointer<InputTarget> &tgt = m_targets[i];
        if (tgt.isNull()) {
            std::swap(m_targets[i], m_targets.back());
            m_targets.pop_back();
            --i;
        } else {
            tgt.lock()->keyEvent(ev);
        }
    }
}

void InputWidget::mouseEvent(QMouseEvent *ev)
{
    for (unsigned int i = 0; i < m_targets.size(); ++i) {
        QWeakPointer<InputTarget> &tgt = m_targets[i];
        if (tgt.isNull()) {
            std::swap(m_targets[i], m_targets.back());
            m_targets.pop_back();
            --i;
        } else {
            tgt.lock()->mouseEvent(ev);
        }
    }
}

}
