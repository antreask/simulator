#ifndef IDE_H
#define IDE_H

#include "CPU/consumer.h"
#include "CPU/exe.h"

class IDE:public Consumer
{
public:
    IDE();

    void wakeup();
    void init(EXE *exec);
private:
    EXE *execute;
};

#endif // IDE_H
