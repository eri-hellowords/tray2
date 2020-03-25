#ifndef POPUP_H
#define POPUP_H
#include <QWidget>
#include <QtGui>

class Popup : public QWidget
{
    Q_OBJECT
public:
    Popup();
protected:
    void moveEvent ( QMoveEvent * event );
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
private:
    QPoint oldPos;
};

#endif // POPUP_H
