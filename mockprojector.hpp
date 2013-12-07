#ifndef MOCKPROJECTOR_HPP
#define MOCKPROJECTOR_HPP

#include <QObject>
//#include <QStringList>

class MockProjector : public QObject
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

    enum CommandError
    {
        CommandNoError,
        CommandOutOfParameter,
        CommandUnavailableTime,
        CommandProjectorFailure
    };

    enum ErrorStatus
    {
        StatusNoError,
        StatusWarning,
        StatusError
    };

    enum LampPowerStatus
    {
        LampOff,
        LampOn
    };

    struct LampStatus
    {
        int index;
        int lightingTime;
        LampPowerStatus powerStatus;
    };


    Q_PROPERTY(QString address READ address WRITE setAddress NOTIFY addressChanged)
    Q_PROPERTY(bool connected READ isConnected WRITE setConnected NOTIFY connectedChanged)
    Q_PROPERTY(PowerStatus powerStatus READ powerStatus WRITE setPowerStatus NOTIFY powerStatusChanged)
    Q_PROPERTY(bool videoMuted READ isVideoMuted WRITE setVideoMuted NOTIFY videoMutedChanged)
    Q_PROPERTY(bool audioMuted READ isAudioMuted WRITE setAudioMuted NOTIFY audioMutedChanged)
    Q_PROPERTY(ErrorStatus fanError READ fanError NOTIFY fanErrorChanged)
    Q_PROPERTY(ErrorStatus lampError READ lampError NOTIFY lampErrorChanged)
    Q_PROPERTY(ErrorStatus temperatureError READ temperatureError NOTIFY temperatureErrorChanged)
    Q_PROPERTY(ErrorStatus coverError READ coverError NOTIFY coverErrorChanged)
    Q_PROPERTY(ErrorStatus filterError READ filterError NOTIFY filterErrorChanged)
    Q_PROPERTY(ErrorStatus otherError READ otherError NOTIFY otherErrorChanged)
    //Q_PROPERTY(QList<LampStatus> lampStatuses READ lampStatuses NOTIFY lampStatusesChanged)
    //Q_PROPERTY(QStringList inputStrings READ inputStrings)
    Q_PROPERTY(int inputIndex READ inputIndex WRITE setInputIndex NOTIFY inputIndexChanged)
    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
    Q_PROPERTY(QString manufacturer READ manufacturer)
    Q_PROPERTY(QString nameInformation READ nameInformation)
    Q_PROPERTY(QString otherInformation READ otherInformation)
    Q_PROPERTY(bool class2Compatible READ isClass2Compatible)

    explicit MockProjector(const QString& address, QObject *parent = 0);
    explicit MockProjector();
    virtual ~MockProjector();

    QString address() const;

    bool isConnected() const;
    PowerStatus powerStatus() const;
    bool isVideoMuted() const;
    bool isAudioMuted() const;

    ErrorStatus fanError() const;
    ErrorStatus lampError() const;
    ErrorStatus temperatureError() const;
    ErrorStatus coverError() const;
    ErrorStatus filterError() const;
    ErrorStatus otherError() const;

    //QList<LampStatus> lampStatuses() const;

    //QStringList inputStrings() const;
    int inputIndex() const;

    QString name() const;
    QString manufacturer() const;
    QString nameInformation() const;
    QString otherInformation() const;

    bool isClass2Compatible() const;

signals:
    void addressChanged(QString) const;
    void connectedChanged(bool) const;
    void powerStatusChanged(PowerStatus) const;
    void videoMutedChanged(bool) const;
    void audioMutedChanged(bool) const;

    void fanErrorChanged(ErrorStatus) const;
    void lampErrorChanged(ErrorStatus) const;
    void temperatureErrorChanged(ErrorStatus) const;
    void coverErrorChanged(ErrorStatus) const;
    void filterErrorChanged(ErrorStatus) const;
    void otherErrorChanged(ErrorStatus) const;

    //void lampStatusesChanged(QList<LampStatus>) const;

    void inputIndexChanged(int) const;

    void nameChanged(QString) const;


public slots:
    void setAddress(const QString&);
    void setConnected(bool);
    void setPowerStatus(PowerStatus);
    void setVideoMuted(bool);
    void setAudioMuted(bool);
    void setInputIndex(int);

private:
    QString mAddress;
    bool mIsConnected;
    PowerStatus mPowerStatus;
    bool mIsVideoMuted;
    bool mIsAudioMuted;
    int mInputIndex;
};

#endif // MOCKPROJECTOR_HPP
