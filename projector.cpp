#include "projector.h"

#include <QtDebug>
#include <QTcpSocket>

Projector::Projector(QObject *parent) :
    QObject(parent),
    mSocket(new QTcpSocket(this))
{
    qDebug() << "Projector::Projector()";

    connect(mSocket, &QTcpSocket::readyRead,
            this, &Projector::readPendingDatagrams);

    connect(mSocket,
            &QTcpSocket::connected,
            [&]()
    {
        qDebug() << "Projector" << address() << "connected";
        emit connectedChanged(true);
        queryAll();
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

void Projector::setPower(bool power)
{
    QByteArray msg("%1POWR ");
    if (power)
    {
        msg += "1\r";
    }
    else
    {
        msg += "0\r";
    }
    sendMessage(msg);
}

void Projector::queryAll()
{
    queryPower();
}

void Projector::readPendingDatagrams()
{
    QByteArray msg(mSocket->readAll());
    if (msg == "%1POWR=OK\r")
    {
        queryPower();
    }
    else if (msg == "%1POWR=0\r")
    {
        emit powerChanged(PowerOff);
    }
    else if (msg == "%1POWR=1\r")
    {
        emit powerChanged(PowerOn);
    }
    else if (msg == "%1POWR=2\r")
    {
        emit powerChanged(PowerCooling);
    }
    else if (msg == "%1POWR=3\r")
    {
        emit powerChanged(PowerWarmUp);
    }
    else if (msg == "%1POWR=ERR2\r")
    {
        qDebug() << "Set power error : out of parameter";
    }
    else if (msg == "%1POWR=ERR3\r")
    {
        qDebug() << "Power error : unavailable time";
    }
    else if (msg == "%1POWR=ERR4\r")
    {
        qDebug() << "Power error : projector failure";
    }
}

void Projector::queryPower()
{
    sendMessage("%1POWR ?\r");
}

void Projector::sendMessage(const QByteArray& message)
{
    Q_ASSERT(mSocket->isValid());
    Q_ASSERT(connected());
    Q_ASSERT(mSocket->isWritable());

    if(mSocket->write(message) == -1)
    {
        qDebug() << "Error while sending message";
    }
}
