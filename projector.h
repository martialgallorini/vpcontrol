#ifndef PROJECTOR_H
#define PROJECTOR_H

#include <QObject>

class Projector : public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(QString address READ address WRITE setAddress NOTIFY addressChanged)

    explicit Projector(QObject *parent = 0);
    ~Projector();

    QString address() const;
    void setAddress(const QString&);

signals:
    void addressChanged(QString);

public slots:

private:
    QString mAddress;
};

#endif // PROJECTOR_H
