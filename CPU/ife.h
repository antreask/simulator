#ifndef IFE_H
#define IFE_H

#include "CPU/consumer.h"

class IFE:public Consumer
{
public:
    IFE();
    void wakeup();
};

#endif // IFE_H
