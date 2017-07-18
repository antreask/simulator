#ifndef DATAMEMORY_H
#define DATAMEMORY_H

#include <QTableWidgetItem>
#include <QStandardItemModel>
#include <QHeaderView>

QT_BEGIN_NAMESPACE
class QAction;
class QObject;
class QMenu;
class QTextEdit;
QT_END_NAMESPACE

class DataMemory:public QTableWidget
{
    Q_OBJECT

public:
    DataMemory();

    QStandardItemModel *getDMmodel() const;
    void setDMmodel(QStandardItemModel *value);

    QTableView *getDMTable() const;
    void setDMTable(QTableView *value);

    bool addline(QString line);


public slots:
    void clearmemory();

signals:
    void clearDMsig();


private:

    QTableView *DMTable;
    QStandardItemModel *DMmodel;
    void addnewdata(const QStringList &list);
    void set_increase_value(QString type);
    int lastAddress=0;
    int increase_value=0;

};

#endif // DATAMEMORY_H
