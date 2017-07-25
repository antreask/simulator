#include "CPU/event.h"
#include <QDebug>

Event::Event()
{
    qDebug()<< "Event's constructor called";
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





