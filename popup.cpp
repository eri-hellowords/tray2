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
