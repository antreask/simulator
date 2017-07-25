#include "instructionmemory.h"
#include <QRegularExpression>
#include <QDebug>


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
    QRegularExpression separator("(\\ |\\,|\\:|\\t|\\;|\\=)"); //RegEx for ' ' or ',' or '.' or ':' or '\t'
    QStringList list = line.split(separator,QString::SkipEmptyParts);
    bundle=false;

    if (list.length()==1)
    {
        addnewdata(line);
        return true;
    }

    if (list.length()!=4)
    {
        qDebug() << "Wrong number of arguments" << list.length();
        for (int i=0; i<list.length(); i++)
            qDebug() <<list[i];
        return false;
    }

    if (!insts.contains(list[0]))
    {
        qDebug() << "Argument 0 error";
        qDebug() <<list[0];
        return false;
    }

    if (!GPRegs.contains(list[1]) &&!SPRegs.contains(list[1]) && !PRRegs.contains(list[1]))
    {
        qDebug() << "Argument 1 error";
        qDebug() <<list[1];
        return false;
    }

    if (!GPRegs.contains(list[2]) && !SPRegs.contains(list[2]) && !PRRegs.contains(list[2]))
    {
        qDebug() << "Argument 2 error";
        qDebug() <<list[2];
        return false;
    }

    if (!GPRegs.contains(list[3]) && !SPRegs.contains(list[3]) && !PRRegs.contains(list[3]))
    {

        QRegExp re("\\d*");  // a digit (\d), zero or more times (*)
        if (!re.exactMatch(list[3]))
        {
            qDebug() << "Argument 3 error";
            qDebug() <<list[3];
            return false;
        }
        QString num=list[3];
        if (num.toInt()>4095)
            bundle=true;
    }

    addnewdata(list);
    return true;
}


void InstructionMemory::addnewdata(const QString &line)
{
    QList<QStandardItem*> rowData;
    rowData.clear();
    rowData << new QStandardItem(QString("%1").arg(lastAddress));
    rowData << new QStandardItem(line);
    IMmodel->appendRow(rowData);
    IMTable->resizeColumnsToContents();
}

void InstructionMemory::addnewdata(const QStringList &list)
{
    QList<QStandardItem*> rowData;
    QString instr;
    instr=list[0]+"   "+list[1]+" = "+list[2]+" , "+list[3];
    rowData.clear();
    rowData << new QStandardItem(QString("%1").arg(lastAddress));
    rowData << new QStandardItem(instr);
    IMmodel->appendRow(rowData);
    if (bundle)
        lastAddress+=8;
    else
        lastAddress+=4;
    IMTable->resizeColumnsToContents();

}

int InstructionMemory::getPCReg() const
{
    return PCReg;
}

void InstructionMemory::setPCReg(int value)
{
    PCReg = value;
}

void InstructionMemory::clearmemory()
{
    IMmodel->clear();
    IMmodel->setHorizontalHeaderLabels(QStringList() << tr("Address")<< tr("Instruction"));;
    IMTable->setModel(IMmodel);
    lastAddress=0;
    PCReg=0;
}
