#include "mainwindow.h"
#include "saveresform.h"
#include "printform.h"
#include <ui_saveresform.h>
#include <ui_printform.h>
#include <QStatusBar>
#include <QDesktopWidget>
#include <QDialog>
#include <QObject>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QSettings>

void MainWindow::file_SaveLogFile()
{

    static QDialog* saveDialog;
    static Ui::saveResForm* slf;

    saveDialog=new QDialog();
    slf =new Ui::saveResForm();
    slf->setupUi(saveDialog);

    QFileDialog* fb = new QFileDialog(0,
                                      tr("Save To Log File"),
                                      "",
                                      tr("Text files (*.txt);; All (*)"));

    connect(slf->saveFileToolButton, SIGNAL(clicked()), fb, SLOT(exec()));
    connect(fb, SIGNAL(fileSelected(QString)), slf->SaveLineEdit, SLOT(setText(QString)));

    connect(slf->buttonBox, SIGNAL(accepted()), saveDialog, SLOT(accept()));
    connect(slf->buttonBox, SIGNAL(rejected()), saveDialog, SLOT(reject()));

    if (saveDialog->exec() == QDialog::Accepted)
    {
        if (!slf->SaveLineEdit->text().isNull())
        {

            QFile file(slf->SaveLineEdit->text());
            file.open(QIODevice::WriteOnly | QIODevice::Truncate);
            QTextStream outFile(&file);

            if (slf->GPRegsCheckBox->isChecked())
            {
                QString textData;
                for (int i = 0; i<RF->getGPRegTable()->model()->rowCount(); i++)
                {
                    for (int j = 0; j < RF->getGPRegTable()->model()->columnCount(); j++)
                    {

                        textData += RF->getGPRegTable()->model()->data(RF->getGPRegTable()->model()->index(i,j)).toString();
                    }
                    textData += "\n";             // (optional: for new line segmentation)
                }
                outFile << "General Purpose Registers\n"
                        << "---------------------------\n"
                        << textData << "\n";
            }
            if (slf->SPRegsCheckBox->isChecked())
            {
                QString textData;
                for (int i = 0; i<RF->getSPRegTable()->model()->rowCount(); i++)
                {
                    for (int j = 0; j < RF->getSPRegTable()->model()->columnCount(); j++)
                    {

                        textData += RF->getSPRegTable()->model()->data(RF->getSPRegTable()->model()->index(i,j)).toString();
                    }
                    textData += "\n";             // (optional: for new line segmentation)
                }
                outFile << "Special Purpose Registers\n"
                        << "--------------------------\n"
                        << textData << "\n";
            }
            if (slf->PredRegsCheckBox->isChecked())
            {
                QString textData;
                for (int i = 0; i<RF->getPredRegTable()->model()->rowCount(); i++)
                {
                    for (int j = 0; j < RF->getPredRegTable()->model()->columnCount(); j++)
                    {

                        textData += RF->getPredRegTable()->model()->data(RF->getPredRegTable()->model()->index(i,j)).toString();
                    }
                    textData += "\n";             // (optional: for new line segmentation)
                }
                outFile << "Predicate Registers\n"
                        << "-------------------\n"
                        << textData << "\n";
            }

            if (slf->InstrCheckBox->isChecked())
            {
                QString textData;
                for (int i = 0; i<IM->getIMTable()->model()->rowCount(); i++)
                {
                    for (int j = 0; j < IM->getIMTable()->model()->columnCount(); j++)
                    {

                        textData += IM->getIMTable()->model()->data(IM->getIMTable()->model()->index(i,j)).toString();
                    }
                    textData += "\n";             // (optional: for new line segmentation)
                }
                outFile << "Predicate Registers\n"
                        << "--------------------\n"
                        << textData << "\n";

            }

            if (slf->DataCheckBox->isChecked())
            {
                QString textData;
                for (int i = 0; i<DM->getDMTable()->model()->rowCount(); i++)
                {
                    for (int j = 0; j < DM->getDMTable()->model()->columnCount(); j++)
                    {

                        textData += DM->getDMTable()->model()->data(DM->getDMTable()->model()->index(i,j)).toString();
                    }
                    textData += "\n";             // (optional: for new line segmentation)
                }
                outFile << "Predicate Registers\n"
                        << "--------------------\n"
                        << textData << "\n";

            }

            file.close();
        }
    }
}


