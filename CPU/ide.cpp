#include "CPU/ide.h"
#include <QDebug>
IDE::IDE()
{
    qDebug()<< "IDE's constructor called";
}

void IDE::wakeup()
{
    qDebug()<< "IDE's wakeup called";
}
