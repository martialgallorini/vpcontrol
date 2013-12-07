#include "mockprojector.hpp"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QtQml>

int main(int argc, char *argv[])
{
    //qmlRegisterType<MockProjector>("net.charlesfleche.vpcontrol", 1, 0, "MockProjector");

    QGuiApplication app(argc, argv);

    QList<QObject*> projectors;
    projectors.append(new MockProjector("http://192.168.0.1:8888"));
    projectors.append(new MockProjector("http://192.168.0.2:8889"));
    projectors.append(new MockProjector("http://192.168.0.3:8890"));

    QQmlApplicationEngine engine(QUrl("qrc:/qml/main.qml"));
    engine.rootContext()->setContextProperty( "projectorsModel", QVariant::fromValue(projectors));

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
