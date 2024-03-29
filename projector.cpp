#include "projector.h"

#include <QtDebug>
#include <QTcpSocket>
#include <QVariantMap>


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
/* XXX
 * Breaks compilation
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

/* XXX
 * Breaks compilation
    connect(mSocket,
            &QTcpSocket::proxyAuthenticationRequired,
            [&]()
    {
        qDebug() << "Projector" << address() << "proxyAuthenticationRequired";
    });
*/

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
        msg += "1";
    }
    else
    {
        msg += "0";
    }
    sendMessage(msg);
}

void Projector::sendMessage(const QByteArray& message)
{
    Q_ASSERT(mSocket->isValid());
    Q_ASSERT(connected());
    Q_ASSERT(mSocket->isWritable());
    Q_ASSERT(!message.endsWith("\r"));

    if(mSocket->write(message + "\r") == -1)
    {
        qDebug() << "Error while sending message";
    }
}

void Projector::setMute(bool mute)
{
    QByteArray msg("%1AVMT ");
    if (mute)
    {
        msg += "31";
    }
    else
    {
        msg += "30";
    }
    sendMessage(msg);
}

void Projector::setInputSource(int index)
{
    if (index < 0 || index >= inputSourcesValues.count())
    {
        qWarning() << "Projector::setInputSource: out of range index";
        return;
    }
    Q_ASSERT(index < inputSourcesValues.count());
    QByteArray msg("%1INPT ");
    msg += inputSourcesValues[index];
    sendMessage(msg);
}

void Projector::queryAll()
{
    queryName();
    queryManufacturer();
    queryModel();
    queryPower();
    queryMute();
    queryInputs();
    queryInput();
}

void Projector::readPendingDatagrams()
{
    foreach(const QByteArray& msg, mSocket->readAll().split('\r'))
    {
        if (msg == "%1POWR=OK")
        {
            queryPower();
        }
        else if (msg == "%1POWR=0")
        {
            emit powerChanged(PowerOff);
        }
        else if (msg == "%1POWR=1")
        {
            emit powerChanged(PowerOn);
        }
        else if (msg == "%1POWR=2")
        {
            emit powerChanged(PowerCooling);
        }
        else if (msg == "%1POWR=3")
        {
            emit powerChanged(PowerWarmUp);
        }
        else if (msg == "%1POWR=ERR2")
        {
            qDebug() << "Set power error : out of parameter";
        }
        else if (msg == "%1POWR=ERR3")
        {
            qDebug() << "Power error : unavailable time";
        }
        else if (msg == "%1POWR=ERR4")
        {
            qDebug() << "Power error : projector failure";
        }
        else if (msg == "%1NAME=ERR3")
        {
            qDebug() << "Name query error : unavailable time";
        }
        else if (msg == "%1NAME=ERR4")
        {
            qDebug() << "Name query error : projector failure";
        }
        else if (msg.startsWith("%1NAME="))
        {
            emit nameChanged(value(msg));
        }
        else if (msg == "%1INF1=ERR3")
        {
            qDebug() << "Manufacturer query error : unavailable time";
        }
        else if (msg == "%1INF1=ERR4")
        {
            qDebug() << "Manufacturer query error : projector failure";
        }
        else if (msg.startsWith("%1INF1="))
        {
            emit manufacturerChanged(value(msg));
        }
        else if (msg == "%1INF2=ERR3")
        {
            qDebug() << "Projector model query error : unavailable time";
        }
        else if (msg == "%1INF2=ERR4")
        {
            qDebug() << "Projector model query error : projector failure";
        }
        else if (msg.startsWith("%1INF2="))
        {
            emit modelChanged(value(msg));
        }
        else if (msg == "%1AVMT=OK")
        {
            emit queryMute();
        }
        else if (msg == "%1AVMT=ERR2")
        {
            qDebug() << "Set mute error : out of parameter";
        }
        else if (msg == "%1AVMT=ERR3")
        {
            qDebug() << "Mute error : unavailable time";
        }
        else if (msg == "%1AVMT=ERR4")
        {
            qDebug() << "Mute error : projector failure";
        }
        else if (msg.startsWith("%1AVMT="))
        {
            const QByteArray answer(value(msg));
            if (answer == "11")
            {
                emit videoMuteChanged(true);
                emit audioMuteChanged(false);
            }
            if (answer == "21")
            {
                emit videoMuteChanged(false);
                emit audioMuteChanged(true);
            }
            if (answer == "31")
            {
                emit videoMuteChanged(true);
                emit audioMuteChanged(true);
            }
            if (answer == "30")
            {
                emit videoMuteChanged(false);
                emit audioMuteChanged(false);
            }
        }
        else if (msg == "%1INST=ERR3")
        {
            qDebug() << "Input query error : unavailable time";
        }
        else if (msg == "%1INST=ERR4")
        {
            qDebug() << "Input query error : projector failure";
        }
        else if (msg.startsWith("%1INST="))
        {
            inputSourcesValues = value(msg).split(' ');
            qDebug() << inputSourcesValues << inputSourcesAsStrings();
            emit inputSourcesChanged(inputSourcesAsStrings());
        }
        else if (msg == "%1INPT=OK")
        {
            queryInput();
        }
        else if (msg == "%1INPT=ERR1")
        {
            qDebug() << "Input switch error : ERR1";
        }
        else if (msg == "%1INPT=ERR2")
        {
            qDebug() << "Input switch error : non-existent input source";
        }
        else if (msg == "%1INPT=ERR3")
        {
            qDebug() << "Input switch error : unavailable time";
        }
        else if (msg == "%1INPT=ERR4")
        {
            qDebug() << "Input switch error : projector failure";
        }
        else if (msg.startsWith("%1INPT="))
        {
            emit inputSourceChanged(inputSourcesValues.indexOf(value(msg)));
        }
    }
}

QStringList Projector::inputSourcesAsStrings() const
{
    QStringList ret;

    foreach (const QByteArray& inputBytes, inputSourcesValues)
    {
        Q_ASSERT(inputBytes.count() == 2);

        QString source;
        switch(QByteArray(1, inputBytes[0]).toInt())
        {
        case 1:
            source += "RGBA";
            break;
        case 2:
            source += "Video";
            break;
        case 3:
            source += "Digital";
            break;
        case 4:
            source += "Storage";
            break;
        case 5:
            source += "Network";
            break;
        }
        source += " ";
        source += inputBytes[1];
        //const int index = QByteArray(1, inputBytes[1]).toInt();
        ret.append(source);
    }
    return ret;
}

void Projector::queryPower()
{
    sendMessage("%1POWR ?");
}

void Projector::queryName()
{
    sendMessage("%1NAME ?");
}

void Projector::queryManufacturer()
{
    sendMessage("%1INF1 ?");
}

void Projector::queryModel()
{
    sendMessage("%1INF2 ?");
}

void Projector::queryMute()
{
    sendMessage("%1AVMT ?");
}

void Projector::queryInputs()
{
    sendMessage("%1INST ?");
}

void Projector::queryInput()
{
    sendMessage("%1INPT ?");
}

QByteArray Projector::value(const QByteArray& message)
{
    return message.mid(7);
}