void MainWindow::print()
{
    QDialog* printDialog=new QDialog();
    Ui::PrintForm* pf =new Ui::PrintForm();
    pf->setupUi(printDialog);

    QPrinter printer;
    QPrintDialog dialog(&printer, this);

    connect(pf->buttonBox, SIGNAL(accepted()), printDialog, SLOT(accept()));
    connect(pf->buttonBox, SIGNAL(rejected()), printDialog, SLOT(reject()));


    if (printDialog->exec() == QDialog::Accepted)
    {
        QTextDocument textDocument;
        QString finalData;

        if (pf->AssemblyCheckBox->isChecked())
        {
            finalData+="\nAssembly Code\n";
            finalData+="------------------\n";
            finalData+=editor->toPlainText()+"\n";
        }

        if (pf->GPCheckBox->isChecked())
        {
            QString textData;
            for (int i = 0; i<RF->getGPRegTable()->model()->rowCount(); i++)
            {
                for (int j = 0; j < RF->getGPRegTable()->model()->columnCount(); j++)
                {
                    textData += RF->getGPRegTable()->model()->data(RF->getGPRegTable()->model()->index(i,j)).toString();
                }
                textData += "\n";
            }
            finalData+="\nGeneral Purpose Registers\n";
            finalData+="-----------------------------\n";
            finalData+=textData;
        }

        if (pf->SPCheckBox->isChecked())
        {
            QString textData;
            for (int i = 0; i<RF->getSPRegTable()->model()->rowCount(); i++)
            {
                for (int j = 0; j < RF->getSPRegTable()->model()->columnCount(); j++)
                {
                    textData += RF->getSPRegTable()->model()->data(RF->getSPRegTable()->model()->index(i,j)).toString();
                }
                textData += "\n";
            }
            finalData+="\nSpecial Registers\n";
            finalData+="----------------------\n";
            finalData+=textData;
        }

        if (pf->PredCheckBox->isChecked())
        {
            QString textData;
            for (int i = 0; i<RF->getPredRegTable()->model()->rowCount(); i++)
            {
                for (int j = 0; j < RF->getPredRegTable()->model()->columnCount(); j++)
                {
                    textData += RF->getPredRegTable()->model()->data(RF->getPredRegTable()->model()->index(i,j)).toString();
                }
                textData += "\n";
            }
            finalData+="\nPredicate Registers\n";
            finalData+="----------------------\n";
            finalData+=textData;
        }

        if (pf->IMCheckBox->isChecked())
        {
            QString textData;
            for (int i = 0; i<DM->getDMTable()->model()->rowCount(); i++)
            {
                for (int j = 0; j < DM->getDMTable()->model()->columnCount(); j++)
                {
                    textData += DM->getDMTable()->model()->data(DM->getDMTable()->model()->index(i,j)).toString();
                }
                textData += "\n";
            }
            finalData+="\nInstruction Memory\n";
            finalData+="----------------------\n";
            finalData+=textData;
        }

        if (pf->DMCheckBox->isChecked())
        {
            QString textData;
            for (int i = 0; i<IM->getIMTable()->model()->rowCount(); i++)
            {
                for (int j = 0; j < IM->getIMTable()->model()->columnCount(); j++)
                {
                    textData += RF->IM->getIMTable()->model()->data(IM->getIMTable()->model()->index(i,j)).toString();
                }
                textData += "\n";
            }
            finalData+="\nData Memory\n";
            finalData+="----------------------\n";
            finalData+=textData;
        }

        if (dialog.exec())
        {
            textDocument.setPlainText(finalData);
            textDocument.print(&printer);
        }


    }

}

