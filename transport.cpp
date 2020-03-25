#include "transport.h"
#include <QSysInfo>


Transport::Transport(QObject *parent) : QObject(parent)
{
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::Any, 7817);

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));


    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, QOverload<>::of(&Transport::Ping));
    timer->start(10000);
}

void Transport::setServer(QHostAddress address)
{
    remote = address;
}

void Transport::readyRead()
{
    // when data comes in
    QByteArray buffer;
    buffer.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;

    // qint64 QUdpSocket::readDatagram(char * data, qint64 maxSize,
    //                 QHostAddress * address = 0, quint16 * port = 0)
    // Receives a datagram no larger than maxSize bytes and stores it in data.
    // The sender's host address and port is stored in *address and *port
    // (unless the pointers are 0).

    socket->readDatagram(buffer.data(), buffer.size(),
                         &sender, &senderPort);

    qDebug() << "Message from: " << sender.toString();
    qDebug() << "Message port: " << senderPort;
    qDebug() << "Message: " << buffer;

    if (buffer.startsWith("pong:")) {
        ;
    } else if (buffer.startsWith("invi:")) {
        ;
    }

}

void Transport::Ping()
{
    QByteArray Data;
    Data.append("ping:");
    Data.append(QSysInfo::machineUniqueId());

    // Sends the datagram datagram
    // to the host address and at port.
    // qint64 QUdpSocket::writeDatagram(const QByteArray & datagram,
    //                      const QHostAddress & host, quint16 port)
    socket->writeDatagram(Data, remote, 7818);
}
