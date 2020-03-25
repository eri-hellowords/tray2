#ifndef POPUP_H
#define POPUP_H
#include <QWidget>

class Popup : public QWidget
{
    Q_OBJECT
public:
    Popup();
protected:
    void moveEvent ( QMoveEvent * event );
};

#endif // POPUP_H
