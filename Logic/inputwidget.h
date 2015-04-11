#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H

#include <QQuickItem>
#include <bits/stdc++.h>

namespace Logic {
class InputTarget;
class InputWidget : public QQuickItem
{
    Q_OBJECT
public:
    InputWidget();
    ~InputWidget();

    void mouseMoveEvent(QMouseEvent *ev) override;
    void keyPressEvent(QKeyEvent *ev) override;
    void keyReleaseEvent(QKeyEvent *ev) override;
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;

    void addInputTarget(const QSharedPointer<InputTarget> &tgt);

    void setViewport(const QSize &vp);

private:
    void keyEvent(QKeyEvent *ev);
    void mouseEvent(QMouseEvent *ev);

    std::vector<QWeakPointer<InputTarget>> m_targets;
    QSize m_viewport;
};

}

#endif // INPUTWIDGET_H
