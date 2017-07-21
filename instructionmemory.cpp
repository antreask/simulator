#include "instructionmemory.h"
#include <QRegularExpression>


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

bool InstructionMemory::addline(QString line)
{
    QRegularExpression separator("(\\ |\\,|\\=|\\t)"); //RegEx for ' ' or ',' or '.' or ':' or '\t'
    QStringList list = line.split(separator,QString::SkipEmptyParts);

    /*if ((list[1]!=)
            return false;

            addnewdata(list);*/

    return true;
}

void InstructionMemory::clearmemory()
{
    IMmodel->clear();
    IMmodel->setHorizontalHeaderLabels(QStringList() << tr("Address")<< tr("Instruction"));;
    IMTable->setModel(IMmodel);
    lastAddress=0;
}
