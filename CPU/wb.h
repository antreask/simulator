#ifndef WB_H
#define WB_H

#include "CPU/consumer.h"

class WB:public Consumer
{
public:
    WB();
    void wakeup();
};

#endif // WB_H
