#include "CPU/mem.h"
#include <QDebug>
MEM::MEM()
{
    qDebug()<< "MEM's constructor called";
}

void MEM::wakeup()
{
    qDebug()<< "MEM's wakeup called";
}
