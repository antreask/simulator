#include "mainwindow.h"
#include <QTextStream>


void MainWindow::checkFile()
{

    QString src=editor->toPlainText();
    QTextStream assembly(&src, QIODevice::ReadOnly);

    if (src.isEmpty())
    {
        console->append("Nothing to build. Load an assembly file or write your own program!");
        return;
    }
    QString line;
    while( !assembly.atEnd())
        console->append(assembly.readLine());

}



/*
QString text = plainTextEdit->plainText();
QTextStream str(&text, QIODevice::ReadOnly);
QString line;
for (int n = 0; !str.atEnd() && n < 3; ++n)
  line = str.readLine();
qDebug() << "fourth or last line:" << line;


*/
