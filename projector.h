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
    void manufacturerChanged(QString manufacturerName);
    void modelChanged(QString modelName);
    void addressChanged(QString);
    void connectedChanged(bool);
    void powerChanged(PowerStatus powerStatus);
    void videoMuteChanged(bool videoMute);
    void audioMuteChanged(bool audioMute);

public slots:
    void setPower(bool);
    void setMute(bool);
    void queryAll();

private slots:
    void readPendingDatagrams();

private:
    void queryPower();
    void queryName();
    void queryManufacturer();
    void queryModel();
    void queryMute();
    void sendMessage(const QByteArray&);

    static QByteArray value(const QByteArray&);

    QString mAddress;
    QTcpSocket* mSocket;
};

#endif // PROJECTOR_H
