#include "popup.h"
#include <QSettings>

Popup::Popup()
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    QSettings settings("eri.su", "tray2");
    restoreGeometry(settings.value("popup/geometry").toByteArray());
    resize(300, 120);
}

void Popup::moveEvent(QMoveEvent *event) {
    QSettings settings("eri.su", "tray2");
    settings.setValue("popup/geometry", saveGeometry());
}

void Popup::mousePressEvent(QMouseEvent *event) {
    oldPos = event->globalPos();
}

void Popup::mouseMoveEvent(QMouseEvent *event) {
    const QPoint delta = event->globalPos() - oldPos ;
    move(x()+delta.x(), y()+delta.y());
    oldPos = event->globalPos();
}
