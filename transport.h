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
    void setServer(QHostAddress address);

private slots:
    void readyRead();

signals:
private:
    void Ping();
    QUdpSocket *socket;
    QHostAddress remote = QHostAddress::LocalHost;
    QTimer *timer;
};

#endif // TRANSPORT_H
