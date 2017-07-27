#include "CPU/consumer.h"
#include <QDebug>


Consumer::Consumer()
{
    //qDebug()<< "Consumer's constructor";

}

void Consumer::wakeup()
{
    //qDebug()<< "Consumer's wakeup called";
}

QString Consumer::getName() const
{
    return name;
}

void Consumer::setName(const QString &value)
{
    name = value;
}
