#include "mainwindow.h"

#include <QFileInfo>
#include <QDesktopServices>
#include <qmessagebox.h>

// Help menu
//

void MainWindow::help_ViewHelp()
{
    QString path=QFileInfo(".").absolutePath();

    if(QFileInfo(path+"/doc.pdf").exists())
    {
        // it exists
        QDesktopServices::openUrl(QUrl(path+"/doc.pdf"));
    }
    else
    {
        // it doesn't exist
        console->append("The documentation file does not exist\n"+ path+"/doc.pdf does not exist");
        QMessageBox msgBox;
        msgBox.setText("Cannot find Patmos' ISA Simulator help file.\n"+ path+"/doc.pdf does not exist.");
        msgBox.exec();
        return;

    }





}


void MainWindow::help_AboutSimulator()
{
    QMessageBox box(QMessageBox::NoIcon,
                    tr("About Patmos ISA Simulator"),
                    QString(tr("<span style='font-size: 14pt;'>"
                               "<br><center>Patmos ISA Simulator\n</center><br/>"
                               "<center><img src=':/icons/dtu.png'>"
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
