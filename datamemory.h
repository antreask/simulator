#ifndef DATAMEMORY_H
#define DATAMEMORY_H

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

class DataMemory
{
public:
    DataMemory();

    QStandardItemModel *getDMmodel() const;
    void setDMmodel(QStandardItemModel *value);

    QTableView *getDMTable() const;
    void setDMTable(QTableView *value);

private:

    QTableView *DMTable;
    QStandardItemModel *DMmodel;
};

#endif // DATAMEMORY_H
