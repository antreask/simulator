#include "mainwindow.h"
#include <QTextStream>
#include <QDebug>
#include <QDockWidget>


void MainWindow::checkFile()
{

    QString src=editor->toPlainText();
    QTextStream assembly(&src, QIODevice::ReadOnly);

    if (src.isEmpty())
    {
        console->append("Nothing to build. Load an assembly file or write a new one.");
        return;
    }
    QString line;
    int line_num=0;
    while( !assembly.atEnd())
    {
        line = assembly.readLine();
        line_num++;

        if (line == ".data")
        {
            dataflag=true;
            instflag=false;
            mainflag=false;
            continue;
        }
        else if (line == ".text")
        {
            dataflag=false;
            instflag=true;
            mainflag=false;
            continue;
        }
        else if (line == ".main")
        {
            dataflag=false;
            instflag=false;
            mainflag=true;
            continue;
        }

        if (dataflag && line !=".data")
        {
            if (!DM->addline(line))
            {
                QString s="sadf";
                console->append("<html>"
                                "<font color=\"red\">"
                                "<b>Line "+QString::number(line_num)+"- Error:</b>"
                                "  Wrong data type!"
                                "</font>"
                                " </html>");
                return;
            }
        }

    }
    DataDock->setWidget(DM->getDMTable());
    //console->append(assembly.readLine());

}

void MainWindow::sim_Run()
{
    DM->clearmemory();
    DataDock->setWidget(DM->getDMTable());
}

/*
QString text = plainTextEdit->plainText();
QTextStream str(&text, QIODevice::ReadOnly);
QString line;
for (int n = 0; !str.atEnd() && n < 3; ++n)
  line = str.readLine();
qDebug() << "fourth or last line:" << line;
            qDebug() << "string compare ok";

*/
