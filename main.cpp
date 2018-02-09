#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "I18n.hpp"
int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    I18n i18n;
    QQmlApplicationEngine engine;
    QObject::connect(&i18n, &I18n::retransRequest, &engine, &QQmlApplicationEngine::retranslate);

    engine.rootContext()->setContextProperty("i18n", &i18n);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
