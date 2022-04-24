#include <iostream>

// QtChessGUI
#include <QtChessGUI/ChessViewController.h>

// Qt
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QDebug>
#include <QDirIterator>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    // QQmlApplicationEngine engine(":/QtChessGUI/main.qml");
    QQuickView view;

    QQmlEngine* engine = view.engine();
    QObject::connect(engine, &QQmlEngine::quit, []() {
        qDebug() << "exit";
    });

    engine->addImportPath("qrc:/");

    // QDirIterator it(":", QDirIterator::Subdirectories);
    // while (it.hasNext()) {
    //     qDebug() << it.next();
    // }

    qmlRegisterType<ChessViewController>("QtChessGUI.Controls", 1, 0, "ChessViewController");

    {
        view.setSource(QUrl::fromLocalFile(":/QtChessGUI/main.qml"));
        view.show();
    }

    return app.exec();
}
