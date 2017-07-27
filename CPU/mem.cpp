#include "CPU/mem.h"
#include <QDebug>
MEM::MEM()
{
    setName("memory");
    //qDebug()<< "MEM's constructor called";
}

void MEM::wakeup()
{
    //  qDebug()<< "MEM's wakeup called";
}

void MEM::init(WB *wr_back)
{
    write=wr_back;
}
