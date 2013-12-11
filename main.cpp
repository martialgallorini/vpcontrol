#include "projector.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QtQml>

int main(int argc, char *argv[])
{
    qmlRegisterType<Projector>("org.vpcontrol.qmlcomponents", 1, 0, "Projector");

    QGuiApplication app(argc, argv);
    app.setOrganizationName("vpcontrol");
    app.setApplicationName("vpcontrol");

    QQmlApplicationEngine engine(QUrl("qrc:/main.qml"));

    QObject *topLevel = engine.rootObjects().value(0);
    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);
    if ( !window )
    {
        qWarning("Error: Your root item has to be a Window.");
        return -1;
    }
    window->show();
    return app.exec();
}
