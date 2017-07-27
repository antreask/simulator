#ifndef EXE_H
#define EXE_H

#include "CPU/consumer.h"
#include "CPU/mem.h"

class EXE:public Consumer
{
public:
    EXE();

    void wakeup();
    void init(MEM *memo);
private:
    MEM *memory;
};

#endif // EXE_H
