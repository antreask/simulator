
#include "mainwindow.h"
#include "saveresform.h"
#include "ui_saveresform.h"

#include <QDebug>
#include <QPainter>
#include <QDockWidget>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QDesktopWidget>
#include <QStringBuilder>
#include <QMessageBox>
#include <QFileDialog>
#include <QPrinter>
#include <QPrintDialog>




#define QT_USE_FAST_CONCATENATION


//using namespace std;

MainWindow::MainWindow()
{
    init();
    setCurrentFile(QString());
}

MainWindow::MainWindow(const QString &fileName)
{
    init();
    loadFile(fileName);
}


void MainWindow::init()
{
    setAttribute(Qt::WA_DeleteOnClose);

    isUntitled = true;
    //textEdit = new QTextEdit;
    editor= new CodeEditor;
    editor->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 250);"));
    //set font
    QFont font;
    font.setPointSize(11);
    editor->setFont(font);
    RF=new RegisterFile();
    IM=new InstructionMemory();
    DM=new DataMemory();
    setCentralWidget(editor);

    createActions();
    createStatusBar();
    createDockWindows();
    readSettings();

    connect(editor->document(), &QTextDocument::contentsChanged,
            this, &MainWindow::documentWasModified);

    connect(RF,SIGNAL(clearRegSig()),this,SLOT(isRegFileChanged()));
    connect(RF,SIGNAL(basechanged()),this,SLOT(isBaseChanged()));
    setUnifiedTitleAndToolBarOnMac(true);
}


void MainWindow::createDockWindows()
{

    InstrDock = new QDockWidget(tr("Instruction Memory"), this);
    InstrDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    InstrDock->setWidget(IM->getIMTable());

    addDockWidget(Qt::LeftDockWidgetArea, InstrDock);

    viewMenu->addAction(InstrDock->toggleViewAction());

    DataDock = new QDockWidget(tr("Data Memory"), this);
    DataDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    DataDock->setWidget(DM->getDMTable());

    addDockWidget(Qt::LeftDockWidgetArea, DataDock);

    viewMenu->addAction(DataDock->toggleViewAction());


    GPDock = new QDockWidget(tr("GP Registers"), this);
    GPDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    GPDock->setWidget(RF->getGPRegTable());

    addDockWidget(Qt::RightDockWidgetArea, GPDock);

    viewMenu->addAction(GPDock->toggleViewAction());


    SPDock = new QDockWidget(tr("SP Registers"), this);
    SPDock->setWidget(RF->getSPRegTable());
    addDockWidget(Qt::RightDockWidgetArea, SPDock);

    viewMenu->addAction(SPDock->toggleViewAction());


    PredDock = new QDockWidget(tr("Pred. Registers"), this);
    PredDock->setWidget(RF->getPredRegTable());
    addDockWidget(Qt::RightDockWidgetArea, PredDock);

    viewMenu->addAction(PredDock->toggleViewAction());


}




void MainWindow::closeEvent(QCloseEvent *event)
{
    if (maybeSave())
    {
        writeSettings();
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void MainWindow::newFile()
{
    MainWindow *other = new MainWindow;
    other->tile(this);
    other->show();
}

void MainWindow::open()
{

    const QString fileName = QFileDialog::getOpenFileName(this,tr("Open Assembly Code"),"",
                             tr("Assembly (*.a *.s *.asm);;Text files (*.txt)"));

    if (!fileName.isEmpty())
        openFile(fileName);
}

void MainWindow::openFile(const QString &fileName)
{
    MainWindow *existing = findMainWindow(fileName);
    if (existing)
    {
        existing->show();
        existing->raise();
        existing->activateWindow();
        return;
    }

    if (isUntitled && editor->document()->isEmpty() && !isWindowModified())
    {
        loadFile(fileName);
        return;
    }

    MainWindow *other = new MainWindow(fileName);
    if (other->isUntitled)
    {
        delete other;
        return;
    }
    other->tile(this);
    other->show();
}

bool MainWindow::save()
{
    return isUntitled ? saveAs() : saveFile(curFile);
}

bool MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                       curFile);
    if (fileName.isEmpty())
        return false;

    return saveFile(fileName);
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Patmos ISA Simulator"),
                       tr(" A simulator with a graphical user interface for the Patmos processor "));
}


void MainWindow::sim_ReinitializeSimulator()
{

}


void MainWindow::sim_Run()
{

}


void MainWindow::sim_Pause()
{

}


void MainWindow::sim_Stop()
{

}


void MainWindow::sim_SingleStep()
{

}



void MainWindow::documentWasModified()
{
    setWindowModified(true);
}




void MainWindow::loadFile(const QString &fileName)
{

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, tr("Patmos Simulator"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(fileName), file.errorString()));
        return;
    }

    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    editor->setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File loaded"), 2000);


}


