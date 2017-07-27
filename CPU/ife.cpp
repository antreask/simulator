#include "CPU/ife.h"
#include <QDebug>
#include <QTableWidget>
#include <QString>
#include "mainwindow.h"


IFE::IFE()
{
    //qDebug()<< "IFE's constructor called";
    setName("fetch");
}

void IFE::init(InstructionMemory *mem, IDE *decode)
{
    Imem=mem;
    dec=decode;
}

void IFE::printIM()
{
    for (int i = 0; i<Imem->getIMmodel()->rowCount(); i++)
    {
        for (int j = 0; j < Imem->getIMmodel()->columnCount(); j++)
        {
            qDebug()<< Imem->getIMmodel()->data(Imem->getIMmodel()->index(i,j)).toString();
        }

    }
}



void IFE::wakeup()
{
    // qDebug()<< "IFE's wakeup called";

}
