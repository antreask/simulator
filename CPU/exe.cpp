#include "CPU/exe.h"
#include <QDebug>
EXE::EXE()
{
    setName("execute");
    // qDebug()<< "EXE's constructor called";
}

void EXE::wakeup()
{
    // qDebug()<< "EXE's wakeup called";
}

void EXE::init(MEM *memo)
{
    memory=memo;
}
