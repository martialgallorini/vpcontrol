TARGET = vpcontrol

QT += core qml quick network

CONFIG += c++11

OTHER_FILES += \
    main.qml \
    ProjectorView.qml \
    PowerButton.qml \
    MuteButton.qml \
    StatusButton.qml

RESOURCES += \
    resources.qrc

SOURCES += \
    main.cpp \
    projector.cpp

HEADERS += \
    projector.h