void MainWindow::readSettings()
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    const QByteArray geometry = settings.value("geometry", QByteArray()).toByteArray();
    if (geometry.isEmpty())
    {
        const QRect availableGeometry = QApplication::desktop()->availableGeometry(this);
        resize(availableGeometry.width() / 3, availableGeometry.height() / 2);
        move((availableGeometry.width() - width()) / 2,
             (availableGeometry.height() - height()) / 2);
    }
    else
    {
        restoreGeometry(geometry);
    }
}

void MainWindow::writeSettings()
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    settings.setValue("geometry", saveGeometry());
}

bool MainWindow::maybeSave()
{
    if (!editor->document()->isModified())
        return true;
    const QMessageBox::StandardButton ret
        = QMessageBox::warning(this, tr("Patmos Simulator"),
                               tr("The document has been modified.\n"
                                  "Do you want to save your changes?"),
                               QMessageBox::Save | QMessageBox::Discard
                               | QMessageBox::Cancel);
    switch (ret)
    {
    case QMessageBox::Save:
        return save();
    case QMessageBox::Cancel:
        return false;
    default:
        break;
    }
    return true;
}



void MainWindow::setRecentFilesVisible(bool visible)
{
    recentFileSubMenuAct->setVisible(visible);
    recentFileSeparator->setVisible(visible);
}

static inline QString recentFilesKey()
{
    return QStringLiteral("recentFileList");
}
static inline QString fileKey()
{
    return QStringLiteral("file");
}

static QStringList readRecentFiles(QSettings &settings)
{
    QStringList result;
    const int count = settings.beginReadArray(recentFilesKey());
    for (int i = 0; i < count; ++i)
    {
        settings.setArrayIndex(i);
        result.append(settings.value(fileKey()).toString());
    }
    settings.endArray();
    return result;
}

static void writeRecentFiles(const QStringList &files, QSettings &settings)
{
    const int count = files.size();
    settings.beginWriteArray(recentFilesKey());
    for (int i = 0; i < count; ++i)
    {
        settings.setArrayIndex(i);
        settings.setValue(fileKey(), files.at(i));
    }
    settings.endArray();
}

bool MainWindow::hasRecentFiles()
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    const int count = settings.beginReadArray(recentFilesKey());
    settings.endArray();
    return count > 0;
}

void MainWindow::prependToRecentFiles(const QString &fileName)
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

    const QStringList oldRecentFiles = readRecentFiles(settings);

    QStringList recentFiles = oldRecentFiles;
    recentFiles.removeAll(fileName);
    recentFiles.prepend(fileName);
    if (oldRecentFiles != recentFiles)
        writeRecentFiles(recentFiles, settings);

    setRecentFilesVisible(!recentFiles.isEmpty());
}

void MainWindow::updateRecentFileActions()
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

    const QStringList recentFiles = readRecentFiles(settings);
    const int count = qMin(int(MaxRecentFiles), recentFiles.size());
    int i = 0;
    for ( ; i < count; ++i)
    {
        const QString fileName = MainWindow::strippedName(recentFiles.at(i));
        recentFileActs[i]->setText(tr("&%1 %2").arg(i + 1).arg(fileName));
        recentFileActs[i]->setData(recentFiles.at(i));
        recentFileActs[i]->setVisible(true);
    }
    for ( ; i < MaxRecentFiles; ++i)
        recentFileActs[i]->setVisible(false);
}

void MainWindow::openRecentFile()
{
    if (const QAction *action = qobject_cast<const QAction *>(sender()))
        openFile(action->data().toString());
}

bool MainWindow::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, tr("Patmos Simulator"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(fileName), file.errorString()));
        return false;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << editor->toPlainText();
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}

void MainWindow::setCurrentFile(const QString &fileName)
{
    static int sequenceNumber = 1;

    isUntitled = fileName.isEmpty();
    if (isUntitled)
    {
        curFile = tr("simulation%1").arg(sequenceNumber++);
    }
    else
    {
        curFile = QFileInfo(fileName).canonicalFilePath();
    }

    editor->document()->setModified(false);
    setWindowModified(false);

    if (!isUntitled && windowFilePath() != curFile)
        MainWindow::prependToRecentFiles(curFile);

    setWindowFilePath(curFile);
}
