#include "mainwindow.h"
#include <QTextStream>
#include <QDebug>
#include <QDockWidget>


void MainWindow::checkFile()
{

    clearEverything();
    console->clear();
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
        line =line.mid(0, line.indexOf("#"));

        if (line.trimmed().isEmpty()) /* nothing but whitespace */
            continue;

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
            console->append("Data Segment is syntactically correct.");
            continue;
        }
        else if (line == "main:")
        {
            dataflag=false;
            instflag=true;
            mainflag=true;
            continue;
        }

        if (dataflag && line !=".data")
        {
            if (!DM->addline(line))
            {
                console->append("<html>"
                                "<font color=\"red\">"
                                "<b>Line "+QString::number(line_num)+"- Error:</b>"
                                "  Wrong data type!"
                                "</font>"
                                " </html>");
                clearEverything();
                syntaxpass=false;
                return;
            }
            continue;

        }
        else if (instflag && (line != ".text") && mainflag)
        {
            if (!IM->addline(line))
            {
                console->append("<html>"
                                "<font color=\"red\">"
                                "<b>Line "+QString::number(line_num)+"- Error:</b>"
                                "  Wrong instruction!"
                                "</font>"
                                " </html>");
                clearEverything();
                syntaxpass=false;
                return;
            }
            continue;
        }



    }
    console->append("Text Segment is syntactically correct.");
    syntaxpass=true;
    DataDock->setWidget(DM->getDMTable());
    //console->append(assembly.readLine());

}

void MainWindow::clearEverything()
{
    RF->clearRegisters();
    DM->clearmemory();
    IM->clearmemory();
}





