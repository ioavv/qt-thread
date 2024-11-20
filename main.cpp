#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QThread>
#include <QThreadPool>
#include "taskmanager.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<TaskManager>("com.example", 1, 0, "TaskManager");
    const QUrl url(QStringLiteral("file:///home/emilano/qt-thread/Main.qml"));

    QObject::connect(&engine, &::QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject* object, const QUrl &objUrl) {
    if(!object && url == objUrl)
    QCoreApplication::exit(-1);
    },
    Qt::QueuedConnection);
    engine.load(url);

    QThreadPool::globalInstance()->setMaxThreadCount(10);

    return app.exec();
}
