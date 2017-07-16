
#include <QApplication>
#include <QCommandLineParser>

#include "mainwindow.h"
#include "registerfile.h"

MainWindow* Window;
QApplication* App;

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(images);
    QApplication app(argc, argv);
    QCoreApplication::setApplicationName("Patmos ISA Simulator");
    QCoreApplication::setOrganizationName("DTU Compute");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
    QCommandLineParser parser;
    parser.setApplicationDescription(QCoreApplication::applicationName());
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("file", "The file(s) to open.");
    parser.process(app);



    MainWindow *mainWin = Q_NULLPTR;
    foreach (const QString &file, parser.positionalArguments()) {
        MainWindow *newWin = new MainWindow(file);
        newWin->tile(mainWin);
        newWin->show();
        mainWin = newWin;
    }

    if (!mainWin)
        mainWin = new MainWindow;

    App = &app;
    Window = mainWin;

    Window->show();

    /*CodeEditor editor;
    editor.setWindowTitle(QObject::tr("Code Editor Example"));
    editor.show();*/





    return app.exec();
}
