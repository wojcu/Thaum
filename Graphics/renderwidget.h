#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include <QQuickItem>
#include <QSharedPointer>
#include "renderingobject.h"

namespace Logic {
class Engine;
class Clock;
}

namespace Graphics {
class RenderWidgetRenderer;
class RenderingObject;

class RenderWidget : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)
public:
    RenderWidget();
    ~RenderWidget();

    int refreshRate() const;
    void setRefreshRate(int refreshRate);

    bool active() const;
    void setActive(bool active);

    QSharedPointer<RenderingObject> renderingObject() const;
    void setRenderingObject(const QSharedPointer<RenderingObject> &renderingObject);

    void setClock(const QSharedPointer<Logic::Clock> &clock);

    void setEngine(Logic::Engine *eng);

signals:
    void activeChanged();

public slots:

private slots:
    void onWindowChanged(QQuickWindow *);
    void onRefresh();
    void onSync();
    void onCleanup();

private:
    QSharedPointer<QTimer> m_timer;
    QSharedPointer<RenderWidgetRenderer> m_renderer;
    QSharedPointer<Logic::Clock> m_clock;
    int m_refreshRate;
    bool m_active;
    Logic::Engine *m_engine;
};

}

#endif // RENDERWIDGET_H
