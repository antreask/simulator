#include "instructionmemory.h"

InstructionMemory::InstructionMemory()
{

    IMmodel = new QStandardItemModel(0,2,this);

    IMTable = new QTableView();

    IMTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //IMTable->horizontalHeader()->hide();
    IMTable->verticalHeader()->hide();
    IMmodel->setHorizontalHeaderLabels(QStringList() << tr("Address")<< tr("Instruction"));
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

void InstructionMemory::clearmemory()
{
    IMmodel->clear();
    IMmodel->setHorizontalHeaderLabels(QStringList() << tr("Address")<< tr("Instruction"));;
    IMTable->setModel(IMmodel);
    lastAddress=0;
}