void MainWindow::tile(const QMainWindow *previous)
{
    if (!previous)
        return;
    int topFrameWidth = previous->geometry().top() - previous->pos().y();
    if (!topFrameWidth)
        topFrameWidth = 40;
    const QPoint pos = previous->pos() + 2 * QPoint(topFrameWidth, topFrameWidth);
    if (QApplication::desktop()->availableGeometry(this).contains(rect().bottomRight() + pos))
        move(pos);
}

//! [implicit tr context]
void MainWindow::createActions()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    //! [implicit tr context]
    QToolBar *fileToolBar = addToolBar(tr("File"));

    const QIcon newIcon = QIcon::fromTheme("document-new", QIcon(":/icons/new.png"));
    QAction *newAct = new QAction(newIcon, tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Open a new simulation window"));
    connect(newAct, &QAction::triggered, this, &MainWindow::newFile);
    fileMenu->addAction(newAct);
    fileToolBar->addAction(newAct);

    const QIcon openIcon = QIcon::fromTheme("document-open", QIcon(":/icons/ReloadFile.png"));
    QAction *openAct = new QAction(openIcon, tr("&Load..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Load an existing assembly file"));
    connect(openAct, &QAction::triggered, this, &MainWindow::open);
    fileMenu->addAction(openAct);

    fileToolBar->addAction(openAct);
    fileToolBar->addSeparator();

    const QIcon saveIcon = QIcon::fromTheme("document-save", QIcon(":/icons/Save.png"));
    QAction *saveAct = new QAction(saveIcon, tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the assembly file to disk"));
    connect(saveAct, &QAction::triggered, this, &MainWindow::save);
    fileMenu->addAction(saveAct);
    fileToolBar->addAction(saveAct);

    const QIcon saveAsIcon = QIcon::fromTheme("document-save-as");
    QAction *saveAsAct = fileMenu->addAction(saveAsIcon, tr("Save &As..."), this, &MainWindow::saveAs);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    saveAsAct->setStatusTip(tr("Save the assembly file under a new name"));


    const QIcon saveLogIcon = QIcon::fromTheme("document-save", QIcon(":/icons/SaveLog.png"));
    QAction *saveLogAct = new QAction(saveLogIcon, tr("&Save Results"), this);
    saveLogAct->setShortcut(tr("Shift+S"));
    saveLogAct->setStatusTip(tr("Save the results to disk"));
    connect(saveLogAct, &QAction::triggered, this, &MainWindow::file_SaveLogFile);
    fileMenu->addAction(saveLogAct);

    fileToolBar->addAction(saveLogAct);
    fileToolBar->addSeparator();
    fileMenu->addSeparator();

    const QIcon printIcon = QIcon::fromTheme("document-open", QIcon(":/icons/Print.png"));
    QAction *printAct = new QAction(printIcon, tr("&Print"), this);
    printAct->setShortcuts(QKeySequence::Print);
    printAct->setStatusTip(tr("Print Results"));
    connect(printAct, &QAction::triggered, this, &MainWindow::print);
    fileMenu->addAction(printAct);
    fileToolBar->addAction(printAct);




    fileMenu->addSeparator();

    QMenu *recentMenu = fileMenu->addMenu(tr("Recent..."));
    connect(recentMenu, &QMenu::aboutToShow, this, &MainWindow::updateRecentFileActions);
    recentFileSubMenuAct = recentMenu->menuAction();

    for (int i = 0; i < MaxRecentFiles; ++i)
    {
        recentFileActs[i] = recentMenu->addAction(QString(), this, &MainWindow::openRecentFile);
        recentFileActs[i]->setVisible(false);
    }

    recentFileSeparator = fileMenu->addSeparator();

    setRecentFilesVisible(MainWindow::hasRecentFiles());

    QAction *closeAct = fileMenu->addAction(tr("&Close"), this, &QWidget::close);
    closeAct->setShortcut(tr("Ctrl+W"));
    closeAct->setStatusTip(tr("Close this window"));

    const QIcon exitIcon = QIcon::fromTheme("application-exit");
    QAction *exitAct = fileMenu->addAction(exitIcon, tr("Exit"), qApp, &QApplication::closeAllWindows);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));

