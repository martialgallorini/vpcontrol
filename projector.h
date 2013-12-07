#ifndef PROJECTOR_H
#define PROJECTOR_H

#include <QObject>

class QTcpSocket;

class Projector : public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(QString address READ address WRITE setAddress NOTIFY addressChanged)
    Q_PROPERTY(bool connected READ connected WRITE setConnected NOTIFY connectedChanged)

    explicit Projector(QObject *parent = 0);
    ~Projector();

    QString address() const;
    void setAddress(const QString&);

    bool connected() const;
    void setConnected(bool);

signals:
    void addressChanged(QString);
    void connectedChanged(bool);

public slots:

private:
    QString mAddress;
    QTcpSocket* mSocket;
};

#endif // PROJECTOR_H
