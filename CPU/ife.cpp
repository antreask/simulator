#include "CPU/ife.h"
#include <QDebug>
IFE::IFE()
{
    qDebug()<< "WB called";
}

void IFE::wakeup()
{
    qDebug()<< "WB called";
}
