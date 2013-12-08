#ifndef PROJECTOR_H
#define PROJECTOR_H

#include <QObject>

class QTcpSocket;

class Projector : public QObject
{
    Q_OBJECT

public:
    enum PowerStatus
    {
        PowerOff,
        PowerWarmUp,
        PowerOn,
        PowerCooling
    };
    Q_ENUMS(PowerStatus)

    Q_PROPERTY(QString address READ address WRITE setAddress NOTIFY addressChanged)
    Q_PROPERTY(bool connected READ connected WRITE setConnected NOTIFY connectedChanged)

    explicit Projector(QObject *parent = 0);
    ~Projector();

    QString address() const;
    void setAddress(const QString&);

    bool connected() const;
    void setConnected(bool);

signals:
    void nameChanged(QString projectorName);
    void addressChanged(QString);
    void connectedChanged(bool);
    void powerChanged(PowerStatus powerStatus);

public slots:
    void setPower(bool);
    void queryAll();

private slots:
    void readPendingDatagrams();

private:
    void queryPower();
    void queryName();
    void sendMessage(const QByteArray&);

    QString mAddress;
    QTcpSocket* mSocket;
};

#endif // PROJECTOR_H
