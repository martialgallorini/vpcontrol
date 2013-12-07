#include "projector.h"

#include <QtDebug>

Projector::Projector(QObject *parent) :
    QObject(parent)
{
    qDebug() << "Projector::Projector()";
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
