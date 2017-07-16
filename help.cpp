#include "mainwindow.h"

#include <QFileInfo>
#include <QProcess>
#include <qmessagebox.h>

// Help menu
//

void MainWindow::help_ViewHelp()
{
    QProcess *process = new QProcess;
    QStringList args;

    char* helpFile[] = {"help/qtspim.qhc",      // Windows
                        "/Applications/QtSpim.app/Contents/Resources/doc/qtspim.qhc", // Mac
                        "/usr/lib/qtspim/help/qtspim.qhc", // Linux
                        0
                       };

    int i;
    for (i = 0; helpFile[i] != 0; i += 1)
    {
        QFileInfo fi1(helpFile[i]);
        if (fi1.exists())
        {
            args << QLatin1String("-collectionFile") << QLatin1String(helpFile[i]);
            break;
        }
    }

    if (helpFile[i] == 0)
    {
        QMessageBox msgBox;
        msgBox.setText(tr("Cannot find Patmos' ISA Simulator help file. Check installation."));
        msgBox.exec();
        return;
    }

    char* assistant[] = {"assistant", // Windows
                         "/Applications/QtSpim.app/Contents/MacOS/Assistant", // Mac
                         "/usr/lib/qtspim/bin/assistant", // Linux
                         0
                        };

    process->start(QLatin1String(assistant[i]), args);
    if (!process->waitForStarted())
    {
        QMessageBox msgBox;
        msgBox.setText(tr("Cannot start help browser (Qt assistant). Check installation."));
        msgBox.exec();
    }
}


void MainWindow::help_AboutSimulator()
{
    QMessageBox box(QMessageBox::NoIcon,
                    tr("About Patmos ISA Simulator"),
                    QString(tr("<span style='font-size: 14pt;'>"
                               "<br><center>Patmos ISA Simulator\n</center><br/>"
                               "<center><img src=':/icons/dtulogo.jpg'>"
                               "<span style='font-size: 10pt;'>"))
                    + QString("<p>") + "version 1.1" + QString("</p>")
                    + QString (tr("<p>A simulator of the Patmos processor.</p>"
                                  "<p>Copyright 2017 Technical University of Denmark, DTU Compute."
                                  "All rights reserved.</p>"
                                  "<p> The aim of this project is to create a graphical user interface for the Patmos processor to help visualize the "
                                  "internal operation of the architecture as well as provide how the "
                                  "computer instructions are being processed by the architecture. Moreover, the simulator will be able to simulate the "
                                  "different parts of the Patmos processor based on an assembly file.</p> "
                                  "</span>")),
                    QMessageBox::Ok);
    box.exec();
}
