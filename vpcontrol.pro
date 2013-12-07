TARGET = vpcontrol

QT += qml quick

OTHER_FILES += \
    main.qml \
    TestWidget.qml \
    ProjectorView.qml

RESOURCES += \
    resources.qrc

SOURCES += \
    main.cpp \
    mockprojector.cpp \
    projector.cpp

HEADERS += \
    mockprojector.hpp \
    projector.h