#ifndef QT_NO_CLIPBOARD

    QMenu *simMenu = menuBar()->addMenu(tr("Simulator"));

    const QIcon clearRegIcon = QIcon(":/icons/ClearRegs.png");
    // first method
    //QAction *clearReg = simMenu->addAction(clearRegIcon,tr("Clear Registers"), RF, &MainWindow::about);
    //second method
    QAction *clearReg = simMenu->addAction(clearRegIcon,tr("Clear Registers"));
    connect(clearReg, SIGNAL(triggered()), RF, SLOT(clearRegisters()));
    clearReg->setStatusTip(tr("Clear register file"));

    simMenu->addSeparator();

    fileToolBar->addSeparator();
    fileToolBar->addAction(clearReg);
    fileToolBar->addSeparator();

    const QIcon checkIcon = QIcon(":/icons/Check.png");
    QAction *check = simMenu->addAction(checkIcon,tr("Check Source"), qApp, &QApplication::aboutQt);
    check->setShortcut(tr("F5"));
    check->setStatusTip(tr("The program will run until it finishes"));
    fileToolBar->addAction(check);

    const QIcon runIcon = QIcon(":/icons/Run.png");
    QAction *run = simMenu->addAction(runIcon,tr("Run/Continue"), qApp, &QApplication::aboutQt);
    run->setShortcut(tr("F5"));
    run->setStatusTip(tr("The program will run until it finishes"));
    fileToolBar->addAction(run);


    const QIcon pauseIcon = QIcon(":/icons/Pause.png");
    QAction *pause = simMenu->addAction(pauseIcon,tr("Pause"), qApp, &QApplication::aboutQt);
    fileToolBar->addAction(pause);

    const QIcon stopIcon = QIcon(":/icons/Stop.png");
    QAction *stop = simMenu->addAction(stopIcon,tr("Stop"), qApp, &QApplication::aboutQt);
    fileToolBar->addAction(stop);

    const QIcon singleStepIcon = QIcon(":/icons/SingleStep.png");
    QAction *singleStep = simMenu->addAction(singleStepIcon,tr("Single Step"), qApp, &QApplication::aboutQt);
    singleStep->setStatusTip(tr("Move a single step between instructions"));
    singleStep->setShortcut(tr("F6"));
    fileToolBar->addAction(singleStep);

#endif // !QT_NO_CLIPBOARD

#ifndef QT_NO_CLIPBOARD


    QMenu *regMenu = menuBar()->addMenu(tr("Registers"));

    //QAction *Bin = regMenu->addAction(tr("Bin"), this,  &MainWindow::about);
    QAction *Bin = regMenu->addAction(("Bin"));
    connect(Bin, SIGNAL(triggered()), RF, SLOT(changeBase2()));
    Bin->setCheckable(true);
    Bin->setShortcut(tr("Shift+1"));
    Bin->setStatusTip(tr("Display the contents of registers in binary"));

    //QAction *Octal = regMenu->addAction(tr("Octal"), this, &MainWindow::about);
    QAction *Octal = regMenu->addAction(("Octal"));
    connect(Octal, SIGNAL(triggered()), RF, SLOT(changeBase8()));
    Octal->setCheckable(true);
    Octal->setShortcut(tr("Shift+2"));
    Octal->setStatusTip(tr("Display the contents of registers in base8"));

    //QAction *Dec = regMenu->addAction(tr("Dec"), this, &MainWindow::about);
    QAction *Dec = regMenu->addAction(("Dec"));
    connect(Dec, SIGNAL(triggered()), RF, SLOT(changeBase10()));
    Dec->setCheckable(true);
    Dec->setChecked(true);
    Dec->setShortcut(tr("Shift+3"));
    Dec->setStatusTip(tr("Display the contents of registers in base10"));

    //QAction *Hex = regMenu->addAction(tr("Hex"), this, &MainWindow::about);
    QAction *Hex = regMenu->addAction(("Hex"));
    connect(Hex, SIGNAL(triggered()), RF, SLOT(changeBase16()));
    Hex->setCheckable(true);
    Hex->setShortcut(tr("Shift+4"));
    Hex->setStatusTip(tr("Display the contents of registers in base16"));

    RegViewGroup = new QActionGroup(this);
    RegViewGroup->addAction(Bin);
    RegViewGroup->addAction(Octal);
    RegViewGroup->addAction(Dec);
    RegViewGroup->addAction(Hex);


#endif // !QT_NO_CLIPBOARD

    viewMenu = menuBar()->addMenu(tr("&View"));


    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));

    const QIcon helpIcon = QIcon(":/icons/Help.png");
    QAction *docAct = helpMenu->addAction(helpIcon,tr("&Documentation"), this, &MainWindow::help_ViewHelp);
    docAct->setStatusTip(tr("Show the program's documentation file"));


    QAction *aboutAct = helpMenu->addAction(tr("About"), this, &MainWindow::help_AboutSimulator);
    //aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));

    fileToolBar->addSeparator();
    fileToolBar->addAction(docAct);


}



void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::isRegFileChanged()
{
    qDebug() << "isregfilechanged run";
    GPDock->setWidget(RF->getGPRegTable());
    SPDock->setWidget(RF->getSPRegTable());
    PredDock->setWidget(RF->getPredRegTable());


}

void MainWindow::isBaseChanged()
{
    GPDock->setWidget(RF->tableToBase(RF->getBase(),RF->getGPRegTable()));
    SPDock->setWidget(RF->tableToBase(RF->getBase(),RF->getSPRegTable()));
    PredDock->setWidget(RF->tableToBase(RF->getBase(),RF->getPredRegTable()));

}








QString MainWindow::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}

MainWindow *MainWindow::findMainWindow(const QString &fileName) const
{
    QString canonicalFilePath = QFileInfo(fileName).canonicalFilePath();

    foreach (QWidget *widget, QApplication::topLevelWidgets())
    {
        MainWindow *mainWin = qobject_cast<MainWindow *>(widget);
        if (mainWin && mainWin->curFile == canonicalFilePath)
            return mainWin;
    }

    return 0;
}



