#include "CPU/wb.h"
#include <QDebug>
WB::WB()
{
    qDebug()<< "WB's constructor called";
}

void WB::wakeup()
{
    qDebug()<< "WB's wakeup called";
}
