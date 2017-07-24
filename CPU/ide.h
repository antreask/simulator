#ifndef IDE_H
#define IDE_H

#include "CPU/consumer.h"

class IDE:public Consumer
{
public:
    IDE();

    void wakeup();
};

#endif // IDE_H
