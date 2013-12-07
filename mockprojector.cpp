#include "mockprojector.hpp"

MockProjector::MockProjector(const QString& address, QObject *parent) :
    QObject(parent),
    mIsConnected(true),
    mPowerStatus(PowerOn),
    mIsVideoMuted(false),
    mIsAudioMuted(false),
    mInputIndex(0)
{
    setAddress(address);
}

MockProjector::MockProjector()
{
}

MockProjector::~MockProjector()
{
}

bool MockProjector::isConnected() const
{
    return mIsConnected;
}

MockProjector::PowerStatus MockProjector::powerStatus() const
{
    return mPowerStatus;
}

bool MockProjector::isVideoMuted() const
{
    return mIsVideoMuted;
}

bool MockProjector::isAudioMuted() const
{
    return mIsAudioMuted;
}

MockProjector::ErrorStatus MockProjector::fanError() const
{
    return StatusNoError;
}

MockProjector::ErrorStatus MockProjector::lampError() const
{
    return StatusWarning;
}

MockProjector::ErrorStatus MockProjector::temperatureError() const
{
    return StatusError;
}

MockProjector::ErrorStatus MockProjector::coverError() const
{
    return StatusNoError;
}

MockProjector::ErrorStatus MockProjector::filterError() const
{
    return StatusNoError;
}

MockProjector::ErrorStatus MockProjector::otherError() const
{
    return StatusWarning;
}
/*
QList<MockProjector::LampStatus> MockProjector::lampStatuses() const
{
    return QList<LampStatus>()
            << LampStatus {1, 1234, LampOn}
            << LampStatus {2, 5678, LampOff};
}

QStringList MockProjector::inputStrings() const
{
    return QStringList()
            << "HDMI 1"
            << "HDMI 2"
            << "RGB"
            << "DVI";
}
*/
int MockProjector::inputIndex() const
{
    return mInputIndex;
}

QString MockProjector::name() const
{
    return "ProjectorName";
}

QString MockProjector::manufacturer() const
{
    return "Manufacturer";
}

QString MockProjector::nameInformation() const
{
    return "NameInformation";
}

QString MockProjector::otherInformation() const
{
    return "OtherInformation";
}

bool MockProjector::isClass2Compatible() const
{
    return true;
}

QString MockProjector::address() const
{
    return mAddress;
}

void MockProjector::setAddress(const QString& address)
{
    if (mAddress == address)
    {
        return;
    }
    mAddress = address;
    emit addressChanged(mAddress);
}

void MockProjector::setConnected(bool isConnected)
{
    mIsConnected = isConnected;
    emit connectedChanged(mIsConnected);
}

void MockProjector::setPowerStatus(PowerStatus powerStatus)
{
    mPowerStatus = powerStatus;
    emit powerStatusChanged(mPowerStatus);
}

void MockProjector::setVideoMuted(bool isVideoMuted)
{
    mIsVideoMuted = isVideoMuted;
    emit videoMutedChanged(isVideoMuted);
}

void MockProjector::setAudioMuted(bool isAudioMuted)
{
    mIsAudioMuted = isAudioMuted;
    emit audioMutedChanged(isAudioMuted);
}

void MockProjector::setInputIndex(int inputIndex)
{
    mInputIndex = inputIndex;
    emit inputIndexChanged(mInputIndex);
}
