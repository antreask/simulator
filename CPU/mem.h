#ifndef MEM_H
#define MEM_H

#include "CPU/consumer.h"

class MEM:public Consumer
{
public:
    MEM();
    void wakeup();
};

#endif // MEM_H
