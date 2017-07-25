#include "CPU/exe.h"
#include <QDebug>
EXE::EXE()
{
    qDebug()<< "EXE's constructor called";
}

void EXE::wakeup()
{
    qDebug()<< "EXE's wakeup called";
}
