#include "CPU/exe.h"
#include <QDebug>
EXE::EXE()
{
    qDebug()<< "WB called";
}

void EXE::wakeup()
{
    qDebug()<< "WB called";
}
