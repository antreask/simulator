
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QTableWidget>
#include <codeeditor.h>
#include <QActionGroup>
#include <QSpinBox>
#include <deque>
#include "registerfile.h"
#include "instructionmemory.h"
#include "datamemory.h"
#include "CPU/consumer.h"
#include "CPU/event.h"
#include "global_info.h"


QT_BEGIN_NAMESPACE
class QAction;
class QListWidget;
class QMenu;
class QTextEdit;
QT_END_NAMESPACE

//! [class definition with macro]
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    //! [class definition with macro]
    explicit MainWindow(const QString &fileName);

    void tile(const QMainWindow *previous);
    void help_ViewHelp();
    void help_AboutSimulator();
    QDockWidget *DataDock;
    QDockWidget *InstrDock;
    QDockWidget *GPDock;
    QDockWidget *SPDock;
    QDockWidget *PredDock;
    QDockWidget *ConsoleDock;
    QSpinBox *Spinbox;
    RegisterFile *RF;
    InstructionMemory *IM;
    DataMemory *DM;
    QActionGroup *RegViewGroup;
    global_info *GI;

public slots:
    void isRegFileChanged();
    void isBaseChanged();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void updateRecentFileActions();
    void openRecentFile();
    void about();
    void print();
    void documentWasModified();

    void sim_Run();
    void sim_SingleStep();

private:
    enum { MaxRecentFiles = 5 };

    void init();
    void createActions();
    void createStatusBar();
    void createDockWindows();
    void readSettings();
    void writeSettings();
    bool maybeSave();
    void openFile(const QString &fileName);
    void loadFile(const QString &fileName);
    static bool hasRecentFiles();
    void prependToRecentFiles(const QString &fileName);
    void setRecentFilesVisible(bool visible);
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    void file_SaveLogFile();
    static QString strippedName(const QString &fullFileName);
    MainWindow *findMainWindow(const QString &fileName) const;


    void checkFile();
    void displayGPRegisters();
    void displaySPRegisters();
    void displayPredRegisters();
    void initRegFile();


    CodeEditor *editor;

    QAction *recentFileActs[MaxRecentFiles];
    QAction *recentFileSeparator;
    QAction *recentFileSubMenuAct;
    QTextEdit *console;

    QMenu *viewMenu;
    QString curFile;
    void clearEverything();
    bool isUntitled;
    bool isfileok=false;
    bool dataflag=false;
    bool instflag=false;
    bool mainflag=false;
    bool syntaxpass=false;
    int base=10;
};

extern MainWindow* Window;
extern QApplication* App;

#endif
