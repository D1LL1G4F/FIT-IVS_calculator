/**
  * @file main.c
  *
  * @author Bakaľárová Alica
  * @author Jedlička Jakub
  * @author Kňazík Matej
  * @author Lovíšek Vladimír
  * @date 24 Apr 2017
  *
  * @brief Calculator application made for school project in IVS subject on FIT VUT
  *
  * This app is made in Qt quick controls 2. This main.cpp file only runs engine and loads GUI
  * main.qml file where all the magic happens. Also registers calcinterface module as import for
  * all qml files.
  */

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QIcon>

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
