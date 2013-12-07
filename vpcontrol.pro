TARGET = vpcontrol

QT += qml quick network

QMAKE_CXXFLAGS += -std=c++11

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

