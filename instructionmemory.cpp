#include "instructionmemory.h"

InstructionMemory::InstructionMemory()
{

    IMmodel = new QStandardItemModel();

    IMTable = new QTableView();

    IMTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    IMTable->horizontalHeader()->hide();
    IMTable->verticalHeader()->hide();

    IMTable->setModel(IMmodel);


}

QTableView *InstructionMemory::getIMTable() const
{
    return IMTable;
}

void InstructionMemory::setIMTable(QTableView *value)
{
    IMTable = value;
}

QStandardItemModel *InstructionMemory::getIMmodel() const
{
    return IMmodel;
}

void InstructionMemory::setIMmodel(QStandardItemModel *value)
{
    IMmodel = value;
}
