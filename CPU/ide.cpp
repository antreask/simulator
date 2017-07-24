#include "CPU/ide.h"
#include <QDebug>
IDE::IDE()
{
    qDebug()<< "WB called";
}

void IDE::wakeup()
{
    qDebug()<< "WB called";
}
