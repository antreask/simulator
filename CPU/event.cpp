#include "CPU/event.h"
#include <QDebug>

Event::Event()
{
    //qDebug()<< "Event's constructor called";
}

Event::Event(Consumer *cons, int weight)
{
    this->cons=cons;
    this->weight=weight;

}

Event::Event(Consumer *cons)
{
    this->cons=cons;
    qDebug() << cons->getName();
    if ((cons->getName())=="fetch")
        weight=0;
    else if ((cons->getName())=="decode")
        weight=1;
    else if ((cons->getName())=="execute")
        weight=2;
    else if ((cons->getName())=="memory")
        weight=3;
    else if ((cons->getName())=="write")
        weight=4;
}

int Event::getClock_cycle() const
{
    return clock_cycle;
}

void Event::setClock_cycle(int value)
{
    clock_cycle = value;
}

int Event::getWeight() const
{
    return weight;
}

void Event::setWeight(int value)
{
    weight = value;
}

Consumer *Event::getCons() const
{
    return cons;
}

void Event::setCons(Consumer *value)
{
    cons = value;
}





