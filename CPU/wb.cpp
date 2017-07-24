#include "CPU/wb.h"
#include <QDebug>
WB::WB()
{
    qDebug()<< "WB called";
}

void WB::wakeup()
{
    qDebug()<< "WB called";
}
