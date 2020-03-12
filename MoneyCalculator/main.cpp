#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>

#include <moneycalculator.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication a(argc, argv);


    MoneyCalculator model;
    model.addMoneyValue(MoneyValue(0,1));
    model.addMoneyValue(MoneyValue(0,2));
    model.addMoneyValue(MoneyValue(0,5));
    model.addMoneyValue(MoneyValue(0,10));
    model.addMoneyValue(MoneyValue(0,20));
    model.addMoneyValue(MoneyValue(0,50));
    model.addMoneyValue(MoneyValue(0,100));
    model.addMoneyValue(MoneyValue(0,200));
    model.addMoneyValue(MoneyValue(0,500));
    model.addMoneyValue(MoneyValue(0,1000));
    model.addMoneyValue(MoneyValue(0,2000));
    model.addMoneyValue(MoneyValue(0,5000));
    model.addMoneyValue(MoneyValue(0,10000));
    model.addMoneyValue(MoneyValue(0,20000));
    model.addMoneyValue(MoneyValue(0,50000));

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    QQmlContext *ctxt = view.rootContext();
    ctxt->setContextProperty("myModel", &model);


    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &a, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return a.exec();
}


