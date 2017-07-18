#ifndef INSTRUCTIONMEMORY_H
#define INSTRUCTIONMEMORY_H

#include <QTableWidgetItem>
#include <QStandardItemModel>
#include <QHeaderView>

QT_BEGIN_NAMESPACE
class QAction;
class QObject;
class QMenu;
class QTextEdit;
QT_END_NAMESPACE

class InstructionMemory:public QTableWidget
{
    Q_OBJECT
public:
    InstructionMemory();



    QTableView *getIMTable() const;
    void setIMTable(QTableView *value);

    QStandardItemModel *getIMmodel() const;
    void setIMmodel(QStandardItemModel *value);


public slots:
    void clearmemory();

signals:
    void clearIMsig();

private:

    QTableView *IMTable;
    QStandardItemModel *IMmodel;
    int lastAddress=0;

};

#endif // INSTRUCTIONMEMORY_H
