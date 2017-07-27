#ifndef MEM_H
#define MEM_H

#include "CPU/consumer.h"
#include "CPU/wb.h"

class MEM:public Consumer
{
public:
    MEM();
    void wakeup();
    void init(WB * wr_back);
private:
    WB *write;
};

#endif // MEM_H
