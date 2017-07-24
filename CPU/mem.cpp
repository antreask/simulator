#include "CPU/mem.h"
#include <QDebug>
MEM::MEM()
{
    qDebug()<< "WB called";
}

void MEM::wakeup()
{
    qDebug()<< "WB called";
}
