QT += qml quick

TARGET = vpcontrol

# what is this ?
qtHaveModule(widgets) {
    QT += widgets
}

include(src/src.pri)

OTHER_FILES += \
    qml/main.qml \
    qml/TestWidget.qml

RESOURCES += \
    resources.qrc

SOURCES += \
    src/mockprojector.cpp

HEADERS += \
    src/mockprojector.hpp

