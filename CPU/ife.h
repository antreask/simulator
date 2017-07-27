#ifndef IFE_H
#define IFE_H

#include <cassert>
#include "CPU/consumer.h"
#include "instructionmemory.h"
#include "CPU/ide.h"

class IFE:public Consumer
{
public:
    IFE();
    void init(InstructionMemory *mem, IDE *decode);
    void printIM();
    void wakeup();

private:
    InstructionMemory *Imem;
    IDE *dec;
};

#endif // IFE_H
