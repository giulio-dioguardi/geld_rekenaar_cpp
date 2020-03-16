#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>

#include <moneycalculator.h>
#include <moneycalculatormodel.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication a(argc, argv);

    qmlRegisterType<MoneyCalculatorModel>("Calculator", 1, 0 , "MoneyCalculatorList");
    qmlRegisterUncreatableType<MoneyCalculator>("Calculator", 1, 0, "MoneyCalculator",
                                                "Shouldn't be created");

    MoneyCalculator model;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("moneyCalculatorModel", &model);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &a, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return a.exec();
}


