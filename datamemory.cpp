#include "datamemory.h"
#include <QDebug>
#include <QRegularExpression>

DataMemory::DataMemory()
{
    DMmodel = new QStandardItemModel(0,3,this);

    DMTable = new QTableView();

    DMTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //DMTable->resizeColumnsToContents();
    //DMTable->horizontalHeader()->hide();
    DMTable->verticalHeader()->hide();
    DMmodel->setHorizontalHeaderLabels(QStringList() << tr("Address")
                                       << tr("Content")<< tr("Label"));

    DMTable->setModel(DMmodel);
}

QStandardItemModel *DataMemory::getDMmodel() const
{
    return DMmodel;
}

void DataMemory::setDMmodel(QStandardItemModel *value)
{
    DMmodel = value;
}

QTableView *DataMemory::getDMTable() const
{
    return DMTable;
}

void DataMemory::setDMTable(QTableView *value)
{
    DMTable = value;
}

void DataMemory::addnewdata(const QStringList &list)
{
    QList<QStandardItem*> rowData;
    set_increase_value(list[1]);
    for (int i=2; i<list.length(); i++)
    {
        rowData.clear();
        rowData << new QStandardItem(QString("%1").arg(lastAddress));
        rowData << new QStandardItem(QString("%1").arg(list[i]));
        rowData << new QStandardItem(QString("%1").arg(list[0]));
        DMmodel->appendRow(rowData);
        lastAddress+=increase_value;
    }
    DMTable->resizeColumnsToContents();
}

void DataMemory::set_increase_value(QString type)
{
    if (type=="byte")
    {
        increase_value=1;
        return;
    }
    if (type=="half")
    {
        increase_value=2;
        return;
    }
    if (type=="word")
    {
        increase_value=4;
        return;
    }
}

void DataMemory::clearmemory()
{
    DMmodel->clear();
    DMmodel->setHorizontalHeaderLabels(QStringList() << tr("Address")
                                       << tr("Content")<< tr("Label"));
    DMTable->setModel(DMmodel);
    lastAddress=0;
    increase_value=0;

}

bool DataMemory::addline(QString line)
{
    QRegularExpression separator("(\\ |\\,|\\.|\\:|\\t)"); //RegEx for ' ' or ',' or '.' or ':' or '\t'
    QStringList list = line.split(separator,QString::SkipEmptyParts);

    if ((list[1]!="byte")&&(list[1]!="half")&&(list[1]!="word"))
        return false;

    addnewdata(list);

    return true;
}
