#ifndef INSTRUCTIONMEMORY_H
#define INSTRUCTIONMEMORY_H

#include <QTableWidgetItem>
#include <QStandardItemModel>
#include <QHeaderView>
#include <qactiongroup.h>

QT_BEGIN_NAMESPACE
class QAction;
class QObject;
class QMenu;
class QTextEdit;
QT_END_NAMESPACE

class InstructionMemory
{
public:
    InstructionMemory();



    QTableView *getIMTable() const;
    void setIMTable(QTableView *value);

    QStandardItemModel *getIMmodel() const;
    void setIMmodel(QStandardItemModel *value);

private:

    QTableView *IMTable;
    QStandardItemModel *IMmodel;

};

#endif // INSTRUCTIONMEMORY_H
