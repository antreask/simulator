#ifndef EXE_H
#define EXE_H

#include "CPU/consumer.h"

class EXE:public Consumer
{
public:
    EXE();

    void wakeup();
};

#endif // EXE_H
