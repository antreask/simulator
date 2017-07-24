#include "CPU/event.h"
#include <QDebug>

Event::Event()
{
    qDebug()<< "WB called";
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

