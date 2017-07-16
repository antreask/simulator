#include "datamemory.h"

DataMemory::DataMemory()
{
    DMmodel = new QStandardItemModel();

    DMTable = new QTableView();

    DMTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    DMTable->horizontalHeader()->hide();
    DMTable->verticalHeader()->hide();

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
