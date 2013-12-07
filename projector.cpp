#include "projector.h"

#include <QtDebug>
#include <QTcpSocket>

Projector::Projector(QObject *parent) :
    QObject(parent),
    mSocket(new QTcpSocket(this))
{
    qDebug() << "Projector::Projector()";

    connect(mSocket,
            &QTcpSocket::connected,
            [&]()
    {
        qDebug() << "Projector" << address() << "connected";
        emit connectedChanged(true);
    });

    connect(mSocket,
            &QTcpSocket::disconnected,
            [&]()
    {
        qDebug() << "Projector" << address() << "disconnected";
        emit connectedChanged(false);
    });
/*
    connect(mSocket,
            SIGNAL(error(QAbstractSocket::SocketError)),
            [&](QAbstractSocket::SocketError error)
    {
        qDebug() << "Projector" << address() << "error" << error;
    });
*/
    connect(mSocket,
            &QTcpSocket::hostFound,
            [&]()
    {
        qDebug() << "Projector" << address() << "hostFound";
    });

    connect(mSocket,
            &QTcpSocket::proxyAuthenticationRequired,
            [&]()
    {
        qDebug() << "Projector" << address() << "proxyAuthenticationRequired";
    });

    connect(mSocket,
            &QTcpSocket::stateChanged,
            [&](QAbstractSocket::SocketState socketState)
    {
        qDebug() << "Projector" << address() << "stateChanged" << socketState;
    });
}

Projector::~Projector()
{
    qDebug() << "Projector::~Projector()";
}

QString Projector::address() const
{
    qDebug() << "Projector::address()";
    return mAddress;
}

void Projector::setAddress(const QString& address)
{
    qDebug() << "Projector::address()";

    if (address != mAddress)
    {
        mAddress = address;
        qDebug() << "Projector address changed to" << mAddress;

        emit addressChanged(mAddress);
    }
}

void Projector::setConnected(bool connect)
{
    if (connect)
    {
        Q_ASSERT(!connected());
        mSocket->connectToHost(mAddress, 10000);
    }
    else
    {
        Q_ASSERT(connected());
        mSocket->disconnectFromHost();
    }
}

bool Projector::connected() const
{
    return mSocket->state() == QAbstractSocket::ConnectedState;
}
