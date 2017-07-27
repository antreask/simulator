#ifndef EVENT_H
#define EVENT_H


#include "CPU/consumer.h"

class Event
{
public:
    Event();
    Event(const int &clock,Consumer *cons, int weight);
    Event(const int &clock,Consumer *cons);

    int getClock_cycle() const;
    void setClock_cycle(int value);

    int getWeight() const;
    void setWeight(int value);

    Consumer *getCons() const;
    void setCons(Consumer *value);

private:
    int clock_cycle;
    int weight;
    Consumer *cons;
};

#endif // EVENT_H
