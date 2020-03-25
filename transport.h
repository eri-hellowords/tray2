#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <QUdpSocket>
#include <QObject>
#include <QTimer>

class Transport : public QObject
{
    Q_OBJECT
public:
    explicit Transport(QObject *parent = nullptr);
    void Ping();
    void setServer(QHostAddress address);

private slots:
    void readyRead();

signals:
private:
    QUdpSocket *socket;
    QHostAddress remote = QHostAddress::LocalHost;
    QTimer *timer;
};

#endif // TRANSPORT_H
