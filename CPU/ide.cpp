#include "CPU/ide.h"
#include <QDebug>
IDE::IDE()
{
    setName("decode");
    // qDebug()<< "IDE's constructor called";
}

void IDE::wakeup()
{
    // qDebug()<< "IDE's wakeup called";
}

void IDE::init(EXE *exec)
{
    execute=exec;
}
