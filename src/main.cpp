#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "calcinterface.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);


    qmlRegisterType<CalcInterface>("CalcInterface",1,0,"CalcInterface"); // Creates registered type for QML import


    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));


    return app.exec();
}
