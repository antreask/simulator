#ifndef IFE_H
#define IFE_H

#include <cassert>
#include "CPU/consumer.h"
#include "instructionmemory.h"

class IFE:public Consumer
{
public:
    IFE();
    void init(InstructionMemory *mem);
    void printIM();
    void wakeup();

private:
    InstructionMemory *Imem;
};

#endif // IFE_H
